/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: c_code_MR100.h
 *
 * Code generated for Simulink model 'c_code_MR100'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Oct 12 15:01:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_c_code_MR100_h_
#define RTW_HEADER_c_code_MR100_h_
#ifndef c_code_MR100_COMMON_INCLUDES_
#define c_code_MR100_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* c_code_MR100_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T r[6];                         /* '<S1>/R1' */
  real_T l[6];                         /* '<S1>/L1' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Lookup_Table10_table
   * Referenced by: '<S2>/Lookup_Table10'
   */
  int16_T Lookup_Table10_table[201];

  /* Computed Parameter: Lookup_Table2_table
   * Referenced by: '<S2>/Lookup_Table2'
   */
  int16_T Lookup_Table2_table[201];

  /* Computed Parameter: Lookup_Table1_table
   * Referenced by: '<S2>/Lookup_Table1'
   */
  int16_T Lookup_Table1_table[201];

  /* Computed Parameter: Lookup_Table9_table
   * Referenced by: '<S2>/Lookup_Table9'
   */
  int16_T Lookup_Table9_table[201];

  /* Computed Parameter: Lookup_Table8_table
   * Referenced by: '<S2>/Lookup_Table8'
   */
  int16_T Lookup_Table8_table[201];

  /* Computed Parameter: Lookup_Table7_table
   * Referenced by: '<S2>/Lookup_Table7'
   */
  int16_T Lookup_Table7_table[201];

  /* Computed Parameter: Lookup_Table6_table
   * Referenced by: '<S2>/Lookup_Table6'
   */
  int16_T Lookup_Table6_table[201];

  /* Computed Parameter: Lookup_Table5_table
   * Referenced by: '<S2>/Lookup_Table5'
   */
  int16_T Lookup_Table5_table[201];

  /* Computed Parameter: Lookup_Table4_table
   * Referenced by: '<S2>/Lookup_Table4'
   */
  int16_T Lookup_Table4_table[201];

  /* Computed Parameter: Lookup_Table3_table
   * Referenced by: '<S2>/Lookup_Table3'
   */
  int16_T Lookup_Table3_table[201];

  /* Computed Parameter: Lookup_Table_else10_table
   * Referenced by: '<S3>/Lookup_Table_else10'
   */
  int16_T Lookup_Table_else10_table[100];

  /* Computed Parameter: Lookup_Table_else9_table
   * Referenced by: '<S3>/Lookup_Table_else9'
   */
  int16_T Lookup_Table_else9_table[100];

  /* Computed Parameter: Lookup_Table_else1_table
   * Referenced by: '<S3>/Lookup_Table_else1'
   */
  int16_T Lookup_Table_else1_table[100];

  /* Computed Parameter: Lookup_Table_else8_table
   * Referenced by: '<S3>/Lookup_Table_else8'
   */
  int16_T Lookup_Table_else8_table[100];

  /* Computed Parameter: Lookup_Table_else7_table
   * Referenced by: '<S3>/Lookup_Table_else7'
   */
  int16_T Lookup_Table_else7_table[100];

  /* Computed Parameter: Lookup_Table_else6_table
   * Referenced by: '<S3>/Lookup_Table_else6'
   */
  int16_T Lookup_Table_else6_table[100];

  /* Computed Parameter: Lookup_Table_else5_table
   * Referenced by: '<S3>/Lookup_Table_else5'
   */
  int16_T Lookup_Table_else5_table[100];

  /* Computed Parameter: Lookup_Table_else4_table
   * Referenced by: '<S3>/Lookup_Table_else4'
   */
  int16_T Lookup_Table_else4_table[100];

  /* Computed Parameter: Lookup_Table_else3_table
   * Referenced by: '<S3>/Lookup_Table_else3'
   */
  int16_T Lookup_Table_else3_table[100];

  /* Computed Parameter: Lookup_Table_else2_table
   * Referenced by: '<S3>/Lookup_Table_else2'
   */
  int16_T Lookup_Table_else2_table[100];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T R_Hip_Yaw;                    /* '<Root>/R_Hip_Yaw' */
  real_T R_Hip_Roll;                   /* '<Root>/R_Hip_Roll' */
  real_T R_Hip_Pitch;                  /* '<Root>/R_Hip_Pitch' */
  real_T R_knee;                       /* '<Root>/R_knee' */
  real_T R_Ankle_Pitch;                /* '<Root>/R_Ankle_Pitch' */
  real_T R_Ankle_Roll;                 /* '<Root>/R_Ankle_Roll' */
  real_T L_Hip_Yaw;                    /* '<Root>/L_Hip_Yaw' */
  real_T L_Hip_Roll;                   /* '<Root>/L_Hip_Roll' */
  real_T L_Hip_Pitch;                  /* '<Root>/L_Hip_Pitch' */
  real_T L_knee;                       /* '<Root>/L_knee' */
  real_T L_Ankle_Pitch;                /* '<Root>/L_Ankle_Pitch' */
  real_T L_Ankle_Roll;                 /* '<Root>/L_Ankle_Roll' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void c_code_MR100_initialize(void);
extern void c_code_MR100_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Gain46' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain47' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain48' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain49' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain50' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain51' : Eliminated nontunable gain of 1
 * Block '<S1>/Gain53' : Eliminated nontunable gain of 1
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'c_code_MR100'
 * '<S1>'   : 'c_code_MR100/Subsystem'
 * '<S2>'   : 'c_code_MR100/Subsystem/If Action Subsystem2'
 * '<S3>'   : 'c_code_MR100/Subsystem/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_c_code_MR100_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
