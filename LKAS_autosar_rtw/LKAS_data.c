/*
 * File: LKAS_data.c
 *
 * Code generated for Simulink model 'LKAS'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug 21 16:33:42 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LKAS.h"
#include "LKAS_private.h"

/* Invariant block signals (default storage) */
const ConstB_LKAS_T LKAS_ConstB = {
  10.0F,                               /* '<S87>/Saturation' */
  0.1F,                                /* '<S87>/Divide2' */
  0.9F,                                /* '<S87>/Add2' */
  10.0F,                               /* '<S81>/Saturation' */
  0.1F,                                /* '<S81>/Divide2' */
  0.9F,                                /* '<S81>/Add2' */
  10.0F,                               /* '<S82>/Saturation' */
  0.1F,                                /* '<S82>/Divide2' */
  0.9F,                                /* '<S82>/Add2' */
  0.0F,                                /* '<S613>/Data Type Conversion22' */
  0.0F,                                /* '<S613>/Data Type Conversion23' */
  0.0F,                                /* '<S613>/Data Type Conversion24' */
  0.0F,                                /* '<S613>/Data Type Conversion27' */
  0.0F,                                /* '<S613>/Data Type Conversion28' */
  0.0F,                                /* '<S613>/Data Type Conversion29' */
  0.0F,                                /* '<S613>/Data Type Conversion30' */
  0.0F,                                /* '<S613>/Data Type Conversion31' */
  0.0F,                                /* '<S613>/Data Type Conversion32' */
  0.0F,                                /* '<S613>/Data Type Conversion33' */
  0.0F,                                /* '<S613>/Data Type Conversion34' */
  0.0F,                                /* '<S613>/Data Type Conversion35' */
  0.0F,                                /* '<S613>/Data Type Conversion37' */
  0.0F,                                /* '<S613>/Data Type Conversion39' */
  0.0F,                                /* '<S613>/Data Type Conversion40' */
  0.0F,                                /* '<S613>/Data Type Conversion41' */
  0.0F,                                /* '<S613>/Data Type Conversion42' */
  0.0F,                                /* '<S613>/Data Type Conversion43' */
  0.0F,                                /* '<S613>/Data Type Conversion53' */
  0.0F,                                /* '<S613>/Data Type Conversion1' */
  0.0F,                                /* '<S613>/Data Type Conversion51' */
  0.0F,                                /* '<S613>/Data Type Conversion48' */
  0.0F,                                /* '<S613>/Data Type Conversion49' */
  0.0F,                                /* '<S613>/Data Type Conversion50' */
  0.0F,                                /* '<S613>/Data Type Conversion52' */
  0.0F,                                /* '<S613>/Data Type Conversion54' */
  0.0F,                                /* '<S613>/Data Type Conversion55' */
  0.0F,                                /* '<S613>/Data Type Conversion56' */
  0.0F,                                /* '<S613>/Data Type Conversion57' */
  0.0F,                                /* '<S613>/Data Type Conversion59' */
  0.0F,                                /* '<S613>/Data Type Conversion60' */
  0.0F,                                /* '<S613>/Data Type Conversion61' */
  0.0F,                                /* '<S613>/Data Type Conversion62' */
  0.0F,                                /* '<S613>/Data Type Conversion63' */
  0.0F,                                /* '<S613>/Data Type Conversion3' */
  0.0F,                                /* '<S613>/Data Type Conversion4' */
  0.0F,                                /* '<S613>/Data Type Conversion2' */
  0.0F,                                /* '<S613>/Data Type Conversion79' */
  0.0F,                                /* '<S613>/Data Type Conversion81' */
  0.0F,                                /* '<S613>/Data Type Conversion71' */
  0.0F,                                /* '<S613>/Data Type Conversion73' */
  0.0F,                                /* '<S611>/Data Type Conversion6' */
  0.0F,                                /* '<S612>/Data Type Conversion8' */
  0.0F,                                /* '<S612>/Data Type Conversion1' */
  0.0F,                                /* '<S612>/Data Type Conversion3' */
  0.0F,                                /* '<S612>/Data Type Conversion16' */
  0.0F,                                /* '<S612>/Data Type Conversion5' */
  0.0F,                                /* '<S612>/Data Type Conversion10' */
  0.0F,                                /* '<S612>/Data Type Conversion6' */
  0.0F,                                /* '<S612>/Data Type Conversion13' */
  0.0F,                                /* '<S612>/Data Type Conversion22' */
  0.0F,                                /* '<S612>/Data Type Conversion21' */
  0.0F,                                /* '<S612>/Data Type Conversion2' */
  0.0F,                                /* '<S612>/Data Type Conversion11' */
  0.0F,                                /* '<S612>/Data Type Conversion15' */
  0.0F,                                /* '<S612>/Data Type Conversion14' */
  0.0F,                                /* '<S612>/Data Type Conversion4' */
  0.0F,                                /* '<S612>/Data Type Conversion7' */
  0.0F,                                /* '<S612>/Data Type Conversion17' */
  0.0F,                                /* '<S612>/Data Type Conversion18' */
  0.0F,                                /* '<S612>/Data Type Conversion28' */
  0.0F,                                /* '<S612>/Data Type Conversion29' */
  0.0F,                                /* '<S612>/Data Type Conversion49' */
  0.0F,                                /* '<S612>/Data Type Conversion48' */
  0.0F,                                /* '<S612>/Data Type Conversion9' */
  0.0F,                                /* '<S612>/Data Type Conversion32' */
  0.0F,                                /* '<S612>/Data Type Conversion31' */
  0.0F,                                /* '<S612>/Data Type Conversion47' */
  0.0F,                                /* '<S612>/Data Type Conversion50' */
  0.0F,                                /* '<S612>/Data Type Conversion52' */
  0.0F,                                /* '<S612>/Data Type Conversion53' */
  0.0F,                                /* '<S612>/Data Type Conversion12' */
  0.0F,                                /* '<S612>/Data Type Conversion19' */
  0.0F,                                /* '<S612>/Data Type Conversion20' */
  0.0F,                                /* '<S612>/Data Type Conversion24' */
  0.0F,                                /* '<S612>/Data Type Conversion25' */
  0.0F,                                /* '<S612>/Data Type Conversion55' */
  0.0F,                                /* '<S612>/Data Type Conversion54' */
  0.0F,                                /* '<S612>/Data Type Conversion34' */
  0.0F,                                /* '<S612>/Data Type Conversion33' */
  0.0F,                                /* '<S612>/Data Type Conversion35' */
  0.0F,                                /* '<S610>/Data Type Conversion3' */
  0.0F,                                /* '<S610>/Data Type Conversion13' */
  0.0F,                                /* '<S610>/Data Type Conversion2' */
  0.0F,                                /* '<S610>/Data Type Conversion4' */
  0.0F,                                /* '<S610>/Data Type Conversion6' */
  0.0F,                                /* '<S610>/Data Type Conversion22' */
  200428.0F,                           /* '<S2>/Version' */
  0.0F,                                /* '<S612>/Data Type Conversion23' */
  0.0F,                                /* '<S613>/Data Type Conversion38' */
  10.0F,                               /* '<S187>/Saturation' */
  0.1F,                                /* '<S187>/Divide2' */
  0.9F,                                /* '<S187>/Add2' */
  1.0F,                                /* '<S202>/Add3' */
  0U,                                  /* '<S9>/Cast To Single4' */
  1U,                                  /* '<S69>/Constant' */
  0U,                                  /* '<S9>/Cast To Single14' */
  0U,                                  /* '<S9>/Cast To Single15' */
  0U,                                  /* '<S620>/Constant17' */
  0U,                                  /* '<S620>/Constant18' */
  0U,                                  /* '<S620>/Constant19' */
  0U,                                  /* '<S620>/Constant20' */
  0U,                                  /* '<S620>/Constant21' */
  0U,                                  /* '<S621>/Constant1' */
  0U,                                  /* '<S621>/Constant2' */
  0U,                                  /* '<S621>/Constant3' */
  0U,                                  /* '<S621>/Constant4' */
  0U,                                  /* '<S621>/Constant5' */
  0U,                                  /* '<S621>/Constant6' */
  0U,                                  /* '<S621>/Constant7' */
  0U,                                  /* '<S621>/Constant8' */
  0U,                                  /* '<S621>/Constant9' */
  0                                    /* '<S534>/Compare' */
};

/* Constant parameters (default storage) */
const ConstP_LKAS_T LKAS_ConstP = {
  /* Pooled Parameter (Expression: [0.012141,0.005179,0.00298,0.002547,0.001715,0.001283,0.001021,0.000982])
   * Referenced by:
   *   '<S229>/Lookup Table2'
   *   '<S127>/Lookup Table2'
   *   '<S287>/Lookup Table2'
   *   '<S288>/Lookup Table2'
   *   '<S186>/Lookup Table2'
   *   '<S267>/Lookup Table2'
   */
  { 0.012141F, 0.005179F, 0.00298F, 0.002547F, 0.001715F, 0.001283F, 0.001021F,
    0.000982F },

  /* Pooled Parameter (Expression: [11.7,18.83,26.98,31.98,51.04,79,86.08,90.59])
   * Referenced by:
   *   '<S229>/Lookup Table2'
   *   '<S127>/Lookup Table2'
   *   '<S287>/Lookup Table2'
   *   '<S288>/Lookup Table2'
   *   '<S186>/Lookup Table2'
   *   '<S267>/Lookup Table2'
   */
  { 11.7F, 18.83F, 26.98F, 31.98F, 51.04F, 79.0F, 86.08F, 90.59F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
