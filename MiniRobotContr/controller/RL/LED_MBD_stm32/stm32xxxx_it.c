/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stm32xxxx_it.c
 *
 * Code generated for Simulink model :LED_MBD.
 *
 * Model version      : 1.14
 * Simulink Coder version    : 9.9 (R2023a) 19-Nov-2022
 * TLC version       : 9.9 (Nov  8 2023)
 * C/C++ source code generated on  : Sat Nov  9 16:29:02 2024
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN SysTick_IRQn 0 */
  {
    extern volatile uint32_t remainAutoReloadTimerLoopVal_S;

    /* Manage number of loop before interrupt has to be processed. */
    if (remainAutoReloadTimerLoopVal_S) {
      remainAutoReloadTimerLoopVal_S--;
    }
  }

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] stm32xxxx_it.c
 */
