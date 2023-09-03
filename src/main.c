#include "stm32f0xx.h"
#include "delay.h"
#include "user.h"
#include "string.h"

/**************************************************************************************************************************************
Demo 程序流程  EnableMaster=true  为主机端
               EnableMaster=false 为从机端
***************************************************************************************************************************************/

/*
1.支持最大64字节FIFO

2.速率0.6K-200k可选

3.DIO3做为接收中断引脚

4.功率最大20dbm
*/

bool EnableMaster = true;//EnableMaster=true  为主机端
                         //EnableMaster=false 为从机端
#define RF_PACKET_SIZE 100 /* Define the payload size here */

u8 g_txBuffer[]={0x09,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07}; /* RF Tx buffer */

u8 g_rxBuffer[RF_PACKET_SIZE]; /* RF Rx buffer */

u8 user_rxBuffer[RF_PACKET_SIZE]; /* User RF Rx buffer */

void OnMaster(void);
void OnSlave(void);

void SysClock_48()
{
  RCC_PLLCmd(DISABLE);
  RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_12); // 48M
  RCC_PLLCmd(ENABLE);
  while (!RCC_GetFlagStatus(RCC_FLAG_PLLRDY))
    ;
  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
}

void Tick_Configration()
{
  /* Setup SysTick Timer for 1ms interrupts ( not too often to save power ) */
  if (SysTick_Config(SystemCoreClock / 1000))
  {
    /* Capture error */
    while (1)
      ;
  }
}

void RCC_Configuration()
{
  /* Enable GPIO clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOF, ENABLE);

  /* Enable peripheral Clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2 | RCC_APB1Periph_PWR, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_SYSCFG, ENABLE);
}

void Led_Init(void)
{
  GPIO_Pin_Setting(LED1_PORT, LED1_PIN, GPIO_Speed_50MHz, GPIO_Mode_OUT);
}

void HW_Int()
{
  SysClock_48();
  Tick_Configration();
  RCC_Configuration();
  NVIC_Config();  
  Led_Init();
}
void LedToggle(void)
{
  GPIO_WriteBit(LED1_PORT, LED1_PIN, Bit_RESET); 
  Delay_Ms(2);
  GPIO_WriteBit(LED1_PORT, LED1_PIN, Bit_SET);
}

int main(void)
{
  HW_Int();
  RF_Init();//射频初始化
  
  if (Cmt2300_IsExist())//初始化成功
  {
    LedToggle();
  }
  else//初始化失败
  {
     GPIO_WriteBit(LED1_PORT, LED1_PIN, Bit_SET);
  }
    
   Cmt2300_ConfigTxPower(7);//等级7   +20dbm
   Cmt2300_ConfigDataRate(rf_rate_1K2);//速率设置为1.2Kbps // 0.6k、1.2k、 2.4k 、4.8k、10k、50k、100k、200k 可选
   Cmt2300_ConfigPktLenthType(CMT2300_PKT_TYPE_VARIABLE);//可变包类型
   Cmt2300_ConfigDataMode(CMT2300_DATA_MODE_PACKET); // packer 模式
   Cmt2300_EnableFifoMerge(true); // 使能 64-byte  FIFO
  
 
  if (true == EnableMaster)
  {    
      RF_StartTx(g_txBuffer,  g_txBuffer[0] , INFINITE); 
  }
  else
  {
      RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
  }
  
  while (1)
  {
    if (true == EnableMaster)
    {
      OnMaster();
    }
    else
    {
      
      OnSlave();
    }
    
  }
}
/* Manages the master operation */
void OnMaster(void)
{
  switch (RF_Process())
  {
    case RF_IDLE:
 
      RF_StartTx(g_txBuffer,  g_txBuffer[0] , INFINITE);//发射数据
      
      break;
    
    case RF_TX_DONE: //发射完成
    
      LedToggle();

      break;
  
    default:
      break;
  }
}

/* Manages the slave operation */
void OnSlave(void)
{
  switch (RF_Process())
  {
  case RF_IDLE: 
  
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    
    break;
  
  case RF_RX_DONE: //接收数据完成
    
      memcpy(user_rxBuffer,g_rxBuffer,g_rxBuffer[0]); 
  
      if(user_rxBuffer[0])
      {
         LedToggle();
      }
      
    break;
  
  case RF_TX_DONE:
  
    break;
  
  case RF_ERROR:
  
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    
    break;
  
  case RF_RX_TIMEOUT:
  
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
  

  break;

  default:
    break;
  }
}
