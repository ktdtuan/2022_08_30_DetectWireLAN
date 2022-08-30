/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#define LED_READY_Pin GPIO_PIN_0
#define LED_READY_GPIO_Port GPIOA
#define LED_ERR_08_Pin GPIO_PIN_1
#define LED_ERR_08_GPIO_Port GPIOA
#define LED_ERR_07_Pin GPIO_PIN_2
#define LED_ERR_07_GPIO_Port GPIOA
#define LED_ERR_06_Pin GPIO_PIN_3
#define LED_ERR_06_GPIO_Port GPIOA
#define LED_ERR_05_Pin GPIO_PIN_4
#define LED_ERR_05_GPIO_Port GPIOA
#define INPUT_08_Pin GPIO_PIN_5
#define INPUT_08_GPIO_Port GPIOA
#define INPUT_07_Pin GPIO_PIN_6
#define INPUT_07_GPIO_Port GPIOA
#define INPUT_06_Pin GPIO_PIN_7
#define INPUT_06_GPIO_Port GPIOA
#define INPUT_05_Pin GPIO_PIN_0
#define INPUT_05_GPIO_Port GPIOB
#define INPUT_04_Pin GPIO_PIN_1
#define INPUT_04_GPIO_Port GPIOB
#define INPUT_03_Pin GPIO_PIN_2
#define INPUT_03_GPIO_Port GPIOB
#define INPUT_02_Pin GPIO_PIN_10
#define INPUT_02_GPIO_Port GPIOB
#define INPUT_01_Pin GPIO_PIN_11
#define INPUT_01_GPIO_Port GPIOB
#define OUTPUT_07_Pin GPIO_PIN_12
#define OUTPUT_07_GPIO_Port GPIOB
#define OUTPUT_05_Pin GPIO_PIN_13
#define OUTPUT_05_GPIO_Port GPIOB
#define OUTPUT_03_Pin GPIO_PIN_14
#define OUTPUT_03_GPIO_Port GPIOB
#define OUTPUT_01_Pin GPIO_PIN_15
#define OUTPUT_01_GPIO_Port GPIOB
#define OUTPUT_02_Pin GPIO_PIN_8
#define OUTPUT_02_GPIO_Port GPIOA
#define OUTPUT_04_Pin GPIO_PIN_9
#define OUTPUT_04_GPIO_Port GPIOA
#define OUTPUT_06_Pin GPIO_PIN_10
#define OUTPUT_06_GPIO_Port GPIOA
#define OUTPUT_08_Pin GPIO_PIN_11
#define OUTPUT_08_GPIO_Port GPIOA
#define LED_ERR_02_Pin GPIO_PIN_3
#define LED_ERR_02_GPIO_Port GPIOB
#define LED_ERR_01_Pin GPIO_PIN_4
#define LED_ERR_01_GPIO_Port GPIOB
#define LED_ERR_03_Pin GPIO_PIN_5
#define LED_ERR_03_GPIO_Port GPIOB
#define LED_ERR_04_Pin GPIO_PIN_6
#define LED_ERR_04_GPIO_Port GPIOB
#define BUTTON_EN_Pin GPIO_PIN_7
#define BUTTON_EN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
