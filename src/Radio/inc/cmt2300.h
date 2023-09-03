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
 * @file    cmt2300.h
 * @brief   CMT2300 transceiver RF chip driver
 *
 * @version 1.2
 * @date    Feb 08 2017
 * @author  CMOSTEK R@D
 */

#ifndef __CMT2300_H
#define __CMT2300_H

#include <stdbool.h>
#include "cmt2300_defs.h"
#include "cmt2300_hal.h"
#include "stm32f0xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef MOD_CMT2300
#define EXT
#else
#define EXT extern
#endif

#define ENABLE_WAIT_CHIP_STATUS /* Enable the wait when switch chip status */

  
typedef enum
{
    rf_rate_0K6 = 0,
    rf_rate_1K2,
    rf_rate_2K4,
    rf_rate_4K8,
    rf_rate_10K,
    rf_rate_50K,
    rf_rate_100K,
    rf_rate_200K,
 
} User_rfrate_t;


   /* ************************************************************************
   The following are for chip status controls.
*  ************************************************************************ */
   EXT void Cmt2300_SoftReset(void);
   EXT uint8_t Cmt2300_GetChipStatus(void);
   EXT bool Cmt2300_WaitChipStatus(uint8_t nStatus);
   EXT bool Cmt2300_GoSleep(void);
   EXT bool Cmt2300_GoStby(void);


   EXT bool Cmt2300_GoTFS(void);
   EXT bool Cmt2300_GoRFS(void);
   EXT bool Cmt2300_GoTx(void);
   EXT bool Cmt2300_GoRx(void);

   /* ************************************************************************
*  The following are for chip interrupts, GPIO, FIFO operations.
*  ************************************************************************ */
   EXT void Cmt2300_ConfigGpio(uint8_t nGpioSel);
   EXT void Cmt2300_ConfigInterrupt(uint8_t nInt1Sel, uint8_t nInt2Sel);
   EXT void Cmt2300_ConfigInterrupt_2(uint8_t nInt2Sel);

   EXT void Cmt2300_SetInterruptPolar(bool bActiveHigh);
   EXT void Cmt2300_SetFifoThreshold(uint8_t nFifoThreshold);
   EXT void Cmt2300_EnableAntennaSwitch(uint8_t nMode);
   EXT void Cmt2300_EnableInterrupt(uint8_t nEnable);
   EXT void Cmt2300_EnableRxFifoAutoClear(bool bEnable);
   EXT void Cmt2300_EnableFifoMerge(bool bEnable);
   EXT void Cmt2300_EnableReadFifo(void);
   EXT void Cmt2300_EnableWriteFifo(void);
   EXT void Cmt2300_RestoreFifo(void);
   EXT uint8_t Cmt2300_ClearFifo(void);
   EXT uint8_t Cmt2300_ClearFifo_tx(void);

   EXT uint8_t Cmt2300_ClearInterruptFlags(void);

   EXT uint8_t Cmt2300_ClearInterruptFlags_clr1(void);
   EXT uint8_t Cmt2300_ClearInterruptFlags_clr2(void);

   /* ************************************************************************
*  The following are for Tx DIN operations in direct mode.
*  ************************************************************************ */
   EXT void Cmt2300_ConfigTxDin(uint8_t nDinSel);
   EXT void Cmt2300_EnableTxDin(bool bEnable);
   EXT void Cmt2300_EnableTxDinInvert(bool bEnable);

   /* ************************************************************************
*  The following are general operations.
*  ************************************************************************ */
   EXT bool Cmt2300_IsExist(void);
   EXT uint8_t Cmt2300_GetRssiCode(void);
   EXT int Cmt2300_GetRssiDBm(void);
   EXT void Cmt2300_SetFrequencyChannel(uint8_t nChann);
   EXT void Cmt2300_SetFrequencyStep(uint8_t nOffset);
   EXT void Cmt2300_SetPayloadLength(uint16_t nLength);
   EXT void Cmt2300_EnableLfosc(bool bEnable);
   EXT void Cmt2300_EnableLfoscOutput(bool bEnable);

   /* ************************************************************************
*  The following are for chip initializes.
*  ************************************************************************ */
   EXT void Cmt2300_Init(void);
   EXT bool Cmt2300_ConfigRegBank(uint8_t base_addr, const uint8_t bank[], uint8_t len);

   /* ************************************************************************
*  The following are for CRC Configurations.
*  ************************************************************************ */
   void Cmt2300_ConfigCRC_Polynomial(uint8_t Polynomial);
   void Cmt2300_ConfigCRC_RANGE(uint8_t RANGE);
   void Cmt2300_EnableCRC(bool STA);
   void Cmt2300_ConfigCRC_BitOrder(uint8_t BitOrder);
   void Cmt2300_EnableCRC_ByteSwap(bool STA);
   void Cmt2300_EnableCRC_BitInv(bool STA);
   void Cmt2300_ConfigPktLenthType(uint8_t PktLenthType);
   void Cmt2300_ConfigDataRate(uint8_t DataRate);
   void Cmt2300_ConfigFrqChannel(uint8_t FrqChannel);
   void Cmt2300_ConfigTxPower(uint8_t TxPower);
   void Cmt2300_ConfigDataMode(uint8_t DataMode);
   void Cmt2300_ConfigTxDinSource(uint8_t TxDinSource);
   void Cmt2300_ConfigGPIOMode(uint8_t GPIOMode);
//-------------------------------
#undef EXT

#ifdef __cplusplus
}
#endif

#endif
