/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
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

#include "Subsystem.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real_T rt_modd_snf(real_T u0, real_T u1);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void Subsystem_step(void)
{
  real_T rtb_Gain1;

  /* If: '<S1>/If1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/In1'
   *  Saturate: '<S3>/Saturation2'
   *  Sum: '<S3>/Add1'
   */
  if (rtU.In1 <= 2.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
     *  Constant: '<S2>/Constant4'
     *  Merge: '<S1>/L1'
     */
    rtDW.l[0] = 0.0;

    /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
     *  Constant: '<S2>/Constant6'
     *  Merge: '<S1>/R1'
     */
    rtDW.r[0] = 0.0;

    /* Gain: '<S2>/Gain14' */
    rtb_Gain1 = 100.0 * rtU.In1;

    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain5'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[5] = 26844.0 * (real_T)rtConstP.Lookup_Table10_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion10' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain41'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table2'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[2] = 26844.0 * (real_T)rtConstP.Lookup_Table2_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain40'
     *  LookupNDDirect: '<S2>/Lookup_Table1'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Lookup_Table1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[1] = 26844.0 * (real_T)rtConstP.Lookup_Table1_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain4'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[4] = 26844.0 * (real_T)rtConstP.Lookup_Table9_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain3'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table8'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table8':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[3] = 26844.0 * (real_T)rtConstP.Lookup_Table8_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain2'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table7'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table7':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[2] = 26844.0 * (real_T)rtConstP.Lookup_Table7_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
     *  Gain: '<S2>/Gain1'
     *  Gain: '<S2>/Gain14'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table6'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table6':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[1] = 26844.0 * (real_T)rtConstP.Lookup_Table6_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain44'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table5'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table5':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[5] = 26844.0 * (real_T)rtConstP.Lookup_Table5_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain43'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table4'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table4':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[4] = 26844.0 * (real_T)rtConstP.Lookup_Table4_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S2>/Data Type Conversion9' incorporates:
     *  Gain: '<S2>/Gain14'
     *  Gain: '<S2>/Gain42'
     *  LookupNDDirect: '<S2>/Lookup_Table10'
     *  LookupNDDirect: '<S2>/Lookup_Table3'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Lookup_Table10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Lookup_Table3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[3] = 26844.0 * (real_T)rtConstP.Lookup_Table3_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (rtU.In1 - 2.0 <= 0.0) {
      /* Saturate: '<S3>/Saturation2' */
      rtb_Gain1 = 0.0;
    } else {
      /* Saturate: '<S3>/Saturation2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Sum: '<S3>/Add1'
       */
      rtb_Gain1 = rtU.In1 - 2.0;
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Constant: '<S3>/Constant4'
     *  Math: '<S3>/Math Function'
     *  Saturate: '<S3>/Saturation2'
     */
    rtb_Gain1 = 100.0 * rt_modd_snf(rtb_Gain1, 1.0);

    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain6'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[5] = 26844.0 * (real_T)rtConstP.Lookup_Table_else10_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain5'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[4] = 26844.0 * (real_T)rtConstP.Lookup_Table_else9_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain40'
     *  LookupNDDirect: '<S3>/Lookup_Table_else1'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Lookup_Table_else1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[1] = 26844.0 * (real_T)rtConstP.Lookup_Table_else1_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain4'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else8'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else8':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[3] = 26844.0 * (real_T)rtConstP.Lookup_Table_else8_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain3'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else7'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else7':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[2] = 26844.0 * (real_T)rtConstP.Lookup_Table_else7_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain2'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else6'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else6':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[1] = 26844.0 * (real_T)rtConstP.Lookup_Table_else6_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion6' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain44'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else5'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else5':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[5] = 26844.0 * (real_T)rtConstP.Lookup_Table_else5_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain43'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else4'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else4':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[4] = 26844.0 * (real_T)rtConstP.Lookup_Table_else4_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion8' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain42'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else3'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[3] = 26844.0 * (real_T)rtConstP.Lookup_Table_else3_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion9' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain41'
     *  LookupNDDirect: '<S3>/Lookup_Table_else10'
     *  LookupNDDirect: '<S3>/Lookup_Table_else2'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Lookup_Table_else10':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Lookup_Table_else2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[2] = 26844.0 * (real_T)rtConstP.Lookup_Table_else2_table[(int32_T)
      rtb_Gain1] * 3.7252902984619141E-9;

    /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Merge: '<S1>/L1'
     */
    rtDW.l[0] = 0.0;

    /* DataTypeConversion: '<S3>/Data Type Conversion5' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Gain: '<S3>/Gain1'
     *  Merge: '<S1>/R1'
     */
    rtDW.r[0] = 0.0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
  }

  /* End of If: '<S1>/If1' */

  /* Outport: '<Root>/Out2' incorporates:
   *  Gain: '<S1>/Gain54'
   */
  rtY.Out2 = -rtDW.r[1];

  /* Outport: '<Root>/Out3' incorporates:
   *  Gain: '<S1>/Gain55'
   */
  rtY.Out3 = -rtDW.r[2];

  /* Outport: '<Root>/Out4' incorporates:
   *  Gain: '<S1>/Gain56'
   */
  rtY.Out4 = -rtDW.r[3];

  /* Outport: '<Root>/Out9' incorporates:
   *  Gain: '<S1>/Gain45'
   */
  rtY.Out9 = -rtDW.l[2];

  /* Outport: '<Root>/Out12' incorporates:
   *  Gain: '<S1>/Gain52'
   */
  rtY.Out12 = -rtDW.l[5];

  /* Outport: '<Root>/Out7' */
  rtY.Out7 = 0.0;

  /* Outport: '<Root>/Out8' */
  rtY.Out8 = rtDW.l[1];

  /* Outport: '<Root>/Out10' */
  rtY.Out10 = rtDW.l[3];

  /* Outport: '<Root>/Out11' */
  rtY.Out11 = rtDW.l[4];

  /* Outport: '<Root>/Out1' */
  rtY.Out1 = 0.0;

  /* Outport: '<Root>/Out5' */
  rtY.Out5 = rtDW.r[4];

  /* Outport: '<Root>/Out6' */
  rtY.Out6 = rtDW.r[5];
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Outport: '<Root>/Out7' */
  rtY.Out7 = rtDW.l[0];

  /* SystemInitialize for Outport: '<Root>/Out8' */
  rtY.Out8 = rtDW.l[1];

  /* SystemInitialize for Outport: '<Root>/Out10' */
  rtY.Out10 = rtDW.l[3];

  /* SystemInitialize for Outport: '<Root>/Out11' */
  rtY.Out11 = rtDW.l[4];

  /* SystemInitialize for Outport: '<Root>/Out1' */
  rtY.Out1 = rtDW.r[0];

  /* SystemInitialize for Outport: '<Root>/Out5' */
  rtY.Out5 = rtDW.r[4];

  /* SystemInitialize for Outport: '<Root>/Out6' */
  rtY.Out6 = rtDW.r[5];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
