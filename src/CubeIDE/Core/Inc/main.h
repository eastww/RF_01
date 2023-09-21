/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPIO_RS485_EN_Pin GPIO_PIN_4
#define GPIO_RS485_EN_GPIO_Port GPIOA
#define GPIO_RF_GPIO1_Pin GPIO_PIN_12
#define GPIO_RF_GPIO1_GPIO_Port GPIOB
#define GPIO_RF_GPIO2_Pin GPIO_PIN_13
#define GPIO_RF_GPIO2_GPIO_Port GPIOB
#define GPIO_RF_GPIO2_EXTI_IRQn EXTI4_15_IRQn
#define GPIO_RF_FCSB_Pin GPIO_PIN_14
#define GPIO_RF_FCSB_GPIO_Port GPIOB
#define GPIO_RF_CSB_Pin GPIO_PIN_15
#define GPIO_RF_CSB_GPIO_Port GPIOB
#define GPIO_RF_SDIO_Pin GPIO_PIN_8
#define GPIO_RF_SDIO_GPIO_Port GPIOA
#define GPIO_RF_SCK_Pin GPIO_PIN_11
#define GPIO_RF_SCK_GPIO_Port GPIOA
#define GPIO_RF_GPIO3_Pin GPIO_PIN_12
#define GPIO_RF_GPIO3_GPIO_Port GPIOA
#define GPIO_RF_GPIO3_EXTI_IRQn EXTI4_15_IRQn
#define GPIO_LED1_Pin GPIO_PIN_4
#define GPIO_LED1_GPIO_Port GPIOB
#define GPIO_LED2_Pin GPIO_PIN_5
#define GPIO_LED2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
