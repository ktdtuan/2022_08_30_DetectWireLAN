/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// INPUT
uint8_t input_08(void) { return HAL_GPIO_ReadPin(INPUT_08_GPIO_Port, INPUT_08_Pin); }
uint8_t input_07(void) { return HAL_GPIO_ReadPin(INPUT_07_GPIO_Port, INPUT_07_Pin); }
uint8_t input_06(void) { return HAL_GPIO_ReadPin(INPUT_06_GPIO_Port, INPUT_06_Pin); }
uint8_t input_05(void) { return HAL_GPIO_ReadPin(INPUT_05_GPIO_Port, INPUT_05_Pin); }
uint8_t input_04(void) { return HAL_GPIO_ReadPin(INPUT_04_GPIO_Port, INPUT_04_Pin); }
uint8_t input_03(void) { return HAL_GPIO_ReadPin(INPUT_03_GPIO_Port, INPUT_03_Pin); }
uint8_t input_02(void) { return HAL_GPIO_ReadPin(INPUT_02_GPIO_Port, INPUT_02_Pin); }
uint8_t input_01(void) { return HAL_GPIO_ReadPin(INPUT_01_GPIO_Port, INPUT_01_Pin); }

// OUTPUT
void output_08(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_08_GPIO_Port, OUTPUT_08_Pin, val); }
void output_07(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_07_GPIO_Port, OUTPUT_07_Pin, val); }
void output_06(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_06_GPIO_Port, OUTPUT_06_Pin, val); }
void output_05(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_05_GPIO_Port, OUTPUT_05_Pin, val); }
void output_04(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_04_GPIO_Port, OUTPUT_04_Pin, val); }
void output_03(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_03_GPIO_Port, OUTPUT_03_Pin, val); }
void output_02(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_02_GPIO_Port, OUTPUT_02_Pin, val); }
void output_01(uint8_t val) { HAL_GPIO_WritePin(OUTPUT_01_GPIO_Port, OUTPUT_01_Pin, val); }

// LED ERROR
void led_err_08(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_08_GPIO_Port, LED_ERR_08_Pin, val); }
void led_err_07(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_07_GPIO_Port, LED_ERR_07_Pin, val); }
void led_err_06(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_06_GPIO_Port, LED_ERR_06_Pin, val); }
void led_err_05(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_05_GPIO_Port, LED_ERR_05_Pin, val); }
void led_err_04(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_04_GPIO_Port, LED_ERR_04_Pin, val); }
void led_err_03(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_03_GPIO_Port, LED_ERR_03_Pin, val); }
void led_err_02(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_02_GPIO_Port, LED_ERR_02_Pin, val); }
void led_err_01(uint8_t val) { HAL_GPIO_WritePin(LED_ERR_01_GPIO_Port, LED_ERR_01_Pin, val); }

// LED READY
void led_ready(uint8_t val) { HAL_GPIO_WritePin(LED_READY_GPIO_Port, LED_READY_Pin, val); }

// BUTTON ENABLE
uint8_t button_en() { return (uint8_t)HAL_GPIO_ReadPin(BUTTON_EN_GPIO_Port, BUTTON_EN_Pin); }

// function pointer
typedef uint8_t (*pInput)(void);
typedef void (*pOutput)(uint8_t val);
pInput inputArray[] = {input_08, input_07, input_06, input_05, input_04, input_03, input_02, input_01};
pOutput outputArray[] = {output_08, output_07, output_06, output_05, output_04, output_03, output_02, output_01};
pOutput ledErrArray[] = {led_err_08, led_err_07, led_err_06, led_err_05, led_err_04, led_err_03, led_err_02, led_err_01};

// flag check ready
uint8_t checkReady = 0;
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    // while (button_en());

    checkReady = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
      outputArray[i](0);
      HAL_Delay(1);

      if (inputArray[i]() != 0)
      {
        checkReady++;
        ledErrArray[i](0);
      }
      else
        ledErrArray[i](1);
      outputArray[i](1);
    }

    // check and turn on/off led ready
    if (checkReady != 0)
      led_ready(1);
    else
      led_ready(0);
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_READY_GPIO_Port, LED_READY_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_ERR_08_Pin | LED_ERR_07_Pin | LED_ERR_06_Pin | LED_ERR_05_Pin | OUTPUT_02_Pin | OUTPUT_04_Pin | OUTPUT_06_Pin | OUTPUT_08_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OUTPUT_07_Pin | OUTPUT_05_Pin | OUTPUT_03_Pin | OUTPUT_01_Pin | LED_ERR_02_Pin | LED_ERR_01_Pin | LED_ERR_03_Pin | LED_ERR_04_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : LED_READY_Pin LED_ERR_08_Pin LED_ERR_07_Pin LED_ERR_06_Pin
                           LED_ERR_05_Pin */
  GPIO_InitStruct.Pin = LED_READY_Pin | LED_ERR_08_Pin | LED_ERR_07_Pin | LED_ERR_06_Pin | LED_ERR_05_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : INPUT_08_Pin INPUT_07_Pin INPUT_06_Pin */
  GPIO_InitStruct.Pin = INPUT_08_Pin | INPUT_07_Pin | INPUT_06_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : INPUT_05_Pin INPUT_04_Pin INPUT_03_Pin INPUT_02_Pin
                           INPUT_01_Pin BUTTON_EN_Pin */
  GPIO_InitStruct.Pin = INPUT_05_Pin | INPUT_04_Pin | INPUT_03_Pin | INPUT_02_Pin | INPUT_01_Pin | BUTTON_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : OUTPUT_07_Pin OUTPUT_05_Pin OUTPUT_03_Pin OUTPUT_01_Pin */
  GPIO_InitStruct.Pin = OUTPUT_07_Pin | OUTPUT_05_Pin | OUTPUT_03_Pin | OUTPUT_01_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : OUTPUT_02_Pin OUTPUT_04_Pin OUTPUT_06_Pin OUTPUT_08_Pin */
  GPIO_InitStruct.Pin = OUTPUT_02_Pin | OUTPUT_04_Pin | OUTPUT_06_Pin | OUTPUT_08_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_ERR_02_Pin LED_ERR_01_Pin LED_ERR_03_Pin LED_ERR_04_Pin */
  GPIO_InitStruct.Pin = LED_ERR_02_Pin | LED_ERR_01_Pin | LED_ERR_03_Pin | LED_ERR_04_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
