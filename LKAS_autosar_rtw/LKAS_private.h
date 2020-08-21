/*
 * File: LKAS_private.h
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

#ifndef RTW_HEADER_LKAS_private_h_
#define RTW_HEADER_LKAS_private_h_
#include "rtwtypes.h"
#include "LKAS.h"
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

extern float32 look1_iflf_pbinlgpw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 prevIndex[], uint32 maxIndex);
extern void LKAS_IfActionSubsystem2(float32 *rty_Out1);
extern void L_MovingStandardDeviation2_Init(DW_MovingStandardDeviation2_L_T
  *localDW);
extern void MovingStandardDeviation2_Reset(DW_MovingStandardDeviation2_L_T
  *localDW);
extern float32 LKAS_MovingStandardDeviation2(float32 rtu_In1,
  DW_MovingStandardDeviation2_L_T *localDW);
extern void LKAS_SumCondition_Init(DW_SumCondition_LKAS_T *localDW);
extern void LKAS_SumCondition_Reset(DW_SumCondition_LKAS_T *localDW);
extern void LKAS_SumCondition_Disable(uint16 *rty_Out, DW_SumCondition_LKAS_T
  *localDW);
extern void LKAS_SumCondition(boolean rtu_In, float32 rtu_In1, uint16 *rty_Out,
  DW_SumCondition_LKAS_T *localDW);
extern void LKAS_ifaction3(float32 rtu_In1, float32 *rty_Out1);
extern void LKAS_ifaction(float32 rtu_In, float32 *rty_Out);
extern void LKAS_IfActionSubsystem(float32 rtu_In1, float32 *rty_Out1);
extern void LKAS_IfActionSubsystem_j(float32 rtu_In1, float32 *rty_Out1);
extern void LKAS_ifaction_c(float32 rtu_In, float32 *rty_Out);
extern void LKAS_IfActionSubsystem_g(float32 rtu_Enable, float32 rtu_T1, float32
  rtu_Plan, float32 *rty_T1_1, float32 *rty_Plan_1,
  DW_IfActionSubsystem_LKAS_c_T *localDW);
extern void LKAS_IfActionSubsystem2_l(float32 rtu_T1, float32 rtu_Plan, float32 *
  rty_T1_1, float32 *rty_Plan_1);
extern void LKAS_IfActionSubsystem3(float32 rtu_In1, float32 rtu_In2, float32
  *rty_Out1);
extern void LKAS_MATLABFunction(float32 rtu_u1, float32 rtu_u2, float32 *rty_y);
extern void LKAS_Ph1SWA(float32 *rty_Out);
extern void LKAS_Ph2SWA(float32 *rty_Out);
extern void LKAS_Ph3SWA(float32 *rty_Out);
extern void LKAS_IfActionSubsystem3_m(boolean rtu_In1, boolean *rty_Out);
extern void LKAS_IfActionSubsystem4(boolean *rty_Out);
extern void LKAS_IfActionSubsystem_e(boolean *rty_Out);
extern void LKAS_Count5s1_Init(DW_Count5s1_LKAS_T *localDW);
extern void LKAS_Count5s1_Reset(DW_Count5s1_LKAS_T *localDW);
extern void LKAS_Count5s1_Disable(boolean *rty_Out, DW_Count5s1_LKAS_T *localDW);
extern void LKAS_Count5s1(boolean rtu_Enable, float32 rtu_LKA_SampleTime,
  boolean *rty_Out, DW_Count5s1_LKAS_T *localDW);
extern void LKAMotionPlanningCalculati_Init(void);
extern void LKAMotionPlanningCalculat_Reset(void);
extern void LKAMotionPlanningCalculationLKA(void);
extern void LKAS_LDW_State_Machine_Reset(void);
extern void LKAS_LDW_State_Machine(void);
extern void LKAS_LKA_State_Machine_Reset(void);
extern void LKAS_LKA_State_Machine(void);

#endif                                 /* RTW_HEADER_LKAS_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
