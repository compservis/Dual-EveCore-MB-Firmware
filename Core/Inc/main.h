/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define ST_CS2_Pin GPIO_PIN_0
#define ST_CS2_GPIO_Port GPIOA
#define ST_CS1_Pin GPIO_PIN_4
#define ST_CS1_GPIO_Port GPIOA
#define ST_SCK_Pin GPIO_PIN_5
#define ST_SCK_GPIO_Port GPIOA
#define ST_MISO_Pin GPIO_PIN_6
#define ST_MISO_GPIO_Port GPIOA
#define ST_MOSI_Pin GPIO_PIN_7
#define ST_MOSI_GPIO_Port GPIOA
#define ST_RST_Pin GPIO_PIN_4
#define ST_RST_GPIO_Port GPIOC
#define ST_IRQ1_Pin GPIO_PIN_5
#define ST_IRQ1_GPIO_Port GPIOC
#define ST_IRQ1_EXTI_IRQn EXTI9_5_IRQn
#define ST_IRQ2_Pin GPIO_PIN_0
#define ST_IRQ2_GPIO_Port GPIOB
#define ST_IRQ2_EXTI_IRQn EXTI0_IRQn
#define ST_SYNC11_Pin GPIO_PIN_1
#define ST_SYNC11_GPIO_Port GPIOB
#define ST_SYNC01_Pin GPIO_PIN_10
#define ST_SYNC01_GPIO_Port GPIOB
#define ST_SYNC12_Pin GPIO_PIN_11
#define ST_SYNC12_GPIO_Port GPIOB
#define ST_SYNC02_Pin GPIO_PIN_12
#define ST_SYNC02_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
