/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g4xx_hal.h"

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
#define BTN_0_Pin GPIO_PIN_13
#define BTN_0_GPIO_Port GPIOC
#define BTN_1_Pin GPIO_PIN_14
#define BTN_1_GPIO_Port GPIOC
#define MPU6500_CS_Pin GPIO_PIN_4
#define MPU6500_CS_GPIO_Port GPIOA
#define MPU6500_INT_Pin GPIO_PIN_4
#define MPU6500_INT_GPIO_Port GPIOC
#define DR16_NC_Pin GPIO_PIN_10
#define DR16_NC_GPIO_Port GPIOB
#define DR16_RX_Pin GPIO_PIN_11
#define DR16_RX_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOB
#define WS2812_Pin GPIO_PIN_8
#define WS2812_GPIO_Port GPIOA
#define SEG_DP_Pin GPIO_PIN_15
#define SEG_DP_GPIO_Port GPIOA
#define SEG_G_Pin GPIO_PIN_10
#define SEG_G_GPIO_Port GPIOC
#define SEG_F_Pin GPIO_PIN_11
#define SEG_F_GPIO_Port GPIOC
#define SEG_E_Pin GPIO_PIN_3
#define SEG_E_GPIO_Port GPIOB
#define SEG_D_Pin GPIO_PIN_4
#define SEG_D_GPIO_Port GPIOB
#define SEG_C_Pin GPIO_PIN_5
#define SEG_C_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_6
#define SEG_B_GPIO_Port GPIOB
#define SEG_A_Pin GPIO_PIN_7
#define SEG_A_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_9
#define LED0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
