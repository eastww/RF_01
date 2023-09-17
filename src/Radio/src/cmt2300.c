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
 * @file    cmt2300.c
 * @brief   CMT2300 transceiver RF chip driver
 *
 * @version 1.2
 * @date    Feb 08 2017
 * @author  CMOSTEK R@D
 */
#define MOD_CMT2300

#include "cmt2300.h"
#include "CMT2300_FrqSetTab.h"
#include "./../../delay.h"
/*! ********************************************************
* @name    Cmt2300_SoftReset
* @desc    Soft reset.
* *********************************************************/
void Cmt2300_SoftReset(void)
{
    Cmt2300_WriteReg(0x7F, 0xFF);
}

/*! ********************************************************
* @name    Cmt2300_GetChipStatus
* @desc    Get the chip status.
* @return
*          CMT2300_STA_PUP
*          CMT2300_STA_SLEEP
*          CMT2300_STA_STBY
*          CMT2300_STA_RFS
*          CMT2300_STA_TFS
*          CMT2300_STA_RX
*          CMT2300_STA_TX
*          CMT2300_STA_EEPROM
*          CMT2300_STA_CAL
* *********************************************************/
uint8_t Cmt2300_GetChipStatus(void)
{
    return Cmt2300_ReadReg(CMT2300_CUS_MODE_STA) & CMT2300_MASK_CHIP_MODE_STA;
}

/*! ********************************************************
* @name    Cmt2300_GetChipStatus
* @desc    Wait the chip status, and 50*200 us as timeout.
* @param   nStatus: the chip status
* @return  true or false
* *********************************************************/
bool Cmt2300_WaitChipStatus(uint8_t nStatus)
{
#ifdef ENABLE_WAIT_CHIP_STATUS
    uint8_t i;
    uint8_t temp;

    for (i = 0; i < 50; i++)
    {
        //			Cmt2300_DelayUs(200);
        temp = Cmt2300_GetChipStatus();
        if (nStatus == temp)
            return true;
    }

    return false;
#else
    return true;
#endif
}

//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_ConfigCRCPolynomial
// Return Value : None
// Parameters   :
// Notes        : nEnable
//					CMT2300_CRC_TYPE_CCITT16
//					CMT2300_CRC_TYPE_IBM16
//					CMT2300_CRC_TYPE_ITuint16_t
//					CMT2300_CRC_TYPE_NA

//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigCRC_Polynomial(uint8_t Polynomial)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT21) & (~CMT2300_MASK_CRC_TYPE);
    Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp | Polynomial);
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_ConfigCRC_RANGE
// Return Value : None
// Parameters   :
// Notes        : nEnable
//					CMT2300_CRC_RANGE_PAYLOAD
//					CMT2300_CRC_RANGE_DATA
//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigCRC_RANGE(uint8_t RANGE)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT21) & (~CMT2300_MASK_CRC_RANGE);
    Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp | RANGE);
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_ConfigCRC_BitOrder
// Return Value : None
// Parameters   :
// Notes        : nEnable
//					CMT2300_CRC_BIT_ORDER_MSB
//					CMT2300_CRC_BIT_ORDER_LSB
//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigCRC_BitOrder(uint8_t BitOrder)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT24) & (~CMT2300_MASK_CRC_BIT_ORDER);
    Cmt2300_WriteReg(CMT2300_CUS_PKT24, tmp | BitOrder);
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_EnableCRC
//
// Return Value : None
// Parameters   :
// Notes        : true or false

//-----------------------------------------------------------------------------------------------
void Cmt2300_EnableCRC(bool STA)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT21);
    if (STA)
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp | CMT2300_MASK_CRC_EN);
    }
    else
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp & (~CMT2300_MASK_CRC_EN));
    }
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_EnableCRC_ByteSwap
//
// Return Value : None
// Parameters   :
// Notes        : true or false

//-----------------------------------------------------------------------------------------------
void Cmt2300_EnableCRC_ByteSwap(bool STA)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT21);
    if (STA)
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp | CMT2300_MASK_CRC_BYTE_SWAP);
    }
    else
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp & (~CMT2300_MASK_CRC_BYTE_SWAP));
    }
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_EnableCRC_BitInv
//
// Return Value : None
// Parameters   :
// Notes        : true or false

//-----------------------------------------------------------------------------------------------
void Cmt2300_EnableCRC_BitInv(bool STA)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT21);
    if (STA)
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp | CMT2300_MASK_CRC_BIT_INV);
    }
    else
    {
        Cmt2300_WriteReg(CMT2300_CUS_PKT21, tmp & (~CMT2300_MASK_CRC_BIT_INV));
    }
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_EnablePktLenthFixed
//
// Return Value : None
// Parameters   :
// Notes        : true or false
//							CMT2300_PKT_TYPE_FIXED
//							CMT2300_PKT_TYPE_VARIABLE

//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigPktLenthType(uint8_t PktLenthType)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT14) & (~CMT2300_MASK_PKT_TYPE);
    ;
    Cmt2300_WriteReg(CMT2300_CUS_PKT14, tmp | PktLenthType);
}
/*! ********************************************************
* @name    Cmt2300_GoSleep
* @desc    Entry SLEEP mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoSleep(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_SLEEP);
    return Cmt2300_WaitChipStatus(CMT2300_STA_SLEEP);
}

/*! ********************************************************
* @name    Cmt2300_GoStby
* @desc    Entry Sleep mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoStby(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_STBY);
    return Cmt2300_WaitChipStatus(CMT2300_STA_STBY);
}

/*! ********************************************************
* @name    Cmt2300_GoTFS
* @desc    Entry TFS mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoTFS(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_TFS);
    return Cmt2300_WaitChipStatus(CMT2300_STA_TFS);
}

/*! ********************************************************
* @name    Cmt2300_GoRFS
* @desc    Entry RFS mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoRFS(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_RFS);
    return Cmt2300_WaitChipStatus(CMT2300_STA_RFS);
}

bool Cmt2300_TxEnd(void)
{
    if ((Cmt2300_ReadReg(CMT2300_CUS_FIFO_FLAG) & CMT2300_MASK_TX_FIFO_NMTY_FLG) != 0)
        return false;

    if ((Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1) & CMT2300_MASK_TX_DONE_FLG) == 0)
        return false;

    return true;
}

/*! ********************************************************
* @name    Cmt2300_GoTx
* @desc    Entry Tx mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoTx(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_TX);
    return Cmt2300_WaitChipStatus(CMT2300_STA_TX);
}

/*! ********************************************************
* @name    Cmt2300_GoRx
* @desc    Entry Rx mode.
* @return  true or false
* *********************************************************/
bool Cmt2300_GoRx(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_MODE_CTL, CMT2300_GO_RX);
    return Cmt2300_WaitChipStatus(CMT2300_STA_RX);
}

/*! ********************************************************
* @name    Cmt2300_ConfigGpio
* @desc    Config GPIO pins mode.
* @param   nGpioSel: GPIO1_SEL | GPIO2_SEL | GPIO3_SEL | GPIO4_SEL
*          GPIO1_SEL:
*            CMT2300_GPIO1_SEL_DOUT/DIN 
*            CMT2300_GPIO1_SEL_INT1
*            CMT2300_GPIO1_SEL_INT2 
*            CMT2300_GPIO1_SEL_DCLK
*
*          GPIO2_SEL:
*            CMT2300_GPIO2_SEL_INT1 
*            CMT2300_GPIO2_SEL_INT2
*            CMT2300_GPIO2_SEL_DOUT/DIN 
*            CMT2300_GPIO2_SEL_DCLK
*
*          GPIO3_SEL:
*            CMT2300_GPIO3_SEL_CLKO 
*            CMT2300_GPIO3_SEL_DOUT/DIN
*            CMT2300_GPIO3_SEL_INT2 
*            CMT2300_GPIO3_SEL_DCLK
*
*          GPIO4_SEL:
*            CMT2300_GPIO4_SEL_RSTIN 
*            CMT2300_GPIO4_SEL_INT1
*            CMT2300_GPIO4_SEL_DOUT 
*            CMT2300_GPIO4_SEL_DCLK
* *********************************************************/
void Cmt2300_ConfigGpio(uint8_t nGpioSel)
{
    Cmt2300_WriteReg(CMT2300_CUS_IO_SEL, nGpioSel);
}

/*! ********************************************************
* @name    Cmt2300_ConfigInterrupt
* @desc    Config interrupt on INT1 and INT2.
* @param   nInt1Sel, nInt2Sel
*            CMT2300_INT_SEL_RX_ACTIVE
*            CMT2300_INT_SEL_TX_ACTIVE
*            CMT2300_INT_SEL_RSSI_VLD
*            CMT2300_INT_SEL_PREAM_OK
*            CMT2300_INT_SEL_SYNC_OK
*            CMT2300_INT_SEL_NODE_OK
*            CMT2300_INT_SEL_CRC_OK
*            CMT2300_INT_SEL_PKT_OK
*            CMT2300_INT_SEL_SL_TMO
*            CMT2300_INT_SEL_RX_TMO
*            CMT2300_INT_SEL_TX_DONE
*            CMT2300_INT_SEL_RX_FIFO_NMTY
*            CMT2300_INT_SEL_RX_FIFO_TH
*            CMT2300_INT_SEL_RX_FIFO_FULL
*            CMT2300_INT_SEL_RX_FIFO_WBYTE
*            CMT2300_INT_SEL_RX_FIFO_OVF
*            CMT2300_INT_SEL_TX_FIFO_NMTY
*            CMT2300_INT_SEL_TX_FIFO_TH
*            CMT2300_INT_SEL_TX_FIFO_FULL
*            CMT2300_INT_SEL_STATE_IS_STBY
*            CMT2300_INT_SEL_STATE_IS_FS
*            CMT2300_INT_SEL_STATE_IS_RX
*            CMT2300_INT_SEL_STATE_IS_TX
*            CMT2300_INT_SEL_LED
*            CMT2300_INT_SEL_TRX_ACTIVE
*            CMT2300_INT_SEL_PKT_DONE
* *********************************************************/
void Cmt2300_ConfigInterrupt(uint8_t nInt1Sel, uint8_t nInt2Sel)
{
    nInt1Sel &= CMT2300_MASK_INT1_SEL;
    nInt1Sel |= (~CMT2300_MASK_INT1_SEL) & Cmt2300_ReadReg(CMT2300_CUS_INT1_CTL);
    Cmt2300_WriteReg(CMT2300_CUS_INT1_CTL, nInt1Sel);

    nInt2Sel &= CMT2300_MASK_INT2_SEL;
    nInt2Sel |= (~CMT2300_MASK_INT2_SEL) & Cmt2300_ReadReg(CMT2300_CUS_INT2_CTL);
    Cmt2300_WriteReg(CMT2300_CUS_INT2_CTL, nInt2Sel);
}

void Cmt2300_ConfigInterrupt_2(uint8_t nInt2Sel)
{
    nInt2Sel &= CMT2300_MASK_INT2_SEL;
    nInt2Sel |= (~CMT2300_MASK_INT2_SEL) & Cmt2300_ReadReg(CMT2300_CUS_INT2_CTL);
    Cmt2300_WriteReg(CMT2300_CUS_INT2_CTL, nInt2Sel);
}

/*! ********************************************************
* @name    Cmt2300_SetInterruptPolar
* @desc    Set the polarity of the interrupt.
* @param   bEnable(true): active-high (default)
*          bEnable(false): active-low
* *********************************************************/
void Cmt2300_SetInterruptPolar(bool bActiveHigh)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT1_CTL);

    if (bActiveHigh)
        tmp &= ~CMT2300_MASK_INT_POLAR;
    else
        tmp |= CMT2300_MASK_INT_POLAR;

    Cmt2300_WriteReg(CMT2300_CUS_INT1_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_SetFifoThreshold
* @desc    Set FIFO threshold.
* @param   nFifoThreshold
* *********************************************************/
void Cmt2300_SetFifoThreshold(uint8_t nFifoThreshold)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT29);

    tmp &= ~CMT2300_MASK_FIFO_TH;
    tmp |= nFifoThreshold & CMT2300_MASK_FIFO_TH;

    Cmt2300_WriteReg(CMT2300_CUS_PKT29, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableAntennaSwitch
* @desc    Enable antenna switch, output TX_ACTIVE/RX_ACTIVE
*          via GPIO1/GPIO2.
* @param   nMode 
*            0: RF_SWT1_EN=1, RF_SWT2_EN=0
*               GPIO1: RX_ACTIVE, GPIO2: TX_ACTIVE
*            1: RF_SWT1_EN=0, RF_SWT2_EN=1
*               GPIO1: RX_ACTIVE, GPIO2: ~RX_ACTIVE
* *********************************************************/
void Cmt2300_EnableAntennaSwitch(uint8_t nMode)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT1_CTL);

    if (0 == nMode)
    {
        tmp |= CMT2300_MASK_RF_SWT1_EN;
        tmp &= ~CMT2300_MASK_RF_SWT2_EN;
    }
    else if (1 == nMode)
    {
        tmp &= ~CMT2300_MASK_RF_SWT1_EN;
        tmp |= CMT2300_MASK_RF_SWT2_EN;
    }

    Cmt2300_WriteReg(CMT2300_CUS_INT1_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableInterrupt
* @desc    Enable interrupt.
* @param   nEnable 
*            CMT2300_MASK_SL_TMO_EN   |
*            CMT2300_MASK_RX_TMO_EN   |
*            CMT2300_MASK_TX_DONE_EN  |
*            CMT2300_MASK_PREAM_OK_EN |
*            CMT2300_MASK_SYNC_OK_EN  |
*            CMT2300_MASK_NODE_OK_EN  |
*            CMT2300_MASK_CRC_OK_EN   |
*            CMT2300_MASK_PKT_DONE_EN
* *********************************************************/
void Cmt2300_EnableInterrupt(uint8_t nEnable)
{
    Cmt2300_WriteReg(CMT2300_CUS_INT_EN, nEnable);
}

/*! ********************************************************
* @name    Cmt2300_EnableRxFifoAutoClear
* @desc    Auto clear Rx FIFO before entry Rx mode.
* @param   bEnable(true): Enable it(default)
*          bEnable(false): Disable it
* *********************************************************/
void Cmt2300_EnableRxFifoAutoClear(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);

    if (bEnable)
        tmp &= ~CMT2300_MASK_FIFO_AUTO_CLR_DIS;
    else
        tmp |= CMT2300_MASK_FIFO_AUTO_CLR_DIS;

    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableFifoMerge
* @desc    Enable FIFO merge.
* @param   bEnable(true): use a single 64-byte FIFO for either Tx or Rx
*          bEnable(false): use a 32-byte FIFO for Tx and another 32-byte FIFO for Rx(default)
* *********************************************************/
void Cmt2300_EnableFifoMerge(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);

    if (bEnable)
        tmp |= CMT2300_MASK_FIFO_MERGE_EN;
    else
        tmp &= ~CMT2300_MASK_FIFO_MERGE_EN;

    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableReadFifo
* @desc    Enable SPI to read the FIFO.
* *********************************************************/
void Cmt2300_EnableReadFifo(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);
    tmp &= ~CMT2300_MASK_SPI_FIFO_RD_WR_SEL;
    tmp &= ~CMT2300_MASK_FIFO_RX_TX_SEL;
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableWriteFifo
* @desc    Enable SPI to write the FIFO.
* *********************************************************/
void Cmt2300_EnableWriteFifo(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);
    tmp |= CMT2300_MASK_SPI_FIFO_RD_WR_SEL;
    tmp |= CMT2300_MASK_FIFO_RX_TX_SEL;
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_RestoreFifo
* @desc    Restore the FIFO.
* *********************************************************/
void Cmt2300_RestoreFifo(void)
{
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CLR, CMT2300_MASK_FIFO_RESTORE);
}

/*! ********************************************************
* @name    Cmt2300_ClearFifo
* @desc    Clear the Tx FIFO and Rx FIFO.
* @return  FIFO flags
*            CMT2300_MASK_RX_FIFO_FULL_FLG |
*            CMT2300_MASK_RX_FIFO_NMTY_FLG |
*            CMT2300_MASK_RX_FIFO_TH_FLG   |
*            CMT2300_MASK_RX_FIFO_OVF_FLG  |
*            CMT2300_MASK_TX_FIFO_FULL_FLG |
*            CMT2300_MASK_TX_FIFO_NMTY_FLG |
*            CMT2300_MASK_TX_FIFO_TH_FLG
* *********************************************************/
uint8_t Cmt2300_ClearFifo(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CLR);
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CLR, CMT2300_MASK_FIFO_CLR_RX | CMT2300_MASK_FIFO_CLR_TX);
    return tmp;
}

uint8_t Cmt2300_ClearFifo_tx(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CLR);
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CLR, CMT2300_MASK_FIFO_CLR_TX);
    return tmp;
}

/*! ********************************************************
* @name    Cmt2300_ClearInterruptFlags
* @desc    Clear all interrupt flags.
* @return  Some interrupt flags
*            CMT2300_MASK_SL_TMO_EN    |
*            CMT2300_MASK_RX_TMO_EN    |
*            CMT2300_MASK_TX_DONE_EN   |
*            CMT2300_MASK_PREAM_OK_FLG |
*            CMT2300_MASK_SYNC_OK_FLG  |
*            CMT2300_MASK_NODE_OK_FLG  |
*            CMT2300_MASK_CRC_OK_FLG   |
*            CMT2300_MASK_PKT_OK_FLG
* *********************************************************/
uint8_t Cmt2300_ClearInterruptFlags(void)
{
    uint8_t nFlag1, nFlag2;
    uint8_t nClr1 = 0;
    uint8_t nClr2 = 0;
    uint8_t nRet = 0;
    uint8_t nIntPolar;

    nIntPolar = Cmt2300_ReadReg(CMT2300_CUS_INT1_CTL);
    nIntPolar = (nIntPolar & CMT2300_MASK_INT_POLAR) ? 1 : 0;

    nFlag1 = Cmt2300_ReadReg(CMT2300_CUS_INT_FLAG);
    nFlag2 = Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1);

    if (nIntPolar)
    {
        /* Interrupt flag active-low */
        nFlag1 = ~nFlag1;
        nFlag2 = ~nFlag2;
    }

    if (CMT2300_MASK_LBD_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_LBD_CLR; /* Clear LBD_FLG */
    }

    if (CMT2300_MASK_COL_ERR_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_PKT_DONE_CLR; /* Clear COL_ERR_FLG by PKT_DONE_CLR */
    }

    if (CMT2300_MASK_PKT_ERR_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_PKT_DONE_CLR; /* Clear PKT_ERR_FLG by PKT_DONE_CLR */
    }

    if (CMT2300_MASK_PREAM_OK_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_PREAM_OK_CLR; /* Clear PREAM_OK_FLG */
        nRet |= CMT2300_MASK_PREAM_OK_FLG;  /* Return PREAM_OK_FLG */
    }

    if (CMT2300_MASK_SYNC_OK_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_SYNC_OK_CLR; /* Clear SYNC_OK_FLG */
        nRet |= CMT2300_MASK_SYNC_OK_FLG;  /* Return SYNC_OK_FLG */
    }

    if (CMT2300_MASK_NODE_OK_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_NODE_OK_CLR; /* Clear NODE_OK_FLG */
        nRet |= CMT2300_MASK_NODE_OK_FLG;  /* Return NODE_OK_FLG */
    }

    if (CMT2300_MASK_CRC_OK_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_CRC_OK_CLR; /* Clear CRC_OK_FLG */
        nRet |= CMT2300_MASK_CRC_OK_FLG;  /* Return CRC_OK_FLG */
    }

    if (CMT2300_MASK_PKT_OK_FLG & nFlag1)
    {
        nClr2 |= CMT2300_MASK_PKT_DONE_CLR; /* Clear PKT_OK_FLG */
        nRet |= CMT2300_MASK_PKT_OK_FLG;    /* Return PKT_OK_FLG */
    }

    if (CMT2300_MASK_SL_TMO_FLG & nFlag2)
    {
        nClr1 |= CMT2300_MASK_SL_TMO_CLR; /* Clear SL_TMO_FLG */
        nRet |= CMT2300_MASK_SL_TMO_EN;   /* Return SL_TMO_FLG by SL_TMO_EN */
    }

    if (CMT2300_MASK_RX_TMO_FLG & nFlag2)
    {
        nClr1 |= CMT2300_MASK_RX_TMO_CLR; /* Clear RX_TMO_FLG */
        nRet |= CMT2300_MASK_RX_TMO_EN;   /* Return RX_TMO_FLG by RX_TMO_EN */
    }

    if (CMT2300_MASK_TX_DONE_FLG & nFlag2)
    {
        nClr1 |= CMT2300_MASK_TX_DONE_CLR; /* Clear TX_DONE_FLG */
        nRet |= CMT2300_MASK_TX_DONE_EN;   /* Return TX_DONE_FLG by TX_DONE_EN */
    }

    Cmt2300_WriteReg(CMT2300_CUS_INT_CLR1, nClr1);
    Cmt2300_WriteReg(CMT2300_CUS_INT_CLR2, nClr2);

    if (nIntPolar)
    {
        /* Interrupt flag active-low */
        nRet = ~nRet;
    }

    return nRet;
}

uint8_t Cmt2300_ClearInterruptFlags_clr1(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT_CLR1);
    Cmt2300_WriteReg(CMT2300_CUS_INT_CLR1, CMT2300_MASK_TX_DONE_CLR | CMT2300_MASK_SL_TMO_CLR | CMT2300_MASK_RX_TMO_CLR);
    return tmp;
}
uint8_t Cmt2300_ClearInterruptFlags_clr2(void)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT_CLR2);
    Cmt2300_WriteReg(CMT2300_CUS_INT_CLR2, CMT2300_MASK_LBD_CLR | CMT2300_MASK_PREAM_OK_CLR | CMT2300_MASK_SYNC_OK_CLR | CMT2300_MASK_NODE_OK_CLR | CMT2300_MASK_CRC_OK_CLR | CMT2300_MASK_PKT_DONE_CLR);
    return tmp;
}

/*! ********************************************************
* @name    Cmt2300_ConfigTxDin
* @desc    Used to select whether to use GPIO1 or GPIO2 or GPIO3
*          as DIN in the direct mode. It only takes effect when 
*          call Cmt2300_EnableTxDin(true) in the direct mode.
* @param   nDinSel
*            CMT2300_TX_DIN_SEL_GPIO1
*            CMT2300_TX_DIN_SEL_GPIO2
*            CMT2300_TX_DIN_SEL_GPIO3
* *********************************************************/
void Cmt2300_ConfigTxDin(uint8_t nDinSel)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);
    tmp &= ~CMT2300_MASK_TX_DIN_SEL;
    tmp |= nDinSel;
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}
/*! ********************************************************
* @name    Cmt2300_ConfigTxDin
* @desc    Used to select whether to use GPIO1 or GPIO2 or GPIO3
*          as DIN in the direct mode. It only takes effect when 
*          call Cmt2300_EnableTxDin(true) in the direct mode.
* @param   nDinSel
*            CMT2300_TX_DIN_GPIO_DOUT
*            CMT2300_TX_DIN_GPIO_DIN
* *********************************************************/
void Cmt2300_ConfigGPIOMode(uint8_t GPIOMode)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);
    tmp &= ~CMT2300_MASK_TX_DIN_EN;
    tmp |= GPIOMode;
    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}
/*! ********************************************************
* @name    Cmt2300_ConfigDataRate
* @desc    
* @param   DataRate = 0~7
            =0 0.6k
            =1 1.2k
            =2 2.4k
            =3 4.8k
            =4 10k
            =5 50k
            =6 100k
            =7 200k

* *********************************************************/
void Cmt2300_ConfigDataRate(uint8_t DataRate)
{
 
    uint8_t tmp = Cmt2300_ReadReg(0x04) & 0x0f;

    Cmt2300_ConfigRegBank(CMT2300_DATA_RATE_BANK_ADDR, g_cmt2300DataRate_SetTab[DataRate], CMT2300_DATA_RATE_BANK_SIZE);
    Cmt2300_WriteReg(0x04, (g_cmt2300DataRate_SetTab2[DataRate][0] & (~0x0f)) | tmp);
    Cmt2300_WriteReg(0x55, g_cmt2300DataRate_SetTab2[DataRate][1]);
    Cmt2300_WriteReg(0x56, g_cmt2300DataRate_SetTab2[DataRate][2]);
    Cmt2300_WriteReg(0x57, g_cmt2300DataRate_SetTab2[DataRate][3]);
    Cmt2300_WriteReg(0x58, g_cmt2300DataRate_SetTab2[DataRate][4]);
    Cmt2300_WriteReg(0x59, g_cmt2300DataRate_SetTab2[DataRate][5]);
    Cmt2300_WriteReg(0x5a, g_cmt2300DataRate_SetTab2[DataRate][6]);
    Cmt2300_WriteReg(0x5b, g_cmt2300DataRate_SetTab2[DataRate][7]);
    tmp = Cmt2300_ReadReg(0x5e) & 0x3f;
    Cmt2300_WriteReg(0x5e, (g_cmt2300DataRate_SetTab2[DataRate][8] & (~0x3f)) | tmp);
}

//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_ConfigDataMode
//
// Return Value : None
// Parameters   :
// Notes        : true or false
//							CMT2300_DATA_MODE_DIRECT
//							CMT2300_DATA_MODE_PACKET

//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigDataMode(uint8_t DataMode)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT1) & (~0x03);
    ;
    Cmt2300_WriteReg(CMT2300_CUS_PKT1, tmp | DataMode);
}
//------------------------------------------------------------------------------------------------
// Function Name :Cmt2300_ConfigDataMode
//
// Return Value : None
// Parameters   :
// Notes        : true or false
//							CMT2300_TxDinSource_FIFO
//							CMT2300_TxDinSource_GPIO

//-----------------------------------------------------------------------------------------------
void Cmt2300_ConfigTxDinSource(uint8_t TxDinSource)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_TX1) & (~0x04);
    ;
    Cmt2300_WriteReg(CMT2300_CUS_TX1, tmp | TxDinSource);
}
/*! ********************************************************
* @name    Cmt2300_ConfigTxPower
* @desc    
* @param   TxPower = 0,1,2,3，4,5,6,7
* *********************************************************/
void Cmt2300_ConfigTxPower(uint8_t TxPower)
{
    uint8_t tmp = Cmt2300_ReadReg(0x03) & (~0x01);

    if(TxPower>7)
    {
       TxPower=7;
    }
    
    Cmt2300_WriteReg(0x03, (g_cmt2300TxPower_Tab[TxPower][0] & 0x01) | tmp);
    Cmt2300_WriteReg(0x5c, g_cmt2300TxPower_Tab[TxPower][1]);
    Cmt2300_WriteReg(0x5d, g_cmt2300TxPower_Tab[TxPower][2]);
    tmp = Cmt2300_ReadReg(0x5e) & (~0x3f);
    Cmt2300_WriteReg(0x5e, (g_cmt2300TxPower_Tab[TxPower][3] & 0x3f) | tmp);
}
/*! ********************************************************
* @name    Cmt2300_ConfigFrqChannel
* @desc    
* @param   FrqChannel = 0~4
0-433MHZ
1-433.92MHZ
2-868MHZ
3-915MHZ
4-920MHZ
* *********************************************************/
void Cmt2300_ConfigFrqChannel(uint8_t FrqChannel)
{   
    Cmt2300_ConfigRegBank(CMT2300_FREQUENCY_BANK_ADDR, g_cmt2300FrequencyBank_SetTab[FrqChannel], CMT2300_FREQUENCY_BANK_SIZE);
}
/*! ********************************************************
* @name    Cmt2300_EnableTxDin
* @desc    Used to change GPIO1/GPIO2/GPIO3 between DOUT and DIN.
* @param   bEnable(true): used as DIN
*          bEnable(false): used as DOUT(default)
* *********************************************************/
void Cmt2300_EnableTxDin(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_FIFO_CTL);

    if (bEnable)
        tmp |= CMT2300_MASK_TX_DIN_EN;
    else
        tmp &= ~CMT2300_MASK_TX_DIN_EN;

    Cmt2300_WriteReg(CMT2300_CUS_FIFO_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableTxDinInvert
* @desc    Used to invert DIN data in direct mode.
* @param   bEnable(true): invert DIN
*          bEnable(false): not invert DIN(default)
* *********************************************************/
void Cmt2300_EnableTxDinInvert(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT2_CTL);

    if (bEnable)
        tmp |= CMT2300_MASK_TX_DIN_INV;
    else
        tmp &= ~CMT2300_MASK_TX_DIN_INV;

    Cmt2300_WriteReg(CMT2300_CUS_INT2_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_IsExist
* @desc    Chip indentify.
* @return  true: chip is exist, false: chip not found
* *********************************************************/
bool Cmt2300_IsExist(void)
{
    uint8_t back, dat;

    back = Cmt2300_ReadReg(CMT2300_CUS_PKT17);
    Cmt2300_WriteReg(CMT2300_CUS_PKT17, 0xAA);

    // system_delay_us(5*20);

    dat = Cmt2300_ReadReg(CMT2300_CUS_PKT17);
    Cmt2300_WriteReg(CMT2300_CUS_PKT17, back);

    if (0xAA == dat)
        return true;

    return false;
}

/*! ********************************************************
* @name    Cmt2300_GetRssiCode
* @desc    Get RSSI code.
* @return  RSSI code
* *********************************************************/
uint8_t Cmt2300_GetRssiCode(void)
{
    return Cmt2300_ReadReg(CMT2300_CUS_RSSI_CODE);
}

/*! ********************************************************
* @name    Cmt2300_GetRssiDBm
* @desc    Get RSSI dBm.
* @return  dBm
* *********************************************************/
int Cmt2300_GetRssiDBm(void)
{
    return (int)Cmt2300_ReadReg(CMT2300_CUS_RSSI_DBM) - 128;
}

/*! ********************************************************
* @name    Cmt2300_SetFrequencyChannel
* @desc    This defines up to 255 frequency channel
*          for fast frequency hopping operation.
* @param   nChann: the frequency channel
* *********************************************************/
void Cmt2300_SetFrequencyChannel(uint8_t nChann)
{
    Cmt2300_WriteReg(CMT2300_CUS_FREQ_CHNL, nChann);
}

/*! ********************************************************
* @name    Cmt2300_SetFrequencyStep
* @desc    This defines the frequency channel step size 
*          for fast frequency hopping operation. 
*          One step size is 2.5 kHz.
* @param   nOffset: the frequency step
* *********************************************************/
void Cmt2300_SetFrequencyStep(uint8_t nOffset)
{
    Cmt2300_WriteReg(CMT2300_CUS_FREQ_OFS, nOffset);
}

/*! ********************************************************
* @name    Cmt2300_SetPayloadLength
* @desc    Set payload length.
* @param   nLength
* *********************************************************/
void Cmt2300_SetPayloadLength(uint16_t nLength)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_PKT14);

    tmp &= ~CMT2300_MASK_PAYLOAD_LENG_10_8;
    tmp |= (nLength >> 4) & CMT2300_MASK_PAYLOAD_LENG_10_8;
    Cmt2300_WriteReg(CMT2300_CUS_PKT14, tmp);

    tmp = nLength & CMT2300_MASK_PAYLOAD_LENG_7_0;
    Cmt2300_WriteReg(CMT2300_CUS_PKT15, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableLfosc
* @desc    If you need use sleep timer, you should enable LFOSC.
* @param   bEnable(true): Enable it(default)
*          bEnable(false): Disable it
* *********************************************************/
void Cmt2300_EnableLfosc(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_SYS2);

    if (bEnable)
    {
        tmp |= CMT2300_MASK_LFOSC_RECAL_EN;
        tmp |= CMT2300_MASK_LFOSC_CAL1_EN;
        tmp |= CMT2300_MASK_LFOSC_CAL2_EN;
    }
    else
    {
        tmp &= ~CMT2300_MASK_LFOSC_RECAL_EN;
        tmp &= ~CMT2300_MASK_LFOSC_CAL1_EN;
        tmp &= ~CMT2300_MASK_LFOSC_CAL2_EN;
    }

    Cmt2300_WriteReg(CMT2300_CUS_SYS2, tmp);
}

/*! ********************************************************
* @name    Cmt2300_EnableLfoscOutput
* @desc    LFOSC clock is output via GPIO3.
* @param   bEnable(true): Enable it
*          bEnable(false): Disable it(default)
* *********************************************************/
void Cmt2300_EnableLfoscOutput(bool bEnable)
{
    uint8_t tmp = Cmt2300_ReadReg(CMT2300_CUS_INT2_CTL);

    if (bEnable)
        tmp |= CMT2300_MASK_LFOSC_OUT_EN;
    else
        tmp &= ~CMT2300_MASK_LFOSC_OUT_EN;

    Cmt2300_WriteReg(CMT2300_CUS_INT2_CTL, tmp);
}

/*! ********************************************************
* @name    Cmt2300_Init
* @desc    Initialize chip status.
* *********************************************************/
void Cmt2300_Init(void)
{
    uint8_t tmp;

    Cmt2300_SoftReset();
   
    Delay_Ms(10);
   
    Cmt2300_GoStby();

    tmp = Cmt2300_ReadReg(CMT2300_CUS_MODE_STA);
    tmp |= CMT2300_MASK_CFG_RETAIN;  /* Enable CFG_RETAIN */
    tmp &= ~CMT2300_MASK_RSTN_IN_EN; /* Disable RSTN_IN */
    Cmt2300_WriteReg(CMT2300_CUS_MODE_STA, tmp);

    Cmt2300_EnableLfosc(false); /* Diable LFOSC */

    Cmt2300_ClearInterruptFlags();
}

/*! ********************************************************
* @name    Cmt2300_ConfigRegBank
* @desc    Config one register bank.
* *********************************************************/
bool Cmt2300_ConfigRegBank(uint8_t base_addr, const uint8_t bank[], uint8_t len)
{
    uint8_t i;
    for (i = 0; i < len; i++)
        Cmt2300_WriteReg(i + base_addr, bank[i]);

    return true;
}
