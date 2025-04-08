/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: c_code_MR100.c
 *
 * Code generated for Simulink model 'c_code_MR100'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Oct 21 16:11:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "c_code_MR100.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>
#define NumBitsPerChar                 8U

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
  real_T y;
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
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
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
void c_code_MR100_step(void)
{
  real_T rtb_DirectLookupTablenD9_h;

  /* If: '<S1>/If1' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/time_input_0.001'
   *  Merge: '<S1>/L1'
   *  Merge: '<S1>/R1'
   *  Saturate: '<S3>/Saturation2'
   *  Sum: '<S3>/Add1'
   */
  if (rtU.time_input_0001 <= 2.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Gain: '<S2>/Gain14' */
    rtb_DirectLookupTablenD9_h = 100.0 * rtU.time_input_0001;

    /* Gain: '<S2>/Gain40' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[1] = 0.0001 * rtConstP.DirectLookupTablenD_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain41' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)1'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[2] = 0.0001 * rtConstP.DirectLookupTablenD1_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain42' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)2'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[3] = 0.0001 * rtConstP.DirectLookupTablenD2_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain43' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)3'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[4] = 0.0001 * rtConstP.DirectLookupTablenD3_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain44' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)4'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)4':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[5] = 0.0001 * rtConstP.DirectLookupTablenD4_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain1' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)5'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)5':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[1] = 0.0001 * rtConstP.DirectLookupTablenD5_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain2' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)6'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)6':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[2] = 0.0001 * rtConstP.DirectLookupTablenD6_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain3' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)7'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)7':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[3] = 0.0001 * rtConstP.DirectLookupTablenD7_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain4' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)8'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)8':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[4] = 0.0001 * rtConstP.DirectLookupTablenD8_table[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S2>/Gain5' incorporates:
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S2>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S2>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S2>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[5] = 0.0001 * rtConstP.DirectLookupTablenD9_table[(int16_T)
      rtb_DirectLookupTablenD9_h];
    rtDW.l[0] = 0.0;
    rtDW.r[0] = 0.0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (rtU.time_input_0001 - 2.0 <= 0.0) {
      /* Saturate: '<S3>/Saturation2' */
      rtb_DirectLookupTablenD9_h = 0.0;
    } else {
      /* Saturate: '<S3>/Saturation2' incorporates:
       *  Constant: '<S3>/Constant2'
       *  Sum: '<S3>/Add1'
       */
      rtb_DirectLookupTablenD9_h = rtU.time_input_0001 - 2.0;
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Constant: '<S3>/Constant4'
     *  Math: '<S3>/Math Function'
     *  Saturate: '<S3>/Saturation2'
     */
    rtb_DirectLookupTablenD9_h = 100.0 * rt_modd_snf(rtb_DirectLookupTablenD9_h,
      1.0);

    /* Gain: '<S3>/Gain40' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[1] = 0.0001 * rtConstP.DirectLookupTablenD_table_j[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain41' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)1'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[2] = 0.0001 * rtConstP.DirectLookupTablenD1_table_m[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain42' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)2'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)2':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[3] = 0.0001 * rtConstP.DirectLookupTablenD2_table_c[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain43' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)3'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)3':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[4] = 0.0001 * rtConstP.DirectLookupTablenD3_table_c[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain44' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)4'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/L1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)4':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.l[5] = 0.0001 * rtConstP.DirectLookupTablenD4_table_n[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain2' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)5'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)5':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[1] = 0.0001 * rtConstP.DirectLookupTablenD5_table_k[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain3' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)6'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)6':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[2] = 0.0001 * rtConstP.DirectLookupTablenD6_table_n[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain4' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)7'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)7':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[3] = 0.0001 * rtConstP.DirectLookupTablenD7_table_n[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain5' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)8'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)8':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[4] = 0.0001 * rtConstP.DirectLookupTablenD8_table_j[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain6' incorporates:
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)'
     *  LookupNDDirect: '<S3>/Direct Lookup Table (n-D)9'
     *  Merge: '<S1>/R1'
     *
     * About '<S3>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     *
     * About '<S3>/Direct Lookup Table (n-D)9':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'on'
     */
    rtDW.r[5] = 0.0001 * rtConstP.DirectLookupTablenD9_table_b[(int16_T)
      rtb_DirectLookupTablenD9_h];

    /* Gain: '<S3>/Gain1' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Merge: '<S1>/R1'
     */
    rtDW.r[0] = 0.0;
    rtDW.l[0] = 0.0;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
  }

  /* End of If: '<S1>/If1' */

  /* Outport: '<Root>/R_Hip_Roll' incorporates:
   *  Gain: '<S1>/Gain54'
   */
  rtY.R_Hip_Roll = -rtDW.r[1];

  /* Outport: '<Root>/R_Hip_Pitch' incorporates:
   *  Gain: '<S1>/Gain55'
   */
  rtY.R_Hip_Pitch = -rtDW.r[2];

  /* Outport: '<Root>/R_knee' incorporates:
   *  Gain: '<S1>/Gain56'
   */
  rtY.R_knee = -rtDW.r[3];

  /* Outport: '<Root>/L_Hip_Pitch' incorporates:
   *  Gain: '<S1>/Gain45'
   */
  rtY.L_Hip_Pitch = -rtDW.l[2];

  /* Outport: '<Root>/L_Ankle_Roll' incorporates:
   *  Gain: '<S1>/Gain52'
   */
  rtY.L_Ankle_Roll = -rtDW.l[5];

  /* Outport: '<Root>/L_Hip_Yaw' */
  rtY.L_Hip_Yaw = 0.0;

  /* Outport: '<Root>/L_Hip_Roll' */
  rtY.L_Hip_Roll = rtDW.l[1];

  /* Outport: '<Root>/L_knee' */
  rtY.L_knee = rtDW.l[3];

  /* Outport: '<Root>/L_Ankle_Pitch' */
  rtY.L_Ankle_Pitch = rtDW.l[4];

  /* Outport: '<Root>/R_Hip_Yaw' */
  rtY.R_Hip_Yaw = 0.0;

  /* Outport: '<Root>/R_Ankle_Pitch' */
  rtY.R_Ankle_Pitch = rtDW.r[4];

  /* Outport: '<Root>/R_Ankle_Roll' */
  rtY.R_Ankle_Roll = rtDW.r[5];
}

/* Model initialize function */
void c_code_MR100_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
