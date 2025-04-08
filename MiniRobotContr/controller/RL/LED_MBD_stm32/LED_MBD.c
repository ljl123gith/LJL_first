/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LED_MBD.c
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

#include "LED_MBD.h"
#include "LED_MBD_private.h"
#include "LED_MBD_dt.h"

/* Real-time model */
static RT_MODEL_LED_MBD LED_MBD_M_;
RT_MODEL_LED_MBD *const LED_MBD_M = &LED_MBD_M_;

/* Model step function */
void LED_MBD_step(void)
{
  {
    if (LED_MBD_P.Constant5_Value != TIM3_Conf.CH3_duty) {
      TIM3_Conf.CH3_duty = LED_MBD_P.Constant5_Value;
      if (LED_MBD_P.Constant5_Value >= 0) {
        /* Channel3 duty cycle is an input port. */
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,(uint32_t)
                              (LED_MBD_P.Constant5_Value * (&htim3)->
          Instance->ARR / 100));
      }
    }

    if (LED_MBD_P.Constant6_Value != TIM3_Conf.CH4_duty) {
      TIM3_Conf.CH4_duty = LED_MBD_P.Constant6_Value;
      if (LED_MBD_P.Constant6_Value >= 0) {
        /* Channe4 duty cycle is an input port. */
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,(uint32_t)
                              (LED_MBD_P.Constant6_Value * (&htim3)->
          Instance->ARR / 100));
      }
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)LED_MBD_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(LED_MBD_M)!=-1) &&
        !((rtmGetTFinal(LED_MBD_M)-LED_MBD_M->Timing.taskTime0) >
          LED_MBD_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LED_MBD_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LED_MBD_M)) {
      rtmSetErrorStatus(LED_MBD_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LED_MBD_M->Timing.taskTime0 =
    ((time_T)(++LED_MBD_M->Timing.clockTick0)) * LED_MBD_M->Timing.stepSize0;
}

/* Model initialize function */
void LED_MBD_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(LED_MBD_M, 10.0);
  LED_MBD_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  LED_MBD_M->Sizes.checksums[0] = (441520903U);
  LED_MBD_M->Sizes.checksums[1] = (2103388976U);
  LED_MBD_M->Sizes.checksums[2] = (2994867160U);
  LED_MBD_M->Sizes.checksums[3] = (2549944052U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    LED_MBD_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LED_MBD_M->extModeInfo,
      &LED_MBD_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LED_MBD_M->extModeInfo, LED_MBD_M->Sizes.checksums);
    rteiSetTPtr(LED_MBD_M->extModeInfo, rtmGetTPtr(LED_MBD_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LED_MBD_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    /* user code (Start function Header) */
    {
      /* TIM3 initialization. */
      /* Store TIM3 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM3_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim3;

      /* Store TIM information. */
      TIM3_Conf.TIM_Prescaler = 71;
      TIM3_Conf.TIM_APBClock = 72000000;
      TIM3_Conf.TIM_ARR = 1000 - 1;
      TIM3_Conf.TIM_Clock = 1.0E+6;
      TIM3_Conf.TIM_Freq = 1000.0;
      TIM3_Conf.CH1_duty = 0.0;
      TIM3_Conf.CH2_duty = 0.0;
      TIM3_Conf.CH3_duty = 50.0;
      TIM3_Conf.CH4_duty = 50.0;
      TIM3_Conf.CH1_type = UNKNOWN;
      TIM3_Conf.CH2_type = UNKNOWN;
      TIM3_Conf.CH3_type = OUTPUT_PWM;
      TIM3_Conf.CH4_type = OUTPUT_PWM;

      /* Interrupt handler default initialization. */
      TIM3_Conf.ItUpFcn = NULL;
      TIM3_Conf.ItTrgFcn = NULL;
      TIM3_Conf.ItComFcn = NULL;
      TIM3_Conf.ItBrkFcn = NULL;
      TIM3_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim3)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim3,TIM3_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim3,1000 - 1);

      /* Set CH3 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,(uint32_t)(500));

      /* Set CH4 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,(uint32_t)(500));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim3,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */
    {
      /* TIM3 Start. */

      /* Wait for htim3 State READY. */
      while ((&htim3)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);

      /* Wait for htim3 State READY. */
      while ((&htim3)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_MBD.c
 */
