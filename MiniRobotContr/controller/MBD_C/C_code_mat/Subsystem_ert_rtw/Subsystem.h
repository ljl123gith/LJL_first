/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Oct 12 14:57:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

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
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
  real_T Out5;                         /* '<Root>/Out5' */
  real_T Out6;                         /* '<Root>/Out6' */
  real_T Out7;                         /* '<Root>/Out7' */
  real_T Out8;                         /* '<Root>/Out8' */
  real_T Out9;                         /* '<Root>/Out9' */
  real_T Out10;                        /* '<Root>/Out10' */
  real_T Out11;                        /* '<Root>/Out11' */
  real_T Out12;                        /* '<Root>/Out12' */
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
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);

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
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('c_code_MR100/Subsystem')    - opens subsystem c_code_MR100/Subsystem
 * hilite_system('c_code_MR100/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'c_code_MR100'
 * '<S1>'   : 'c_code_MR100/Subsystem'
 * '<S2>'   : 'c_code_MR100/Subsystem/If Action Subsystem2'
 * '<S3>'   : 'c_code_MR100/Subsystem/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
