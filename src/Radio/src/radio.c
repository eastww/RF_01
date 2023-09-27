/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, CMOSTEK SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * Copyright (C) CMOSTEK SZ.
 */

/*!
 * @file    radio.c
 * @brief   Generic radio handlers
 *
 * @version 1.1
 * @date    Feb 08 2017
 * @author  CMOSTEK R@D
 */

#include "radio.h"
#include "cmt2300_params.h"
#include "CMT230_params_RxTxTest.h"
#include "string.h"
#ifdef USE_CUBEIDE
#include "./../../gpio.h"
#include "./../../delay.h"
#include "./../../CubeIDE/Bsp/config/rf_cfg.h"
#include "./../../CubeIDE/Bsp/timer.h"
#endif

#define INFINITE 0xffffffff

static EnumRFStatus g_nNextRFState = RF_STATE_IDLE;
static uint8_t *g_pRxBuffer = NULL;
static uint8_t *g_pTxBuffer = NULL;
static uint16_t g_nRxLength = 0;
static uint16_t g_nTxLength = 0;

uint32_t g_nRxTimeout = INFINITE;
uint32_t g_nTxTimeout = INFINITE;
uint32_t g_nRxTimeCount = 0;
uint32_t g_nTxTimeCount = 0;

uint8_t PlayLoadlen;
uint8_t g_nInterrutFlags;
extern volatile uint32_t g_nSysTickCount;
extern volatile uint8_t  cmt2300_irq_request;	//request for irq
void RF_Init(void)
{
    Cmt2300_InitGpio();
    Cmt2300_Init();

    /* Config registers */
    Cmt2300_ConfigRegBank(CMT2300_CMT_BANK_ADDR, g_cmt2300CmtBank, CMT2300_CMT_BANK_SIZE);
    Cmt2300_ConfigRegBank(CMT2300_SYSTEM_BANK_ADDR, g_cmt2300SystemBank, CMT2300_SYSTEM_BANK_SIZE);
    Cmt2300_ConfigRegBank(CMT2300_FREQUENCY_BANK_ADDR, g_cmt2300FrequencyBank, CMT2300_FREQUENCY_BANK_SIZE);
    Cmt2300_ConfigRegBank(CMT2300_DATA_RATE_BANK_ADDR, g_cmt2300DataRateBank, CMT2300_DATA_RATE_BANK_SIZE);
    Cmt2300_ConfigRegBank(CMT2300_BASEBAND_BANK_ADDR, g_cmt2300BasebandBank, CMT2300_BASEBAND_BANK_SIZE);
    Cmt2300_ConfigRegBank(CMT2300_TX_BANK_ADDR, g_cmt2300TxBank, CMT2300_TX_BANK_SIZE);

    RF_Config();
}
 
//单载波
int8_t RF_initWirelessCare(void)
{
    Cmt2300_Init();
    /* Config registers */
    Cmt2300_ConfigRegBank(CMT2300_CMT_BANK_ADDR, g_cmt2300TxOokBank, sizeof(g_cmt2300TxOokBank));

    Delay_Ms(10);
    cmt_spi3_gpio3_out();
    cmt_spi3_gpio3_1();

    Cmt2300_GoStby();
    Delay_Ms(2);

    Cmt2300_EnableAntennaSwitch(1);

    Cmt2300_ConfigGpio(CMT2300_GPIO3_SEL_DIN);

    Cmt2300_EnableTxDin(true);
    Cmt2300_ConfigTxDin(CMT2300_TX_DIN_SEL_GPIO3);

    if (false == Cmt2300_GoTx())
    {
        g_nNextRFState = RF_STATE_ERROR;
        return -1;
    }
    else
    {
        g_nNextRFState = RF_STATE_TX_WAIT;
        return 0;
    }
}
//灵敏度
int8_t RF_initRxSensitivityTest(void)
{
    Cmt2300_Init();
    /* Config registers */
    Cmt2300_ConfigRegBank(CMT2300_CMT_BANK_ADDR, g_cmt2300RxTestFskBank, sizeof(g_cmt2300RxTestFskBank));

    Delay_Ms(10);
    cmt_spi3_gpio3_in();

    Cmt2300_GoStby();
    Delay_Ms(2);
    Cmt2300_EnableAntennaSwitch(1);

    Cmt2300_ConfigGpio(CMT2300_GPIO3_SEL_DOUT);

    if (false == Cmt2300_GoRx())
    {
        g_nNextRFState = RF_STATE_ERROR;
        return -1;
    }
    else
    {
        g_nNextRFState = RF_STATE_RX_WAIT;
        return 0;
    }
}
void RF_Config(void)
{
#ifdef ENABLE_ANTENNA_SWITCH
    /* If you enable antenna switch, GPIO1/GPIO2 will output RX_ACTIVE/TX_ACTIVE,
       and it can't output INT1/INT2 via GPIO1/GPIO2 */
    Cmt2300_EnableAntennaSwitch(0);

#else
    
    Cmt2300_EnableAntennaSwitch(0);
        /* Config GPIOs */
    Cmt2300_ConfigGpio(
       // CMT2300_GPIO1_SEL_INT1 | /* INT1 > GPIO1 */
       // CMT2300_GPIO2_SEL_INT2 | /* INT2 > GPIO2 */
        CMT2300_GPIO3_SEL_INT2);   /* INT2 > GPIO3 */

    /* Config interrupt */
    Cmt2300_ConfigInterrupt(
        CMT2300_INT_SEL_TX_DONE, /* Config INT1 */
        CMT2300_INT_SEL_PKT_OK   /* Config INT2 */
    );
#endif

    /* Enable interrupt */
         Cmt2300_EnableInterrupt(
        CMT2300_MASK_TX_DONE_EN |
        CMT2300_MASK_PREAM_OK_EN |
        CMT2300_MASK_SYNC_OK_EN |
        CMT2300_MASK_NODE_OK_EN |
        CMT2300_MASK_CRC_OK_EN |
        CMT2300_MASK_PKT_DONE_EN);

    Cmt2300_EnableLfosc(false);

    /* Use a single 64-byte FIFO for either Tx or Rx */
    //Cmt2300_EnableFifoMerge(true);

    //Cmt2300_SetFifoThreshold(16);

    /* Go to sleep for configuration to take effect */
    Cmt2300_GoSleep();
}

void RF_SetStatus(EnumRFStatus nStatus)
{
    g_nNextRFState = nStatus;
}

EnumRFStatus RF_GetStatus(void)
{
    return g_nNextRFState;
}

uint8_t RF_GetInterruptFlags(void)
{
    return g_nInterrutFlags;
}

void RF_StartRx(uint8_t buf[], uint16_t len, uint32_t timeout)
{
    g_pRxBuffer = buf;
    g_nRxLength = len;
    g_nRxTimeout = timeout;

    memset(g_pRxBuffer, 0, g_nRxLength);

    g_nNextRFState = RF_STATE_RX_START;
}

void RF_StartTx(uint8_t buf[], uint16_t len, uint32_t timeout)
{
    g_pTxBuffer = buf;
    g_nTxLength = len;
    g_nTxTimeout = timeout;

    g_nNextRFState = RF_STATE_TX_START;
}

EnumRFResult RF_Process(void)
{
    EnumRFResult nRes = RF_BUSY;

    switch (g_nNextRFState)
    {
    case RF_STATE_IDLE:
    {
        nRes = RF_IDLE;
        break;
    }

    case RF_STATE_RX_START:
    {
        Cmt2300_GoStby();
        Cmt2300_ClearInterruptFlags();

        /* Must clear FIFO after enable SPI to read or write the FIFO */
        Cmt2300_EnableReadFifo();
        Cmt2300_ClearFifo();

        if (false == Cmt2300_GoRx())
        {
            g_nNextRFState = RF_STATE_ERROR;
        }
        else
        {
            cmt2300_irq_request=0;
            g_nNextRFState = RF_STATE_RX_WAIT;

            g_nRxTimeCount = Cmt2300_GetTickCount();
        }

        break;
    }

    case RF_STATE_RX_WAIT:
    {
#ifdef ENABLE_ANTENNA_SWITCH
        if (CMT2300_MASK_PKT_OK_FLG & Cmt2300_ReadReg(CMT2300_CUS_INT_FLAG)) /* Read PKT_OK flag */
#else
        if (cmt2300_irq_request) /* Read INT2, PKT_OK */
#endif
        {
            cmt2300_irq_request=0;
            g_nNextRFState = RF_STATE_RX_DONE;
        }

        if( (INFINITE != g_nRxTimeout) && ((g_nSysTickCount-g_nRxTimeCount) > g_nRxTimeout) )
            g_nNextRFState = RF_STATE_RX_TIMEOUT;
        
        break;
    }

    case RF_STATE_RX_DONE:
    {
        Cmt2300_GoStby();

        Cmt2300_ReadFifo(g_pRxBuffer, 1);//读取数据长度
           
        PlayLoadlen=g_pRxBuffer[0];
        
        /* The length need be smaller than 32 */
        Cmt2300_ReadFifo(g_pRxBuffer, PlayLoadlen);

        g_nInterrutFlags = Cmt2300_ClearInterruptFlags();

        //        Cmt2300_GoSleep();
#ifdef USE_CUBEIDE
        rfRecvDoneCallback();
        led2Toggle();
#endif
        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_RX_DONE;
        break;
    }

    case RF_STATE_RX_TIMEOUT:
    {
        //        Cmt2300_GoSleep();
        //
#ifdef USE_CUBEIDE
    	rfRecvTimeoutCallback();
#endif
        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_RX_TIMEOUT;

        break;
    }

    case RF_STATE_TX_START:
    {
        Cmt2300_GoStby();
        Cmt2300_ClearInterruptFlags();

        /* Must clear FIFO after enable SPI to read or write the FIFO */
        Cmt2300_EnableWriteFifo();
        Cmt2300_ClearFifo();

        Cmt2300_SetPayloadLength(g_nTxLength); //发射数据长度
      
        Cmt2300_WriteFifo(g_pTxBuffer, g_nTxLength);

        if (0 == (CMT2300_MASK_TX_FIFO_NMTY_FLG & Cmt2300_ReadReg(CMT2300_CUS_FIFO_FLAG)))
        {
            g_nNextRFState = RF_STATE_ERROR;
        }

        if (false == Cmt2300_GoTx())
        {
            g_nNextRFState = RF_STATE_ERROR;
        }
        else  
        {
            cmt2300_irq_request=0;
            g_nNextRFState = RF_STATE_TX_WAIT;

            g_nTxTimeCount = Cmt2300_GetTickCount();
        }

        break;
    }

    case RF_STATE_TX_WAIT:
    {
#ifdef ENABLE_ANTENNA_SWITCH
        if (CMT2300_MASK_TX_DONE_FLG & Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1)) /* Read TX_DONE flag */
#else
        if (CMT2300_MASK_TX_DONE_FLG & Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1)) /* Read TX_DONE flag */
#endif
        {         
          g_nNextRFState = RF_STATE_TX_DONE;
        }
        
        if( (INFINITE != g_nTxTimeout) && ((g_nSysTickCount-g_nTxTimeCount) > g_nTxTimeout) )
            g_nNextRFState = RF_STATE_TX_TIMEOUT;

        break;
    }

    case RF_STATE_TX_DONE:
    {
        Cmt2300_ClearInterruptFlags();
        //Cmt2300_GoSleep();
#ifdef USE_CUBEIDE
        rfSendDoneCallback();
        led1Toggle();
#endif
        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_TX_DONE;
        break;
    }

    case RF_STATE_TX_TIMEOUT:
    {
        //        Cmt2300_GoSleep();      
        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_TX_TIMEOUT;
        break;
    }

    case RF_STATE_ERROR:
    {
        Cmt2300_SoftReset();
        Delay_Ms(10);

        Cmt2300_GoStby();
        RF_Config();
#ifdef USE_CUBEIDE
        rfRecvErrorCallback();
#endif
        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_ERROR;
        break;
    }

    default:
        break;
    }

    return nRes;
}
EnumRFResult RF_sendMessage(unsigned char *message, unsigned char messageLen)
{
    EnumRFResult nRes = RF_BUSY;

    switch (g_nNextRFState)
    {
    case RF_STATE_IDLE:
    {
        nRes = RF_IDLE;
        break;
    }
    case RF_STATE_TX_START:
    {
        Cmt2300_GoStby();
        Cmt2300_ClearInterruptFlags();

        /* Must clear FIFO after enable SPI to read or write the FIFO */
        Cmt2300_EnableWriteFifo();
        Cmt2300_ClearFifo();

        /* The length need be smaller than 32 */
        Cmt2300_WriteFifo(message, messageLen);

        if (0 == (CMT2300_MASK_TX_FIFO_NMTY_FLG & Cmt2300_ReadReg(CMT2300_CUS_FIFO_FLAG)))
            g_nNextRFState = RF_STATE_ERROR;

        if (false == Cmt2300_GoTx())
            g_nNextRFState = RF_STATE_ERROR;
        else
            g_nNextRFState = RF_STATE_TX_WAIT;

        //        g_nTxTimeCount = Cmt2300_GetTickCount();

        break;
    }

    case RF_STATE_TX_WAIT:
    {
#ifdef ENABLE_ANTENNA_SWITCH
        if (CMT2300_MASK_TX_DONE_FLG & Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1)) /* Read TX_DONE flag */
#else
        if (cmt2300_irq_request) /* Read INT1, TX_DONE */
#endif
        {
            cmt2300_irq_request=0;
            g_nNextRFState = RF_STATE_TX_DONE;
        }

        //        if( (INFINITE != g_nTxTimeout) && ((Cmt2300_GetTickCount()-g_nTxTimeCount) > g_nTxTimeout) )
        //            g_nNextRFState = RF_STATE_TX_TIMEOUT;

        break;
    }

    case RF_STATE_TX_DONE:
    {
        Cmt2300_ClearInterruptFlags();
        Cmt2300_GoSleep();

        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_TX_DONE;
        break;
    }

    case RF_STATE_TX_TIMEOUT:
    {
        Cmt2300_GoSleep();

        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_TX_TIMEOUT;
        break;
    }

    case RF_STATE_ERROR:
    {
        Cmt2300_SoftReset();
        Delay_Ms(10);
        Cmt2300_GoStby();
        RF_Config();

        g_nNextRFState = RF_STATE_IDLE;
        nRes = RF_ERROR;
        break;
    }

    default:
        break;
    }

    return nRes;
}
