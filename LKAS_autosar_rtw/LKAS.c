/*
 * File: LKAS.c
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

/* Named constants for Chart: '<S93>/LDW_State_Machine' */
#define LKAS_IN_Fault                  ((uint8)1U)
#define LKAS_IN_LDWEnable              ((uint8)1U)
#define LKAS_IN_LDWLeftActive          ((uint8)2U)
#define LKAS_IN_LDWRightActive         ((uint8)3U)
#define LKAS_IN_LDWSelected            ((uint8)1U)
#define LKAS_IN_NO_ACTIVE_CHILD        ((uint8)0U)
#define LKAS_IN_Normal                 ((uint8)2U)
#define LKAS_IN_SysOff                 ((uint8)2U)
#define LKAS_IN_SysOn                  ((uint8)3U)
#define LKAS_IN_Unavailable            ((uint8)1U)
#define LKAS_IN_Unselected             ((uint8)2U)

/* Named constants for Chart: '<S93>/LKA_State_Machine' */
#define LKAS_IN_Fault_e                ((uint8)1U)
#define LKAS_IN_LKAEnable              ((uint8)1U)
#define LKAS_IN_LKALeftActive          ((uint8)2U)
#define LKAS_IN_LKARightActive         ((uint8)3U)
#define LKAS_IN_LKASelected            ((uint8)1U)
#define LKAS_IN_NO_ACTIVE_CHILD_l      ((uint8)0U)
#define LKAS_IN_Normal_l               ((uint8)2U)
#define LKAS_IN_SysOff_a               ((uint8)2U)
#define LKAS_IN_SysOn_c                ((uint8)3U)
#define LKAS_IN_Unavailable_a          ((uint8)1U)
#define LKAS_IN_Unselected_m           ((uint8)2U)

/* Named constants for Chart: '<S70>/LaneReconstructSM' */
#define LKAS_IN_DoubleLost             ((uint8)1U)
#define LKAS_IN_LeftLost               ((uint8)2U)
#define LKAS_IN_NoLaneLost             ((uint8)3U)
#define LKAS_IN_RightLost              ((uint8)4U)

/* Block signals (default storage) */
B_LKAS_T LKAS_B;

/* Block states (default storage) */
DW_LKAS_T LKAS_DW;
float32 look1_iflf_pbinlgpw(float32 u0, const float32 bp0[], const float32
  table[], uint32 prevIndex[], uint32 maxIndex)
{
  float32 frac;
  uint32 iRght;
  uint32 iLeft;
  uint32 bpIdx;
  uint32 found;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = (iRght + iLeft) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = (iRght + iLeft) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
}

/*
 * Output and update for action system:
 *    '<S94>/If Action Subsystem2'
 *    '<S133>/if action 4'
 *    '<S134>/if action 4'
 *    '<S135>/if action 4'
 *    '<S136>/if action 4'
 *    '<S147>/If Action Subsystem3'
 *    '<S155>/If Action Subsystem3'
 *    '<S174>/If Action Subsystem2'
 */
void LKAS_IfActionSubsystem2(float32 *rty_Out1)
{
  /* SignalConversion: '<S98>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
   *  Constant: '<S98>/Constant'
   */
  *rty_Out1 = 0.0F;
}

/*
 * System initialize for atomic system:
 *    '<S108>/Moving Standard Deviation2'
 *    '<S120>/Moving Standard Deviation1'
 *    '<S120>/Moving Standard Deviation2'
 */
void L_MovingStandardDeviation2_Init(DW_MovingStandardDeviation2_L_T *localDW)
{
  /* InitializeConditions for Delay: '<S116>/Delay' */
  localDW->Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay1' */
  localDW->Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay10' */
  localDW->Delay10_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay11' */
  localDW->Delay11_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay12' */
  localDW->Delay12_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay13' */
  localDW->Delay13_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay14' */
  localDW->Delay14_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay15' */
  localDW->Delay15_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay16' */
  localDW->Delay16_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay17' */
  localDW->Delay17_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay18' */
  localDW->Delay18_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay19' */
  localDW->Delay19_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay2' */
  localDW->Delay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay20' */
  localDW->Delay20_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay21' */
  localDW->Delay21_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay22' */
  localDW->Delay22_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay23' */
  localDW->Delay23_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay24' */
  localDW->Delay24_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay25' */
  localDW->Delay25_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay26' */
  localDW->Delay26_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay27' */
  localDW->Delay27_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay28' */
  localDW->Delay28_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay29' */
  localDW->Delay29_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay3' */
  localDW->Delay3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay30' */
  localDW->Delay30_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay31' */
  localDW->Delay31_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay32' */
  localDW->Delay32_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay33' */
  localDW->Delay33_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay34' */
  localDW->Delay34_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay35' */
  localDW->Delay35_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay36' */
  localDW->Delay36_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay37' */
  localDW->Delay37_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay38' */
  localDW->Delay38_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay39' */
  localDW->Delay39_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay4' */
  localDW->Delay4_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay40' */
  localDW->Delay40_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay41' */
  localDW->Delay41_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay42' */
  localDW->Delay42_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay43' */
  localDW->Delay43_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay44' */
  localDW->Delay44_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay45' */
  localDW->Delay45_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay46' */
  localDW->Delay46_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay47' */
  localDW->Delay47_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay48' */
  localDW->Delay48_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay5' */
  localDW->Delay5_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay6' */
  localDW->Delay6_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay7' */
  localDW->Delay7_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay8' */
  localDW->Delay8_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay9' */
  localDW->Delay9_DSTATE = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S108>/Moving Standard Deviation2'
 *    '<S120>/Moving Standard Deviation1'
 *    '<S120>/Moving Standard Deviation2'
 */
void MovingStandardDeviation2_Reset(DW_MovingStandardDeviation2_L_T *localDW)
{
  /* InitializeConditions for Delay: '<S116>/Delay' */
  localDW->Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay1' */
  localDW->Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay10' */
  localDW->Delay10_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay11' */
  localDW->Delay11_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay12' */
  localDW->Delay12_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay13' */
  localDW->Delay13_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay14' */
  localDW->Delay14_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay15' */
  localDW->Delay15_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay16' */
  localDW->Delay16_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay17' */
  localDW->Delay17_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay18' */
  localDW->Delay18_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay19' */
  localDW->Delay19_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay2' */
  localDW->Delay2_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay20' */
  localDW->Delay20_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay21' */
  localDW->Delay21_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay22' */
  localDW->Delay22_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay23' */
  localDW->Delay23_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay24' */
  localDW->Delay24_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay25' */
  localDW->Delay25_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay26' */
  localDW->Delay26_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay27' */
  localDW->Delay27_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay28' */
  localDW->Delay28_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay29' */
  localDW->Delay29_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay3' */
  localDW->Delay3_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay30' */
  localDW->Delay30_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay31' */
  localDW->Delay31_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay32' */
  localDW->Delay32_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay33' */
  localDW->Delay33_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay34' */
  localDW->Delay34_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay35' */
  localDW->Delay35_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay36' */
  localDW->Delay36_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay37' */
  localDW->Delay37_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay38' */
  localDW->Delay38_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay39' */
  localDW->Delay39_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay4' */
  localDW->Delay4_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay40' */
  localDW->Delay40_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay41' */
  localDW->Delay41_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay42' */
  localDW->Delay42_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay43' */
  localDW->Delay43_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay44' */
  localDW->Delay44_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay45' */
  localDW->Delay45_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay46' */
  localDW->Delay46_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay47' */
  localDW->Delay47_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay48' */
  localDW->Delay48_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay5' */
  localDW->Delay5_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay6' */
  localDW->Delay6_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay7' */
  localDW->Delay7_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay8' */
  localDW->Delay8_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S116>/Delay9' */
  localDW->Delay9_DSTATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S108>/Moving Standard Deviation2'
 *    '<S120>/Moving Standard Deviation1'
 *    '<S120>/Moving Standard Deviation2'
 */
float32 LKAS_MovingStandardDeviation2(float32 rtu_In1,
  DW_MovingStandardDeviation2_L_T *localDW)
{
  /* local block i/o variables */
  float32 rtb_Delay_c;
  float32 rtb_Delay1;
  float32 rtb_Delay10;
  float32 rtb_Delay11;
  float32 rtb_Delay12;
  float32 rtb_Delay13;
  float32 rtb_Delay14;
  float32 rtb_Delay15;
  float32 rtb_Delay16;
  float32 rtb_Delay17;
  float32 rtb_Delay18;
  float32 rtb_Delay19;
  float32 rtb_Delay2;
  float32 rtb_Delay20;
  float32 rtb_Delay21;
  float32 rtb_Delay22;
  float32 rtb_Delay23;
  float32 rtb_Delay24;
  float32 rtb_Delay25;
  float32 rtb_Delay26;
  float32 rtb_Delay27;
  float32 rtb_Delay29;
  float32 rtb_Delay3;
  float32 rtb_Delay30;
  float32 rtb_Delay31;
  float32 rtb_Delay32;
  float32 rtb_Delay33;
  float32 rtb_Delay34;
  float32 rtb_Delay35;
  float32 rtb_Delay36;
  float32 rtb_Delay37;
  float32 rtb_Delay39;
  float32 rtb_Delay4;
  float32 rtb_Delay40;
  float32 rtb_Delay41;
  float32 rtb_Delay42;
  float32 rtb_Delay43;
  float32 rtb_Delay44;
  float32 rtb_Delay45;
  float32 rtb_Delay46;
  float32 rtb_Delay5;
  float32 rtb_Delay6;
  float32 rtb_Delay7;
  float32 rtb_Delay8;
  float32 rtb_Delay47;
  float32 rty_Out1_0;
  sint32 j;
  sint32 n;
  sint32 str;
  sint32 jtmp;
  float32 rtb_TmpSignalConversionAtStanda[50];

  /* Delay: '<S116>/Delay' */
  rtb_Delay_c = localDW->Delay_DSTATE;

  /* Delay: '<S116>/Delay1' */
  rtb_Delay1 = localDW->Delay1_DSTATE;

  /* Delay: '<S116>/Delay10' */
  rtb_Delay10 = localDW->Delay10_DSTATE;

  /* Delay: '<S116>/Delay11' */
  rtb_Delay11 = localDW->Delay11_DSTATE;

  /* Delay: '<S116>/Delay12' */
  rtb_Delay12 = localDW->Delay12_DSTATE;

  /* Delay: '<S116>/Delay13' */
  rtb_Delay13 = localDW->Delay13_DSTATE;

  /* Delay: '<S116>/Delay14' */
  rtb_Delay14 = localDW->Delay14_DSTATE;

  /* Delay: '<S116>/Delay15' */
  rtb_Delay15 = localDW->Delay15_DSTATE;

  /* Delay: '<S116>/Delay16' */
  rtb_Delay16 = localDW->Delay16_DSTATE;

  /* Delay: '<S116>/Delay17' */
  rtb_Delay17 = localDW->Delay17_DSTATE;

  /* Delay: '<S116>/Delay18' */
  rtb_Delay18 = localDW->Delay18_DSTATE;

  /* Delay: '<S116>/Delay19' */
  rtb_Delay19 = localDW->Delay19_DSTATE;

  /* Delay: '<S116>/Delay2' */
  rtb_Delay2 = localDW->Delay2_DSTATE;

  /* Delay: '<S116>/Delay20' */
  rtb_Delay20 = localDW->Delay20_DSTATE;

  /* Delay: '<S116>/Delay21' */
  rtb_Delay21 = localDW->Delay21_DSTATE;

  /* Delay: '<S116>/Delay22' */
  rtb_Delay22 = localDW->Delay22_DSTATE;

  /* Delay: '<S116>/Delay23' */
  rtb_Delay23 = localDW->Delay23_DSTATE;

  /* Delay: '<S116>/Delay24' */
  rtb_Delay24 = localDW->Delay24_DSTATE;

  /* Delay: '<S116>/Delay25' */
  rtb_Delay25 = localDW->Delay25_DSTATE;

  /* Delay: '<S116>/Delay26' */
  rtb_Delay26 = localDW->Delay26_DSTATE;

  /* Delay: '<S116>/Delay27' */
  rtb_Delay27 = localDW->Delay27_DSTATE;

  /* Delay: '<S116>/Delay28' incorporates:
   *  Delay: '<S116>/Delay19'
   */
  localDW->Delay19_DSTATE = localDW->Delay28_DSTATE;

  /* Delay: '<S116>/Delay29' */
  rtb_Delay29 = localDW->Delay29_DSTATE;

  /* Delay: '<S116>/Delay3' */
  rtb_Delay3 = localDW->Delay3_DSTATE;

  /* Delay: '<S116>/Delay30' */
  rtb_Delay30 = localDW->Delay30_DSTATE;

  /* Delay: '<S116>/Delay31' */
  rtb_Delay31 = localDW->Delay31_DSTATE;

  /* Delay: '<S116>/Delay32' */
  rtb_Delay32 = localDW->Delay32_DSTATE;

  /* Delay: '<S116>/Delay33' */
  rtb_Delay33 = localDW->Delay33_DSTATE;

  /* Delay: '<S116>/Delay34' */
  rtb_Delay34 = localDW->Delay34_DSTATE;

  /* Delay: '<S116>/Delay35' */
  rtb_Delay35 = localDW->Delay35_DSTATE;

  /* Delay: '<S116>/Delay36' */
  rtb_Delay36 = localDW->Delay36_DSTATE;

  /* Delay: '<S116>/Delay37' */
  rtb_Delay37 = localDW->Delay37_DSTATE;

  /* Delay: '<S116>/Delay38' incorporates:
   *  Delay: '<S116>/Delay29'
   */
  localDW->Delay29_DSTATE = localDW->Delay38_DSTATE;

  /* Delay: '<S116>/Delay39' */
  rtb_Delay39 = localDW->Delay39_DSTATE;

  /* Delay: '<S116>/Delay4' */
  rtb_Delay4 = localDW->Delay4_DSTATE;

  /* Delay: '<S116>/Delay40' */
  rtb_Delay40 = localDW->Delay40_DSTATE;

  /* Delay: '<S116>/Delay41' */
  rtb_Delay41 = localDW->Delay41_DSTATE;

  /* Delay: '<S116>/Delay42' */
  rtb_Delay42 = localDW->Delay42_DSTATE;

  /* Delay: '<S116>/Delay43' */
  rtb_Delay43 = localDW->Delay43_DSTATE;

  /* Delay: '<S116>/Delay44' */
  rtb_Delay44 = localDW->Delay44_DSTATE;

  /* Delay: '<S116>/Delay45' */
  rtb_Delay45 = localDW->Delay45_DSTATE;

  /* Delay: '<S116>/Delay46' */
  rtb_Delay46 = localDW->Delay46_DSTATE;

  /* Delay: '<S116>/Delay47' */
  rtb_Delay47 = localDW->Delay47_DSTATE;

  /* Delay: '<S116>/Delay48' incorporates:
   *  Delay: '<S116>/Delay39'
   */
  localDW->Delay39_DSTATE = localDW->Delay48_DSTATE;

  /* Delay: '<S116>/Delay5' */
  rtb_Delay5 = localDW->Delay5_DSTATE;

  /* Delay: '<S116>/Delay6' */
  rtb_Delay6 = localDW->Delay6_DSTATE;

  /* Delay: '<S116>/Delay7' */
  rtb_Delay7 = localDW->Delay7_DSTATE;

  /* Delay: '<S116>/Delay8' */
  rtb_Delay8 = localDW->Delay8_DSTATE;

  /* Delay: '<S116>/Delay9' incorporates:
   *  Delay: '<S116>/Delay10'
   */
  localDW->Delay10_DSTATE = localDW->Delay9_DSTATE;

  /* SignalConversion: '<S116>/TmpSignal ConversionAtStandard DeviationInport1' incorporates:
   *  Delay: '<S116>/Delay10'
   *  Delay: '<S116>/Delay19'
   *  Delay: '<S116>/Delay29'
   *  Delay: '<S116>/Delay39'
   */
  rtb_TmpSignalConversionAtStanda[0] = rtu_In1;
  rtb_TmpSignalConversionAtStanda[1] = rtb_Delay_c;
  rtb_TmpSignalConversionAtStanda[2] = rtb_Delay1;
  rtb_TmpSignalConversionAtStanda[3] = rtb_Delay2;
  rtb_TmpSignalConversionAtStanda[4] = rtb_Delay3;
  rtb_TmpSignalConversionAtStanda[5] = rtb_Delay4;
  rtb_TmpSignalConversionAtStanda[6] = rtb_Delay5;
  rtb_TmpSignalConversionAtStanda[7] = rtb_Delay6;
  rtb_TmpSignalConversionAtStanda[8] = rtb_Delay7;
  rtb_TmpSignalConversionAtStanda[9] = rtb_Delay8;
  rtb_TmpSignalConversionAtStanda[10] = localDW->Delay10_DSTATE;
  rtb_TmpSignalConversionAtStanda[11] = rtb_Delay10;
  rtb_TmpSignalConversionAtStanda[12] = rtb_Delay11;
  rtb_TmpSignalConversionAtStanda[13] = rtb_Delay12;
  rtb_TmpSignalConversionAtStanda[14] = rtb_Delay13;
  rtb_TmpSignalConversionAtStanda[15] = rtb_Delay14;
  rtb_TmpSignalConversionAtStanda[16] = rtb_Delay15;
  rtb_TmpSignalConversionAtStanda[17] = rtb_Delay16;
  rtb_TmpSignalConversionAtStanda[18] = rtb_Delay17;
  rtb_TmpSignalConversionAtStanda[19] = rtb_Delay18;
  rtb_TmpSignalConversionAtStanda[20] = localDW->Delay19_DSTATE;
  rtb_TmpSignalConversionAtStanda[21] = rtb_Delay19;
  rtb_TmpSignalConversionAtStanda[22] = rtb_Delay20;
  rtb_TmpSignalConversionAtStanda[23] = rtb_Delay21;
  rtb_TmpSignalConversionAtStanda[24] = rtb_Delay22;
  rtb_TmpSignalConversionAtStanda[25] = rtb_Delay23;
  rtb_TmpSignalConversionAtStanda[26] = rtb_Delay24;
  rtb_TmpSignalConversionAtStanda[27] = rtb_Delay25;
  rtb_TmpSignalConversionAtStanda[28] = rtb_Delay26;
  rtb_TmpSignalConversionAtStanda[29] = rtb_Delay27;
  rtb_TmpSignalConversionAtStanda[30] = localDW->Delay29_DSTATE;
  rtb_TmpSignalConversionAtStanda[31] = rtb_Delay29;
  rtb_TmpSignalConversionAtStanda[32] = rtb_Delay30;
  rtb_TmpSignalConversionAtStanda[33] = rtb_Delay31;
  rtb_TmpSignalConversionAtStanda[34] = rtb_Delay32;
  rtb_TmpSignalConversionAtStanda[35] = rtb_Delay33;
  rtb_TmpSignalConversionAtStanda[36] = rtb_Delay34;
  rtb_TmpSignalConversionAtStanda[37] = rtb_Delay35;
  rtb_TmpSignalConversionAtStanda[38] = rtb_Delay36;
  rtb_TmpSignalConversionAtStanda[39] = rtb_Delay37;
  rtb_TmpSignalConversionAtStanda[40] = localDW->Delay39_DSTATE;
  rtb_TmpSignalConversionAtStanda[41] = rtb_Delay39;
  rtb_TmpSignalConversionAtStanda[42] = rtb_Delay40;
  rtb_TmpSignalConversionAtStanda[43] = rtb_Delay41;
  rtb_TmpSignalConversionAtStanda[44] = rtb_Delay42;
  rtb_TmpSignalConversionAtStanda[45] = rtb_Delay43;
  rtb_TmpSignalConversionAtStanda[46] = rtb_Delay44;
  rtb_TmpSignalConversionAtStanda[47] = rtb_Delay45;
  rtb_TmpSignalConversionAtStanda[48] = rtb_Delay46;
  rtb_TmpSignalConversionAtStanda[49] = rtb_Delay47;

  /* S-Function (sdspstatfcns): '<S116>/Standard Deviation' */
  for (j = 0; j < 1; j++) {
    localDW->StandardDeviation_AccVal = rtb_TmpSignalConversionAtStanda[j];
    localDW->StandardDeviation_SqData = rtb_TmpSignalConversionAtStanda[j] *
      rtb_TmpSignalConversionAtStanda[j];
    str = 1;
    for (n = 48; n >= 0; n--) {
      jtmp = j + str;
      localDW->StandardDeviation_AccVal += rtb_TmpSignalConversionAtStanda[jtmp];
      localDW->StandardDeviation_SqData += rtb_TmpSignalConversionAtStanda[jtmp]
        * rtb_TmpSignalConversionAtStanda[jtmp];
      str++;
    }

    rty_Out1_0 = sqrtf(fabsf((localDW->StandardDeviation_SqData -
      localDW->StandardDeviation_AccVal * localDW->StandardDeviation_AccVal /
      50.0F) / 49.0F));
  }

  /* End of S-Function (sdspstatfcns): '<S116>/Standard Deviation' */

  /* Update for Delay: '<S116>/Delay' */
  localDW->Delay_DSTATE = rtu_In1;

  /* Update for Delay: '<S116>/Delay1' */
  localDW->Delay1_DSTATE = rtb_Delay_c;

  /* Update for Delay: '<S116>/Delay11' */
  localDW->Delay11_DSTATE = rtb_Delay10;

  /* Update for Delay: '<S116>/Delay12' */
  localDW->Delay12_DSTATE = rtb_Delay11;

  /* Update for Delay: '<S116>/Delay13' */
  localDW->Delay13_DSTATE = rtb_Delay12;

  /* Update for Delay: '<S116>/Delay14' */
  localDW->Delay14_DSTATE = rtb_Delay13;

  /* Update for Delay: '<S116>/Delay15' */
  localDW->Delay15_DSTATE = rtb_Delay14;

  /* Update for Delay: '<S116>/Delay16' */
  localDW->Delay16_DSTATE = rtb_Delay15;

  /* Update for Delay: '<S116>/Delay17' */
  localDW->Delay17_DSTATE = rtb_Delay16;

  /* Update for Delay: '<S116>/Delay18' */
  localDW->Delay18_DSTATE = rtb_Delay17;

  /* Update for Delay: '<S116>/Delay2' */
  localDW->Delay2_DSTATE = rtb_Delay1;

  /* Update for Delay: '<S116>/Delay20' */
  localDW->Delay20_DSTATE = rtb_Delay19;

  /* Update for Delay: '<S116>/Delay21' */
  localDW->Delay21_DSTATE = rtb_Delay20;

  /* Update for Delay: '<S116>/Delay22' */
  localDW->Delay22_DSTATE = rtb_Delay21;

  /* Update for Delay: '<S116>/Delay23' */
  localDW->Delay23_DSTATE = rtb_Delay22;

  /* Update for Delay: '<S116>/Delay24' */
  localDW->Delay24_DSTATE = rtb_Delay23;

  /* Update for Delay: '<S116>/Delay25' */
  localDW->Delay25_DSTATE = rtb_Delay24;

  /* Update for Delay: '<S116>/Delay26' */
  localDW->Delay26_DSTATE = rtb_Delay25;

  /* Update for Delay: '<S116>/Delay27' */
  localDW->Delay27_DSTATE = rtb_Delay26;

  /* Update for Delay: '<S116>/Delay28' */
  localDW->Delay28_DSTATE = rtb_Delay18;

  /* Update for Delay: '<S116>/Delay3' */
  localDW->Delay3_DSTATE = rtb_Delay2;

  /* Update for Delay: '<S116>/Delay30' */
  localDW->Delay30_DSTATE = rtb_Delay29;

  /* Update for Delay: '<S116>/Delay31' */
  localDW->Delay31_DSTATE = rtb_Delay30;

  /* Update for Delay: '<S116>/Delay32' */
  localDW->Delay32_DSTATE = rtb_Delay31;

  /* Update for Delay: '<S116>/Delay33' */
  localDW->Delay33_DSTATE = rtb_Delay32;

  /* Update for Delay: '<S116>/Delay34' */
  localDW->Delay34_DSTATE = rtb_Delay33;

  /* Update for Delay: '<S116>/Delay35' */
  localDW->Delay35_DSTATE = rtb_Delay34;

  /* Update for Delay: '<S116>/Delay36' */
  localDW->Delay36_DSTATE = rtb_Delay35;

  /* Update for Delay: '<S116>/Delay37' */
  localDW->Delay37_DSTATE = rtb_Delay36;

  /* Update for Delay: '<S116>/Delay38' */
  localDW->Delay38_DSTATE = rtb_Delay27;

  /* Update for Delay: '<S116>/Delay4' */
  localDW->Delay4_DSTATE = rtb_Delay3;

  /* Update for Delay: '<S116>/Delay40' */
  localDW->Delay40_DSTATE = rtb_Delay39;

  /* Update for Delay: '<S116>/Delay41' */
  localDW->Delay41_DSTATE = rtb_Delay40;

  /* Update for Delay: '<S116>/Delay42' */
  localDW->Delay42_DSTATE = rtb_Delay41;

  /* Update for Delay: '<S116>/Delay43' */
  localDW->Delay43_DSTATE = rtb_Delay42;

  /* Update for Delay: '<S116>/Delay44' */
  localDW->Delay44_DSTATE = rtb_Delay43;

  /* Update for Delay: '<S116>/Delay45' */
  localDW->Delay45_DSTATE = rtb_Delay44;

  /* Update for Delay: '<S116>/Delay46' */
  localDW->Delay46_DSTATE = rtb_Delay45;

  /* Update for Delay: '<S116>/Delay47' */
  localDW->Delay47_DSTATE = rtb_Delay46;

  /* Update for Delay: '<S116>/Delay48' */
  localDW->Delay48_DSTATE = rtb_Delay37;

  /* Update for Delay: '<S116>/Delay5' */
  localDW->Delay5_DSTATE = rtb_Delay4;

  /* Update for Delay: '<S116>/Delay6' */
  localDW->Delay6_DSTATE = rtb_Delay5;

  /* Update for Delay: '<S116>/Delay7' */
  localDW->Delay7_DSTATE = rtb_Delay6;

  /* Update for Delay: '<S116>/Delay8' */
  localDW->Delay8_DSTATE = rtb_Delay7;

  /* Update for Delay: '<S116>/Delay9' */
  localDW->Delay9_DSTATE = rtb_Delay8;
  return rty_Out1_0;
}

/*
 * System initialize for enable system:
 *    '<S120>/Sum Condition'
 *    '<S120>/Sum Condition1'
 */
void LKAS_SumCondition_Init(DW_SumCondition_LKAS_T *localDW)
{
  /* InitializeConditions for Memory: '<S124>/Memory' */
  localDW->Memory_PreviousInput = 0.0F;
}

/*
 * System reset for enable system:
 *    '<S120>/Sum Condition'
 *    '<S120>/Sum Condition1'
 */
void LKAS_SumCondition_Reset(DW_SumCondition_LKAS_T *localDW)
{
  /* InitializeConditions for Memory: '<S124>/Memory' */
  localDW->Memory_PreviousInput = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S120>/Sum Condition'
 *    '<S120>/Sum Condition1'
 */
void LKAS_SumCondition_Disable(uint16 *rty_Out, DW_SumCondition_LKAS_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S120>/Sum Condition' incorporates:
   *  EnablePort: '<S124>/Enable'
   */
  /* Disable for Outport: '<S124>/Out' */
  *rty_Out = ((uint16)0U);

  /* End of Outputs for SubSystem: '<S120>/Sum Condition' */
  localDW->SumCondition_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S120>/Sum Condition'
 *    '<S120>/Sum Condition1'
 */
void LKAS_SumCondition(boolean rtu_In, float32 rtu_In1, uint16 *rty_Out,
  DW_SumCondition_LKAS_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S120>/Sum Condition' incorporates:
   *  EnablePort: '<S124>/Enable'
   */
  if (rtu_In) {
    if (!localDW->SumCondition_MODE) {
      LKAS_SumCondition_Reset(localDW);
      localDW->SumCondition_MODE = true;
    }

    /* Saturate: '<S124>/Saturation' incorporates:
     *  Memory: '<S124>/Memory'
     *  Sum: '<S124>/Add1'
     */
    if (1.0F + localDW->Memory_PreviousInput > 100000.0F) {
      localDW->Memory_PreviousInput = 100000.0F;
    } else if (1.0F + localDW->Memory_PreviousInput < 0.0F) {
      localDW->Memory_PreviousInput = 0.0F;
    } else {
      localDW->Memory_PreviousInput++;
    }

    /* End of Saturate: '<S124>/Saturation' */

    /* DataTypeConversion: '<S124>/Data Type Conversion' incorporates:
     *  RelationalOperator: '<S124>/Relational Operator'
     */
    *rty_Out = (uint16)(localDW->Memory_PreviousInput >= rtu_In1);
  } else {
    if (localDW->SumCondition_MODE) {
      LKAS_SumCondition_Disable(rty_Out, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S120>/Sum Condition' */
}

/*
 * Output and update for action system:
 *    '<S133>/if action 3'
 *    '<S134>/if action 3'
 *    '<S135>/if action 3'
 *    '<S136>/if action 3'
 *    '<S147>/If Action Subsystem2'
 *    '<S147>/If Action Subsystem1'
 *    '<S231>/If Action Subsystem2'
 *    '<S231>/If Action Subsystem1'
 *    '<S232>/If Action Subsystem2'
 *    '<S232>/If Action Subsystem1'
 *    ...
 */
void LKAS_ifaction3(float32 rtu_In1, float32 *rty_Out1)
{
  /* Inport: '<S139>/In1' */
  *rty_Out1 = rtu_In1;
}

/* System initialize for action system: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' */
void LKAMotionPlanningCalculati_Init(void)
{
  /* InitializeConditions for Memory: '<S132>/Memory' */
  LKAS_DW.Memory_PreviousInput_lp = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory' */
  LKAS_DW.Memory_PreviousInput_j = ((uint16)0U);

  /* InitializeConditions for Memory: '<S133>/Memory' */
  LKAS_DW.Memory_PreviousInput_gf = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory1' */
  LKAS_DW.Memory1_PreviousInput = 0.0F;

  /* InitializeConditions for Memory: '<S134>/Memory' */
  LKAS_DW.Memory_PreviousInput_n5 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory2' */
  LKAS_DW.Memory2_PreviousInput = 0.0F;

  /* InitializeConditions for Memory: '<S135>/Memory' */
  LKAS_DW.Memory_PreviousInput_bj = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_a = 0.0F;

  /* InitializeConditions for Memory: '<S136>/Memory' */
  LKAS_DW.Memory_PreviousInput_e3 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory4' */
  LKAS_DW.Memory4_PreviousInput = 0.0F;
}

/* System reset for action system: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' */
void LKAMotionPlanningCalculat_Reset(void)
{
  /* InitializeConditions for Memory: '<S132>/Memory' */
  LKAS_DW.Memory_PreviousInput_lp = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory' */
  LKAS_DW.Memory_PreviousInput_j = ((uint16)0U);

  /* InitializeConditions for Memory: '<S133>/Memory' */
  LKAS_DW.Memory_PreviousInput_gf = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory1' */
  LKAS_DW.Memory1_PreviousInput = 0.0F;

  /* InitializeConditions for Memory: '<S134>/Memory' */
  LKAS_DW.Memory_PreviousInput_n5 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory2' */
  LKAS_DW.Memory2_PreviousInput = 0.0F;

  /* InitializeConditions for Memory: '<S135>/Memory' */
  LKAS_DW.Memory_PreviousInput_bj = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_a = 0.0F;

  /* InitializeConditions for Memory: '<S136>/Memory' */
  LKAS_DW.Memory_PreviousInput_e3 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S126>/Memory4' */
  LKAS_DW.Memory4_PreviousInput = 0.0F;
}

/*
 * Output and update for action system: '<S102>/LKA Motion Planning Calculation (LKAMPCal)'
 * Block description for: '<S102>/LKA Motion Planning Calculation (LKAMPCal)'
 *   Block Name: LKA Motion Planning Calculation
 *   Ab.: LKAMPCal
 *   No.: 1.2.3.2
 *   Rev: 0.0.1
 *   Update Date: 19-3-26
 */
void LKAMotionPlanningCalculationLKA(void)
{
  /* local block i/o variables */
  float32 rtb_Memory1;
  float32 rtb_Memory2;
  float32 rtb_Memory3;
  float32 rtb_Memory4;
  float32 rtb_Merge1;
  float32 rtb_Merge1_h;
  float32 rtb_Merge1_g;
  float32 rtb_Merge1_i;
  float32 rtb_K1K2Det_dphi2PhSWAGrad2;
  float32 rtb_K1K2Det_stReplFlag;
  float32 rtb_K1K2Det_dphi1PhHdAgIni;
  float32 DelteSW0;
  float32 u;
  float32 Kw;
  float32 StpLngth;
  float32 K1;
  float32 K2_2;
  float32 T1;
  float32 T2;
  sint32 a;
  float32 Delte_Psi;
  float32 K2;
  float32 c_T1;
  float32 c_T2;
  uint16 rtb_Add_0;

  /* Sum: '<S132>/Add' incorporates:
   *  Constant: '<S132>/Constant'
   *  Memory: '<S132>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_lp = (uint16)((uint32)((uint16)1U) +
    LKAS_DW.Memory_PreviousInput_lp);

  /* Saturate: '<S132>/Saturation1' */
  if (LKAS_DW.Memory_PreviousInput_lp < ((uint16)100U)) {
    rtb_Add_0 = LKAS_DW.Memory_PreviousInput_lp;
  } else {
    rtb_Add_0 = ((uint16)100U);
  }

  /* End of Saturate: '<S132>/Saturation1' */

  /* If: '<S132>/If' incorporates:
   *  Constant: '<S132>/Constant19'
   */
  if (rtb_Add_0 == ((uint16)1U)) {
    /* Outputs for IfAction SubSystem: '<S132>/if action 2' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    /* SignalConversion: '<S138>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
     *  Constant: '<S138>/Constant'
     */
    LKAS_DW.Memory_PreviousInput_j = ((uint16)0U);

    /* End of Outputs for SubSystem: '<S132>/if action 2' */
  }

  /* End of If: '<S132>/If' */

  /* Sum: '<S133>/Add' incorporates:
   *  Constant: '<S133>/Constant'
   *  Memory: '<S133>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_gf = (uint16)((uint32)((uint16)1U) +
    LKAS_DW.Memory_PreviousInput_gf);

  /* Memory: '<S126>/Memory1' */
  rtb_Memory1 = LKAS_DW.Memory1_PreviousInput;

  /* Saturate: '<S133>/Saturation1' */
  if (LKAS_DW.Memory_PreviousInput_gf < ((uint16)100U)) {
    rtb_Add_0 = LKAS_DW.Memory_PreviousInput_gf;
  } else {
    rtb_Add_0 = ((uint16)100U);
  }

  /* End of Saturate: '<S133>/Saturation1' */

  /* If: '<S133>/If' incorporates:
   *  Constant: '<S133>/Constant19'
   */
  if (rtb_Add_0 == ((uint16)1U)) {
    /* Outputs for IfAction SubSystem: '<S133>/if action 4' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    LKAS_IfActionSubsystem2(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S133>/if action 4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S133>/if action 3' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    LKAS_ifaction3(rtb_Memory1, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S133>/if action 3' */
  }

  /* End of If: '<S133>/If' */

  /* Sum: '<S134>/Add' incorporates:
   *  Constant: '<S134>/Constant'
   *  Memory: '<S134>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_n5 = (uint16)((uint32)((uint16)1U) +
    LKAS_DW.Memory_PreviousInput_n5);

  /* Memory: '<S126>/Memory2' */
  rtb_Memory2 = LKAS_DW.Memory2_PreviousInput;

  /* Saturate: '<S134>/Saturation1' */
  if (LKAS_DW.Memory_PreviousInput_n5 < ((uint16)100U)) {
    rtb_Add_0 = LKAS_DW.Memory_PreviousInput_n5;
  } else {
    rtb_Add_0 = ((uint16)100U);
  }

  /* End of Saturate: '<S134>/Saturation1' */

  /* If: '<S134>/If' incorporates:
   *  Constant: '<S134>/Constant19'
   */
  if (rtb_Add_0 == ((uint16)1U)) {
    /* Outputs for IfAction SubSystem: '<S134>/if action 4' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    LKAS_IfActionSubsystem2(&rtb_Merge1_h);

    /* End of Outputs for SubSystem: '<S134>/if action 4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S134>/if action 3' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    LKAS_ifaction3(rtb_Memory2, &rtb_Merge1_h);

    /* End of Outputs for SubSystem: '<S134>/if action 3' */
  }

  /* End of If: '<S134>/If' */

  /* Sum: '<S135>/Add' incorporates:
   *  Constant: '<S135>/Constant'
   *  Memory: '<S135>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_bj = (uint16)((uint32)((uint16)1U) +
    LKAS_DW.Memory_PreviousInput_bj);

  /* Memory: '<S126>/Memory3' */
  rtb_Memory3 = LKAS_DW.Memory3_PreviousInput_a;

  /* Saturate: '<S135>/Saturation1' */
  if (LKAS_DW.Memory_PreviousInput_bj < ((uint16)100U)) {
    rtb_Add_0 = LKAS_DW.Memory_PreviousInput_bj;
  } else {
    rtb_Add_0 = ((uint16)100U);
  }

  /* End of Saturate: '<S135>/Saturation1' */

  /* If: '<S135>/If' incorporates:
   *  Constant: '<S135>/Constant19'
   */
  if (rtb_Add_0 == ((uint16)1U)) {
    /* Outputs for IfAction SubSystem: '<S135>/if action 4' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    LKAS_IfActionSubsystem2(&rtb_Merge1_g);

    /* End of Outputs for SubSystem: '<S135>/if action 4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S135>/if action 3' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    LKAS_ifaction3(rtb_Memory3, &rtb_Merge1_g);

    /* End of Outputs for SubSystem: '<S135>/if action 3' */
  }

  /* End of If: '<S135>/If' */

  /* Sum: '<S136>/Add' incorporates:
   *  Constant: '<S136>/Constant'
   *  Memory: '<S136>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_e3 = (uint16)((uint32)((uint16)1U) +
    LKAS_DW.Memory_PreviousInput_e3);

  /* Memory: '<S126>/Memory4' */
  rtb_Memory4 = LKAS_DW.Memory4_PreviousInput;

  /* Saturate: '<S136>/Saturation1' */
  if (LKAS_DW.Memory_PreviousInput_e3 < ((uint16)100U)) {
    rtb_Add_0 = LKAS_DW.Memory_PreviousInput_e3;
  } else {
    rtb_Add_0 = ((uint16)100U);
  }

  /* End of Saturate: '<S136>/Saturation1' */

  /* If: '<S136>/If' incorporates:
   *  Constant: '<S136>/Constant19'
   */
  if (rtb_Add_0 == ((uint16)1U)) {
    /* Outputs for IfAction SubSystem: '<S136>/if action 4' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    LKAS_IfActionSubsystem2(&rtb_Merge1_i);

    /* End of Outputs for SubSystem: '<S136>/if action 4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S136>/if action 3' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    LKAS_ifaction3(rtb_Memory4, &rtb_Merge1_i);

    /* End of Outputs for SubSystem: '<S136>/if action 3' */
  }

  /* End of If: '<S136>/If' */

  /* MATLAB Function: '<S126>/MATLAB Function' */
  DelteSW0 = LKAS_B.In_d * 0.0174532924F;
  u = LKAS_B.In_f / 3.6F;
  Kw = u / ((LKAS_B.StbFacm_SY * u * u + 1.0F) * LKAS_B.LKA_WhlBaseL_C_n *
            LKAS_B.LKA_StrRatio_C_h);
  rtb_K1K2Det_stReplFlag = 0.0F;
  StpLngth = LKAS_B.LL_lStpLngth_C_g * 0.0174532924F;
  LKAS_DW.Memory1_PreviousInput = rtb_Merge1;
  LKAS_DW.Memory2_PreviousInput = rtb_Merge1_h;
  LKAS_DW.Memory3_PreviousInput_a = rtb_Merge1_g;
  LKAS_DW.Memory4_PreviousInput = rtb_Merge1_i;
  K1 = 0.0F;
  K2 = 0.0F;
  K2_2 = 0.0F;
  if (LKAS_DW.Memory_PreviousInput_j == 0) {
    K1 = -2.0F * LKAS_B.In_p / (Kw * LKAS_B.MPInP_tiTTLCIni *
      LKAS_B.MPInP_tiTTLCIni) - 2.0F * DelteSW0 / LKAS_B.MPInP_tiTTLCIni;
    LKAS_DW.Memory4_PreviousInput = K1 * LKAS_B.MPInP_tiTTLCIni + DelteSW0;
    Delte_Psi = (DelteSW0 + LKAS_DW.Memory4_PreviousInput) * 0.5F *
      LKAS_B.MPInP_tiTTLCIni * Kw + LKAS_B.In_ni;
    K2 = -LKAS_DW.Memory4_PreviousInput * LKAS_DW.Memory4_PreviousInput * Kw /
      ((LKAS_B.In_a - Delte_Psi) * 2.0F);
    c_T1 = (LKAS_DW.Memory4_PreviousInput - DelteSW0) / K1;
    c_T2 = (0.0F - LKAS_DW.Memory4_PreviousInput) / K2;
    K2_2 = K2;
    LKAS_DW.Memory3_PreviousInput_a = ((2.0F * DelteSW0 +
      LKAS_DW.Memory4_PreviousInput) * (0.166666672F * Kw) * c_T1 * c_T1 +
      LKAS_B.In_ni * c_T1) * u + (0.333333343F * Kw * c_T2 * c_T2 *
      LKAS_DW.Memory4_PreviousInput + Delte_Psi * c_T2) * u;
  }

  Delte_Psi = LKAS_DW.Memory3_PreviousInput_a * LKAS_B.Merge;
  if ((0.0F < Delte_Psi) && (Delte_Psi <= LKAS_B.LL_DesDvt_C_f) &&
      (LKAS_DW.Memory_PreviousInput_j == 0)) {
    rtb_K1K2Det_stReplFlag = 0.0F;
  } else {
    if ((Delte_Psi > LKAS_B.LL_DesDvt_C_f) || (LKAS_DW.Memory_PreviousInput_j !=
         0)) {
      rtb_K1K2Det_stReplFlag = 1.0F;
      for (a = 0; a < 8; a++) {
        Delte_Psi = LKAS_DW.Memory3_PreviousInput_a * LKAS_B.Merge;
        if ((Delte_Psi > LKAS_B.LL_DesDvt_C_f) &&
            (LKAS_DW.Memory_PreviousInput_j == 0)) {
          LKAS_DW.Memory_PreviousInput_j = 1U;
        }

        if ((Delte_Psi > LKAS_B.LL_DesDvt_C_f) &&
            (LKAS_DW.Memory_PreviousInput_j == 1)) {
          LKAS_DW.Memory4_PreviousInput += LKAS_B.Merge * StpLngth;
          LKAS_DW.Memory1_PreviousInput++;
        }

        if ((Delte_Psi <= LKAS_B.LL_DesDvt_C_f) &&
            (LKAS_DW.Memory_PreviousInput_j == 1)) {
          LKAS_DW.Memory_PreviousInput_j = 2U;
        }

        if ((Delte_Psi < LKAS_B.LL_DesDvt_C_f) &&
            (LKAS_DW.Memory_PreviousInput_j == 2)) {
          LKAS_DW.Memory4_PreviousInput -= LKAS_B.Merge * StpLngth * powf(0.5F,
            LKAS_DW.Memory2_PreviousInput + 1.0F);
          LKAS_DW.Memory2_PreviousInput++;
        }

        if ((Delte_Psi >= LKAS_B.LL_DesDvt_C_f) &&
            (LKAS_DW.Memory_PreviousInput_j == 2)) {
          LKAS_DW.Memory4_PreviousInput += LKAS_B.Merge * StpLngth * powf(0.5F,
            LKAS_DW.Memory2_PreviousInput + 1.0F);
          LKAS_DW.Memory2_PreviousInput++;
        }

        K2_2 = (LKAS_DW.Memory4_PreviousInput * LKAS_DW.Memory4_PreviousInput -
                DelteSW0 * DelteSW0) * Kw / (-2.0F * LKAS_B.In_p);
        if (LKAS_B.Merge * K2_2 > LKAS_B.SWARmax) {
          K2_2 = LKAS_B.Merge * LKAS_B.SWARmax;
        }

        T1 = (LKAS_DW.Memory4_PreviousInput - DelteSW0) / K2_2;
        K2_2 = (DelteSW0 + LKAS_DW.Memory4_PreviousInput) * 0.5F * T1 * Kw +
          LKAS_B.In_ni;
        T2 = (LKAS_B.In_a - K2_2) * 2.0F / (LKAS_DW.Memory4_PreviousInput * Kw);
        LKAS_DW.Memory3_PreviousInput_a = ((2.0F * DelteSW0 +
          LKAS_DW.Memory4_PreviousInput) * (0.166666672F * Kw) * T1 * T1 +
          LKAS_B.In_ni * T1) * u + (0.333333343F * Kw * T2 * T2 *
          LKAS_DW.Memory4_PreviousInput + K2_2 * T2) * u;
      }

      K1 = (LKAS_DW.Memory4_PreviousInput - DelteSW0) / T1;
      K2 = (0.0F - LKAS_DW.Memory4_PreviousInput) / T2;
      K2_2 = K2;
    }
  }

  LKAS_B.K1K2Det_phi2PhSWAIni = LKAS_DW.Memory4_PreviousInput * 57.2957802F;
  LKAS_B.K1K2Det_dphi1PhSWAGrad = K1 * 57.2957802F;
  LKAS_B.K1K2Det_dphi2PhSWAGrad1 = K2 * 57.2957802F;
  rtb_K1K2Det_dphi2PhSWAGrad2 = K2_2 * 57.2957802F;
  rtb_K1K2Det_dphi1PhHdAgIni = LKAS_B.In_p;

  /* End of MATLAB Function: '<S126>/MATLAB Function' */
}

/*
 * Output and update for action system:
 *    '<S149>/if action '
 *    '<S150>/if action '
 *    '<S151>/if action '
 *    '<S152>/if action '
 *    '<S153>/if action '
 *    '<S154>/if action '
 *    '<S173>/if action '
 */
void LKAS_ifaction(float32 rtu_In, float32 *rty_Out)
{
  /* Inport: '<S159>/In' */
  *rty_Out = rtu_In;
}

/*
 * Output and update for action system:
 *    '<S174>/If Action Subsystem'
 *    '<S174>/If Action Subsystem4'
 *    '<S130>/If Action Subsystem1'
 */
void LKAS_IfActionSubsystem(float32 rtu_In1, float32 *rty_Out1)
{
  /* DataTypeConversion: '<S176>/Cast To Single1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S191>/If Action Subsystem'
 *    '<S191>/If Action Subsystem1'
 *    '<S191>/If Action Subsystem2'
 */
void LKAS_IfActionSubsystem_j(float32 rtu_In1, float32 *rty_Out1)
{
  /* Inport: '<S193>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S212>/if action '
 *    '<S213>/if action '
 *    '<S220>/if action '
 *    '<S221>/if action '
 */
void LKAS_ifaction_c(float32 rtu_In, float32 *rty_Out)
{
  /* Inport: '<S214>/In' */
  *rty_Out = rtu_In;
}

/*
 * Output and update for enable system:
 *    '<S205>/If Action Subsystem'
 *    '<S206>/If Action Subsystem'
 */
void LKAS_IfActionSubsystem_g(float32 rtu_Enable, float32 rtu_T1, float32
  rtu_Plan, float32 *rty_T1_1, float32 *rty_Plan_1,
  DW_IfActionSubsystem_LKAS_c_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S205>/If Action Subsystem' incorporates:
   *  EnablePort: '<S210>/Enable'
   */
  if (rtu_Enable > 0.0F) {
    /* Sum: '<S212>/Add' incorporates:
     *  Constant: '<S212>/Constant'
     *  Memory: '<S212>/Memory'
     */
    localDW->Memory_PreviousInput = (uint16)((uint32)((uint16)1U) +
      localDW->Memory_PreviousInput);

    /* Saturate: '<S212>/Saturation1' */
    if (localDW->Memory_PreviousInput >= ((uint16)10000U)) {
      /* Sum: '<S212>/Add' */
      localDW->Memory_PreviousInput = ((uint16)10000U);
    }

    /* End of Saturate: '<S212>/Saturation1' */

    /* If: '<S212>/If' incorporates:
     *  Constant: '<S212>/Constant2'
     */
    if (localDW->Memory_PreviousInput <= ((uint16)1U)) {
      /* Outputs for IfAction SubSystem: '<S212>/if action ' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      LKAS_ifaction_c(rtu_T1, rty_T1_1);

      /* End of Outputs for SubSystem: '<S212>/if action ' */
    }

    /* End of If: '<S212>/If' */

    /* Sum: '<S213>/Add' incorporates:
     *  Constant: '<S213>/Constant'
     *  Memory: '<S213>/Memory'
     */
    localDW->Memory_PreviousInput_m = (uint16)((uint32)((uint16)1U) +
      localDW->Memory_PreviousInput_m);

    /* Saturate: '<S213>/Saturation1' */
    if (localDW->Memory_PreviousInput_m >= ((uint16)10000U)) {
      /* Sum: '<S213>/Add' */
      localDW->Memory_PreviousInput_m = ((uint16)10000U);
    }

    /* End of Saturate: '<S213>/Saturation1' */

    /* If: '<S213>/If' incorporates:
     *  Constant: '<S213>/Constant2'
     */
    if (localDW->Memory_PreviousInput_m == ((uint16)1U)) {
      /* Outputs for IfAction SubSystem: '<S213>/if action ' incorporates:
       *  ActionPort: '<S215>/Action Port'
       */
      LKAS_ifaction_c(rtu_Plan, rty_Plan_1);

      /* End of Outputs for SubSystem: '<S213>/if action ' */
    }

    /* End of If: '<S213>/If' */
  }

  /* End of Outputs for SubSystem: '<S205>/If Action Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S205>/If Action Subsystem2'
 *    '<S206>/If Action Subsystem2'
 */
void LKAS_IfActionSubsystem2_l(float32 rtu_T1, float32 rtu_Plan, float32
  *rty_T1_1, float32 *rty_Plan_1)
{
  /* Inport: '<S211>/T1' */
  *rty_T1_1 = rtu_T1;

  /* Inport: '<S211>/Plan' */
  *rty_Plan_1 = rtu_Plan;
}

/*
 * Output and update for action system:
 *    '<S231>/If Action Subsystem3'
 *    '<S252>/If Action Subsystem3'
 *    '<S253>/If Action Subsystem3'
 *    '<S270>/If Action Subsystem3'
 */
void LKAS_IfActionSubsystem3(float32 rtu_In1, float32 rtu_In2, float32 *rty_Out1)
{
  /* Gain: '<S243>/Gain' incorporates:
   *  Sum: '<S243>/Add'
   */
  *rty_Out1 = (rtu_In1 + rtu_In2) * 0.5F;
}

/*
 * Output and update for atomic system:
 *    '<S236>/MATLAB Function'
 *    '<S237>/MATLAB Function'
 */
void LKAS_MATLABFunction(float32 rtu_u1, float32 rtu_u2, float32 *rty_y)
{
  *rty_y = rtu_u1 * cosf(rtu_u2);
}

/* System reset for atomic system: '<S93>/LDW_State_Machine' */
void LKAS_LDW_State_Machine_Reset(void)
{
  LKAS_DW.is_SysOff_j = LKAS_IN_NO_ACTIVE_CHILD;
  LKAS_DW.is_SysOn_i = LKAS_IN_NO_ACTIVE_CHILD;
  LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
  LKAS_DW.is_active_c27_LKAS = 0U;
  LKAS_DW.is_c27_LKAS = LKAS_IN_NO_ACTIVE_CHILD;
  LKAS_B.LDWSM_stLDWActvFlg = 0U;
  LKAS_B.LDWSM_stLDWState = 0U;
}

/*
 * Output and update for atomic system: '<S93>/LDW_State_Machine'
 * Block description for: '<S93>/LDW_State_Machine'
 *   Block Name: LDW State Machine
 *   Ab.: LDWSM
 *   No.: 1.1.2.0
 *   Rev: 0.0.1
 *   Update Date: 19-3-26
 */
void LKAS_LDW_State_Machine(void)
{
  boolean tmp;

  /* Chart: '<S93>/LDW_State_Machine'
   *
   * Block description for '<S93>/LDW_State_Machine':
   *  Block Name: LDW State Machine
   *  Ab.: LDWSM
   *  No.: 1.1.2.0
   *  Rev: 0.0.1
   *  Update Date: 19-3-26
   */
  if (LKAS_DW.is_active_c27_LKAS == 0U) {
    LKAS_DW.is_active_c27_LKAS = 1U;
    LKAS_DW.is_c27_LKAS = LKAS_IN_SysOff;
    LKAS_DW.is_SysOff_j = LKAS_IN_Unavailable;
    LKAS_B.LDWSM_stLDWState = 0U;
  } else {
    switch (LKAS_DW.is_c27_LKAS) {
     case LKAS_IN_Fault:
      tmp = !LKAS_B.LKA_Fault;
      if (tmp && ((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode ==
            2))) {
        LKAS_DW.is_c27_LKAS = LKAS_IN_SysOn;
        LKAS_DW.is_SysOn_i = LKAS_IN_LDWSelected;
        LKAS_B.LDWSM_stLDWState = 2U;
      } else if ((LKAS_B.IMAPve_d_LKA_Mode == 0) && tmp) {
        LKAS_DW.is_c27_LKAS = LKAS_IN_SysOff;
        LKAS_DW.is_SysOff_j = LKAS_IN_Unselected;
        LKAS_B.LDWSM_stLDWState = 1U;
      } else {
        LKAS_B.LDWSM_stLDWState = 6U;
      }
      break;

     case LKAS_IN_SysOff:
      if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode == 2)) &&
          LKAS_B.LKA_Fault) {
        LKAS_DW.is_SysOff_j = LKAS_IN_NO_ACTIVE_CHILD;
        LKAS_DW.is_c27_LKAS = LKAS_IN_Fault;
        LKAS_B.LDWSM_stLDWState = 6U;
      } else if ((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode ==
                  2)) {
        LKAS_DW.is_SysOff_j = LKAS_IN_NO_ACTIVE_CHILD;
        LKAS_DW.is_c27_LKAS = LKAS_IN_SysOn;
        LKAS_DW.is_SysOn_i = LKAS_IN_LDWSelected;
        LKAS_B.LDWSM_stLDWState = 2U;
      } else if (LKAS_DW.is_SysOff_j == LKAS_IN_Unavailable) {
        LKAS_B.LDWSM_stLDWState = 0U;
        if (LKAS_B.IMAPve_d_LKA_Mode == 0) {
          LKAS_DW.is_SysOff_j = LKAS_IN_Unselected;
          LKAS_B.LDWSM_stLDWState = 1U;
        }
      } else {
        LKAS_B.LDWSM_stLDWState = 1U;
      }
      break;

     default:
      if (LKAS_B.LKA_Fault) {
        if (LKAS_DW.is_SysOn_i == LKAS_IN_Normal) {
          switch (LKAS_DW.is_Normal_l) {
           case LKAS_IN_LDWLeftActive:
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;

           case LKAS_IN_LDWRightActive:
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;

           default:
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;
          }

          LKAS_DW.is_SysOn_i = LKAS_IN_NO_ACTIVE_CHILD;
        } else {
          LKAS_DW.is_SysOn_i = LKAS_IN_NO_ACTIVE_CHILD;
        }

        LKAS_DW.is_c27_LKAS = LKAS_IN_Fault;
        LKAS_B.LDWSM_stLDWState = 6U;
      } else if ((LKAS_B.IMAPve_d_LKA_Mode != 1) && (LKAS_B.IMAPve_d_LKA_Mode !=
                  2)) {
        if (LKAS_DW.is_SysOn_i == LKAS_IN_Normal) {
          switch (LKAS_DW.is_Normal_l) {
           case LKAS_IN_LDWLeftActive:
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;

           case LKAS_IN_LDWRightActive:
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;

           default:
            LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
            break;
          }

          LKAS_DW.is_SysOn_i = LKAS_IN_NO_ACTIVE_CHILD;
        } else {
          LKAS_DW.is_SysOn_i = LKAS_IN_NO_ACTIVE_CHILD;
        }

        LKAS_DW.is_c27_LKAS = LKAS_IN_SysOff;
        LKAS_DW.is_SysOff_j = LKAS_IN_Unselected;
        LKAS_B.LDWSM_stLDWState = 1U;
      } else if (LKAS_DW.is_SysOn_i == LKAS_IN_LDWSelected) {
        LKAS_B.LDWSM_stLDWState = 2U;
        if (LKAS_B.Merge_k && (!LKAS_B.Merge1_j)) {
          LKAS_DW.is_SysOn_i = LKAS_IN_Normal;
          LKAS_DW.is_Normal_l = LKAS_IN_LDWEnable;
          LKAS_B.LDWSM_stLDWState = 3U;
        }
      } else if (LKAS_B.Merge1_j) {
        switch (LKAS_DW.is_Normal_l) {
         case LKAS_IN_LDWLeftActive:
          LKAS_B.LDWSM_stLDWActvFlg = 0U;
          LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
          break;

         case LKAS_IN_LDWRightActive:
          LKAS_B.LDWSM_stLDWActvFlg = 0U;
          LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
          break;

         default:
          LKAS_DW.is_Normal_l = LKAS_IN_NO_ACTIVE_CHILD;
          break;
        }

        LKAS_DW.is_SysOn_i = LKAS_IN_LDWSelected;
        LKAS_B.LDWSM_stLDWState = 2U;
      } else {
        switch (LKAS_DW.is_Normal_l) {
         case LKAS_IN_LDWEnable:
          LKAS_B.LDWSM_stLDWState = 3U;
          if ((LKAS_B.Merge_i == 1) && (!LKAS_B.Merge_f)) {
            LKAS_DW.is_Normal_l = LKAS_IN_LDWLeftActive;
            LKAS_B.LDWSM_stLDWState = 4U;
            LKAS_B.LDWSM_stLDWActvFlg = 1U;
          } else {
            if ((LKAS_B.Merge_i == 2) && (!LKAS_B.Merge_f)) {
              LKAS_DW.is_Normal_l = LKAS_IN_LDWRightActive;
              LKAS_B.LDWSM_stLDWState = 5U;
              LKAS_B.LDWSM_stLDWActvFlg = 2U;
            }
          }
          break;

         case LKAS_IN_LDWLeftActive:
          LKAS_B.LDWSM_stLDWState = 4U;
          if (LKAS_B.Merge_f) {
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_LDWEnable;
            LKAS_B.LDWSM_stLDWState = 3U;
          } else {
            if ((LKAS_B.Merge_i == 2) && (!LKAS_B.Merge_f)) {
              LKAS_DW.is_Normal_l = LKAS_IN_LDWRightActive;
              LKAS_B.LDWSM_stLDWState = 5U;
              LKAS_B.LDWSM_stLDWActvFlg = 2U;
            }
          }
          break;

         default:
          LKAS_B.LDWSM_stLDWState = 5U;
          if (LKAS_B.Merge_f) {
            LKAS_B.LDWSM_stLDWActvFlg = 0U;
            LKAS_DW.is_Normal_l = LKAS_IN_LDWEnable;
            LKAS_B.LDWSM_stLDWState = 3U;
          } else {
            if ((LKAS_B.Merge_i == 1) && (!LKAS_B.Merge_f)) {
              LKAS_DW.is_Normal_l = LKAS_IN_LDWLeftActive;
              LKAS_B.LDWSM_stLDWState = 4U;
              LKAS_B.LDWSM_stLDWActvFlg = 1U;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S93>/LDW_State_Machine' */
}

/* System reset for atomic system: '<S93>/LKA_State_Machine' */
void LKAS_LKA_State_Machine_Reset(void)
{
  LKAS_DW.is_SysOff = LKAS_IN_NO_ACTIVE_CHILD_l;
  LKAS_DW.is_SysOn = LKAS_IN_NO_ACTIVE_CHILD_l;
  LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
  LKAS_DW.is_active_c30_LKAS = 0U;
  LKAS_DW.is_c30_LKAS = LKAS_IN_NO_ACTIVE_CHILD_l;
  LKAS_B.LKASM_stLKAActvFlg = 0U;
  LKAS_B.LKASM_stLKAState = 0U;
}

/*
 * Output and update for atomic system: '<S93>/LKA_State_Machine'
 * Block description for: '<S93>/LKA_State_Machine'
 *   Block Name: LKA State Machine
 *   Ab.: LKASM
 *   No.: 1.1.3.0
 *   Rev: 0.0.1
 *   Update Date: 19-3-26
 */
void LKAS_LKA_State_Machine(void)
{
  boolean tmp;

  /* Chart: '<S93>/LKA_State_Machine'
   *
   * Block description for '<S93>/LKA_State_Machine':
   *  Block Name: LKA State Machine
   *  Ab.: LKASM
   *  No.: 1.1.3.0
   *  Rev: 0.0.1
   *  Update Date: 19-3-26
   */
  if (LKAS_DW.is_active_c30_LKAS == 0U) {
    LKAS_DW.is_active_c30_LKAS = 1U;
    LKAS_DW.is_c30_LKAS = LKAS_IN_SysOff_a;
    LKAS_DW.is_SysOff = LKAS_IN_Unavailable_a;
    LKAS_B.LKASM_stLKAState = 0U;
  } else {
    switch (LKAS_DW.is_c30_LKAS) {
     case LKAS_IN_Fault_e:
      tmp = !LKAS_B.LKA_Fault;
      if (tmp && (LKAS_B.IMAPve_d_LKA_Mode == 2)) {
        LKAS_DW.is_c30_LKAS = LKAS_IN_SysOn_c;
        LKAS_DW.is_SysOn = LKAS_IN_LKASelected;
        LKAS_B.LKASM_stLKAState = 2U;
      } else if (((LKAS_B.IMAPve_d_LKA_Mode == 0) || (LKAS_B.IMAPve_d_LKA_Mode ==
        1)) && tmp) {
        LKAS_DW.is_c30_LKAS = LKAS_IN_SysOff_a;
        LKAS_DW.is_SysOff = LKAS_IN_Unselected_m;
        LKAS_B.LKASM_stLKAState = 1U;
      } else {
        LKAS_B.LKASM_stLKAState = 6U;
      }
      break;

     case LKAS_IN_SysOff_a:
      if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && LKAS_B.LKA_Fault) {
        LKAS_DW.is_SysOff = LKAS_IN_NO_ACTIVE_CHILD_l;
        LKAS_DW.is_c30_LKAS = LKAS_IN_Fault_e;
        LKAS_B.LKASM_stLKAState = 6U;
      } else if (LKAS_B.IMAPve_d_LKA_Mode == 2) {
        LKAS_DW.is_SysOff = LKAS_IN_NO_ACTIVE_CHILD_l;
        LKAS_DW.is_c30_LKAS = LKAS_IN_SysOn_c;
        LKAS_DW.is_SysOn = LKAS_IN_LKASelected;
        LKAS_B.LKASM_stLKAState = 2U;
      } else if (LKAS_DW.is_SysOff == LKAS_IN_Unavailable_a) {
        LKAS_B.LKASM_stLKAState = 0U;
        if ((LKAS_B.IMAPve_d_LKA_Mode == 0) || (LKAS_B.IMAPve_d_LKA_Mode == 1))
        {
          LKAS_DW.is_SysOff = LKAS_IN_Unselected_m;
          LKAS_B.LKASM_stLKAState = 1U;
        }
      } else {
        LKAS_B.LKASM_stLKAState = 1U;
      }
      break;

     default:
      if (LKAS_B.LKA_Fault) {
        if (LKAS_DW.is_SysOn == LKAS_IN_Normal_l) {
          switch (LKAS_DW.is_Normal) {
           case LKAS_IN_LKALeftActive:
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;

           case LKAS_IN_LKARightActive:
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;

           default:
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;
          }

          LKAS_DW.is_SysOn = LKAS_IN_NO_ACTIVE_CHILD_l;
        } else {
          LKAS_DW.is_SysOn = LKAS_IN_NO_ACTIVE_CHILD_l;
        }

        LKAS_DW.is_c30_LKAS = LKAS_IN_Fault_e;
        LKAS_B.LKASM_stLKAState = 6U;
      } else if (LKAS_B.IMAPve_d_LKA_Mode != 2) {
        if (LKAS_DW.is_SysOn == LKAS_IN_Normal_l) {
          switch (LKAS_DW.is_Normal) {
           case LKAS_IN_LKALeftActive:
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;

           case LKAS_IN_LKARightActive:
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;

           default:
            LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
            break;
          }

          LKAS_DW.is_SysOn = LKAS_IN_NO_ACTIVE_CHILD_l;
        } else {
          LKAS_DW.is_SysOn = LKAS_IN_NO_ACTIVE_CHILD_l;
        }

        LKAS_DW.is_c30_LKAS = LKAS_IN_SysOff_a;
        LKAS_DW.is_SysOff = LKAS_IN_Unselected_m;
        LKAS_B.LKASM_stLKAState = 1U;
      } else if (LKAS_DW.is_SysOn == LKAS_IN_LKASelected) {
        LKAS_B.LKASM_stLKAState = 2U;
        if (LKAS_B.Merge1_g && (!LKAS_B.Merge2_h)) {
          LKAS_DW.is_SysOn = LKAS_IN_Normal_l;
          LKAS_DW.is_Normal = LKAS_IN_LKAEnable;
          LKAS_B.LKASM_stLKAState = 3U;
        }
      } else if (LKAS_B.Merge2_h) {
        switch (LKAS_DW.is_Normal) {
         case LKAS_IN_LKALeftActive:
          LKAS_B.LKASM_stLKAActvFlg = 0U;
          LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
          break;

         case LKAS_IN_LKARightActive:
          LKAS_B.LKASM_stLKAActvFlg = 0U;
          LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
          break;

         default:
          LKAS_DW.is_Normal = LKAS_IN_NO_ACTIVE_CHILD_l;
          break;
        }

        LKAS_DW.is_SysOn = LKAS_IN_LKASelected;
        LKAS_B.LKASM_stLKAState = 2U;
      } else {
        switch (LKAS_DW.is_Normal) {
         case LKAS_IN_LKAEnable:
          LKAS_B.LKASM_stLKAState = 3U;
          if ((LKAS_B.Merge2 == 1) && (!LKAS_B.Merge1_b)) {
            LKAS_DW.is_Normal = LKAS_IN_LKALeftActive;
            LKAS_B.LKASM_stLKAState = 4U;
            LKAS_B.LKASM_stLKAActvFlg = 1U;
          } else {
            if ((LKAS_B.Merge2 == 2) && (!LKAS_B.Merge1_b)) {
              LKAS_DW.is_Normal = LKAS_IN_LKARightActive;
              LKAS_B.LKASM_stLKAState = 5U;
              LKAS_B.LKASM_stLKAActvFlg = 2U;
            }
          }
          break;

         case LKAS_IN_LKALeftActive:
          LKAS_B.LKASM_stLKAState = 4U;
          if (LKAS_B.Merge1_b) {
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_LKAEnable;
            LKAS_B.LKASM_stLKAState = 3U;
          } else {
            if ((LKAS_B.Merge2 == 2) && (!LKAS_B.Merge1_b)) {
              LKAS_DW.is_Normal = LKAS_IN_LKARightActive;
              LKAS_B.LKASM_stLKAState = 5U;
              LKAS_B.LKASM_stLKAActvFlg = 2U;
            }
          }
          break;

         default:
          LKAS_B.LKASM_stLKAState = 5U;
          if (LKAS_B.Merge1_b) {
            LKAS_B.LKASM_stLKAActvFlg = 0U;
            LKAS_DW.is_Normal = LKAS_IN_LKAEnable;
            LKAS_B.LKASM_stLKAState = 3U;
          } else {
            if ((LKAS_B.Merge2 == 1) && (!LKAS_B.Merge1_b)) {
              LKAS_DW.is_Normal = LKAS_IN_LKALeftActive;
              LKAS_B.LKASM_stLKAState = 4U;
              LKAS_B.LKASM_stLKAActvFlg = 1U;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S93>/LKA_State_Machine' */
}

/*
 * Output and update for action system:
 *    '<S316>/Ph1SWA'
 *    '<S325>/Ph1SWA'
 *    '<S355>/Ph1SWA'
 *    '<S364>/Ph1SWA'
 */
void LKAS_Ph1SWA(float32 *rty_Out)
{
  /* SignalConversion: '<S320>/OutportBuffer_InsertedFor_Out_at_inport_0' incorporates:
   *  Constant: '<S320>/Constant'
   */
  *rty_Out = 1.0F;
}

/*
 * Output and update for action system:
 *    '<S316>/Ph2SWA'
 *    '<S325>/Ph2SWA'
 *    '<S355>/Ph2SWA'
 *    '<S364>/Ph2SWA'
 */
void LKAS_Ph2SWA(float32 *rty_Out)
{
  /* SignalConversion: '<S321>/OutportBuffer_InsertedFor_Out_at_inport_0' incorporates:
   *  Constant: '<S321>/Constant'
   */
  *rty_Out = (-1.0F);
}

/*
 * Output and update for action system:
 *    '<S316>/Ph3SWA'
 *    '<S325>/Ph3SWA'
 *    '<S355>/Ph3SWA'
 *    '<S364>/Ph3SWA'
 */
void LKAS_Ph3SWA(float32 *rty_Out)
{
  /* SignalConversion: '<S322>/OutportBuffer_InsertedFor_Out_at_inport_0' incorporates:
   *  Constant: '<S322>/Constant'
   */
  *rty_Out = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S377>/If Action Subsystem3'
 *    '<S415>/If Action Subsystem3'
 */
void LKAS_IfActionSubsystem3_m(boolean rtu_In1, boolean *rty_Out)
{
  /* Inport: '<S382>/In1' */
  *rty_Out = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S390>/If Action Subsystem4'
 *    '<S390>/If Action Subsystem3'
 *    '<S502>/If Action Subsystem3'
 *    '<S502>/If Action Subsystem4'
 */
void LKAS_IfActionSubsystem4(boolean *rty_Out)
{
  /* SignalConversion: '<S401>/OutportBuffer_InsertedFor_Out_at_inport_0' incorporates:
   *  Constant: '<S401>/Constant'
   */
  *rty_Out = false;
}

/*
 * Output and update for action system:
 *    '<S430>/If Action Subsystem'
 *    '<S430>/If Action Subsystem1'
 */
void LKAS_IfActionSubsystem_e(boolean *rty_Out)
{
  /* SignalConversion: '<S434>/OutportBuffer_InsertedFor_Out_at_inport_0' incorporates:
   *  Constant: '<S434>/Constant'
   */
  *rty_Out = true;
}

/*
 * System initialize for enable system:
 *    '<S298>/Count 5s1'
 *    '<S298>/Count 5s2'
 *    '<S298>/Count 5s3'
 *    '<S298>/Count 5s4'
 *    '<S298>/Count 5s5'
 */
void LKAS_Count5s1_Init(DW_Count5s1_LKAS_T *localDW)
{
  /* InitializeConditions for Sum: '<S605>/Add' incorporates:
   *  Memory: '<S605>/Memory'
   */
  localDW->Memory_PreviousInput = ((uint16)0U);
}

/*
 * System reset for enable system:
 *    '<S298>/Count 5s1'
 *    '<S298>/Count 5s2'
 *    '<S298>/Count 5s3'
 *    '<S298>/Count 5s4'
 *    '<S298>/Count 5s5'
 */
void LKAS_Count5s1_Reset(DW_Count5s1_LKAS_T *localDW)
{
  /* InitializeConditions for Sum: '<S605>/Add' incorporates:
   *  Memory: '<S605>/Memory'
   */
  localDW->Memory_PreviousInput = ((uint16)0U);
}

/*
 * Disable for enable system:
 *    '<S298>/Count 5s1'
 *    '<S298>/Count 5s2'
 *    '<S298>/Count 5s3'
 *    '<S298>/Count 5s4'
 *    '<S298>/Count 5s5'
 */
void LKAS_Count5s1_Disable(boolean *rty_Out, DW_Count5s1_LKAS_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S298>/Count 5s1' incorporates:
   *  EnablePort: '<S605>/Enable'
   */
  /* Disable for Outport: '<S605>/Out' */
  *rty_Out = false;

  /* End of Outputs for SubSystem: '<S298>/Count 5s1' */
  localDW->Count5s1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S298>/Count 5s1'
 *    '<S298>/Count 5s2'
 *    '<S298>/Count 5s3'
 *    '<S298>/Count 5s4'
 *    '<S298>/Count 5s5'
 */
void LKAS_Count5s1(boolean rtu_Enable, float32 rtu_LKA_SampleTime, boolean
                   *rty_Out, DW_Count5s1_LKAS_T *localDW)
{
  float32 tmp;

  /* Outputs for Enabled SubSystem: '<S298>/Count 5s1' incorporates:
   *  EnablePort: '<S605>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->Count5s1_MODE) {
      LKAS_Count5s1_Reset(localDW);
      localDW->Count5s1_MODE = true;
    }

    /* Sum: '<S605>/Add' incorporates:
     *  Constant: '<S605>/Constant'
     *  Memory: '<S605>/Memory'
     */
    localDW->Memory_PreviousInput = (uint16)((uint32)
      localDW->Memory_PreviousInput + ((uint16)1U));

    /* Saturate: '<S605>/Saturation' */
    if (localDW->Memory_PreviousInput >= ((uint16)11000U)) {
      /* Sum: '<S605>/Add' */
      localDW->Memory_PreviousInput = ((uint16)11000U);
    }

    /* End of Saturate: '<S605>/Saturation' */

    /* DataTypeConversion: '<S605>/Cast To Single' incorporates:
     *  Constant: '<S605>/Constant1'
     *  Product: '<S605>/Divide'
     */
    tmp = fmodf(floorf((float32)((uint16)5U) / rtu_LKA_SampleTime), 65536.0F);

    /* RelationalOperator: '<S605>/Relational Operator' incorporates:
     *  DataTypeConversion: '<S605>/Cast To Single'
     */
    *rty_Out = (localDW->Memory_PreviousInput >= (tmp < 0.0F ? (sint32)(uint16)-
      (sint16)(uint16)-tmp : (sint32)(uint16)tmp));
  } else {
    if (localDW->Count5s1_MODE) {
      LKAS_Count5s1_Disable(rty_Out, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S298>/Count 5s1' */
}

/* Model step function for TID1 */
void Runnable_LKAS_Step(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  float32 rtb_IMAPve_g_EPS_SW_Trq;
  float32 rtb_IMAPve_g_ESC_LonAcc;
  float32 rtb_IMAPve_g_ESC_VehSpd;
  float32 rtb_IMAPve_g_SW_Angle;
  float32 rtb_L0_C0;
  float32 rtb_R0_C0;
  float32 rtb_Gain_k;
  float32 rtb_LL_MAX_SYSTEM_CURVATURE_ENA;
  float32 rtb_LL_MIN_LANE_WIDTH_ENABLE;
  float32 rtb_LL_MAX_LANE_WIDTH_ENABLE;
  float32 rtb_LL_MAX_LONG_ACC_ENABLE;
  float32 rtb_Gain_g;
  float32 rtb_LL_MAX_SYSTEM_CURVATURE_DIS;
  float32 rtb_LL_MIN_LANE_WIDTH_DISABLE;
  float32 rtb_LL_MAX_LANE_WIDTH_DISABLE;
  float32 rtb_LL_MAX_LONG_ACC_DISABLE;
  float32 rtb_LL_LFClb_TFC_DiffCtrlRatio;
  float32 rtb_LKA_SampleTime;
  float32 rtb_R0_VR;
  float32 rtb_L0_VR;
  float32 rtb_R0_W;
  float32 rtb_L0_W;
  float32 rtb_IMAPve_g_EMS_RealPedal;
  float32 rtb_IMAPve_g_EPS_LKA_Current;
  float32 rtb_IMAPve_g_ESC_Brake_Press;
  float32 rtb_IMAPve_g_ESC_UnYawRate;
  float32 rtb_IMAPve_g_ESC_YawRate;
  float32 rtb_IMAPve_g_L0_Confidence;
  float32 rtb_IMAPve_g_L1_C0;
  float32 rtb_IMAPve_g_L1_C1;
  float32 rtb_IMAPve_g_L1_C2;
  float32 rtb_IMAPve_g_L1_C3;
  float32 rtb_IMAPve_g_L1_Confidence;
  float32 rtb_IMAPve_g_L1_TLC;
  float32 rtb_IMAPve_g_L1_VR;
  float32 rtb_IMAPve_g_L1_W;
  float32 rtb_L0_C0_l;
  float32 rtb_L0_C1_c;
  float32 rtb_L0_C2_a;
  float32 rtb_L0_C3_l;
  float32 rtb_L0_TLC_k;
  float32 rtb_L0_VR_n;
  float32 rtb_L0_W_l;
  float32 rtb_L1_C0;
  float32 rtb_L1_C1;
  float32 rtb_L1_C2;
  float32 rtb_L1_C3;
  float32 rtb_L1_TLC;
  float32 rtb_L1_VR;
  float32 rtb_L1_W;
  float32 rtb_R0_C0_p;
  float32 rtb_R0_C1_o;
  float32 rtb_R0_C2_c;
  float32 rtb_R0_C3_c;
  float32 rtb_R0_TLC_a;
  float32 rtb_R0_VR_i;
  float32 rtb_R0_W_l;
  float32 rtb_R1_C0;
  float32 rtb_R1_C1;
  float32 rtb_R1_C2;
  float32 rtb_R1_C3;
  float32 rtb_R1_TLC;
  float32 rtb_R1_VR;
  float32 rtb_R1_W;
  float32 rtb_IMAPve_g_R0_Confidence;
  float32 rtb_IMAPve_g_R1_C0;
  float32 rtb_IMAPve_g_R1_C1;
  float32 rtb_IMAPve_g_R1_C2;
  float32 rtb_IMAPve_g_R1_C3;
  float32 rtb_IMAPve_g_R1_Confidence;
  float32 rtb_IMAPve_g_R1_TLC;
  float32 rtb_IMAPve_g_R1_VR;
  float32 rtb_IMAPve_g_R1_W;
  float32 rtb_IMAPve_g_SW_Angle_Speed;
  float32 rtb_LL_NomTAhd_C;
  float32 rtb_LL_LKAS_OUT_OF_CONTROL_TTLC;
  float32 rtb_Gain1;
  float32 rtb_Add1_k;
  float32 rtb_Switch;
  float32 rtb_Switch2;
  float32 rtb_Add5_j;
  float32 rtb_Switch_i;
  float32 rtb_Saturation_e;
  float32 rtb_Abs1;
  float32 rtb_Add_hn;
  float32 rtb_Add_jc;
  float32 rtb_Merge_k;
  float32 rtb_Abs;
  float32 rtb_TSamp;
  float32 rtb_Diff;
  float32 rtb_UnaryMinus;
  float32 rtb_Add1_g;
  float32 rtb_Switch_o;
  float32 rtb_Switch2_k;
  float32 rtb_LFTTTLC;
  float32 rtb_RGTTTLC;
  float32 rtb_Add_b;
  float32 rtb_Add_eq;
  float32 rtb_phiPrdcHdAgLft;
  float32 rtb_Add_g;
  float32 rtb_phiPrdcHdAgRgt;
  float32 rtb_Merge_ky;
  float32 rtb_Add3;
  float32 rtb_Add_fj;
  float32 rtb_Add2;
  float32 rtb_Merge_p;
  float32 rtb_Merge_kn;
  float32 rtb_Switch_j;
  float32 rtb_Saturation_d;
  float32 rtb_Abs1_i;
  float32 rtb_Abs_m;
  float32 rtb_TSamp_n;
  float32 rtb_Diff_j;
  float32 rtb_UnaryMinus_k;
  float32 rtb_Merge1_k;
  float32 rtb_Divide_p;
  float32 rtb_Switch_d;
  float32 rtb_Switch2_m;
  float32 rtb_Divide_k;
  float32 rtb_Switch_on;
  float32 rtb_Switch2_d;
  float32 rtb_Merge1_k5;
  float32 rtb_Divide_kt;
  float32 rtb_Switch_g;
  float32 rtb_Switch2_l;
  float32 rtb_Divide_an;
  float32 rtb_Switch_ov;
  float32 rtb_Switch2_km;
  float32 rtb_Merge1_d;
  float32 rtb_Divide_f;
  float32 rtb_Switch_ob;
  float32 rtb_Switch2_o;
  float32 rtb_Divide_m;
  float32 rtb_Switch_iq;
  float32 rtb_Switch2_g;
  float32 rtb_Merge1_dq;
  float32 rtb_Divide_kz;
  float32 rtb_Switch_p;
  float32 rtb_Switch2_ds;
  float32 rtb_Divide_l1;
  float32 rtb_Switch_pw;
  float32 rtb_Switch2_h;
  float32 rtb_Gain_pe;
  float32 rtb_Merge_m;
  float32 rtb_Merge_a;
  float32 rtb_Abs1_l;
  float32 rtb_Abs_i;
  float32 rtb_Add1_kk;
  float32 rtb_Merge_mb;
  float32 rtb_Add_c3;
  float32 rtb_Saturation6_h;
  float32 rtb_Divide2_p;
  float32 rtb_ExNum;
  float32 rtb_Saturation_d3;
  float32 rtb_Saturation_b;
  float32 rtb_Add1_f;
  float32 rtb_Saturation_n;
  float32 rtb_Switch2_d2;
  float32 rtb_Switch_b;
  float32 rtb_Divide5;
  float32 rtb_Divide2_d;
  float32 rtb_Divide7;
  float32 rtb_Switch_f;
  float32 rtb_Switch2_m5;
  float32 rtb_Saturation_ge;
  float32 rtb_Add_mq;
  float32 rtb_Switch_gc;
  float32 rtb_Switch2_b;
  float32 rtb_UkYk1;
  float32 rtb_Switch_dl;
  float32 rtb_Switch2_lq;
  float32 rtb_Saturation2;
  float32 rtb_Saturation2_g;
  float32 rtb_Saturation2_a;
  float32 rtb_MPInP_vVehSpd;
  float32 rtb_Saturation_o;
  float32 rtb_Saturation_dy;
  float32 rtb_SWACmd_phiSWACmd;
  float32 rtb_T2;
  float32 rtb_phiSWA0;
  float32 rtb_Plan;
  float32 rtb_T1_f;
  float32 rtb_Plan_n;
  float32 rtb_T1_o;
  float32 rtb_Add2_p;
  float32 rtb_deltafalllimit_b;
  float32 rtb_Yk1_eq;
  float32 rtb_Gain2_a;
  float32 rtb_Abs2;
  uint16 rtb_L1_Q;
  uint16 rtb_R1_Q;
  uint16 rtb_Saturation1_l;
  uint16 rtb_Saturation1_la;
  uint16 rtb_Saturation1_b;
  uint16 rtb_Add_p2;
  uint16 rtb_Saturation1_f;
  uint16 rtb_Saturation1_b2;
  uint16 rtb_Saturation1_e;
  uint16 rtb_Saturation1_m;
  uint16 rtb_Saturation2_m;
  uint8 rtb_IMAPve_d_LKA_Main_Switch;
  uint8 rtb_LKA_Switch_State;
  uint8 rtb_LKA_Mode_from_Camera;
  uint8 rtb_R0_Type;
  uint8 rtb_L0_Type;
  uint8 rtb_R0_LC;
  uint8 rtb_L0_LC;
  uint8 rtb_IMAPve_d_Camera_Signal_Faul;
  uint8 rtb_IMAPve_d_Camera_Status;
  uint8 rtb_IMAPve_d_ConsArea;
  uint8 rtb_IMAPve_d_EPS_Steer_Hold_Sta;
  uint8 rtb_IMAPve_d_EPS_TrqLim_State;
  uint8 rtb_IMAPve_d_EPS_Trq_State;
  uint8 rtb_IMAPve_d_ESC_LatAcc_Valid;
  uint8 rtb_IMAPve_d_ESC_LonAcc_Valid;
  uint8 rtb_IMAPve_d_ESC_VehSpd_Valid;
  uint8 rtb_IMAPve_d_ESC_YawRate_Valid;
  uint8 rtb_IMAPve_d_Fusion_Status;
  uint8 rtb_IMAPve_d_L1_LC;
  uint8 rtb_IMAPve_d_L1_Type;
  uint8 rtb_IMAPve_d_LDW_Warn_Mode;
  uint8 rtb_IMAPve_d_Lane_Valid;
  uint8 rtb_L0_LC_o;
  uint8 rtb_L0_Q_m;
  uint8 rtb_L0_Type_j;
  uint8 rtb_L1_LC;
  uint8 rtb_L1_Q_c;
  uint8 rtb_L1_Type;
  uint8 rtb_IMAPve_d_ORI_Lane_ConsArea;
  uint8 rtb_IMAPve_d_ORI_Lane_RoadType;
  uint8 rtb_IMAPve_d_ORI_Lane_Valid;
  uint8 rtb_R0_LC_n;
  uint8 rtb_R0_Type_i;
  uint8 rtb_R0_Q_n;
  uint8 rtb_R1_LC;
  uint8 rtb_R1_Type;
  uint8 rtb_R1_Q_k;
  uint8 rtb_IMAPve_d_R1_LC;
  uint8 rtb_IMAPve_d_R1_Type;
  uint8 rtb_IMAPve_d_Road_Type;
  uint8 rtb_IMAPve_d_SAS_Clb_State;
  uint8 rtb_IMAPve_d_SAS_Trim_State;
  uint8 rtb_IMAPve_d_SWS_Failure_Status;
  uint8 rtb_IMAPve_d_SWS_Fault_Code;
  uint8 rtb_IMAPve_d_Sensor_Status;
  uint8 rtb_LDW_State;
  uint8 rtb_DACMode;
  uint8 rtb_Saturation1_ks;
  boolean rtb_Compare_ef;
  boolean rtb_UnitDelay_a;
  boolean rtb_Compare_oq;
  boolean rtb_Merge_k2;
  boolean rtb_Merge_i;
  boolean rtb_Compare_cg;
  boolean rtb_UnitDelay_d;
  boolean rtb_Compare_ki;
  boolean rtb_Merge_d;
  boolean rtb_LogicalOperator1_l;
  boolean rtb_Compare_am;
  boolean rtb_LogicalOperator2_a;
  boolean rtb_Compare_mm;
  boolean rtb_LogicalOperator3_f;
  boolean rtb_LogicalOperator1_b;
  boolean rtb_Compare_mq;
  boolean rtb_Compare_ox;
  boolean rtb_Compare_hlr;
  boolean rtb_Compare_ny;
  boolean rtb_Compare_b0;
  boolean rtb_Compare_dg;
  boolean rtb_Compare_dk;
  boolean rtb_Compare_hv;
  boolean rtb_Compare_k5;
  boolean rtb_Compare_l4;
  boolean rtb_Compare_mj;
  boolean rtb_Compare_n2g;
  boolean rtb_Compare_jh;
  boolean rtb_Compare_bc2;
  boolean rtb_Compare_ad;
  boolean rtb_Compare_nvm;
  boolean rtb_Compare_ex;
  boolean rtb_Compare_ge;
  boolean rtb_Compare_f4;
  boolean rtb_Compare_ao;
  boolean rtb_Compare_kvr;
  boolean rtb_Compare_gvn;
  boolean rtb_Compare_k3c;
  boolean rtb_Compare_kw;
  boolean rtb_Compare_bm;
  boolean rtb_Compare_nw;
  boolean rtb_Compare_cz;
  boolean rtb_Compare_l1;
  boolean rtb_Compare_m5;
  boolean rtb_Compare_ng;
  boolean rtb_Compare_jn;
  boolean rtb_Compare_ga;
  boolean rtb_RelationalOperator6_f;
  boolean rtb_RelationalOperator5;
  float32 x20;
  UInt16 tmpRead;
  UInt16 tmpRead_0;
  UInt16 tmpRead_1;
  UInt16 tmpRead_2;
  UInt16 tmpRead_3;
  UInt16 tmpRead_4;
  UInt16 tmpRead_5;
  UInt16 tmpRead_6;
  UInt16 tmpRead_7;
  UInt16 tmpRead_8;
  UInt16 tmpRead_9;
  UInt16 tmpRead_a;
  UInt16 tmpRead_b;
  UInt16 tmpRead_c;
  UInt16 tmpRead_d;
  UInt16 tmpRead_e;
  UInt16 tmpRead_f;
  UInt16 tmpRead_g;
  UInt16 tmpRead_h;
  UInt16 tmpRead_i;
  UInt16 tmpRead_j;
  UInt16 tmpRead_k;
  UInt16 tmpRead_l;
  UInt16 tmpRead_m;
  UInt16 tmpRead_n;
  UInt16 tmpRead_o;
  UInt16 tmpRead_p;
  UInt16 tmpRead_q;
  UInt16 tmpRead_r;
  UInt16 tmpRead_s;
  UInt16 tmpRead_t;
  UInt16 tmpRead_u;
  UInt16 tmpRead_v;
  UInt16 tmpRead_w;
  UInt16 tmpRead_x;
  UInt16 tmpRead_y;
  UInt16 tmpRead_z;
  UInt16 tmpRead_10;
  UInt16 tmpRead_11;
  UInt16 tmpRead_12;
  T_M_Nm_Float32 tmpRead_13;
  UInt16 tmpRead_14;
  T_M_Nm_Float32 tmpRead_15;
  UInt16 tmpRead_16;
  T_M_Nm_Float32 tmpRead_17;
  UInt16 tmpRead_18;
  UInt16 tmpRead_19;
  T_M_Nm_Float32 tmpRead_1a;
  UInt16 tmpRead_1b;
  UInt16 tmpRead_1c;
  UInt16 tmpRead_1d;
  UInt16 tmpRead_1e;
  UInt16 tmpRead_1f;
  UInt16 tmpRead_1g;
  UInt16 tmpRead_1h;
  UInt16 tmpRead_1i;
  UInt16 tmpRead_1j;
  uint8 rtb_IMAPve_d_BCM_HazardLamp;
  uint8 rtb_IMAPve_d_BCM_Left_Light;
  uint8 rtb_IMAPve_d_BCM_Right_Light;
  uint8 rtb_IMAPve_d_EPS_LKA_State;
  uint8 rtb_IMAPve_d_TCU_Actual_Gear;
  UInt8 rtb_EPS_LKA_Control;
  float32 rtb_Abs_h;
  float32 rtb_Saturation_k;
  uint8 rtb_IMAPve_d_L0_Type;
  uint8 rtb_IMAPve_d_R0_Type;
  uint8 rtb_L0_Q;
  uint8 rtb_R0_Q;
  float32 rtb_L0_C1;
  float32 rtb_L0_C2;
  float32 rtb_L0_C3;
  float32 rtb_L0_TLC;
  float32 rtb_R0_C1;
  float32 rtb_R0_C2;
  float32 rtb_R0_C3;
  float32 rtb_R0_TLC;
  float32 rtb_LL_LKAS_OUT_OF_CONTROL_LAT_;
  float32 rtb_LL_DvtComp_C;
  float32 rtb_LL_LDW_LatestWarnLine_C;
  float32 rtb_LL_LKA_EarliestWarnLine_C;
  float32 rtb_LL_LKA_LatestWarnLine_C;
  float32 rtb_LL_MAX_DRIVER_TORQUE_DISABL;
  float32 rtb_LL_TkOvStChk_tiTDelTime;
  float32 rtb_LL_ThresDet_lDvtThresLwrLDW;
  float32 rtb_LL_ThresDet_lDvtThresUprLDW;
  float32 rtb_LL_ThresDet_tiTTLCThresLDW;
  float32 rtb_LL_ThresDet_lDvtThresLwrLKA;
  float32 rtb_LL_ThresDet_lDvtThresUprLKA;
  float32 rtb_LL_ThresDet_tiTTLCThresLKA;
  float32 rtb_LL_DvtSpdDet_vDvtSpdMin_C;
  float32 rtb_LL_DvtComp_C_f;
  float32 rtb_LL_LFClb_TFC_vGainLutVehSpd;
  float32 rtb_LL_LFClb_TFC_vGainLutVehS_j;
  float32 rtb_LL_LFClb_TFC_facmGainLutGai;
  float32 rtb_LL_LKASWASyn_TrqSwaAddSwt;
  float32 rtb_LL_LKASWASyn_M1;
  float32 rtb_LL_LKASWASyn_T2;
  float32 rtb_LL_LKAExPrcs_tiExitTime1;
  float32 rtb_LL_LKAExPrcs_tiExitTime2;
  float32 rtb_LL_LKAExPrcs_ExitC0Dvt;
  float32 rtb_LKA_Veh2CamW_C;
  float32 rtb_LKA_Veh2CamL_C;
  float32 rtb_Saturation4_g;
  float32 rtb_LaneWidth;
  boolean rtb_LogicalOperator3_o;
  boolean rtb_LogicalOperator2_p;
  float32 rtb_Saturation9;
  float32 rtb_Saturation10;
  float32 rtb_TTLC;
  float32 rtb_TTLC_f;
  float32 rtb_Divide_a3;
  float32 rtb_Abs_o;
  float32 rtb_Saturation5_cw;
  float32 rtb_Abs_cf;
  float32 rtb_Saturation1_gx;
  sint8 rtPrevAction;
  boolean rtb_RelationalOperator_l0;
  boolean rtb_RelationalOperator1_h;
  float32 rtb_offset;
  uint16 rtb_Add1_hb;
  sint32 rtb_Switch3_0;
  float32 rtb_Add_hn_tmp;
  float32 rtb_Add_jc_tmp;
  float32 rtb_Abs1_tmp;
  float32 rtb_Abs_tmp;
  float32 rtb_TSamp_tmp;
  float32 rtb_LogicalOperator3_g_tmp;
  float32 rtb_LogicalOperator3_g_tmp_0;
  float32 rtb_LogicalOperator3_g_tmp_1;
  float32 rtb_LogicalOperator3_g_tmp_2;
  float32 u0_tmp_tmp;
  float32 u0_tmp_tmp_0;

  /* Inport: '<Root>/IMAPve_d_L0_Q' */
  Rte_Read_IMAPve_d_L0_Q_IMAPve_d_L0_Q(&rtb_Add1_hb);

  /* Inport: '<Root>/IMAPve_d_TCU_Actual_Gear' */
  Rte_Read_IMAPve_d_TCU_Actual_Gear_IMAPve_d_TCU_Actual_Gear(&tmpRead_e);

  /* Inport: '<Root>/IMAPve_d_BCM_Right_Light' */
  Rte_Read_IMAPve_d_BCM_Right_Light_IMAPve_d_BCM_Right_Light(&tmpRead_d);

  /* Inport: '<Root>/IMAPve_d_BCM_Left_Light' */
  Rte_Read_IMAPve_d_BCM_Left_Light_IMAPve_d_BCM_Left_Light(&tmpRead_c);

  /* Inport: '<Root>/IMAPve_d_BCM_HazardLamp' */
  Rte_Read_IMAPve_d_BCM_HazardLamp_IMAPve_d_BCM_HazardLamp(&tmpRead_b);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_g_SW_Angle_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_SW_Angle'
   */
  Rte_Read_IMAPve_g_SW_Angle_IMAPve_g_SW_Angle(&rtb_IMAPve_g_SW_Angle);

  /* DataTypeConversion: '<S1>/IMAPve_g_ESC_LonAcc_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ESC_LonAcc'
   */
  Rte_Read_IMAPve_g_ESC_LonAcc_IMAPve_g_ESC_LonAcc(&rtb_IMAPve_g_ESC_LonAcc);

  /* DataTypeConversion: '<S1>/IMAPve_g_ESC_VehSpd_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ESC_VehSpd'
   */
  Rte_Read_IMAPve_g_ESC_VehSpd_IMAPve_g_ESC_VehSpd(&rtb_IMAPve_g_ESC_VehSpd);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_ESC_LatAcc' */
  Rte_Read_IMAPve_g_ESC_LatAcc_IMAPve_g_ESC_LatAcc(&rtb_TTLC);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_g_EPS_SW_Trq_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_EPS_SW_Trq'
   */
  Rte_Read_IMAPve_g_EPS_SW_Trq_IMAPve_g_EPS_SW_Trq(&rtb_IMAPve_g_EPS_SW_Trq);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_EPS_LKA_State' */
  Rte_Read_IMAPve_d_EPS_LKA_State_IMAPve_d_EPS_LKA_State(&tmpRead_2);

  /* Inport: '<Root>/IMAPve_d_LKA_Mode' */
  Rte_Read_IMAPve_d_LKA_Mode_IMAPve_d_LKA_Mode(&tmpRead_0);

  /* Inport: '<Root>/IMAPve_d_LKA_Main_Switch' */
  Rte_Read_IMAPve_d_LKA_Main_Switch_IMAPve_d_LKA_Main_Switch(&tmpRead);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_d_BCM_HazardLamp_1' */
  rtb_IMAPve_d_BCM_HazardLamp = (uint8)tmpRead_b;

  /* DataTypeConversion: '<S1>/IMAPve_d_BCM_Left_Light_1' */
  rtb_IMAPve_d_BCM_Left_Light = (uint8)tmpRead_c;

  /* DataTypeConversion: '<S1>/IMAPve_d_BCM_Right_Light_1' */
  rtb_IMAPve_d_BCM_Right_Light = (uint8)tmpRead_d;

  /* DataTypeConversion: '<S1>/IMAPve_d_EPS_LKA_State_1' */
  rtb_IMAPve_d_EPS_LKA_State = (uint8)tmpRead_2;

  /* DataTypeConversion: '<S1>/IMAPve_d_LKA_Main_Switch_1' */
  rtb_IMAPve_d_LKA_Main_Switch = (uint8)tmpRead;

  /* DataTypeConversion: '<S1>/IMAPve_d_LKA_Mode_1' */
  LKAS_B.IMAPve_d_LKA_Mode = (uint8)tmpRead_0;

  /* DataTypeConversion: '<S1>/IMAPve_d_TCU_Actual_Gear_1' */
  rtb_IMAPve_d_TCU_Actual_Gear = (uint8)tmpRead_e;

  /* DataTypeConversion: '<S1>/IMAPve_d_L0_Q_1' */
  rtb_EPS_LKA_Control = (UInt8)rtb_Add1_hb;

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/Constant'
   */
  if (rtb_EPS_LKA_Control >= ((uint8)2U)) {
    rtb_L0_Q = ((uint8)3U);
  } else {
    rtb_L0_Q = rtb_EPS_LKA_Control;
  }

  /* End of Switch: '<S74>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_R0_Q' */
  Rte_Read_IMAPve_d_R0_Q_IMAPve_d_R0_Q(&tmpRead_18);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_d_R0_Q_1' */
  rtb_EPS_LKA_Control = (UInt8)tmpRead_18;

  /* Switch: '<S71>/Switch1' incorporates:
   *  Constant: '<S71>/Constant1'
   */
  if (rtb_EPS_LKA_Control >= ((uint8)2U)) {
    rtb_R0_Q = ((uint8)3U);
  } else {
    rtb_R0_Q = rtb_EPS_LKA_Control;
  }

  /* End of Switch: '<S71>/Switch1' */

  /* Chart: '<S70>/LaneReconstructSM' */
  if (LKAS_DW.is_active_c18_LKAS == 0U) {
    LKAS_DW.is_active_c18_LKAS = 1U;
    LKAS_DW.is_c18_LKAS = LKAS_IN_NoLaneLost;
    LKAS_B.LaneRSM_stLftFlg = 1U;
    LKAS_B.LaneRSM_stRgtFlg = 1U;
  } else {
    switch (LKAS_DW.is_c18_LKAS) {
     case LKAS_IN_DoubleLost:
      if ((rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_NoLaneLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 1U;
      } else if ((rtb_L0_Q == 3) && (rtb_R0_Q < 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_RightLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 0U;
      } else {
        if ((rtb_L0_Q < 3) && (rtb_R0_Q == 3)) {
          LKAS_DW.is_c18_LKAS = LKAS_IN_LeftLost;
          LKAS_B.LaneRSM_stLftFlg = 0U;
          LKAS_B.LaneRSM_stRgtFlg = 1U;
        }
      }
      break;

     case LKAS_IN_LeftLost:
      LKAS_B.LaneRSM_stLftFlg = 0U;
      LKAS_B.LaneRSM_stRgtFlg = 1U;
      if ((rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_NoLaneLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 1U;
      } else if ((rtb_L0_Q == 3) && (rtb_R0_Q < 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_RightLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 0U;
      } else {
        if (rtb_R0_Q < 3) {
          LKAS_DW.is_c18_LKAS = LKAS_IN_DoubleLost;
        }
      }
      break;

     case LKAS_IN_NoLaneLost:
      LKAS_B.LaneRSM_stLftFlg = 1U;
      LKAS_B.LaneRSM_stRgtFlg = 1U;
      if ((rtb_L0_Q < 3) && (rtb_R0_Q == 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_LeftLost;
        LKAS_B.LaneRSM_stLftFlg = 0U;
        LKAS_B.LaneRSM_stRgtFlg = 1U;
      } else if ((rtb_L0_Q == 3) && (rtb_R0_Q < 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_RightLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 0U;
      } else {
        if ((rtb_L0_Q < 3) && (rtb_R0_Q < 3)) {
          LKAS_DW.is_c18_LKAS = LKAS_IN_DoubleLost;
        }
      }
      break;

     default:
      LKAS_B.LaneRSM_stLftFlg = 1U;
      LKAS_B.LaneRSM_stRgtFlg = 0U;
      if ((rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_NoLaneLost;
        LKAS_B.LaneRSM_stLftFlg = 1U;
        LKAS_B.LaneRSM_stRgtFlg = 1U;
      } else if ((rtb_L0_Q < 3) && (rtb_R0_Q == 3)) {
        LKAS_DW.is_c18_LKAS = LKAS_IN_LeftLost;
        LKAS_B.LaneRSM_stLftFlg = 0U;
        LKAS_B.LaneRSM_stRgtFlg = 1U;
      } else {
        if (rtb_L0_Q < 3) {
          LKAS_DW.is_c18_LKAS = LKAS_IN_DoubleLost;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S70>/LaneReconstructSM' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_C2' */
  Rte_Read_IMAPve_g_R0_C2_IMAPve_g_R0_C2(&rtb_LL_LKA_LatestWarnLine_C);

  /* Inport: '<Root>/IMAPve_g_R0_C0' */
  Rte_Read_IMAPve_g_R0_C0_IMAPve_g_R0_C0(&rtb_L0_C1);

  /* Inport: '<Root>/IMAPve_d_L0_Type' */
  Rte_Read_IMAPve_d_L0_Type_IMAPve_d_L0_Type(&tmpRead_14);

  /* Inport: '<Root>/IMAPve_g_L0_C2' */
  Rte_Read_IMAPve_g_L0_C2_IMAPve_g_L0_C2(&rtb_R0_C2);

  /* Inport: '<Root>/IMAPve_g_L0_C0' */
  Rte_Read_IMAPve_g_L0_C0_IMAPve_g_L0_C0(&rtb_Abs_h);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Sum: '<S87>/Add1' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C0_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C0_1'
   *  Gain: '<S85>/Gain'
   *  Memory: '<S87>/Memory'
   *  Product: '<S87>/Divide'
   *  Product: '<S87>/Divide1'
   *  Sum: '<S85>/Add'
   */
  LKAS_DW.Memory_PreviousInput = ((-1.0F) * rtb_Abs_h + rtb_L0_C1) *
    LKAS_ConstB.Divide2 + LKAS_ConstB.Add2 * LKAS_DW.Memory_PreviousInput;

  /* Saturate: '<S85>/Saturation' */
  if (LKAS_DW.Memory_PreviousInput > 5.5F) {
    rtb_Saturation_k = 5.5F;
  } else if (LKAS_DW.Memory_PreviousInput < 2.5F) {
    rtb_Saturation_k = 2.5F;
  } else {
    rtb_Saturation_k = LKAS_DW.Memory_PreviousInput;
  }

  /* End of Saturate: '<S85>/Saturation' */

  /* Abs: '<S80>/Abs' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C2_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C2_1'
   *  Sum: '<S80>/Add2'
   */
  rtb_Saturation10 = fabsf(rtb_R0_C2 + rtb_LL_LKA_LatestWarnLine_C);

  /* Saturate: '<S80>/Saturation' */
  if (rtb_Saturation10 > 0.004F) {
    rtb_Saturation10 = 0.004F;
  } else {
    if (rtb_Saturation10 < 0.0F) {
      rtb_Saturation10 = 0.0F;
    }
  }

  /* End of Saturate: '<S80>/Saturation' */

  /* MATLAB Function: '<S80>/get_roadside_offset' */
  rtb_offset = fminf(0.5F, (fminf(0.004F, rtb_Saturation10) / 0.004F + 1.0F) *
                     0.2F * (fminf(4.0F, rtb_Saturation_k) - 2.0F));

  /* DataTypeConversion: '<S1>/IMAPve_d_L0_Type_1' */
  rtb_IMAPve_d_L0_Type = (uint8)tmpRead_14;

  /* Switch: '<S80>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C0_1'
   *  RelationalOperator: '<S83>/Compare'
   *  Sum: '<S80>/Add'
   */
  if (rtb_IMAPve_d_L0_Type == ((uint8)2U)) {
    rtb_Abs_h += rtb_offset;
  }

  /* End of Switch: '<S80>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_R0_Type' */
  Rte_Read_IMAPve_d_R0_Type_IMAPve_d_R0_Type(&tmpRead_19);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Sum: '<S81>/Add1' incorporates:
   *  Memory: '<S81>/Memory'
   *  Product: '<S81>/Divide'
   *  Product: '<S81>/Divide1'
   */
  LKAS_DW.Memory_PreviousInput_o = rtb_Abs_h * LKAS_ConstB.Divide2_o +
    LKAS_ConstB.Add2_b * LKAS_DW.Memory_PreviousInput_o;

  /* DataTypeConversion: '<S1>/IMAPve_d_R0_Type_1' */
  rtb_IMAPve_d_R0_Type = (uint8)tmpRead_19;

  /* Switch: '<S80>/Switch1' incorporates:
   *  Constant: '<S84>/Constant'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C0_1'
   *  RelationalOperator: '<S84>/Compare'
   *  Sum: '<S80>/Add1'
   */
  if (rtb_IMAPve_d_R0_Type == ((uint8)2U)) {
    rtb_Abs_h = rtb_L0_C1 - rtb_offset;
  } else {
    rtb_Abs_h = rtb_L0_C1;
  }

  /* End of Switch: '<S80>/Switch1' */

  /* Sum: '<S82>/Add1' incorporates:
   *  Memory: '<S82>/Memory'
   *  Product: '<S82>/Divide'
   *  Product: '<S82>/Divide1'
   */
  LKAS_DW.Memory_PreviousInput_i = rtb_Abs_h * LKAS_ConstB.Divide2_b +
    LKAS_ConstB.Add2_h * LKAS_DW.Memory_PreviousInput_i;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_C1' */
  Rte_Read_IMAPve_g_R0_C1_IMAPve_g_R0_C1(&rtb_LL_LFClb_TFC_vGainLutVehSpd);

  /* Inport: '<Root>/IMAPve_g_L0_C1' */
  Rte_Read_IMAPve_g_L0_C1_IMAPve_g_L0_C1(&rtb_R0_C1);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S70>/Switch1' incorporates:
   *  Gain: '<S77>/Gain'
   *  Sum: '<S77>/Add'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_C0 = LKAS_DW.Memory_PreviousInput_o;
  } else {
    rtb_L0_C0 = (rtb_Saturation_k - LKAS_DW.Memory_PreviousInput_i) * (-1.0F);
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_C3' */
  Rte_Read_IMAPve_g_R0_C3_IMAPve_g_R0_C3(&rtb_LL_LFClb_TFC_vGainLutVehS_j);

  /* Inport: '<Root>/IMAPve_g_L0_C3' */
  Rte_Read_IMAPve_g_L0_C3_IMAPve_g_L0_C3(&rtb_R0_C3);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S70>/Switch1' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C1_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C2_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C1_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C2_1'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_C1 = rtb_R0_C1;
    rtb_L0_C2 = rtb_R0_C2;
  } else {
    rtb_L0_C1 = rtb_LL_LFClb_TFC_vGainLutVehSpd;
    rtb_L0_C2 = rtb_LL_LKA_LatestWarnLine_C;
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_TLC' */
  Rte_Read_IMAPve_g_R0_TLC_IMAPve_g_R0_TLC(&rtb_LL_LFClb_TFC_facmGainLutGai);

  /* Inport: '<Root>/IMAPve_g_L0_TLC' */
  Rte_Read_IMAPve_g_L0_TLC_IMAPve_g_L0_TLC(&rtb_R0_TLC);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S70>/Switch1' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_C3_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_TLC_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C3_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_TLC_1'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_C3 = rtb_R0_C3;
    rtb_L0_TLC = rtb_R0_TLC;
  } else {
    rtb_L0_C3 = rtb_LL_LFClb_TFC_vGainLutVehS_j;
    rtb_L0_TLC = rtb_LL_LFClb_TFC_facmGainLutGai;
  }

  /* Switch: '<S70>/Switch' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C1_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C2_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_C3_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_TLC_1'
   *  Sum: '<S79>/Add'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    rtb_R0_C0 = LKAS_DW.Memory_PreviousInput_i;
    rtb_R0_C1 = rtb_LL_LFClb_TFC_vGainLutVehSpd;
    rtb_R0_C2 = rtb_LL_LKA_LatestWarnLine_C;
    rtb_R0_C3 = rtb_LL_LFClb_TFC_vGainLutVehS_j;
    rtb_R0_TLC = rtb_LL_LFClb_TFC_facmGainLutGai;
  } else {
    rtb_R0_C0 = rtb_Saturation_k + LKAS_DW.Memory_PreviousInput_o;
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_EPS_Error_State' */
  Rte_Read_IMAPve_d_EPS_Error_State_IMAPve_d_EPS_Error_State(&tmpRead_3);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S613>/Switch2' incorporates:
   *  Constant: '<S613>/LL_MIN_LKAS_SPEED_ENABLE=60'
   */
  if (LKAS_ConstB.DataTypeConversion24 != 0.0F) {
    rtb_Saturation9 = LKAS_ConstB.DataTypeConversion24;
  } else {
    rtb_Saturation9 = LL_MIN_LKAS_SPEED_ENABLE;
  }

  /* End of Switch: '<S613>/Switch2' */

  /* Gain: '<S616>/Gain' incorporates:
   *  Constant: '<S616>/Constant'
   *  Sum: '<S616>/Add'
   */
  rtb_Gain_k = (rtb_Saturation9 - 2.5F) * 0.980392158F;

  /* Switch: '<S613>/Switch5' incorporates:
   *  Constant: '<S613>/LL_MAX_SYSTEM_CURVATURE_ENABLE=0.004'
   */
  if (LKAS_ConstB.DataTypeConversion27 != 0.0F) {
    rtb_LL_MAX_SYSTEM_CURVATURE_ENA = LKAS_ConstB.DataTypeConversion27;
  } else {
    rtb_LL_MAX_SYSTEM_CURVATURE_ENA = LL_MAX_SYSTEM_CURVATURE_ENABLE;
  }

  /* End of Switch: '<S613>/Switch5' */

  /* Switch: '<S613>/Switch6' incorporates:
   *  Constant: '<S613>/LL_MIN_LANE_WIDTH_ENABLE=2.5'
   */
  if (LKAS_ConstB.DataTypeConversion28 != 0.0F) {
    rtb_LL_MIN_LANE_WIDTH_ENABLE = LKAS_ConstB.DataTypeConversion28;
  } else {
    rtb_LL_MIN_LANE_WIDTH_ENABLE = LL_MIN_LANE_WIDTH_ENABLE;
  }

  /* End of Switch: '<S613>/Switch6' */

  /* Switch: '<S613>/Switch7' incorporates:
   *  Constant: '<S613>/LL_MAX_LANE_WIDTH_ENABLE=5.4'
   */
  if (LKAS_ConstB.DataTypeConversion29 != 0.0F) {
    rtb_LL_MAX_LANE_WIDTH_ENABLE = LKAS_ConstB.DataTypeConversion29;
  } else {
    rtb_LL_MAX_LANE_WIDTH_ENABLE = LL_MAX_LANE_WIDTH_ENABLE;
  }

  /* End of Switch: '<S613>/Switch7' */

  /* Switch: '<S613>/Switch15' incorporates:
   *  Constant: '<S613>/LL_MAX_LONG_ACC_ENABLE=3'
   */
  if (LKAS_ConstB.DataTypeConversion35 != 0.0F) {
    rtb_LL_MAX_LONG_ACC_ENABLE = LKAS_ConstB.DataTypeConversion35;
  } else {
    rtb_LL_MAX_LONG_ACC_ENABLE = LL_MAX_LONG_ACC_ENABLE;
  }

  /* End of Switch: '<S613>/Switch15' */

  /* Switch: '<S613>/Switch17' incorporates:
   *  Constant: '<S613>/LL_LKAS_OUT_OF_CONTROL_LAT_VEL=1.5'
   */
  if (LKAS_ConstB.DataTypeConversion37 != 0.0F) {
    rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = LKAS_ConstB.DataTypeConversion37;
  } else {
    rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = LL_LKAS_OUT_OF_CONTROL_LAT_VEL;
  }

  /* End of Switch: '<S613>/Switch17' */

  /* Switch: '<S613>/Switch12' incorporates:
   *  Constant: '<S613>/LL_DvtComp_C=0'
   */
  if (LKAS_ConstB.DataTypeConversion39 != 0.0F) {
    rtb_LL_DvtComp_C = LKAS_ConstB.DataTypeConversion39;
  } else {
    rtb_LL_DvtComp_C = LL_DvtComp_C;
  }

  /* End of Switch: '<S613>/Switch12' */

  /* Switch: '<S613>/Switch13' incorporates:
   *  Constant: '<S613>/LL_LDW_EarliestWarnLine_C=0.3'
   */
  if (LKAS_ConstB.DataTypeConversion40 != 0.0F) {
    rtb_Abs_h = LKAS_ConstB.DataTypeConversion40;
  } else {
    rtb_Abs_h = LL_LDW_EarliestWarnLine_C;
  }

  /* End of Switch: '<S613>/Switch13' */

  /* Switch: '<S613>/Switch21' incorporates:
   *  Constant: '<S613>/LL_LDW_LatestWarnLine_C=-0.4'
   */
  if (LKAS_ConstB.DataTypeConversion41 != 0.0F) {
    rtb_LL_LDW_LatestWarnLine_C = LKAS_ConstB.DataTypeConversion41;
  } else {
    rtb_LL_LDW_LatestWarnLine_C = LL_LDW_LatestWarnLine_C;
  }

  /* End of Switch: '<S613>/Switch21' */

  /* Switch: '<S613>/Switch19' incorporates:
   *  Constant: '<S613>/LL_LKA_EarliestWarnLine_C=0.3'
   */
  if (LKAS_ConstB.DataTypeConversion42 != 0.0F) {
    rtb_LL_LKA_EarliestWarnLine_C = LKAS_ConstB.DataTypeConversion42;
  } else {
    rtb_LL_LKA_EarliestWarnLine_C = LL_LKA_EarliestWarnLine_C;
  }

  /* End of Switch: '<S613>/Switch19' */

  /* Switch: '<S613>/Switch20' incorporates:
   *  Constant: '<S613>/LL_LKA_LatestWarnLine_C=-0.5'
   */
  if (LKAS_ConstB.DataTypeConversion43 != 0.0F) {
    rtb_LL_LKA_LatestWarnLine_C = LKAS_ConstB.DataTypeConversion43;
  } else {
    rtb_LL_LKA_LatestWarnLine_C = LL_LKA_LatestWarnLine_C;
  }

  /* End of Switch: '<S613>/Switch20' */

  /* Switch: '<S613>/Switch3' incorporates:
   *  Constant: '<S613>/LL_MIN_LKAS_SPEED_DISABLE=55'
   */
  if (LKAS_ConstB.DataTypeConversion51 != 0.0F) {
    rtb_Saturation9 = LKAS_ConstB.DataTypeConversion51;
  } else {
    rtb_Saturation9 = LL_MIN_LKAS_SPEED_DISABLE;
  }

  /* End of Switch: '<S613>/Switch3' */

  /* Gain: '<S619>/Gain' incorporates:
   *  Constant: '<S619>/Constant'
   *  Sum: '<S619>/Add'
   */
  rtb_Gain_g = (rtb_Saturation9 - 2.5F) * 0.980392158F;

  /* Switch: '<S613>/Switch29' incorporates:
   *  Constant: '<S613>/LL_MAX_SYSTEM_CURVATURE_DISABLE=0.005'
   */
  if (LKAS_ConstB.DataTypeConversion48 != 0.0F) {
    rtb_LL_MAX_SYSTEM_CURVATURE_DIS = LKAS_ConstB.DataTypeConversion48;
  } else {
    rtb_LL_MAX_SYSTEM_CURVATURE_DIS = LL_MAX_SYSTEM_CURVATURE_DISABLE;
  }

  /* End of Switch: '<S613>/Switch29' */

  /* Switch: '<S613>/Switch30' incorporates:
   *  Constant: '<S613>/LL_MIN_LANE_WIDTH_DISABLE=2.4'
   */
  if (LKAS_ConstB.DataTypeConversion49 != 0.0F) {
    rtb_LL_MIN_LANE_WIDTH_DISABLE = LKAS_ConstB.DataTypeConversion49;
  } else {
    rtb_LL_MIN_LANE_WIDTH_DISABLE = LL_MIN_LANE_WIDTH_DISABLE;
  }

  /* End of Switch: '<S613>/Switch30' */

  /* Switch: '<S613>/Switch31' incorporates:
   *  Constant: '<S613>/LL_MAX_LANE_WIDTH_DISABLE=5.5'
   */
  if (LKAS_ConstB.DataTypeConversion50 != 0.0F) {
    rtb_LL_MAX_LANE_WIDTH_DISABLE = LKAS_ConstB.DataTypeConversion50;
  } else {
    rtb_LL_MAX_LANE_WIDTH_DISABLE = LL_MAX_LANE_WIDTH_DISABLE;
  }

  /* End of Switch: '<S613>/Switch31' */

  /* Switch: '<S613>/Switch33' incorporates:
   *  Constant: '<S613>/LL_MAX_DRIVER_TORQUE_DISABLE=1.6'
   */
  if (LKAS_ConstB.DataTypeConversion54 != 0.0F) {
    rtb_LL_MAX_DRIVER_TORQUE_DISABL = LKAS_ConstB.DataTypeConversion54;
  } else {
    rtb_LL_MAX_DRIVER_TORQUE_DISABL = LL_MAX_DRIVER_TORQUE_DISABLE;
  }

  /* End of Switch: '<S613>/Switch33' */

  /* Switch: '<S613>/Switch23' incorporates:
   *  Constant: '<S613>/LL_MAX_LONG_ACC_DISABLE=3.5'
   */
  if (LKAS_ConstB.DataTypeConversion59 != 0.0F) {
    rtb_LL_MAX_LONG_ACC_DISABLE = LKAS_ConstB.DataTypeConversion59;
  } else {
    rtb_LL_MAX_LONG_ACC_DISABLE = LL_MAX_LONG_ACC_DISABLE;
  }

  /* End of Switch: '<S613>/Switch23' */

  /* Switch: '<S613>/Switch27' incorporates:
   *  Constant: '<S613>/LL_TkOvStChk_tiTDelTime=2'
   */
  if (LKAS_ConstB.DataTypeConversion63 != 0.0F) {
    rtb_LL_TkOvStChk_tiTDelTime = LKAS_ConstB.DataTypeConversion63;
  } else {
    rtb_LL_TkOvStChk_tiTDelTime = LL_TkOvStChk_tiTDelTime;
  }

  /* End of Switch: '<S613>/Switch27' */

  /* Switch: '<S613>/Switch42' incorporates:
   *  Constant: '<S613>/LL_ThresDet_lDvtThresLwr=0.15'
   */
  if (LKAS_ConstB.DataTypeConversion3 != 0.0F) {
    rtb_LL_ThresDet_lDvtThresLwrLDW = LKAS_ConstB.DataTypeConversion3;
  } else {
    rtb_LL_ThresDet_lDvtThresLwrLDW = LL_ThresDet_lDvtThresLwrLDW;
  }

  /* End of Switch: '<S613>/Switch42' */

  /* Switch: '<S613>/Switch43' incorporates:
   *  Constant: '<S613>/LL_ThresDet_lDvtThresUpr=0.3'
   */
  if (LKAS_ConstB.DataTypeConversion4 != 0.0F) {
    rtb_LL_ThresDet_lDvtThresUprLDW = LKAS_ConstB.DataTypeConversion4;
  } else {
    rtb_LL_ThresDet_lDvtThresUprLDW = LL_ThresDet_lDvtThresUprLDW;
  }

  /* End of Switch: '<S613>/Switch43' */

  /* Switch: '<S613>/Switch45' incorporates:
   *  Constant: '<S613>/LL_ThresDet_tiTTLCThres=0.75'
   */
  if (LKAS_ConstB.DataTypeConversion2 != 0.0F) {
    rtb_LL_ThresDet_tiTTLCThresLDW = LKAS_ConstB.DataTypeConversion2;
  } else {
    rtb_LL_ThresDet_tiTTLCThresLDW = LL_ThresDet_tiTTLCThresLDW;
  }

  /* End of Switch: '<S613>/Switch45' */

  /* Switch: '<S613>/Switch35' incorporates:
   *  Constant: '<S613>/LL_ThresDet_lDvtThresLwrLKA=0.3'
   */
  if (LKAS_ConstB.DataTypeConversion79 != 0.0F) {
    rtb_LL_ThresDet_lDvtThresLwrLKA = LKAS_ConstB.DataTypeConversion79;
  } else {
    rtb_LL_ThresDet_lDvtThresLwrLKA = LL_ThresDet_lDvtThresLwrLKA;
  }

  /* End of Switch: '<S613>/Switch35' */

  /* Switch: '<S613>/Switch36' incorporates:
   *  Constant: '<S613>/LL_ThresDet_lDvtThresUprLKA=0.6'
   */
  if (LKAS_ConstB.DataTypeConversion81 != 0.0F) {
    rtb_LL_ThresDet_lDvtThresUprLKA = LKAS_ConstB.DataTypeConversion81;
  } else {
    rtb_LL_ThresDet_lDvtThresUprLKA = LL_ThresDet_lDvtThresUprLKA;
  }

  /* End of Switch: '<S613>/Switch36' */

  /* Switch: '<S613>/Switch37' incorporates:
   *  Constant: '<S613>/LL_ThresDet_tiTTLCThresLKA=1.5'
   */
  if (LKAS_ConstB.DataTypeConversion71 != 0.0F) {
    rtb_LL_ThresDet_tiTTLCThresLKA = LKAS_ConstB.DataTypeConversion71;
  } else {
    rtb_LL_ThresDet_tiTTLCThresLKA = LL_ThresDet_tiTTLCThresLKA;
  }

  /* End of Switch: '<S613>/Switch37' */

  /* Switch: '<S613>/Switch39' incorporates:
   *  Constant: '<S613>/LL_DvtSpdDet_vDvtSpdMin_C=0'
   */
  if (LKAS_ConstB.DataTypeConversion73 != 0.0F) {
    rtb_LL_DvtSpdDet_vDvtSpdMin_C = LKAS_ConstB.DataTypeConversion73;
  } else {
    rtb_LL_DvtSpdDet_vDvtSpdMin_C = LL_DvtSpdDet_vDvtSpdMin_C;
  }

  /* End of Switch: '<S613>/Switch39' */

  /* Switch: '<S612>/Switch1' incorporates:
   *  Constant: '<S612>/LL_DvtComp_C=0'
   */
  if (LKAS_ConstB.DataTypeConversion1_b != 0.0F) {
    rtb_LL_DvtComp_C_f = LKAS_ConstB.DataTypeConversion1_b;
  } else {
    rtb_LL_DvtComp_C_f = LL_DvtComp_C;
  }

  /* End of Switch: '<S612>/Switch1' */

  /* Switch: '<S612>/Switch10' incorporates:
   *  Constant: '<S612>/LL_DesDvt_C=0.2'
   */
  if (LKAS_ConstB.DataTypeConversion22_e != 0.0F) {
    LKAS_B.LL_DesDvt_C_f = LKAS_ConstB.DataTypeConversion22_e;
  } else {
    LKAS_B.LL_DesDvt_C_f = LL_DesDvt_C;
  }

  /* End of Switch: '<S612>/Switch10' */

  /* Switch: '<S612>/Switch15' incorporates:
   *  Constant: '<S612>/LL_lStpLngth_C=5'
   */
  if (LKAS_ConstB.DataTypeConversion21 != 0.0F) {
    LKAS_B.LL_lStpLngth_C_g = LKAS_ConstB.DataTypeConversion21;
  } else {
    LKAS_B.LL_lStpLngth_C_g = LL_lStpLngth_C;
  }

  /* End of Switch: '<S612>/Switch15' */

  /* Switch: '<S612>/Switch31' incorporates:
   *  Constant: '<S612>/LL_LFClb_TFC_vGainLutVehSpdLwr_C=60'
   */
  if (LKAS_ConstB.DataTypeConversion14 != 0.0F) {
    rtb_LL_LFClb_TFC_vGainLutVehSpd = LKAS_ConstB.DataTypeConversion14;
  } else {
    rtb_LL_LFClb_TFC_vGainLutVehSpd = LL_LFClb_TFC_vGainLutVehSpdLwr_C;
  }

  /* End of Switch: '<S612>/Switch31' */

  /* Switch: '<S612>/Switch34' incorporates:
   *  Constant: '<S612>/LL_LFClb_TFC_vGainLutVehSpdUpr_C=120'
   */
  if (LKAS_ConstB.DataTypeConversion4_m != 0.0F) {
    rtb_LL_LFClb_TFC_vGainLutVehS_j = LKAS_ConstB.DataTypeConversion4_m;
  } else {
    rtb_LL_LFClb_TFC_vGainLutVehS_j = LL_LFClb_TFC_vGainLutVehSpdUpr_C;
  }

  /* End of Switch: '<S612>/Switch34' */

  /* Switch: '<S612>/Switch33' incorporates:
   *  Constant: '<S612>/LL_LFClb_TFC_facmGainLutGain1_C=40'
   */
  if (LKAS_ConstB.DataTypeConversion7 != 0.0F) {
    rtb_LL_LFClb_TFC_facmGainLutGai = LKAS_ConstB.DataTypeConversion7;
  } else {
    rtb_LL_LFClb_TFC_facmGainLutGai = LL_LFClb_TFC_facmGainLutGain1_C;
  }

  /* End of Switch: '<S612>/Switch33' */

  /* Switch: '<S612>/Switch48' incorporates:
   *  Constant: '<S612>/LL_LFClb_TFC_DiffCtrlRatio=600'
   */
  if (LKAS_ConstB.DataTypeConversion48_j != 0.0F) {
    rtb_LL_LFClb_TFC_DiffCtrlRatio = LKAS_ConstB.DataTypeConversion48_j;
  } else {
    rtb_LL_LFClb_TFC_DiffCtrlRatio = LL_LFClb_TFC_DiffCtrlRatio;
  }

  /* End of Switch: '<S612>/Switch48' */

  /* Switch: '<S612>/Switch47' incorporates:
   *  Constant: '<S612>/LL_LKASWASyn_TrqSwaAddSwt=1'
   */
  if (LKAS_ConstB.DataTypeConversion47 != 0.0F) {
    rtb_LL_LKASWASyn_TrqSwaAddSwt = LKAS_ConstB.DataTypeConversion47;
  } else {
    rtb_LL_LKASWASyn_TrqSwaAddSwt = LL_LKASWASyn_TrqSwaAddSwt;
  }

  /* End of Switch: '<S612>/Switch47' */

  /* Switch: '<S612>/Switch11' incorporates:
   *  Constant: '<S612>/LL_LKASWASyn_M0=0.4'
   */
  if (LKAS_ConstB.DataTypeConversion12 != 0.0F) {
    rtb_offset = LKAS_ConstB.DataTypeConversion12;
  } else {
    rtb_offset = LL_LKASWASyn_M0;
  }

  /* End of Switch: '<S612>/Switch11' */

  /* Switch: '<S612>/Switch13' incorporates:
   *  Constant: '<S612>/LL_LKASWASyn_M1=0.8'
   */
  if (LKAS_ConstB.DataTypeConversion19 != 0.0F) {
    rtb_LL_LKASWASyn_M1 = LKAS_ConstB.DataTypeConversion19;
  } else {
    rtb_LL_LKASWASyn_M1 = LL_LKASWASyn_M1;
  }

  /* End of Switch: '<S612>/Switch13' */

  /* Switch: '<S612>/Switch16' incorporates:
   *  Constant: '<S612>/LL_LKASWASyn_T2=4'
   */
  if (LKAS_ConstB.DataTypeConversion24_h != 0.0F) {
    rtb_LL_LKASWASyn_T2 = LKAS_ConstB.DataTypeConversion24_h;
  } else {
    rtb_LL_LKASWASyn_T2 = LL_LKASWASyn_T2;
  }

  /* End of Switch: '<S612>/Switch16' */

  /* Switch: '<S612>/Switch55' incorporates:
   *  Constant: '<S612>/LL_LKAExPrcs_tiExitTime3=8'
   */
  if (LKAS_ConstB.DataTypeConversion55_p != 0.0F) {
    rtb_LL_LKAExPrcs_tiExitTime1 = LKAS_ConstB.DataTypeConversion55_p;
  } else {
    rtb_LL_LKAExPrcs_tiExitTime1 = LL_LKAExPrcs_tiExitTime1;
  }

  /* End of Switch: '<S612>/Switch55' */

  /* Switch: '<S612>/Switch54' incorporates:
   *  Constant: '<S612>/LL_LKAExPrcs_tiExitTime3=4'
   */
  if (LKAS_ConstB.DataTypeConversion54_l != 0.0F) {
    rtb_LL_LKAExPrcs_tiExitTime2 = LKAS_ConstB.DataTypeConversion54_l;
  } else {
    rtb_LL_LKAExPrcs_tiExitTime2 = LL_LKAExPrcs_tiExitTime2;
  }

  /* End of Switch: '<S612>/Switch54' */

  /* Switch: '<S612>/Switch44' incorporates:
   *  Constant: '<S612>/LL_LKAExPrcs_ExitC0Dvt=0.01'
   */
  if (LKAS_ConstB.DataTypeConversion33_i != 0.0F) {
    rtb_LL_LKAExPrcs_ExitC0Dvt = LKAS_ConstB.DataTypeConversion33_i;
  } else {
    rtb_LL_LKAExPrcs_ExitC0Dvt = LL_LKAExPrcs_ExitC0Dvt;
  }

  /* End of Switch: '<S612>/Switch44' */

  /* Switch: '<S610>/Switch19' incorporates:
   *  Constant: '<S610>/LKA_SampleTime=0.01'
   */
  if (LKAS_ConstB.DataTypeConversion3_o != 0.0F) {
    rtb_LKA_SampleTime = LKAS_ConstB.DataTypeConversion3_o;
  } else {
    rtb_LKA_SampleTime = LKA_SampleTime;
  }

  /* End of Switch: '<S610>/Switch19' */

  /* Switch: '<S610>/Switch' incorporates:
   *  Constant: '<S610>/LKA_Veh2CamW_C=0.9'
   */
  if (LKAS_ConstB.DataTypeConversion13_k != 0.0F) {
    rtb_LKA_Veh2CamW_C = LKAS_ConstB.DataTypeConversion13_k;
  } else {
    rtb_LKA_Veh2CamW_C = LKA_Veh2CamW_C;
  }

  /* End of Switch: '<S610>/Switch' */

  /* Switch: '<S610>/Switch1' incorporates:
   *  Constant: '<S610>/LKA_Veh2CamL_C=1.56'
   */
  if (LKAS_ConstB.DataTypeConversion2_h != 0.0F) {
    rtb_LKA_Veh2CamL_C = LKAS_ConstB.DataTypeConversion2_h;
  } else {
    rtb_LKA_Veh2CamL_C = LKA_Veh2CamL_C;
  }

  /* End of Switch: '<S610>/Switch1' */

  /* Switch: '<S610>/Switch2' incorporates:
   *  Constant: '<S610>/LKA_WhlBaseL_C=2.65'
   */
  if (LKAS_ConstB.DataTypeConversion4_d != 0.0F) {
    LKAS_B.LKA_WhlBaseL_C_n = LKAS_ConstB.DataTypeConversion4_d;
  } else {
    LKAS_B.LKA_WhlBaseL_C_n = LKA_WhlBaseL_C;
  }

  /* End of Switch: '<S610>/Switch2' */

  /* Switch: '<S610>/Switch3' incorporates:
   *  Constant: '<S610>/LKA_StrRatio_C=15.3'
   */
  if (LKAS_ConstB.DataTypeConversion6_j != 0.0F) {
    LKAS_B.LKA_StrRatio_C_h = LKAS_ConstB.DataTypeConversion6_j;
  } else {
    LKAS_B.LKA_StrRatio_C_h = LKA_StrRatio_C;
  }

  /* End of Switch: '<S610>/Switch3' */

  /* DataTypeConversion: '<S1>/IMAPve_d_EPS_Error_State_1' */
  rtb_EPS_LKA_Control = (UInt8)tmpRead_3;

  /* Outputs for Enabled SubSystem: '<S2>/LLOn' incorporates:
   *  EnablePort: '<S10>/states'
   */
  if (rtb_IMAPve_d_LKA_Main_Switch > 0) {
    if (!LKAS_DW.LLOn_MODE) {
      /* InitializeConditions for Memory: '<S547>/Memory' */
      LKAS_DW.Memory_PreviousInput_d = 0.0F;

      /* InitializeConditions for Delay: '<S92>/Delay' */
      LKAS_DW.Delay_DSTATE = ((uint8)0U);

      /* InitializeConditions for UnitDelay: '<S507>/UD'
       *
       * Block description for '<S507>/UD':
       *
       *  Store in Global RAM
       */
      LKAS_DW.UD_DSTATE = 0.0F;

      /* InitializeConditions for Memory: '<S491>/Memory' */
      LKAS_DW.Memory_PreviousInput_p = 0.0F;

      /* InitializeConditions for UnitDelay: '<S408>/UD'
       *
       * Block description for '<S408>/UD':
       *
       *  Store in Global RAM
       */
      LKAS_DW.UD_DSTATE_c = 0.0F;

      /* InitializeConditions for UnitDelay: '<S417>/Delay Input1'
       *
       * Block description for '<S417>/Delay Input1':
       *
       *  Store in Global RAM
       */
      LKAS_DW.DelayInput1_DSTATE = false;

      /* InitializeConditions for UnitDelay: '<S415>/Unit Delay' */
      LKAS_DW.UnitDelay_DSTATE_ba = false;

      /* InitializeConditions for UnitDelay: '<S416>/Delay Input1'
       *
       * Block description for '<S416>/Delay Input1':
       *
       *  Store in Global RAM
       */
      LKAS_DW.DelayInput1_DSTATE_j = false;

      /* InitializeConditions for Delay: '<S93>/Delay1' */
      LKAS_DW.Delay1_3_DSTATE = ((uint8)0U);

      /* InitializeConditions for UnitDelay: '<S379>/Delay Input1'
       *
       * Block description for '<S379>/Delay Input1':
       *
       *  Store in Global RAM
       */
      LKAS_DW.DelayInput1_DSTATE_b = false;

      /* InitializeConditions for UnitDelay: '<S377>/Unit Delay' */
      LKAS_DW.UnitDelay_DSTATE_c = false;

      /* InitializeConditions for UnitDelay: '<S378>/Delay Input1'
       *
       * Block description for '<S378>/Delay Input1':
       *
       *  Store in Global RAM
       */
      LKAS_DW.DelayInput1_DSTATE_p = false;

      /* InitializeConditions for Memory: '<S342>/Memory' */
      LKAS_DW.Memory_PreviousInput_eb = false;

      /* InitializeConditions for Delay: '<S93>/Delay' */
      LKAS_DW.Delay_DSTATE_e = false;

      /* InitializeConditions for Delay: '<S93>/Delay1' */
      LKAS_DW.Delay1_1_DSTATE = ((uint8)0U);

      /* InitializeConditions for Memory: '<S392>/Memory' */
      LKAS_DW.Memory_PreviousInput_ms = ((uint8)0U);

      /* InitializeConditions for Delay: '<S93>/Delay1' */
      LKAS_DW.Delay1_2_DSTATE = ((uint8)0U);

      /* SystemReset for Chart: '<S93>/LDW_State_Machine'
       *
       * Block description for '<S93>/LDW_State_Machine':
       *  Block Name: LDW State Machine
       *  Ab.: LDWSM
       *  No.: 1.1.2.0
       *  Rev: 0.0.1
       *  Update Date: 19-3-26
       */
      LKAS_LDW_State_Machine_Reset();

      /* SystemReset for Chart: '<S93>/LKA_State_Machine'
       *
       * Block description for '<S93>/LKA_State_Machine':
       *  Block Name: LKA State Machine
       *  Ab.: LKASM
       *  No.: 1.1.3.0
       *  Rev: 0.0.1
       *  Update Date: 19-3-26
       */
      LKAS_LKA_State_Machine_Reset();
      LKAS_DW.LLOn_MODE = true;
    }

    /* Sum: '<S233>/Add1' incorporates:
     *  Sum: '<S233>/Add'
     *  Sum: '<S442>/Add1'
     */
    rtb_Abs_cf = (rtb_L0_C0 - rtb_LL_DvtComp_C) + rtb_LKA_Veh2CamW_C;

    /* Gain: '<S233>/Gain1' incorporates:
     *  Product: '<S233>/Divide'
     *  Product: '<S233>/Divide1'
     *  Sum: '<S233>/Add1'
     *  Sum: '<S233>/Add5'
     *  Trigonometry: '<S233>/Cos2'
     *  Trigonometry: '<S233>/Sin'
     */
    rtb_Gain1 = (rtb_Abs_cf * cosf(rtb_L0_C1) + rtb_LKA_Veh2CamL_C * sinf
                 (rtb_L0_C1)) * (-1.0F);

    /* Outputs for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    /* Outputs for Enabled SubSystem: '<S100>/Subsystem' incorporates:
     *  EnablePort: '<S107>/Enable'
     */
    /* Abs: '<S224>/Abs' incorporates:
     *  Abs: '<S119>/Abs2'
     *  Abs: '<S120>/Abs2'
     *  MATLAB Function: '<S107>/DriverSwaTrqAdd'
     */
    u0_tmp_tmp = fabsf(rtb_L0_C0);

    /* Abs: '<S224>/Abs1' incorporates:
     *  Abs: '<S119>/Abs3'
     *  Abs: '<S120>/Abs3'
     *  MATLAB Function: '<S107>/DriverSwaTrqAdd'
     */
    u0_tmp_tmp_0 = fabsf(rtb_R0_C0);

    /* End of Outputs for SubSystem: '<S100>/Subsystem' */

    /* Sum: '<S224>/Add' incorporates:
     *  Abs: '<S224>/Abs'
     *  Abs: '<S224>/Abs1'
     *  Sum: '<S191>/Add6'
     *  Sum: '<S309>/Add1'
     *  Sum: '<S348>/Add1'
     */
    rtb_Saturation_k = u0_tmp_tmp + u0_tmp_tmp_0;

    /* End of Outputs for SubSystem: '<S10>/LKA' */

    /* Saturate: '<S224>/Saturation' incorporates:
     *  Sum: '<S224>/Add'
     */
    if (rtb_Saturation_k > 6.0F) {
      rtb_LaneWidth = 6.0F;
    } else if (rtb_Saturation_k < 2.0F) {
      rtb_LaneWidth = 2.0F;
    } else {
      rtb_LaneWidth = rtb_Saturation_k;
    }

    /* End of Saturate: '<S224>/Saturation' */

    /* Sum: '<S517>/Add1' incorporates:
     *  Constant: '<S517>/Constant1'
     *  Gain: '<S517>/Gain'
     *  Sum: '<S535>/Add1'
     */
    rtb_Abs_o = 0.5F * rtb_LaneWidth - 1.5F;
    rtb_Add1_k = rtb_Abs_o;

    /* Switch: '<S518>/Switch' incorporates:
     *  Constant: '<S517>/Constant'
     *  RelationalOperator: '<S518>/UpperRelop'
     */
    if (rtb_Add1_k < 0.0F) {
      rtb_Switch = 0.0F;
    } else {
      rtb_Switch = rtb_Add1_k;
    }

    /* End of Switch: '<S518>/Switch' */

    /* Switch: '<S518>/Switch2' incorporates:
     *  RelationalOperator: '<S518>/LowerRelop1'
     */
    if (rtb_Add1_k > rtb_Abs_h) {
      rtb_Switch2 = rtb_Abs_h;
    } else {
      rtb_Switch2 = rtb_Switch;
    }

    /* End of Switch: '<S518>/Switch2' */

    /* Sum: '<S239>/Add1' incorporates:
     *  Sum: '<S239>/Add'
     *  Sum: '<S443>/Add1'
     */
    rtb_Saturation5_cw = (rtb_R0_C0 - rtb_LL_DvtComp_C) - rtb_LKA_Veh2CamW_C;

    /* Sum: '<S239>/Add5' incorporates:
     *  Product: '<S239>/Divide'
     *  Product: '<S239>/Divide1'
     *  Sum: '<S239>/Add1'
     *  Trigonometry: '<S239>/Cos2'
     *  Trigonometry: '<S239>/Sin'
     */
    rtb_Add5_j = rtb_Saturation5_cw * cosf(rtb_R0_C1) + rtb_LKA_Veh2CamL_C *
      sinf(rtb_R0_C1);

    /* Switch: '<S549>/Switch' incorporates:
     *  Constant: '<S614>/Constant'
     *  Constant: '<S615>/Constant'
     *  Gain: '<S614>/Gain'
     *  Gain: '<S615>/Gain'
     *  Sum: '<S614>/Add'
     *  Sum: '<S615>/Add'
     *  Switch: '<S613>/Switch'
     */
    if (LKAS_B.IMAPve_d_LKA_Mode >= ((uint8)2U)) {
      /* Switch: '<S613>/Switch1' incorporates:
       *  Constant: '<S613>/LL_MAX_LKAS_SPEED_ENABLE=140'
       */
      if (LKAS_ConstB.DataTypeConversion23 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion23;
      } else {
        rtb_Saturation9 = LL_MAX_LKAS_SPEED_ENABLE;
      }

      /* End of Switch: '<S613>/Switch1' */
      rtb_Switch_i = (rtb_Saturation9 - 2.5F) * 0.980392158F;
    } else {
      if (LKAS_ConstB.DataTypeConversion22 != 0.0F) {
        /* Switch: '<S613>/Switch' */
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion22;
      } else {
        /* Switch: '<S613>/Switch' incorporates:
         *  Constant: '<S613>/LL_MAX_LDWS_SPEED_ENABLE=140'
         */
        rtb_Saturation9 = LL_MAX_LDWS_SPEED_ENABLE;
      }

      rtb_Switch_i = (rtb_Saturation9 - 2.5F) * 0.980392158F;
    }

    /* End of Switch: '<S549>/Switch' */

    /* Switch: '<S547>/Switch' incorporates:
     *  Constant: '<S547>/Constant'
     *  Constant: '<S547>/Constant1'
     *  Constant: '<S552>/Constant'
     *  Constant: '<S553>/Constant'
     *  Constant: '<S554>/Constant'
     *  Logic: '<S547>/Logical Operator'
     *  RelationalOperator: '<S552>/Compare'
     *  RelationalOperator: '<S553>/Compare'
     *  RelationalOperator: '<S554>/Compare'
     */
    if ((rtb_IMAPve_d_BCM_HazardLamp > ((uint8)0U)) ||
        (rtb_IMAPve_d_BCM_Left_Light > ((uint8)0U)) ||
        (rtb_IMAPve_d_BCM_Right_Light > ((uint8)0U))) {
      rtb_Saturation9 = 3.0F;
    } else {
      rtb_Saturation9 = (-1.0F);
    }

    /* End of Switch: '<S547>/Switch' */

    /* Sum: '<S547>/Add' incorporates:
     *  Memory: '<S547>/Memory'
     */
    rtb_Saturation10 = rtb_Saturation9 + LKAS_DW.Memory_PreviousInput_d;

    /* Saturate: '<S547>/Saturation' */
    if (rtb_Saturation10 > 200.0F) {
      rtb_Saturation_e = 200.0F;
    } else if (rtb_Saturation10 < (-1.0F)) {
      rtb_Saturation_e = (-1.0F);
    } else {
      rtb_Saturation_e = rtb_Saturation10;
    }

    /* End of Saturate: '<S547>/Saturation' */

    /* Abs: '<S541>/Abs1' incorporates:
     *  Abs: '<S448>/Abs1'
     */
    rtb_Abs1_tmp = fabsf(rtb_LaneWidth);
    rtb_Abs1 = rtb_Abs1_tmp;

    /* Switch: '<S612>/Switch2' incorporates:
     *  Constant: '<S612>/LL_CrvtPrvwT_C=0.45'
     */
    if (LKAS_ConstB.DataTypeConversion16 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion16;
    } else {
      rtb_Saturation9 = LL_CrvtPrvwT_C;
    }

    /* End of Switch: '<S612>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    /* Gain: '<S271>/kph to mps' incorporates:
     *  Gain: '<S128>/Gain'
     *  Gain: '<S169>/kph To mps'
     *  Gain: '<S185>/kph to mps'
     *  Gain: '<S186>/kph to mps'
     *  Gain: '<S229>/Gain2'
     *  Gain: '<S240>/kph to mps'
     *  Gain: '<S259>/kph to mps'
     *  Gain: '<S260>/kph to mps'
     *  Gain: '<S267>/kph To mps'
     *  Gain: '<S311>/Gain'
     *  Gain: '<S350>/Gain'
     */
    rtb_Abs_h = 0.277777791F * rtb_IMAPve_g_ESC_VehSpd;

    /* End of Outputs for SubSystem: '<S10>/LKA' */

    /* Product: '<S271>/Divide' incorporates:
     *  Gain: '<S271>/kph to mps'
     */
    rtb_Saturation4_g = rtb_Abs_h * rtb_Saturation9;

    /* Gain: '<S268>/Gain' incorporates:
     *  Gain: '<S257>/Gain'
     *  Gain: '<S258>/Gain'
     */
    rtb_Add_hn_tmp = 2.0F * rtb_L0_C2;

    /* Sum: '<S268>/Add' incorporates:
     *  Gain: '<S268>/Gain'
     *  Gain: '<S268>/Gain1'
     *  Product: '<S268>/Product'
     */
    rtb_Add_hn = 6.0F * rtb_L0_C3 * rtb_Saturation4_g + rtb_Add_hn_tmp;

    /* Gain: '<S269>/Gain' incorporates:
     *  Gain: '<S255>/Gain'
     *  Gain: '<S256>/Gain'
     */
    rtb_Add_jc_tmp = 2.0F * rtb_R0_C2;

    /* Sum: '<S269>/Add' incorporates:
     *  Gain: '<S269>/Gain'
     *  Gain: '<S269>/Gain1'
     *  Product: '<S269>/Product'
     */
    rtb_Add_jc = 6.0F * rtb_R0_C3 * rtb_Saturation4_g + rtb_Add_jc_tmp;

    /* If: '<S270>/If' incorporates:
     *  Delay: '<S92>/Delay'
     */
    if (LKAS_DW.Delay_DSTATE == 1) {
      /* Outputs for IfAction SubSystem: '<S270>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S273>/Action Port'
       */
      LKAS_ifaction3(rtb_Add_hn, &rtb_Merge_k);

      /* End of Outputs for SubSystem: '<S270>/If Action Subsystem2' */
    } else if (LKAS_DW.Delay_DSTATE == 2) {
      /* Outputs for IfAction SubSystem: '<S270>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S272>/Action Port'
       */
      LKAS_ifaction3(rtb_Add_jc, &rtb_Merge_k);

      /* End of Outputs for SubSystem: '<S270>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S270>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S274>/Action Port'
       */
      LKAS_IfActionSubsystem3(rtb_Add_hn, rtb_Add_jc, &rtb_Merge_k);

      /* End of Outputs for SubSystem: '<S270>/If Action Subsystem3' */
    }

    /* End of If: '<S270>/If' */

    /* Outputs for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    /* Abs: '<S539>/Abs' incorporates:
     *  Abs: '<S118>/Abs'
     *  Abs: '<S119>/Abs'
     *  Abs: '<S120>/Abs4'
     *  Abs: '<S405>/Abs1'
     *  Abs: '<S446>/Abs'
     */
    rtb_Abs_tmp = fabsf(rtb_Merge_k);

    /* End of Outputs for SubSystem: '<S10>/LKA' */
    rtb_Abs = rtb_Abs_tmp;

    /* SampleTimeMath: '<S507>/TSamp' incorporates:
     *  SampleTimeMath: '<S408>/TSamp'
     *
     * About '<S507>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * About '<S408>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_tmp = rtb_IMAPve_g_SW_Angle * 100.0F;
    rtb_TSamp = rtb_TSamp_tmp;

    /* Sum: '<S507>/Diff' incorporates:
     *  UnitDelay: '<S507>/UD'
     *
     * Block description for '<S507>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S507>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Diff = rtb_TSamp - LKAS_DW.UD_DSTATE;

    /* Switch: '<S613>/Switch14' */
    if (LKAS_ConstB.DataTypeConversion34 != 0.0F) {
      /* UnaryMinus: '<S501>/Unary Minus' */
      rtb_UnaryMinus = -LKAS_ConstB.DataTypeConversion34;
    } else {
      /* UnaryMinus: '<S501>/Unary Minus' incorporates:
       *  Constant: '<S613>/LL_MAX_LONG_DECEL_ENABLE=2'
       */
      rtb_UnaryMinus = -LL_MAX_LONG_DECEL_ENABLE;
    }

    /* End of Switch: '<S613>/Switch14' */

    /* Switch: '<S613>/Switch8' incorporates:
     *  Constant: '<S613>/LL_MAX_STEER_ANGLE_ENABLE=60'
     */
    if (LKAS_ConstB.DataTypeConversion30 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion30;
    } else {
      rtb_Saturation9 = LL_MAX_STEER_ANGLE_ENABLE;
    }

    /* End of Switch: '<S613>/Switch8' */

    /* Switch: '<S613>/Switch10' incorporates:
     *  Constant: '<S613>/LL_MAX_STEER_SPEED_ENABLE=150'
     */
    if (LKAS_ConstB.DataTypeConversion32 != 0.0F) {
      rtb_Saturation10 = LKAS_ConstB.DataTypeConversion32;
    } else {
      rtb_Saturation10 = LL_MAX_STEER_SPEED_ENABLE;
    }

    /* End of Switch: '<S613>/Switch10' */

    /* Switch: '<S613>/Switch9' incorporates:
     *  Constant: '<S613>/LL_MAX_DRIVER_TORQUE_ENABLE=3'
     */
    if (LKAS_ConstB.DataTypeConversion31 != 0.0F) {
      rtb_Saturation4_g = LKAS_ConstB.DataTypeConversion31;
    } else {
      rtb_Saturation4_g = LL_MAX_DRIVER_TORQUE_ENABLE;
    }

    /* End of Switch: '<S613>/Switch9' */

    /* Switch: '<S613>/Switch11' incorporates:
     *  Constant: '<S613>/LL_MAX_LAT_ACC_ENABLE=3'
     */
    if (LKAS_ConstB.DataTypeConversion33 != 0.0F) {
      rtb_LogicalOperator3_g_tmp_2 = LKAS_ConstB.DataTypeConversion33;
    } else {
      rtb_LogicalOperator3_g_tmp_2 = LL_MAX_LAT_ACC_ENABLE;
    }

    /* End of Switch: '<S613>/Switch11' */

    /* Abs: '<S501>/Abs1' incorporates:
     *  Abs: '<S404>/Abs'
     *  Abs: '<S405>/Abs'
     */
    rtb_Saturation1_gx = fabsf(rtb_IMAPve_g_EPS_SW_Trq);

    /* Abs: '<S537>/Abs' incorporates:
     *  Abs: '<S444>/Abs'
     *  Sum: '<S537>/Add'
     */
    rtb_LogicalOperator3_g_tmp = fabsf(rtb_L0_C1 - rtb_R0_C1);

    /* Abs: '<S501>/Abs2' incorporates:
     *  Abs: '<S276>/Abs2'
     *  Abs: '<S403>/Abs2'
     */
    rtb_LogicalOperator3_g_tmp_0 = fabsf(rtb_IMAPve_g_SW_Angle);

    /* Abs: '<S501>/Abs4' incorporates:
     *  Abs: '<S403>/Abs4'
     *  DataTypeConversion: '<S1>/IMAPve_g_ESC_LatAcc_1'
     */
    rtb_LogicalOperator3_g_tmp_1 = fabsf(rtb_TTLC);

    /* Logic: '<S502>/Logical Operator2' incorporates:
     *  Abs: '<S501>/Abs1'
     *  Abs: '<S501>/Abs2'
     *  Abs: '<S501>/Abs3'
     *  Abs: '<S501>/Abs4'
     *  Abs: '<S537>/Abs'
     *  Constant: '<S539>/Constant'
     *  Constant: '<S542>/Constant'
     *  Constant: '<S544>/Constant'
     *  Constant: '<S545>/Constant'
     *  Constant: '<S551>/Constant'
     *  Constant: '<S555>/Constant'
     *  Logic: '<S501>/Logical Operator3'
     *  Logic: '<S508>/FixPt Logical Operator'
     *  Logic: '<S538>/Logical Operator3'
     *  Logic: '<S540>/Logical Operator'
     *  Logic: '<S543>/FixPt Logical Operator'
     *  Logic: '<S546>/FixPt Logical Operator'
     *  Logic: '<S550>/Logical Operator'
     *  Logic: '<S556>/FixPt Logical Operator'
     *  RelationalOperator: '<S501>/Relational Operator'
     *  RelationalOperator: '<S501>/Relational Operator1'
     *  RelationalOperator: '<S501>/Relational Operator2'
     *  RelationalOperator: '<S501>/Relational Operator3'
     *  RelationalOperator: '<S508>/Lower Test'
     *  RelationalOperator: '<S508>/Upper Test'
     *  RelationalOperator: '<S542>/Compare'
     *  RelationalOperator: '<S543>/Lower Test'
     *  RelationalOperator: '<S543>/Upper Test'
     *  RelationalOperator: '<S544>/Compare'
     *  RelationalOperator: '<S545>/Compare'
     *  RelationalOperator: '<S546>/Lower Test'
     *  RelationalOperator: '<S546>/Upper Test'
     *  RelationalOperator: '<S551>/Compare'
     *  RelationalOperator: '<S555>/Compare'
     *  RelationalOperator: '<S556>/Lower Test'
     *  RelationalOperator: '<S556>/Upper Test'
     *  Switch: '<S70>/Switch'
     *  Switch: '<S70>/Switch1'
     */
    rtb_LogicalOperator3_o = ((rtb_Gain_k <= rtb_IMAPve_g_ESC_VehSpd) &&
      (rtb_IMAPve_g_ESC_VehSpd <= rtb_Switch_i) && (rtb_Saturation_e <= 0.0F) &&
      (rtb_IMAPve_d_TCU_Actual_Gear == ((uint8)3U)) && ((rtb_L0_Q > ((uint8)2U))
      && (rtb_R0_Q > ((uint8)2U)) && ((rtb_LL_MIN_LANE_WIDTH_ENABLE <= rtb_Abs1)
      && (rtb_Abs1 <= rtb_LL_MAX_LANE_WIDTH_ENABLE)) && ((0.0F <= rtb_Abs) &&
      (rtb_Abs <= rtb_LL_MAX_SYSTEM_CURVATURE_ENA)) &&
      (rtb_LogicalOperator3_g_tmp <= 0.025F)) && ((rtb_LogicalOperator3_g_tmp_0 <
      rtb_Saturation9) && (fabsf(rtb_Diff) < rtb_Saturation10) &&
      (rtb_Saturation1_gx < rtb_Saturation4_g) && (rtb_LogicalOperator3_g_tmp_1 <
      rtb_LogicalOperator3_g_tmp_2) && ((rtb_UnaryMinus <
      rtb_IMAPve_g_ESC_LonAcc) && (rtb_IMAPve_g_ESC_LonAcc <
      rtb_LL_MAX_LONG_ACC_ENABLE))));

    /* If: '<S502>/If' incorporates:
     *  Constant: '<S509>/Constant'
     *  Constant: '<S515>/Constant'
     *  Constant: '<S516>/Constant'
     *  DataTypeConversion: '<S502>/Cast To Single'
     *  Logic: '<S502>/Logical Operator3'
     *  Logic: '<S513>/Logical Operator'
     *  Logic: '<S514>/Logical Operator'
     *  RelationalOperator: '<S514>/Relational Operator1'
     *  RelationalOperator: '<S514>/Relational Operator2'
     *  RelationalOperator: '<S515>/Compare'
     *  RelationalOperator: '<S516>/Compare'
     */
    if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode == 2)) &&
        ((LKAS_B.IMAPve_d_LKA_Mode >= ((uint8)1U)) && (((rtb_Gain1 >=
            rtb_Switch2) && (rtb_Add5_j >= rtb_Switch2)) == (sint32)true) &&
         rtb_LogicalOperator3_o)) {
      /* Outputs for IfAction SubSystem: '<S502>/If Action Subsystem' incorporates:
       *  ActionPort: '<S509>/Action Port'
       */
      LKAS_B.Merge_k = true;

      /* End of Outputs for SubSystem: '<S502>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S502>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S511>/Action Port'
       */
      LKAS_IfActionSubsystem4(&LKAS_B.Merge_k);

      /* End of Outputs for SubSystem: '<S502>/If Action Subsystem3' */
    }

    /* End of If: '<S502>/If' */

    /* UnaryMinus: '<S229>/Unary Minus' incorporates:
     *  Product: '<S229>/Product'
     */
    rtb_Saturation9 = -(rtb_Abs_h * rtb_L0_C1);

    /* Saturate: '<S229>/Saturation9' */
    if (rtb_Saturation9 > 1.0F) {
      rtb_Saturation9 = 1.0F;
    } else {
      if (rtb_Saturation9 < (-1.0F)) {
        rtb_Saturation9 = (-1.0F);
      }
    }

    /* End of Saturate: '<S229>/Saturation9' */

    /* Product: '<S229>/Product3' */
    rtb_Saturation10 = rtb_Abs_h * rtb_R0_C1;

    /* Saturate: '<S229>/Saturation10' */
    if (rtb_Saturation10 > 1.0F) {
      rtb_Saturation10 = 1.0F;
    } else {
      if (rtb_Saturation10 < (-1.0F)) {
        rtb_Saturation10 = (-1.0F);
      }
    }

    /* End of Saturate: '<S229>/Saturation10' */

    /* Sum: '<S535>/Add1' */
    rtb_Add1_g = rtb_Abs_o;

    /* Switch: '<S536>/Switch' incorporates:
     *  Constant: '<S535>/Constant'
     *  RelationalOperator: '<S536>/UpperRelop'
     */
    if (rtb_Add1_g < 0.0F) {
      rtb_Switch_o = 0.0F;
    } else {
      rtb_Switch_o = rtb_Add1_g;
    }

    /* End of Switch: '<S536>/Switch' */

    /* Switch: '<S536>/Switch2' incorporates:
     *  RelationalOperator: '<S536>/LowerRelop1'
     */
    if (rtb_Add1_g > rtb_LL_LKA_EarliestWarnLine_C) {
      rtb_Switch2_k = rtb_LL_LKA_EarliestWarnLine_C;
    } else {
      rtb_Switch2_k = rtb_Switch_o;
    }

    /* End of Switch: '<S536>/Switch2' */

    /* Abs: '<S522>/Abs1' incorporates:
     *  Abs: '<S432>/Abs'
     */
    rtb_Abs_o = fabsf(rtb_Saturation9);

    /* Abs: '<S522>/Abs2' incorporates:
     *  Abs: '<S432>/Abs1'
     */
    rtb_LogicalOperator3_g_tmp_2 = fabsf(rtb_Saturation10);

    /* Logic: '<S502>/Logical Operator1' incorporates:
     *  Abs: '<S522>/Abs1'
     *  Abs: '<S522>/Abs2'
     *  Constant: '<S524>/Constant'
     *  Constant: '<S525>/Constant'
     *  Constant: '<S530>/Constant'
     *  Constant: '<S531>/Constant'
     *  Constant: '<S532>/Constant'
     *  Constant: '<S533>/Constant'
     *  Logic: '<S519>/Logical Operator'
     *  Logic: '<S521>/Logical Operator'
     *  Logic: '<S522>/Logical Operator'
     *  Logic: '<S523>/Logical Operator'
     *  RelationalOperator: '<S522>/Relational Operator2'
     *  RelationalOperator: '<S522>/Relational Operator3'
     *  RelationalOperator: '<S523>/Relational Operator1'
     *  RelationalOperator: '<S523>/Relational Operator2'
     *  RelationalOperator: '<S524>/Compare'
     *  RelationalOperator: '<S525>/Compare'
     *  RelationalOperator: '<S530>/Compare'
     *  RelationalOperator: '<S531>/Compare'
     *  RelationalOperator: '<S532>/Compare'
     *  RelationalOperator: '<S533>/Compare'
     */
    rtb_LogicalOperator3_o = (rtb_LogicalOperator3_o &&
      ((LKAS_B.IMAPve_d_LKA_Mode == ((uint8)2U)) &&
       (((rtb_IMAPve_d_EPS_LKA_State == ((uint8)2U)) ||
         (rtb_IMAPve_d_EPS_LKA_State == ((uint8)1U))) == (sint32)true) &&
       (((rtb_Abs_o <= rtb_LL_LKAS_OUT_OF_CONTROL_LAT_) &&
         (rtb_LogicalOperator3_g_tmp_2 <= rtb_LL_LKAS_OUT_OF_CONTROL_LAT_)) ==
        (sint32)true) && (((rtb_Gain1 >= rtb_Switch2_k) && (rtb_Add5_j >=
      rtb_Switch2_k)) == (sint32)true)));

    /* If: '<S502>/If1' incorporates:
     *  Constant: '<S510>/Constant'
     *  DataTypeConversion: '<S502>/Cast To Single'
     *  DataTypeConversion: '<S502>/Cast To Single2'
     */
    if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && rtb_LogicalOperator3_o) {
      /* Outputs for IfAction SubSystem: '<S502>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S510>/Action Port'
       */
      LKAS_B.Merge1_g = true;

      /* End of Outputs for SubSystem: '<S502>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S502>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S512>/Action Port'
       */
      LKAS_IfActionSubsystem4(&LKAS_B.Merge1_g);

      /* End of Outputs for SubSystem: '<S502>/If Action Subsystem4' */
    }

    /* End of If: '<S502>/If1' */

    /* MATLAB Function: '<S229>/MATLAB Function1' */
    if ((rtb_Add5_j > 0.0F) && (rtb_Add5_j < 2.0F) && (rtb_Saturation10 < 0.0F) &&
        (rtb_Saturation10 > -1.5F)) {
      rtb_TTLC = -rtb_Add5_j / rtb_Saturation10;
    } else {
      rtb_TTLC = 3.0F;
    }

    /* End of MATLAB Function: '<S229>/MATLAB Function1' */

    /* Saturate: '<S229>/Saturation1' */
    if (rtb_TTLC > 2.0F) {
      rtb_TTLC = 2.0F;
    } else {
      if (rtb_TTLC < 0.6F) {
        rtb_TTLC = 0.6F;
      }
    }

    /* End of Saturate: '<S229>/Saturation1' */

    /* Saturate: '<S229>/Saturation5' */
    if (rtb_L0_TLC > 2.0F) {
      rtb_L0_TLC = 2.0F;
    } else {
      if (rtb_L0_TLC < 0.6F) {
        rtb_L0_TLC = 0.6F;
      }
    }

    /* End of Saturate: '<S229>/Saturation5' */

    /* Saturate: '<S229>/Saturation6' */
    if (rtb_R0_TLC > 2.0F) {
      rtb_R0_TLC = 2.0F;
    } else {
      if (rtb_R0_TLC < 0.6F) {
        rtb_R0_TLC = 0.6F;
      }
    }

    /* End of Saturate: '<S229>/Saturation6' */

    /* MATLAB Function: '<S229>/MATLAB Function' */
    if ((rtb_Gain1 > 0.0F) && (rtb_Gain1 < 2.0F) && (rtb_Saturation9 < 0.0F) &&
        (rtb_Saturation9 > -1.5F)) {
      rtb_TTLC_f = -rtb_Gain1 / rtb_Saturation9;
    } else {
      rtb_TTLC_f = 3.0F;
    }

    /* End of MATLAB Function: '<S229>/MATLAB Function' */

    /* Saturate: '<S229>/Saturation' */
    if (rtb_TTLC_f > 2.0F) {
      rtb_TTLC_f = 2.0F;
    } else {
      if (rtb_TTLC_f < 0.6F) {
        rtb_TTLC_f = 0.6F;
      }
    }

    /* End of Saturate: '<S229>/Saturation' */

    /* Lookup_n-D: '<S229>/Lookup Table2' */
    rtb_Saturation4_g = look1_iflf_pbinlgpw(rtb_Abs_h, LKAS_ConstP.pooled16,
      LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex, 7U);

    /* Saturate: '<S229>/Saturation2' */
    if (rtb_Saturation4_g > 0.01F) {
      rtb_Saturation4_g = 0.01F;
    } else {
      if (rtb_Saturation4_g < 0.0F) {
        rtb_Saturation4_g = 0.0F;
      }
    }

    /* End of Saturate: '<S229>/Saturation2' */

    /* Gain: '<S281>/Gain1' incorporates:
     *  Gain: '<S254>/kph To mps'
     */
    rtb_LL_LKA_EarliestWarnLine_C = 0.0174532924F * rtb_IMAPve_g_SW_Angle;

    /* Product: '<S229>/Divide' incorporates:
     *  Constant: '<S229>/Constant1'
     *  Constant: '<S229>/Constant2'
     *  Gain: '<S281>/Gain1'
     *  Math: '<S229>/Math Function'
     *  Product: '<S229>/Product1'
     *  Product: '<S229>/Product2'
     *  Sum: '<S229>/Add'
     *
     * About '<S229>/Math Function':
     *  Operator: magnitude^2
     */
    rtb_Divide_a3 = rtb_LL_LKA_EarliestWarnLine_C / ((rtb_Abs_h * rtb_Abs_h *
      rtb_Saturation4_g + 1.0F) * LKAS_B.LKA_WhlBaseL_C_n *
      LKAS_B.LKA_StrRatio_C_h * 2.0F);

    /* MATLAB Function: '<S229>/MATLAB Function3' */
    rtb_Saturation9 = rtb_L0_C2 - rtb_Divide_a3;
    if ((rtb_Saturation9 <= 0.001F) && ((rtb_L0_C1 > 0.0F) || (rtb_L0_C1 < 0.0F)))
    {
      rtb_Saturation9 = (-rtb_L0_C0 - rtb_LKA_Veh2CamW_C) / rtb_L0_C1;
      if (rtb_Saturation9 > 0.0F) {
        rtb_Saturation4_g = rtb_Saturation9 / rtb_Abs_h;
      } else {
        rtb_Saturation4_g = 3.0F;
      }
    } else {
      rtb_Saturation10 = rtb_L0_C1 * rtb_L0_C1 - rtb_Saturation9 * 4.0F *
        (rtb_L0_C0 + rtb_LKA_Veh2CamW_C);
      if ((rtb_Saturation9 > 0.001F) && (rtb_Saturation10 >= 0.0F)) {
        rtb_Saturation10 = sqrtf(rtb_Saturation10);
        x20 = rtb_Saturation9 * 2.0F;
        rtb_Saturation9 = (rtb_Saturation10 + -rtb_L0_C1) / x20;
        x20 = (-rtb_L0_C1 - rtb_Saturation10) / x20;
        rtb_Saturation10 = fmaxf(rtb_Saturation9, x20);
        rtb_Saturation9 = fminf(rtb_Saturation9, x20);
        if (rtb_Saturation9 > 0.0F) {
          rtb_Saturation4_g = rtb_Saturation9 / rtb_Abs_h;
        } else if (rtb_Saturation10 > 0.0F) {
          rtb_Saturation4_g = rtb_Saturation10 / rtb_Abs_h;
        } else {
          rtb_Saturation4_g = 3.0F;
        }
      } else {
        rtb_Saturation4_g = 3.0F;
      }
    }

    rtb_Saturation4_g = fmaxf(0.6F, fminf(rtb_Saturation4_g, 2.0F));

    /* End of MATLAB Function: '<S229>/MATLAB Function3' */

    /* MATLAB Function: '<S229>/MATLAB Function4' */
    rtb_Saturation9 = rtb_R0_C2 - rtb_Divide_a3;
    if ((rtb_Saturation9 <= 0.001F) && ((rtb_R0_C1 > 0.0F) || (rtb_R0_C1 < 0.0F)))
    {
      rtb_Saturation9 = (-rtb_R0_C0 + rtb_LKA_Veh2CamW_C) / rtb_R0_C1;
      if (rtb_Saturation9 > 0.0F) {
        rtb_Saturation9 /= rtb_Abs_h;
      } else {
        rtb_Saturation9 = 3.0F;
      }
    } else {
      rtb_Saturation10 = rtb_R0_C1 * rtb_R0_C1 - rtb_Saturation9 * 4.0F *
        (rtb_R0_C0 - rtb_LKA_Veh2CamW_C);
      if ((rtb_Saturation9 > 0.001F) && (rtb_Saturation10 >= 0.0F)) {
        rtb_Saturation10 = sqrtf(rtb_Saturation10);
        x20 = rtb_Saturation9 * 2.0F;
        rtb_Saturation9 = (rtb_Saturation10 + -rtb_R0_C1) / x20;
        x20 = (-rtb_R0_C1 - rtb_Saturation10) / x20;
        rtb_Saturation10 = fmaxf(rtb_Saturation9, x20);
        rtb_Saturation9 = fminf(rtb_Saturation9, x20);
        if (rtb_Saturation9 > 0.0F) {
          rtb_Saturation9 /= rtb_Abs_h;
        } else if (rtb_Saturation10 > 0.0F) {
          rtb_Saturation9 = rtb_Saturation10 / rtb_Abs_h;
        } else {
          rtb_Saturation9 = 3.0F;
        }
      } else {
        rtb_Saturation9 = 3.0F;
      }
    }

    rtb_Saturation9 = fmaxf(0.6F, fminf(rtb_Saturation9, 2.0F));

    /* End of MATLAB Function: '<S229>/MATLAB Function4' */

    /* MATLAB Function: '<S229>/MATLAB Function2' */
    if (fabsf(rtb_TTLC_f - rtb_L0_TLC) / rtb_TTLC_f <= 0.2F) {
      rtb_TTLC_f = fminf(rtb_TTLC_f, rtb_L0_TLC);
    }

    if (fabsf(rtb_TTLC - rtb_R0_TLC) / rtb_TTLC <= 0.2F) {
      rtb_TTLC = fminf(rtb_TTLC, rtb_R0_TLC);
    }

    if ((fabsf(rtb_Add_hn) > 0.001F) && (fabsf(rtb_Saturation4_g - rtb_TTLC_f) /
         rtb_TTLC_f <= 0.7F) && (rtb_TTLC_f <= 1.95F)) {
      rtb_TTLC_f = (rtb_TTLC_f + rtb_Saturation4_g) / 2.0F;
    }

    if ((fabsf(rtb_Add_jc) > 0.001F) && (fabsf(rtb_Saturation9 - rtb_TTLC) /
         rtb_TTLC <= 0.7F) && (rtb_TTLC <= 1.95F)) {
      rtb_TTLC = (rtb_TTLC + rtb_Saturation9) / 2.0F;
    }

    /* Saturate: '<S229>/Saturation7' incorporates:
     *  MATLAB Function: '<S229>/MATLAB Function2'
     */
    if (rtb_TTLC_f > 2.0F) {
      rtb_LFTTTLC = 2.0F;
    } else if (rtb_TTLC_f < 0.8F) {
      rtb_LFTTTLC = 0.8F;
    } else {
      rtb_LFTTTLC = rtb_TTLC_f;
    }

    /* End of Saturate: '<S229>/Saturation7' */

    /* Saturate: '<S229>/Saturation8' incorporates:
     *  MATLAB Function: '<S229>/MATLAB Function2'
     */
    if (rtb_TTLC > 2.0F) {
      rtb_RGTTTLC = 2.0F;
    } else if (rtb_TTLC < 0.8F) {
      rtb_RGTTTLC = 0.8F;
    } else {
      rtb_RGTTTLC = rtb_TTLC;
    }

    /* End of Saturate: '<S229>/Saturation8' */

    /* MinMax: '<S226>/Min' */
    rtb_Saturation4_g = fminf(rtb_LFTTTLC, rtb_RGTTTLC);

    /* Saturate: '<S226>/Saturation' */
    if (rtb_Saturation4_g > 2.0F) {
      rtb_Saturation4_g = 2.0F;
    } else {
      if (rtb_Saturation4_g < 0.5F) {
        rtb_Saturation4_g = 0.5F;
      }
    }

    /* End of Saturate: '<S226>/Saturation' */

    /* Lookup_n-D: '<S267>/Lookup Table2' */
    rtb_TTLC = look1_iflf_pbinlgpw(rtb_IMAPve_g_ESC_VehSpd, LKAS_ConstP.pooled16,
      LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex_j, 7U);

    /* Saturate: '<S267>/Saturation1' */
    if (rtb_TTLC > 0.012141F) {
      rtb_TTLC = 0.012141F;
    } else {
      if (rtb_TTLC < 0.000982F) {
        rtb_TTLC = 0.000982F;
      }
    }

    /* End of Saturate: '<S267>/Saturation1' */

    /* Product: '<S254>/Divide2' incorporates:
     *  Constant: '<S267>/constant '
     *  Product: '<S254>/Divide1'
     *  Product: '<S267>/Divide2'
     *  Product: '<S267>/Divide3'
     *  Product: '<S267>/Product1'
     *  Sum: '<S267>/Add'
     */
    rtb_TTLC = rtb_Abs_h / LKAS_B.LKA_WhlBaseL_C_n / (rtb_Abs_h * rtb_Abs_h *
      rtb_TTLC + 1.0F) * rtb_LL_LKA_EarliestWarnLine_C * rtb_Saturation4_g /
      LKAS_B.LKA_StrRatio_C_h;

    /* Switch: '<S612>/Switch8' incorporates:
     *  Constant: '<S612>/LL_DvtPrvwT_C=0.45'
     */
    if (LKAS_ConstB.DataTypeConversion8 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion8;
    } else {
      rtb_Saturation9 = LL_DvtPrvwT_C;
    }

    /* End of Switch: '<S612>/Switch8' */

    /* Product: '<S240>/Divide' */
    rtb_Saturation10 = rtb_Abs_h * rtb_Saturation9;

    /* Product: '<S234>/Divide2' */
    rtb_LL_LKA_EarliestWarnLine_C = rtb_Saturation10 * rtb_TTLC;

    /* Product: '<S259>/Divide' */
    rtb_Saturation4_g *= rtb_Abs_h;

    /* Product: '<S257>/Z*Z' incorporates:
     *  Product: '<S255>/Z*Z'
     */
    rtb_TTLC_f = rtb_Saturation4_g * rtb_Saturation4_g;

    /* Gain: '<S257>/Gain1' incorporates:
     *  Gain: '<S258>/Gain1'
     */
    rtb_R0_TLC = 3.0F * rtb_L0_C3;

    /* Sum: '<S257>/Add' incorporates:
     *  Gain: '<S257>/Gain1'
     *  Product: '<S257>/Product3'
     *  Product: '<S257>/Product4'
     *  Product: '<S257>/Z*Z'
     */
    rtb_Add_b = (rtb_Add_hn_tmp * rtb_Saturation4_g + rtb_L0_C1) + rtb_R0_TLC *
      rtb_TTLC_f;

    /* Product: '<S235>/Z*Z' incorporates:
     *  Product: '<S238>/Z*Z'
     */
    rtb_Saturation9 = rtb_Saturation10 * rtb_Saturation10;

    /* Sum: '<S235>/Add' incorporates:
     *  Product: '<S235>/Product'
     *  Product: '<S235>/Product3'
     *  Product: '<S235>/Product4'
     *  Product: '<S235>/Z*Z'
     *  Product: '<S235>/Z*Z*Z'
     */
    rtb_L0_C3 = ((rtb_L0_C1 * rtb_Saturation10 + rtb_L0_C0) + rtb_L0_C2 *
                 rtb_Saturation9) + rtb_Saturation10 * rtb_Saturation9 *
      rtb_L0_C3;

    /* Sum: '<S236>/Add' */
    rtb_Add_eq = rtb_L0_C3 - rtb_LL_DvtComp_C_f;

    /* MATLAB Function: '<S236>/MATLAB Function' */
    LKAS_MATLABFunction(rtb_Add_eq, rtb_Add_b, &rtb_Abs2);

    /* Sum: '<S226>/Add' */
    rtb_phiPrdcHdAgLft = rtb_Add_b + rtb_TTLC;

    /* Gain: '<S255>/Gain1' incorporates:
     *  Gain: '<S256>/Gain1'
     */
    rtb_L0_TLC = 3.0F * rtb_R0_C3;

    /* Sum: '<S255>/Add' incorporates:
     *  Gain: '<S255>/Gain1'
     *  Product: '<S255>/Product3'
     *  Product: '<S255>/Product4'
     */
    rtb_Add_g = (rtb_Add_jc_tmp * rtb_Saturation4_g + rtb_R0_C1) + rtb_L0_TLC *
      rtb_TTLC_f;

    /* Sum: '<S226>/Add1' */
    rtb_phiPrdcHdAgRgt = rtb_Add_g + rtb_TTLC;

    /* If: '<S252>/If' incorporates:
     *  Delay: '<S92>/Delay'
     */
    if (LKAS_DW.Delay_DSTATE == 1) {
      /* Outputs for IfAction SubSystem: '<S252>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S262>/Action Port'
       */
      LKAS_ifaction3(rtb_phiPrdcHdAgLft, &rtb_Merge_ky);

      /* End of Outputs for SubSystem: '<S252>/If Action Subsystem2' */
    } else if (LKAS_DW.Delay_DSTATE == 2) {
      /* Outputs for IfAction SubSystem: '<S252>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S261>/Action Port'
       */
      LKAS_ifaction3(rtb_phiPrdcHdAgRgt, &rtb_Merge_ky);

      /* End of Outputs for SubSystem: '<S252>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S252>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S263>/Action Port'
       */
      LKAS_IfActionSubsystem3(rtb_phiPrdcHdAgLft, rtb_phiPrdcHdAgRgt,
        &rtb_Merge_ky);

      /* End of Outputs for SubSystem: '<S252>/If Action Subsystem3' */
    }

    /* End of If: '<S252>/If' */

    /* MATLAB Function: '<S236>/ ' incorporates:
     *  MATLAB Function: '<S237>/ '
     */
    rtb_TTLC = rtb_LKA_Veh2CamW_C * cosf(rtb_Merge_ky);
    rtb_Saturation4_g = rtb_LKA_Veh2CamL_C * sinf(rtb_Merge_ky);

    /* Sum: '<S236>/Add3' incorporates:
     *  MATLAB Function: '<S236>/ '
     *  Sum: '<S236>/Add1'
     */
    rtb_Add3 = ((rtb_TTLC + rtb_Saturation4_g) + rtb_Abs2) +
      rtb_LL_LKA_EarliestWarnLine_C;

    /* Sum: '<S238>/Add' incorporates:
     *  Product: '<S238>/Product'
     *  Product: '<S238>/Product3'
     *  Product: '<S238>/Product4'
     *  Product: '<S238>/Z*Z*Z'
     */
    rtb_R0_C3 = ((rtb_R0_C1 * rtb_Saturation10 + rtb_R0_C0) + rtb_R0_C2 *
                 rtb_Saturation9) + rtb_Saturation10 * rtb_Saturation9 *
      rtb_R0_C3;

    /* Sum: '<S237>/Add' */
    rtb_Add_fj = rtb_R0_C3 - rtb_LL_DvtComp_C_f;

    /* MATLAB Function: '<S237>/MATLAB Function' */
    LKAS_MATLABFunction(rtb_Add_fj, rtb_Add_g, &rtb_Abs2);

    /* Sum: '<S237>/Add2' incorporates:
     *  MATLAB Function: '<S237>/ '
     *  Sum: '<S237>/Add4'
     */
    rtb_Add2 = (rtb_Abs2 - (rtb_TTLC - rtb_Saturation4_g)) +
      rtb_LL_LKA_EarliestWarnLine_C;

    /* If: '<S231>/If' incorporates:
     *  Delay: '<S92>/Delay'
     */
    if (LKAS_DW.Delay_DSTATE == 1) {
      /* Outputs for IfAction SubSystem: '<S231>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S242>/Action Port'
       */
      LKAS_ifaction3(rtb_Add3, &rtb_Merge_m);

      /* End of Outputs for SubSystem: '<S231>/If Action Subsystem2' */
    } else if (LKAS_DW.Delay_DSTATE == 2) {
      /* Outputs for IfAction SubSystem: '<S231>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S241>/Action Port'
       */
      LKAS_ifaction3(rtb_Add2, &rtb_Merge_m);

      /* End of Outputs for SubSystem: '<S231>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S231>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S243>/Action Port'
       */
      LKAS_IfActionSubsystem3(rtb_Add3, rtb_Add2, &rtb_Merge_m);

      /* End of Outputs for SubSystem: '<S231>/If Action Subsystem3' */
    }

    /* End of If: '<S231>/If' */

    /* If: '<S232>/If' incorporates:
     *  Delay: '<S92>/Delay'
     */
    if (LKAS_DW.Delay_DSTATE == 1) {
      /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S245>/Action Port'
       */
      LKAS_ifaction3(rtb_Gain1, &rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S232>/If Action Subsystem2' */
    } else if (LKAS_DW.Delay_DSTATE == 2) {
      /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S244>/Action Port'
       */
      LKAS_ifaction3(rtb_Add5_j, &rtb_Merge_p);

      /* End of Outputs for SubSystem: '<S232>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S246>/Action Port'
       */
      /* MinMax: '<S246>/Min' */
      rtb_Merge_p = fminf(rtb_Gain1, rtb_Add5_j);

      /* End of Outputs for SubSystem: '<S232>/If Action Subsystem3' */
    }

    /* End of If: '<S232>/If' */

    /* If: '<S253>/If' incorporates:
     *  Delay: '<S92>/Delay'
     */
    if (LKAS_DW.Delay_DSTATE == 1) {
      /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S265>/Action Port'
       */
      LKAS_ifaction3(rtb_Add_b, &rtb_Merge_kn);

      /* End of Outputs for SubSystem: '<S253>/If Action Subsystem2' */
    } else if (LKAS_DW.Delay_DSTATE == 2) {
      /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S264>/Action Port'
       */
      LKAS_ifaction3(rtb_Add_g, &rtb_Merge_kn);

      /* End of Outputs for SubSystem: '<S253>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      LKAS_IfActionSubsystem3(rtb_Add_b, rtb_Add_g, &rtb_Merge_kn);

      /* End of Outputs for SubSystem: '<S253>/If Action Subsystem3' */
    }

    /* End of If: '<S253>/If' */

    /* Switch: '<S493>/Switch' incorporates:
     *  Constant: '<S617>/Constant'
     *  Constant: '<S618>/Constant'
     *  Gain: '<S617>/Gain'
     *  Gain: '<S618>/Gain'
     *  Sum: '<S617>/Add'
     *  Sum: '<S618>/Add'
     *  Switch: '<S613>/Switch28'
     */
    if (LKAS_B.IMAPve_d_LKA_Mode >= ((uint8)2U)) {
      /* Switch: '<S613>/Switch41' incorporates:
       *  Constant: '<S613>/LL_MAX_LKAS_SPEED_DISABLE=150'
       */
      if (LKAS_ConstB.DataTypeConversion1 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion1;
      } else {
        rtb_Saturation9 = LL_MAX_LKAS_SPEED_DISABLE;
      }

      /* End of Switch: '<S613>/Switch41' */
      rtb_Switch_j = (rtb_Saturation9 - 2.5F) * 0.980392158F;
    } else {
      if (LKAS_ConstB.DataTypeConversion53 != 0.0F) {
        /* Switch: '<S613>/Switch28' */
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion53;
      } else {
        /* Switch: '<S613>/Switch28' incorporates:
         *  Constant: '<S613>/LL_MAX_LDWS_SPEED_DISABLE=150'
         */
        rtb_Saturation9 = LL_MAX_LDWS_SPEED_DISABLE;
      }

      rtb_Switch_j = (rtb_Saturation9 - 2.5F) * 0.980392158F;
    }

    /* End of Switch: '<S493>/Switch' */

    /* Switch: '<S491>/Switch' incorporates:
     *  Constant: '<S491>/Constant'
     *  Constant: '<S491>/Constant1'
     *  Constant: '<S496>/Constant'
     *  Constant: '<S497>/Constant'
     *  Constant: '<S498>/Constant'
     *  Logic: '<S491>/Logical Operator'
     *  RelationalOperator: '<S496>/Compare'
     *  RelationalOperator: '<S497>/Compare'
     *  RelationalOperator: '<S498>/Compare'
     */
    if ((rtb_IMAPve_d_BCM_HazardLamp > ((uint8)0U)) ||
        (rtb_IMAPve_d_BCM_Left_Light > ((uint8)0U)) ||
        (rtb_IMAPve_d_BCM_Right_Light > ((uint8)0U))) {
      rtb_Saturation9 = 3.0F;
    } else {
      rtb_Saturation9 = (-1.0F);
    }

    /* End of Switch: '<S491>/Switch' */

    /* Sum: '<S491>/Add' incorporates:
     *  Memory: '<S491>/Memory'
     */
    rtb_Saturation10 = rtb_Saturation9 + LKAS_DW.Memory_PreviousInput_p;

    /* Saturate: '<S491>/Saturation' */
    if (rtb_Saturation10 > 200.0F) {
      rtb_Saturation_d = 200.0F;
    } else if (rtb_Saturation10 < (-1.0F)) {
      rtb_Saturation_d = (-1.0F);
    } else {
      rtb_Saturation_d = rtb_Saturation10;
    }

    /* End of Saturate: '<S491>/Saturation' */

    /* Abs: '<S448>/Abs1' */
    rtb_Abs1_i = rtb_Abs1_tmp;

    /* Abs: '<S446>/Abs' */
    rtb_Abs_m = rtb_Abs_tmp;

    /* SampleTimeMath: '<S408>/TSamp'
     *
     * About '<S408>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_n = rtb_TSamp_tmp;

    /* Sum: '<S408>/Diff' incorporates:
     *  UnitDelay: '<S408>/UD'
     *
     * Block description for '<S408>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S408>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Diff_j = rtb_TSamp_n - LKAS_DW.UD_DSTATE_c;

    /* Switch: '<S613>/Switch22' */
    if (LKAS_ConstB.DataTypeConversion57 != 0.0F) {
      /* UnaryMinus: '<S403>/Unary Minus' */
      rtb_UnaryMinus_k = -LKAS_ConstB.DataTypeConversion57;
    } else {
      /* UnaryMinus: '<S403>/Unary Minus' incorporates:
       *  Constant: '<S613>/LL_MAX_LONG_DECEL_DISABLE=2.5'
       */
      rtb_UnaryMinus_k = -LL_MAX_LONG_DECEL_DISABLE;
    }

    /* End of Switch: '<S613>/Switch22' */

    /* Switch: '<S404>/Switch' incorporates:
     *  Constant: '<S404>/Constant'
     *  Constant: '<S404>/Constant1'
     *  Constant: '<S410>/Constant'
     *  RelationalOperator: '<S410>/Compare'
     */
    if (rtb_IMAPve_d_EPS_LKA_State == ((uint8)3U)) {
      rtb_Saturation9 = 0.5F;
    } else {
      rtb_Saturation9 = 0.25F;
    }

    /* End of Switch: '<S404>/Switch' */

    /* Outputs for Enabled SubSystem: '<S404>/Count 20s' incorporates:
     *  EnablePort: '<S413>/Enable'
     */
    /* RelationalOperator: '<S404>/Relational Operator' */
    if (rtb_Saturation1_gx <= rtb_Saturation9) {
      if (!LKAS_DW.Count20s_MODE) {
        /* InitializeConditions for Sum: '<S413>/Add' incorporates:
         *  Memory: '<S413>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_i3 = ((uint16)0U);
        LKAS_DW.Count20s_MODE = true;
      }

      /* Sum: '<S413>/Add' incorporates:
       *  Constant: '<S411>/Constant'
       *  Constant: '<S412>/Constant'
       *  Logic: '<S404>/Logical Operator2'
       *  Memory: '<S413>/Memory'
       *  RelationalOperator: '<S411>/Compare'
       *  RelationalOperator: '<S412>/Compare'
       */
      LKAS_DW.Memory_PreviousInput_i3 = (uint16)((uint32)
        ((rtb_IMAPve_d_EPS_LKA_State == ((uint8)1U)) ||
         (rtb_IMAPve_d_EPS_LKA_State == ((uint8)3U))) +
        LKAS_DW.Memory_PreviousInput_i3);

      /* Saturate: '<S413>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_i3 >= ((uint16)50000U)) {
        /* Sum: '<S413>/Add' */
        LKAS_DW.Memory_PreviousInput_i3 = ((uint16)50000U);
      }

      /* End of Saturate: '<S413>/Saturation' */

      /* DataTypeConversion: '<S404>/Cast To Single1' incorporates:
       *  Constant: '<S404>/Constant2'
       *  Product: '<S404>/Divide'
       */
      rtb_Saturation9 = fmodf(floorf(20.0F / rtb_LKA_SampleTime), 65536.0F);

      /* RelationalOperator: '<S413>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S404>/Cast To Single1'
       */
      LKAS_B.RelationalOperator_gm = (LKAS_DW.Memory_PreviousInput_i3 >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.Count20s_MODE) {
        /* Disable for Outport: '<S413>/Out' */
        LKAS_B.RelationalOperator_gm = false;
        LKAS_DW.Count20s_MODE = false;
      }
    }

    /* End of RelationalOperator: '<S404>/Relational Operator' */
    /* End of Outputs for SubSystem: '<S404>/Count 20s' */

    /* Saturate: '<S405>/Saturation' */
    if (rtb_IMAPve_g_ESC_VehSpd > 80.0F) {
      rtb_Saturation9 = 80.0F;
    } else if (rtb_IMAPve_g_ESC_VehSpd < 60.0F) {
      rtb_Saturation9 = 60.0F;
    } else {
      rtb_Saturation9 = rtb_IMAPve_g_ESC_VehSpd;
    }

    /* End of Saturate: '<S405>/Saturation' */

    /* Sum: '<S405>/Add' incorporates:
     *  Constant: '<S405>/Constant'
     *  Fcn: '<S405>/Fcn'
     *  Product: '<S405>/Divide2'
     */
    rtb_LL_LKA_EarliestWarnLine_C = (1.5F * rtb_LL_MAX_DRIVER_TORQUE_DISABL -
      rtb_Saturation9 / 180.0F * rtb_LL_MAX_DRIVER_TORQUE_DISABL) + rtb_Abs_tmp /
      0.005F;

    /* Saturate: '<S405>/Saturation1' */
    if (rtb_LL_LKA_EarliestWarnLine_C > 2.75F) {
      rtb_LL_LKA_EarliestWarnLine_C = 2.75F;
    } else {
      if (rtb_LL_LKA_EarliestWarnLine_C < 1.5F) {
        rtb_LL_LKA_EarliestWarnLine_C = 1.5F;
      }
    }

    /* End of Saturate: '<S405>/Saturation1' */

    /* Outputs for Enabled SubSystem: '<S405>/Sum Condition2' incorporates:
     *  EnablePort: '<S414>/state = reset'
     */
    /* RelationalOperator: '<S405>/Relational Operator' */
    if (rtb_Saturation1_gx >= rtb_LL_LKA_EarliestWarnLine_C) {
      if (!LKAS_DW.SumCondition2_MODE) {
        /* InitializeConditions for Sum: '<S414>/Add1' incorporates:
         *  Memory: '<S414>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_p0 = ((uint16)0U);
        LKAS_DW.SumCondition2_MODE = true;
      }

      /* Sum: '<S414>/Add1' incorporates:
       *  Memory: '<S414>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_p0 = (uint16)fmodf(1.0F + (float32)
        LKAS_DW.Memory_PreviousInput_p0, 65536.0F);

      /* Saturate: '<S414>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_p0 >= ((uint16)5000U)) {
        /* Sum: '<S414>/Add1' */
        LKAS_DW.Memory_PreviousInput_p0 = ((uint16)5000U);
      }

      /* End of Saturate: '<S414>/Saturation' */

      /* Switch: '<S613>/Switch26' incorporates:
       *  Constant: '<S613>/LL_TkOvStChk_tiTrqChkT_C=0.1'
       */
      if (LKAS_ConstB.DataTypeConversion62 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion62;
      } else {
        rtb_Saturation9 = LL_TkOvStChk_tiTrqChkT;
      }

      /* End of Switch: '<S613>/Switch26' */

      /* DataTypeConversion: '<S405>/Cast To Single1' incorporates:
       *  Product: '<S405>/Divide'
       */
      rtb_Saturation9 = fmodf(floorf(rtb_Saturation9 / rtb_LKA_SampleTime),
        65536.0F);

      /* RelationalOperator: '<S414>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S405>/Cast To Single1'
       */
      LKAS_B.RelationalOperator_j = (LKAS_DW.Memory_PreviousInput_p0 >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.SumCondition2_MODE) {
        /* Disable for Outport: '<S414>/Out' */
        LKAS_B.RelationalOperator_j = false;
        LKAS_DW.SumCondition2_MODE = false;
      }
    }

    /* End of RelationalOperator: '<S405>/Relational Operator' */
    /* End of Outputs for SubSystem: '<S405>/Sum Condition2' */

    /* RelationalOperator: '<S423>/Compare' incorporates:
     *  Constant: '<S423>/Constant'
     */
    rtb_Compare_ef = ((sint32)LKAS_B.RelationalOperator_j > (sint32)false);

    /* UnitDelay: '<S415>/Unit Delay' */
    rtb_UnitDelay_a = LKAS_DW.UnitDelay_DSTATE_ba;

    /* RelationalOperator: '<S422>/Compare' incorporates:
     *  Constant: '<S422>/Constant'
     */
    rtb_Compare_oq = ((sint32)rtb_UnitDelay_a <= (sint32)false);

    /* If: '<S415>/If' incorporates:
     *  Constant: '<S418>/Constant'
     *  Constant: '<S419>/Constant'
     *  RelationalOperator: '<S416>/FixPt Relational Operator'
     *  RelationalOperator: '<S417>/FixPt Relational Operator'
     *  UnitDelay: '<S416>/Delay Input1'
     *  UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (LKAS_B.RelationalOperator_j && ((sint32)rtb_Compare_ef > (sint32)
         LKAS_DW.DelayInput1_DSTATE)) {
      /* Outputs for IfAction SubSystem: '<S415>/If Action Subsystem' incorporates:
       *  ActionPort: '<S418>/Action Port'
       */
      rtb_Merge_k2 = true;

      /* End of Outputs for SubSystem: '<S415>/If Action Subsystem' */
    } else if ((!rtb_UnitDelay_a) && ((sint32)rtb_Compare_oq > (sint32)
                LKAS_DW.DelayInput1_DSTATE_j)) {
      /* Outputs for IfAction SubSystem: '<S415>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S419>/Action Port'
       */
      rtb_Merge_k2 = false;

      /* End of Outputs for SubSystem: '<S415>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S415>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S420>/Action Port'
       */
      LKAS_IfActionSubsystem3_m(rtb_UnitDelay_a, &rtb_Merge_k2);

      /* End of Outputs for SubSystem: '<S415>/If Action Subsystem3' */
    }

    /* End of If: '<S415>/If' */

    /* Outputs for Enabled SubSystem: '<S415>/Sum Condition1' incorporates:
     *  EnablePort: '<S421>/state = reset'
     */
    if (rtb_Merge_k2) {
      if (!LKAS_DW.SumCondition1_MODE_c) {
        /* InitializeConditions for Sum: '<S421>/Add1' incorporates:
         *  Memory: '<S421>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_h = ((uint16)0U);
        LKAS_DW.SumCondition1_MODE_c = true;
      }

      /* Sum: '<S421>/Add1' incorporates:
       *  Memory: '<S421>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_h = (uint16)((uint32)rtb_Merge_k2 +
        LKAS_DW.Memory_PreviousInput_h);

      /* Saturate: '<S421>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_h >= ((uint16)10000U)) {
        /* Sum: '<S421>/Add1' */
        LKAS_DW.Memory_PreviousInput_h = ((uint16)10000U);
      }

      /* End of Saturate: '<S421>/Saturation' */

      /* DataTypeConversion: '<S405>/Cast To Single2' incorporates:
       *  Product: '<S405>/Divide1'
       */
      rtb_Saturation9 = fmodf(floorf(rtb_LL_TkOvStChk_tiTDelTime /
        rtb_LKA_SampleTime), 65536.0F);

      /* RelationalOperator: '<S421>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S405>/Cast To Single2'
       */
      LKAS_B.RelationalOperator_e = (LKAS_DW.Memory_PreviousInput_h <=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.SumCondition1_MODE_c) {
        /* Disable for Outport: '<S421>/Out' */
        LKAS_B.RelationalOperator_e = false;
        LKAS_DW.SumCondition1_MODE_c = false;
      }
    }

    /* End of Outputs for SubSystem: '<S415>/Sum Condition1' */

    /* Switch: '<S613>/Switch32' incorporates:
     *  Constant: '<S613>/LL_MAX_STEER_ANGLE_DISABLE=70'
     */
    if (LKAS_ConstB.DataTypeConversion52 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion52;
    } else {
      rtb_Saturation9 = LL_MAX_STEER_ANGLE_DISABLE;
    }

    /* End of Switch: '<S613>/Switch32' */

    /* Switch: '<S613>/Switch34' incorporates:
     *  Constant: '<S613>/LL_MAX_STEER_SPEED_DISABLE=200'
     */
    if (LKAS_ConstB.DataTypeConversion55 != 0.0F) {
      rtb_Saturation10 = LKAS_ConstB.DataTypeConversion55;
    } else {
      rtb_Saturation10 = LL_MAX_STEER_SPEED_DISABLE;
    }

    /* End of Switch: '<S613>/Switch34' */

    /* Switch: '<S613>/Switch4' incorporates:
     *  Constant: '<S613>/LL_MAX_LAT_ACC_DISABLE=3.5'
     */
    if (LKAS_ConstB.DataTypeConversion56 != 0.0F) {
      rtb_Saturation4_g = LKAS_ConstB.DataTypeConversion56;
    } else {
      rtb_Saturation4_g = LL_MAX_LAT_ACC_DISABLE;
    }

    /* End of Switch: '<S613>/Switch4' */

    /* Logic: '<S390>/Logical Operator2' incorporates:
     *  Abs: '<S403>/Abs3'
     *  Constant: '<S406>/Constant'
     *  Constant: '<S407>/Constant'
     *  Constant: '<S446>/Constant'
     *  Constant: '<S449>/Constant'
     *  Constant: '<S451>/Constant'
     *  Constant: '<S452>/Constant'
     *  Constant: '<S453>/Constant'
     *  Constant: '<S495>/Constant'
     *  Constant: '<S499>/Constant'
     *  Logic: '<S402>/Logical Operator1'
     *  Logic: '<S403>/Logical Operator'
     *  Logic: '<S403>/Logical Operator1'
     *  Logic: '<S409>/FixPt Logical Operator'
     *  Logic: '<S445>/Logical Operator3'
     *  Logic: '<S446>/Logical Operator'
     *  Logic: '<S447>/Logical Operator'
     *  Logic: '<S450>/FixPt Logical Operator'
     *  Logic: '<S454>/FixPt Logical Operator'
     *  Logic: '<S493>/Logical Operator'
     *  Logic: '<S494>/Logical Operator3'
     *  Logic: '<S500>/FixPt Logical Operator'
     *  RelationalOperator: '<S403>/Relational Operator1'
     *  RelationalOperator: '<S403>/Relational Operator2'
     *  RelationalOperator: '<S403>/Relational Operator3'
     *  RelationalOperator: '<S406>/Compare'
     *  RelationalOperator: '<S407>/Compare'
     *  RelationalOperator: '<S409>/Lower Test'
     *  RelationalOperator: '<S409>/Upper Test'
     *  RelationalOperator: '<S449>/Compare'
     *  RelationalOperator: '<S450>/Lower Test'
     *  RelationalOperator: '<S450>/Upper Test'
     *  RelationalOperator: '<S451>/Compare'
     *  RelationalOperator: '<S452>/Compare'
     *  RelationalOperator: '<S453>/Compare'
     *  RelationalOperator: '<S454>/Lower Test'
     *  RelationalOperator: '<S454>/Upper Test'
     *  RelationalOperator: '<S495>/Compare'
     *  RelationalOperator: '<S499>/Compare'
     *  RelationalOperator: '<S500>/Lower Test'
     *  RelationalOperator: '<S500>/Upper Test'
     *  Switch: '<S70>/Switch'
     *  Switch: '<S70>/Switch1'
     */
    rtb_LogicalOperator2_p = ((rtb_Gain_g >= rtb_IMAPve_g_ESC_VehSpd) ||
      (rtb_IMAPve_g_ESC_VehSpd >= rtb_Switch_j) || (rtb_Saturation_d > 0.0F) ||
      (rtb_IMAPve_d_TCU_Actual_Gear != ((uint8)3U)) || (((rtb_L0_Q < ((uint8)3U))
      && (rtb_R0_Q < ((uint8)3U))) || (((rtb_LL_MIN_LANE_WIDTH_DISABLE <=
      rtb_Abs1_i) && (rtb_Abs1_i <= rtb_LL_MAX_LANE_WIDTH_DISABLE)) == (sint32)
      false) || ((0.0F > rtb_Abs_m) || (rtb_Abs_m >
      rtb_LL_MAX_SYSTEM_CURVATURE_DIS)) || (rtb_LogicalOperator3_g_tmp > 0.04F))
      || ((rtb_LogicalOperator3_g_tmp_0 >= rtb_Saturation9) || (fabsf(rtb_Diff_j)
      >= rtb_Saturation10) || ((rtb_LogicalOperator3_g_tmp_1 >=
      rtb_Saturation4_g) && (rtb_IMAPve_d_EPS_LKA_State != ((uint8)3U))) ||
          (((rtb_UnaryMinus_k < rtb_IMAPve_g_ESC_LonAcc) &&
            (rtb_IMAPve_g_ESC_LonAcc < rtb_LL_MAX_LONG_ACC_DISABLE)) == (sint32)
           false) || LKAS_B.RelationalOperator_gm || LKAS_B.RelationalOperator_e));

    /* If: '<S430>/If' incorporates:
     *  Constant: '<S436>/Constant'
     *  Delay: '<S93>/Delay1'
     */
    if ((LKAS_DW.Delay1_3_DSTATE == 3) && (rtb_IMAPve_d_EPS_LKA_State != 1)) {
      /* Outputs for IfAction SubSystem: '<S430>/If Action Subsystem' incorporates:
       *  ActionPort: '<S434>/Action Port'
       */
      LKAS_IfActionSubsystem_e(&rtb_Merge_i);

      /* End of Outputs for SubSystem: '<S430>/If Action Subsystem' */
    } else if (((LKAS_DW.Delay1_3_DSTATE == 4) || (LKAS_DW.Delay1_3_DSTATE == 5))
               && (rtb_IMAPve_d_EPS_LKA_State != 3)) {
      /* Outputs for IfAction SubSystem: '<S430>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S435>/Action Port'
       */
      LKAS_IfActionSubsystem_e(&rtb_Merge_i);

      /* End of Outputs for SubSystem: '<S430>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S430>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S436>/Action Port'
       */
      rtb_Merge_i = false;

      /* End of Outputs for SubSystem: '<S430>/If Action Subsystem3' */
    }

    /* End of If: '<S430>/If' */

    /* Outputs for Enabled SubSystem: '<S430>/Sum Condition1' incorporates:
     *  EnablePort: '<S437>/state = reset'
     */
    if (rtb_Merge_i) {
      if (!LKAS_DW.SumCondition1_MODE) {
        /* InitializeConditions for Sum: '<S437>/Add1' incorporates:
         *  Memory: '<S437>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_c = 0.0F;
        LKAS_DW.SumCondition1_MODE = true;
      }

      /* Sum: '<S437>/Add1' incorporates:
       *  DataTypeConversion: '<S437>/Cast To Single'
       *  Memory: '<S437>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_c += (float32)rtb_Merge_i;

      /* Saturate: '<S437>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_c > 60000.0F) {
        /* Sum: '<S437>/Add1' */
        LKAS_DW.Memory_PreviousInput_c = 60000.0F;
      } else {
        if (LKAS_DW.Memory_PreviousInput_c < 0.0F) {
          /* Sum: '<S437>/Add1' */
          LKAS_DW.Memory_PreviousInput_c = 0.0F;
        }
      }

      /* End of Saturate: '<S437>/Saturation' */

      /* Switch: '<S613>/Switch24' incorporates:
       *  Constant: '<S613>/LL_MAX_DELAY_EPSSTAR_TIME=0.5'
       */
      if (LKAS_ConstB.DataTypeConversion60 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion60;
      } else {
        rtb_Saturation9 = LL_MAX_DELAY_EPSSTAR_TIME;
      }

      /* End of Switch: '<S613>/Switch24' */

      /* DataTypeConversion: '<S430>/Cast To Single1' incorporates:
       *  Product: '<S430>/Divide'
       */
      rtb_Saturation9 = fmodf(floorf(rtb_Saturation9 / rtb_LKA_SampleTime),
        65536.0F);

      /* RelationalOperator: '<S437>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S430>/Cast To Single1'
       */
      LKAS_B.RelationalOperator_g = (LKAS_DW.Memory_PreviousInput_c >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.SumCondition1_MODE) {
        /* Disable for Outport: '<S437>/Out' */
        LKAS_B.RelationalOperator_g = false;
        LKAS_DW.SumCondition1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S430>/Sum Condition1' */

    /* If: '<S390>/If2' incorporates:
     *  Constant: '<S398>/Constant'
     *  Constant: '<S438>/Constant'
     *  Constant: '<S439>/Constant'
     *  Constant: '<S440>/Constant'
     *  Constant: '<S441>/Constant'
     *  DataTypeConversion: '<S390>/Cast To Single'
     *  Gain: '<S442>/Gain'
     *  Logic: '<S390>/Logical Operator1'
     *  Logic: '<S431>/Logical Operator'
     *  Logic: '<S431>/Logical Operator1'
     *  Logic: '<S432>/Logical Operator'
     *  Logic: '<S433>/Logical Operator'
     *  RelationalOperator: '<S432>/Relational Operator1'
     *  RelationalOperator: '<S432>/Relational Operator2'
     *  RelationalOperator: '<S433>/Relational Operator1'
     *  RelationalOperator: '<S433>/Relational Operator2'
     *  RelationalOperator: '<S438>/Compare'
     *  RelationalOperator: '<S439>/Compare'
     *  RelationalOperator: '<S440>/Compare'
     *  RelationalOperator: '<S441>/Compare'
     */
    if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (rtb_LogicalOperator2_p ||
         ((LKAS_B.IMAPve_d_LKA_Mode == ((uint8)2U)) && ((((rtb_Abs_o >=
              rtb_LL_LKAS_OUT_OF_CONTROL_LAT_) || (rtb_LogicalOperator3_g_tmp_2 >=
              rtb_LL_LKAS_OUT_OF_CONTROL_LAT_)) == (sint32)true) ||
           (((rtb_Abs_cf * (-1.0F) <= rtb_LL_LKA_LatestWarnLine_C) ||
             (rtb_Saturation5_cw <= rtb_LL_LKA_LatestWarnLine_C)) == (sint32)
            true) || (LKAS_B.RelationalOperator_g == true))))) {
      /* Outputs for IfAction SubSystem: '<S390>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S398>/Action Port'
       */
      LKAS_B.Merge2_h = true;

      /* End of Outputs for SubSystem: '<S390>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S390>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S400>/Action Port'
       */
      LKAS_IfActionSubsystem4(&LKAS_B.Merge2_h);

      /* End of Outputs for SubSystem: '<S390>/If Action Subsystem3' */
    }

    /* End of If: '<S390>/If2' */

    /* Product: '<S311>/Divide' */
    rtb_LL_LKA_EarliestWarnLine_C = rtb_L0_C1 * rtb_Abs_h;

    /* Product: '<S311>/Divide1' */
    rtb_Abs_o = rtb_Abs_h * rtb_R0_C1;

    /* If: '<S325>/If' */
    if ((rtb_LL_LKA_EarliestWarnLine_C >= rtb_LL_DvtSpdDet_vDvtSpdMin_C) ||
        (rtb_Abs_o >= rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S325>/Ph1SWA' incorporates:
       *  ActionPort: '<S329>/Action Port'
       */
      LKAS_Ph1SWA(&rtb_Merge1_k);

      /* End of Outputs for SubSystem: '<S325>/Ph1SWA' */
    } else if ((rtb_LL_LKA_EarliestWarnLine_C <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)
               || (rtb_Abs_o <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S325>/Ph2SWA' incorporates:
       *  ActionPort: '<S330>/Action Port'
       */
      LKAS_Ph2SWA(&rtb_Merge1_k);

      /* End of Outputs for SubSystem: '<S325>/Ph2SWA' */
    } else {
      /* Outputs for IfAction SubSystem: '<S325>/Ph3SWA' incorporates:
       *  ActionPort: '<S331>/Action Port'
       */
      LKAS_Ph3SWA(&rtb_Merge1_k);

      /* End of Outputs for SubSystem: '<S325>/Ph3SWA' */
    }

    /* End of If: '<S325>/If' */

    /* Saturate: '<S310>/Saturation4' */
    if (rtb_LL_DvtComp_C > 0.1F) {
      rtb_Saturation4_g = 0.1F;
    } else if (rtb_LL_DvtComp_C < (-0.1F)) {
      rtb_Saturation4_g = (-0.1F);
    } else {
      rtb_Saturation4_g = rtb_LL_DvtComp_C;
    }

    /* End of Saturate: '<S310>/Saturation4' */

    /* Saturate: '<S310>/Saturation1' */
    if (rtb_L0_C1 > 0.2F) {
      rtb_TTLC = 0.2F;
    } else if (rtb_L0_C1 < (-0.2F)) {
      rtb_TTLC = (-0.2F);
    } else {
      rtb_TTLC = rtb_L0_C1;
    }

    /* End of Saturate: '<S310>/Saturation1' */

    /* Saturate: '<S310>/Saturation' */
    if (rtb_L0_C0 > 2.0F) {
      rtb_Saturation9 = 2.0F;
    } else if (rtb_L0_C0 < (-4.0F)) {
      rtb_Saturation9 = (-4.0F);
    } else {
      rtb_Saturation9 = rtb_L0_C0;
    }

    /* End of Saturate: '<S310>/Saturation' */

    /* Gain: '<S314>/Gain' incorporates:
     *  Product: '<S314>/Divide'
     *  Product: '<S314>/Divide1'
     *  Sum: '<S314>/Add'
     *  Sum: '<S314>/Add1'
     *  Sum: '<S314>/Add2'
     *  Trigonometry: '<S314>/Cos'
     *  Trigonometry: '<S314>/Sin'
     */
    rtb_Saturation5_cw = (((rtb_Saturation9 - rtb_Saturation4_g) +
      rtb_LKA_Veh2CamW_C) * cosf(rtb_TTLC) + rtb_LKA_Veh2CamL_C * sinf(rtb_TTLC))
      * (-1.0F);

    /* Saturate: '<S300>/Saturation5' */
    if (rtb_Saturation5_cw > 2.0F) {
      rtb_Saturation5_cw = 2.0F;
    } else {
      if (rtb_Saturation5_cw < (-2.0F)) {
        rtb_Saturation5_cw = (-2.0F);
      }
    }

    /* End of Saturate: '<S300>/Saturation5' */

    /* Saturate: '<S309>/Saturation1' */
    if (rtb_Saturation_k > 5.5F) {
      rtb_Saturation10 = 5.5F;
    } else if (rtb_Saturation_k < 2.4F) {
      rtb_Saturation10 = 2.4F;
    } else {
      rtb_Saturation10 = rtb_Saturation_k;
    }

    /* End of Saturate: '<S309>/Saturation1' */

    /* Sum: '<S309>/Add2' incorporates:
     *  Constant: '<S309>/Constant1'
     *  Gain: '<S309>/Gain'
     */
    rtb_Saturation10 = 0.25F * rtb_Saturation10 - 0.6F;

    /* Saturate: '<S309>/Saturation2' */
    if (rtb_Saturation10 > 0.3F) {
      rtb_Saturation10 = 0.3F;
    } else {
      if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation10 = 0.0F;
      }
    }

    /* End of Saturate: '<S309>/Saturation2' */

    /* Product: '<S309>/Divide' incorporates:
     *  Constant: '<S309>/Constant2'
     */
    rtb_TTLC = rtb_Saturation10 / 0.3F;

    /* Product: '<S309>/Divide5' */
    rtb_Saturation10 = rtb_TTLC * rtb_LL_ThresDet_lDvtThresUprLKA;

    /* Product: '<S309>/Divide6' */
    rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = rtb_TTLC * rtb_LL_ThresDet_tiTTLCThresLKA;

    /* Abs: '<S327>/Abs' incorporates:
     *  Abs: '<S318>/Abs'
     */
    rtb_LogicalOperator3_g_tmp_1 = fabsf(rtb_LL_LKA_EarliestWarnLine_C);

    /* Product: '<S327>/Divide' incorporates:
     *  Abs: '<S327>/Abs'
     */
    rtb_Divide_p = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ *
      rtb_LogicalOperator3_g_tmp_1;

    /* Product: '<S309>/Divide4' */
    rtb_Abs_cf = rtb_TTLC * rtb_LL_ThresDet_lDvtThresLwrLKA;

    /* Switch: '<S332>/Switch' incorporates:
     *  RelationalOperator: '<S332>/UpperRelop'
     */
    if (rtb_Divide_p < rtb_Abs_cf) {
      rtb_Switch_d = rtb_Abs_cf;
    } else {
      rtb_Switch_d = rtb_Divide_p;
    }

    /* End of Switch: '<S332>/Switch' */

    /* Switch: '<S332>/Switch2' incorporates:
     *  RelationalOperator: '<S332>/LowerRelop1'
     */
    if (rtb_Divide_p > rtb_Saturation10) {
      rtb_Switch2_m = rtb_Saturation10;
    } else {
      rtb_Switch2_m = rtb_Switch_d;
    }

    /* End of Switch: '<S332>/Switch2' */

    /* Saturate: '<S310>/Saturation3' */
    if (rtb_R0_C1 > 0.2F) {
      rtb_LL_DvtComp_C_f = 0.2F;
    } else if (rtb_R0_C1 < (-0.2F)) {
      rtb_LL_DvtComp_C_f = (-0.2F);
    } else {
      rtb_LL_DvtComp_C_f = rtb_R0_C1;
    }

    /* End of Saturate: '<S310>/Saturation3' */

    /* Saturate: '<S310>/Saturation2' */
    if (rtb_R0_C0 > 4.0F) {
      rtb_Saturation9 = 4.0F;
    } else if (rtb_R0_C0 < (-2.0F)) {
      rtb_Saturation9 = (-2.0F);
    } else {
      rtb_Saturation9 = rtb_R0_C0;
    }

    /* End of Saturate: '<S310>/Saturation2' */

    /* Sum: '<S315>/Add2' incorporates:
     *  Product: '<S315>/Divide'
     *  Product: '<S315>/Divide1'
     *  Sum: '<S315>/Add'
     *  Sum: '<S315>/Add1'
     *  Trigonometry: '<S315>/Cos'
     *  Trigonometry: '<S315>/Sin'
     */
    rtb_Saturation1_gx = ((rtb_Saturation9 - rtb_Saturation4_g) -
                          rtb_LKA_Veh2CamW_C) * cosf(rtb_LL_DvtComp_C_f) +
      rtb_LKA_Veh2CamL_C * sinf(rtb_LL_DvtComp_C_f);

    /* Saturate: '<S300>/Saturation1' */
    if (rtb_Saturation1_gx > 2.0F) {
      rtb_Saturation1_gx = 2.0F;
    } else {
      if (rtb_Saturation1_gx < (-2.0F)) {
        rtb_Saturation1_gx = (-2.0F);
      }
    }

    /* End of Saturate: '<S300>/Saturation1' */

    /* Abs: '<S328>/Abs' incorporates:
     *  Abs: '<S319>/Abs'
     */
    rtb_LogicalOperator3_g_tmp = fabsf(rtb_Abs_o);

    /* Product: '<S328>/Divide' incorporates:
     *  Abs: '<S328>/Abs'
     */
    rtb_Divide_k = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ * rtb_LogicalOperator3_g_tmp;

    /* Switch: '<S333>/Switch' incorporates:
     *  RelationalOperator: '<S333>/UpperRelop'
     */
    if (rtb_Divide_k < rtb_Abs_cf) {
      rtb_Switch_on = rtb_Abs_cf;
    } else {
      rtb_Switch_on = rtb_Divide_k;
    }

    /* End of Switch: '<S333>/Switch' */

    /* Switch: '<S333>/Switch2' incorporates:
     *  RelationalOperator: '<S333>/LowerRelop1'
     */
    if (rtb_Divide_k > rtb_Saturation10) {
      rtb_Switch2_d = rtb_Saturation10;
    } else {
      rtb_Switch2_d = rtb_Switch_on;
    }

    /* End of Switch: '<S333>/Switch2' */

    /* Switch: '<S326>/Switch3' incorporates:
     *  Constant: '<S328>/Constant'
     *  Gain: '<S326>/Gain1'
     *  Logic: '<S328>/Logical Operator'
     *  RelationalOperator: '<S328>/Relational Operator1'
     *  RelationalOperator: '<S328>/Relational Operator2'
     */
    if (rtb_Merge1_k >= 0.0F) {
      /* Switch: '<S326>/Switch2' incorporates:
       *  Constant: '<S326>/Constant2'
       *  Constant: '<S327>/Constant'
       *  DataTypeConversion: '<S326>/Cast To Single'
       *  Logic: '<S327>/Logical Operator'
       *  RelationalOperator: '<S327>/Relational Operator1'
       *  RelationalOperator: '<S327>/Relational Operator3'
       */
      if (rtb_Merge1_k > 0.0F) {
        rtb_IMAPve_d_BCM_Right_Light = (uint8)((0.0F < rtb_Saturation5_cw) &&
          (rtb_Saturation5_cw <= rtb_Switch2_m));
      } else {
        rtb_IMAPve_d_BCM_Right_Light = ((uint8)0U);
      }

      /* End of Switch: '<S326>/Switch2' */
    } else {
      rtb_IMAPve_d_BCM_Right_Light = (uint8)(((uint32)((0.0F <
        rtb_Saturation1_gx) && (rtb_Saturation1_gx <= rtb_Switch2_d)) * ((uint8)
        128U)) >> 6);
    }

    /* End of Switch: '<S326>/Switch3' */

    /* DataTypeConversion: '<S302>/Data Type Conversion' incorporates:
     *  Constant: '<S336>/Constant'
     *  Constant: '<S337>/Constant'
     *  Constant: '<S338>/Constant'
     *  Constant: '<S339>/Constant'
     *  Logic: '<S302>/Logical Operator'
     *  Logic: '<S302>/Logical Operator1'
     *  Logic: '<S302>/Logical Operator2'
     *  RelationalOperator: '<S336>/Compare'
     *  RelationalOperator: '<S337>/Compare'
     *  RelationalOperator: '<S338>/Compare'
     *  RelationalOperator: '<S339>/Compare'
     *  Switch: '<S70>/Switch'
     *  Switch: '<S70>/Switch1'
     */
    rtb_IMAPve_d_BCM_HazardLamp = (uint8)(((rtb_R0_Q > ((uint8)2U)) &&
      (rtb_IMAPve_d_BCM_Right_Light == ((uint8)2U))) ||
      ((rtb_IMAPve_d_BCM_Right_Light == ((uint8)1U)) && (rtb_L0_Q > ((uint8)2U))));

    /* DataTypeConversion: '<S301>/Cast To Single' incorporates:
     *  Constant: '<S334>/Constant'
     *  Constant: '<S335>/Constant'
     *  Logic: '<S301>/Logical Operator'
     *  RelationalOperator: '<S334>/Compare'
     *  RelationalOperator: '<S335>/Compare'
     */
    rtb_IMAPve_d_BCM_Left_Light = (uint8)((rtb_IMAPve_d_EPS_LKA_State == ((uint8)
      1U)) || (rtb_IMAPve_d_EPS_LKA_State == ((uint8)3U)));

    /* If: '<S299>/If1' incorporates:
     *  Constant: '<S304>/Constant'
     *  Constant: '<S307>/Constant'
     *  Constant: '<S308>/Constant'
     */
    if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (rtb_IMAPve_d_BCM_Right_Light == 1) &&
        (rtb_IMAPve_d_BCM_Left_Light == 1) && (rtb_IMAPve_d_BCM_HazardLamp == 1))
    {
      /* Outputs for IfAction SubSystem: '<S299>/LKA Left Active Flag (LKALftActvFlg)1' incorporates:
       *  ActionPort: '<S307>/Action Port'
       */
      LKAS_B.Merge2 = ((uint8)1U);

      /* End of Outputs for SubSystem: '<S299>/LKA Left Active Flag (LKALftActvFlg)1' */
    } else if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (rtb_IMAPve_d_BCM_Right_Light ==
                2) && (rtb_IMAPve_d_BCM_Left_Light == 1) &&
               (rtb_IMAPve_d_BCM_HazardLamp == 1)) {
      /* Outputs for IfAction SubSystem: '<S299>/LKA Right Active Flag (LKARgtActvFlg)1' incorporates:
       *  ActionPort: '<S308>/Action Port'
       */
      LKAS_B.Merge2 = ((uint8)2U);

      /* End of Outputs for SubSystem: '<S299>/LKA Right Active Flag (LKARgtActvFlg)1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S299>/Default Flag (DflFlg)1' incorporates:
       *  ActionPort: '<S304>/Action Port'
       */
      LKAS_B.Merge2 = ((uint8)0U);

      /* End of Outputs for SubSystem: '<S299>/Default Flag (DflFlg)1' */
    }

    /* End of If: '<S299>/If1' */

    /* Product: '<S350>/Divide' */
    rtb_Abs_cf = rtb_L0_C1 * rtb_Abs_h;

    /* Product: '<S350>/Divide1' */
    rtb_LL_DvtComp_C_f = rtb_Abs_h * rtb_R0_C1;

    /* If: '<S364>/If' */
    if ((rtb_Abs_cf >= rtb_LL_DvtSpdDet_vDvtSpdMin_C) || (rtb_LL_DvtComp_C_f >=
         rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S364>/Ph1SWA' incorporates:
       *  ActionPort: '<S368>/Action Port'
       */
      LKAS_Ph1SWA(&rtb_Merge1_k5);

      /* End of Outputs for SubSystem: '<S364>/Ph1SWA' */
    } else if ((rtb_Abs_cf <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C) ||
               (rtb_LL_DvtComp_C_f <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S364>/Ph2SWA' incorporates:
       *  ActionPort: '<S369>/Action Port'
       */
      LKAS_Ph2SWA(&rtb_Merge1_k5);

      /* End of Outputs for SubSystem: '<S364>/Ph2SWA' */
    } else {
      /* Outputs for IfAction SubSystem: '<S364>/Ph3SWA' incorporates:
       *  ActionPort: '<S370>/Action Port'
       */
      LKAS_Ph3SWA(&rtb_Merge1_k5);

      /* End of Outputs for SubSystem: '<S364>/Ph3SWA' */
    }

    /* End of If: '<S364>/If' */

    /* Saturate: '<S349>/Saturation4' */
    if (rtb_LL_DvtComp_C > 0.1F) {
      rtb_Saturation4_g = 0.1F;
    } else if (rtb_LL_DvtComp_C < (-0.1F)) {
      rtb_Saturation4_g = (-0.1F);
    } else {
      rtb_Saturation4_g = rtb_LL_DvtComp_C;
    }

    /* End of Saturate: '<S349>/Saturation4' */

    /* Saturate: '<S349>/Saturation1' */
    if (rtb_L0_C1 > 0.2F) {
      rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = 0.2F;
    } else if (rtb_L0_C1 < (-0.2F)) {
      rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = (-0.2F);
    } else {
      rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = rtb_L0_C1;
    }

    /* End of Saturate: '<S349>/Saturation1' */

    /* Saturate: '<S349>/Saturation' */
    if (rtb_L0_C0 > 3.0F) {
      rtb_Saturation9 = 3.0F;
    } else if (rtb_L0_C0 < (-3.0F)) {
      rtb_Saturation9 = (-3.0F);
    } else {
      rtb_Saturation9 = rtb_L0_C0;
    }

    /* End of Saturate: '<S349>/Saturation' */

    /* Gain: '<S353>/Gain' incorporates:
     *  Product: '<S353>/Divide'
     *  Product: '<S353>/Divide1'
     *  Sum: '<S353>/Add'
     *  Sum: '<S353>/Add1'
     *  Sum: '<S353>/Add2'
     *  Trigonometry: '<S353>/Cos'
     *  Trigonometry: '<S353>/Sin'
     */
    rtb_LL_DvtComp_C = (((rtb_Saturation9 - rtb_Saturation4_g) +
                         rtb_LKA_Veh2CamW_C) * cosf
                        (rtb_LL_LKAS_OUT_OF_CONTROL_LAT_) + rtb_LKA_Veh2CamL_C *
                        sinf(rtb_LL_LKAS_OUT_OF_CONTROL_LAT_)) * (-1.0F);

    /* Saturate: '<S341>/Saturation5' */
    if (rtb_LL_DvtComp_C > 1.0F) {
      rtb_LL_DvtComp_C = 1.0F;
    } else {
      if (rtb_LL_DvtComp_C < (-1.0F)) {
        rtb_LL_DvtComp_C = (-1.0F);
      }
    }

    /* End of Saturate: '<S341>/Saturation5' */

    /* Saturate: '<S348>/Saturation1' */
    if (rtb_Saturation_k > 5.5F) {
      rtb_Saturation10 = 5.5F;
    } else if (rtb_Saturation_k < 2.4F) {
      rtb_Saturation10 = 2.4F;
    } else {
      rtb_Saturation10 = rtb_Saturation_k;
    }

    /* End of Saturate: '<S348>/Saturation1' */

    /* Sum: '<S348>/Add2' incorporates:
     *  Constant: '<S348>/Constant1'
     *  Gain: '<S348>/Gain'
     */
    rtb_Saturation10 = 0.25F * rtb_Saturation10 - 0.6F;

    /* Saturate: '<S348>/Saturation2' */
    if (rtb_Saturation10 > 0.3F) {
      rtb_Saturation10 = 0.3F;
    } else {
      if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation10 = 0.0F;
      }
    }

    /* End of Saturate: '<S348>/Saturation2' */

    /* Product: '<S348>/Divide' incorporates:
     *  Constant: '<S348>/Constant2'
     */
    rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ = rtb_Saturation10 / 0.3F;

    /* Product: '<S348>/Divide5' */
    rtb_Saturation10 = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ *
      rtb_LL_ThresDet_lDvtThresUprLKA;

    /* Product: '<S348>/Divide6' */
    rtb_Saturation9 = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ *
      rtb_LL_ThresDet_tiTTLCThresLKA;

    /* Product: '<S366>/Divide' incorporates:
     *  Abs: '<S366>/Abs'
     */
    rtb_Divide_kt = rtb_Saturation9 * fabsf(rtb_Abs_cf);

    /* Product: '<S348>/Divide4' */
    rtb_LL_ThresDet_lDvtThresLwrLKA *= rtb_LL_LKAS_OUT_OF_CONTROL_LAT_;

    /* Switch: '<S371>/Switch' incorporates:
     *  RelationalOperator: '<S371>/UpperRelop'
     */
    if (rtb_Divide_kt < rtb_LL_ThresDet_lDvtThresLwrLKA) {
      rtb_Switch_g = rtb_LL_ThresDet_lDvtThresLwrLKA;
    } else {
      rtb_Switch_g = rtb_Divide_kt;
    }

    /* End of Switch: '<S371>/Switch' */

    /* Switch: '<S371>/Switch2' incorporates:
     *  RelationalOperator: '<S371>/LowerRelop1'
     */
    if (rtb_Divide_kt > rtb_Saturation10) {
      rtb_Switch2_l = rtb_Saturation10;
    } else {
      rtb_Switch2_l = rtb_Switch_g;
    }

    /* End of Switch: '<S371>/Switch2' */

    /* Saturate: '<S349>/Saturation2' */
    if (rtb_R0_C0 > 3.0F) {
      rtb_Abs2 = 3.0F;
    } else if (rtb_R0_C0 < (-3.0F)) {
      rtb_Abs2 = (-3.0F);
    } else {
      rtb_Abs2 = rtb_R0_C0;
    }

    /* End of Saturate: '<S349>/Saturation2' */

    /* Sum: '<S354>/Add1' incorporates:
     *  Sum: '<S354>/Add'
     */
    rtb_LL_ThresDet_lDvtThresUprLKA = (rtb_Abs2 - rtb_Saturation4_g) -
      rtb_LKA_Veh2CamW_C;

    /* Saturate: '<S349>/Saturation3' */
    if (rtb_R0_C1 > 0.2F) {
      rtb_Abs2 = 0.2F;
    } else if (rtb_R0_C1 < (-0.2F)) {
      rtb_Abs2 = (-0.2F);
    } else {
      rtb_Abs2 = rtb_R0_C1;
    }

    /* End of Saturate: '<S349>/Saturation3' */

    /* Sum: '<S354>/Add2' incorporates:
     *  Product: '<S354>/Divide'
     *  Product: '<S354>/Divide1'
     *  Trigonometry: '<S354>/Cos'
     *  Trigonometry: '<S354>/Sin'
     */
    rtb_Abs2 = rtb_LL_ThresDet_lDvtThresUprLKA * cosf(rtb_Abs2) +
      rtb_LKA_Veh2CamL_C * sinf(rtb_Abs2);

    /* Saturate: '<S341>/Saturation1' */
    if (rtb_Abs2 > 1.0F) {
      rtb_LKA_Veh2CamL_C = 1.0F;
    } else if (rtb_Abs2 < (-1.0F)) {
      rtb_LKA_Veh2CamL_C = (-1.0F);
    } else {
      rtb_LKA_Veh2CamL_C = rtb_Abs2;
    }

    /* End of Saturate: '<S341>/Saturation1' */

    /* Abs: '<S367>/Abs' */
    rtb_Abs2 = fabsf(rtb_LL_DvtComp_C_f);

    /* Product: '<S367>/Divide' */
    rtb_Divide_an = rtb_Saturation9 * rtb_Abs2;

    /* Switch: '<S372>/Switch' incorporates:
     *  RelationalOperator: '<S372>/UpperRelop'
     */
    if (rtb_Divide_an < rtb_LL_ThresDet_lDvtThresLwrLKA) {
      rtb_Switch_ov = rtb_LL_ThresDet_lDvtThresLwrLKA;
    } else {
      rtb_Switch_ov = rtb_Divide_an;
    }

    /* End of Switch: '<S372>/Switch' */

    /* Switch: '<S372>/Switch2' incorporates:
     *  RelationalOperator: '<S372>/LowerRelop1'
     */
    if (rtb_Divide_an > rtb_Saturation10) {
      rtb_Switch2_km = rtb_Saturation10;
    } else {
      rtb_Switch2_km = rtb_Switch_ov;
    }

    /* End of Switch: '<S372>/Switch2' */

    /* Switch: '<S365>/Switch3' incorporates:
     *  Constant: '<S367>/Constant'
     *  Gain: '<S365>/Gain1'
     *  Logic: '<S367>/Logical Operator'
     *  RelationalOperator: '<S367>/Relational Operator1'
     *  RelationalOperator: '<S367>/Relational Operator2'
     */
    if (rtb_Merge1_k5 >= 0.0F) {
      /* Switch: '<S365>/Switch2' incorporates:
       *  Constant: '<S365>/Constant2'
       *  Constant: '<S366>/Constant'
       *  DataTypeConversion: '<S365>/Cast To Single'
       *  Logic: '<S366>/Logical Operator'
       *  RelationalOperator: '<S366>/Relational Operator1'
       *  RelationalOperator: '<S366>/Relational Operator2'
       */
      if (rtb_Merge1_k5 > 0.0F) {
        rtb_IMAPve_d_BCM_Left_Light = (uint8)((0.0F < rtb_LL_DvtComp_C) &&
          (rtb_LL_DvtComp_C <= rtb_Switch2_l));
      } else {
        rtb_IMAPve_d_BCM_Left_Light = ((uint8)0U);
      }

      /* End of Switch: '<S365>/Switch2' */
    } else {
      rtb_IMAPve_d_BCM_Left_Light = (uint8)(((uint32)((0.0F < rtb_LKA_Veh2CamL_C)
        && (rtb_LKA_Veh2CamL_C <= rtb_Switch2_km)) * ((uint8)128U)) >> 6);
    }

    /* End of Switch: '<S365>/Switch3' */

    /* Saturate: '<S342>/Saturation' */
    if (rtb_Merge_k > 0.005F) {
      rtb_Abs2 = 0.005F;
    } else if (rtb_Merge_k < (-0.005F)) {
      rtb_Abs2 = (-0.005F);
    } else {
      rtb_Abs2 = rtb_Merge_k;
    }

    /* End of Saturate: '<S342>/Saturation' */

    /* Abs: '<S342>/Abs1' */
    rtb_Abs2 = fabsf(rtb_Abs2);

    /* Product: '<S342>/Divide2' incorporates:
     *  Constant: '<S342>/Constant'
     */
    rtb_Abs2 /= 0.005F;

    /* MATLAB Function: '<S342>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<S342>/Cast To Single2'
     */
    rtb_Saturation9 = (1.5F * rtb_LL_MAX_DRIVER_TORQUE_DISABL - fminf(fmaxf
      (60.0F, rtb_IMAPve_g_ESC_VehSpd), 80.0F) / 120.0F *
                       rtb_LL_MAX_DRIVER_TORQUE_DISABL) * 0.8F + rtb_Abs2;

    /* Product: '<S342>/Divide' incorporates:
     *  Constant: '<S342>/Constant2'
     */
    rtb_Abs2 = 0.2F / rtb_LKA_SampleTime;

    /* MATLAB Function: '<S342>/MATLAB Function' */
    if ((rtb_IMAPve_d_BCM_Left_Light == 2) && (rtb_IMAPve_g_EPS_SW_Trq >
         rtb_Saturation9)) {
      rtb_Switch3_0 = 1;
    } else {
      rtb_Switch3_0 = ((rtb_IMAPve_d_BCM_Left_Light == 1) &&
                       (rtb_IMAPve_g_EPS_SW_Trq < -rtb_Saturation9));
    }

    /* Outputs for Enabled SubSystem: '<S342>/Count 0.2s' incorporates:
     *  EnablePort: '<S375>/Enable'
     */
    if (rtb_Switch3_0 > 0) {
      if (!LKAS_DW.Count02s_MODE) {
        /* InitializeConditions for Sum: '<S375>/Add' incorporates:
         *  Memory: '<S375>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_n = ((uint16)0U);
        LKAS_DW.Count02s_MODE = true;
      }

      /* Sum: '<S375>/Add' incorporates:
       *  DataTypeConversion: '<S375>/Cast To Single'
       *  Memory: '<S375>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_n++;

      /* Saturate: '<S375>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_n >= ((uint16)50000U)) {
        /* Sum: '<S375>/Add' */
        LKAS_DW.Memory_PreviousInput_n = ((uint16)50000U);
      }

      /* End of Saturate: '<S375>/Saturation' */

      /* DataTypeConversion: '<S342>/Cast To Single' */
      rtb_Saturation9 = fmodf(floorf(rtb_Abs2), 65536.0F);

      /* RelationalOperator: '<S375>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S342>/Cast To Single'
       */
      LKAS_B.RelationalOperator_fi = (LKAS_DW.Memory_PreviousInput_n >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.Count02s_MODE) {
        /* Disable for Outport: '<S375>/Out' */
        LKAS_B.RelationalOperator_fi = false;
        LKAS_DW.Count02s_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S342>/Count 0.2s' */

    /* RelationalOperator: '<S385>/Compare' incorporates:
     *  Constant: '<S385>/Constant'
     */
    rtb_Compare_cg = ((sint32)LKAS_B.RelationalOperator_fi > (sint32)false);

    /* UnitDelay: '<S377>/Unit Delay' */
    rtb_UnitDelay_d = LKAS_DW.UnitDelay_DSTATE_c;

    /* RelationalOperator: '<S384>/Compare' incorporates:
     *  Constant: '<S384>/Constant'
     */
    rtb_Compare_ki = ((sint32)rtb_UnitDelay_d <= (sint32)false);

    /* If: '<S377>/If' incorporates:
     *  Constant: '<S380>/Constant'
     *  Constant: '<S381>/Constant'
     *  RelationalOperator: '<S378>/FixPt Relational Operator'
     *  RelationalOperator: '<S379>/FixPt Relational Operator'
     *  UnitDelay: '<S378>/Delay Input1'
     *  UnitDelay: '<S379>/Delay Input1'
     *
     * Block description for '<S378>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S379>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (LKAS_B.RelationalOperator_fi && ((sint32)rtb_Compare_cg > (sint32)
         LKAS_DW.DelayInput1_DSTATE_b)) {
      /* Outputs for IfAction SubSystem: '<S377>/If Action Subsystem' incorporates:
       *  ActionPort: '<S380>/Action Port'
       */
      rtb_Merge_d = true;

      /* End of Outputs for SubSystem: '<S377>/If Action Subsystem' */
    } else if ((!rtb_UnitDelay_d) && ((sint32)rtb_Compare_ki > (sint32)
                LKAS_DW.DelayInput1_DSTATE_p)) {
      /* Outputs for IfAction SubSystem: '<S377>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S381>/Action Port'
       */
      rtb_Merge_d = false;

      /* End of Outputs for SubSystem: '<S377>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S377>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S382>/Action Port'
       */
      LKAS_IfActionSubsystem3_m(rtb_UnitDelay_d, &rtb_Merge_d);

      /* End of Outputs for SubSystem: '<S377>/If Action Subsystem3' */
    }

    /* End of If: '<S377>/If' */

    /* Product: '<S342>/Divide1' incorporates:
     *  Constant: '<S342>/Constant1'
     */
    rtb_Abs2 = 1.0F / rtb_LKA_SampleTime;

    /* Outputs for Enabled SubSystem: '<S342>/Count' incorporates:
     *  EnablePort: '<S374>/Enable'
     */
    /* Logic: '<S342>/Logical Operator' incorporates:
     *  Constant: '<S373>/Constant'
     *  Memory: '<S342>/Memory'
     *  RelationalOperator: '<S373>/Compare'
     */
    if ((rtb_IMAPve_d_BCM_Left_Light > ((uint8)0U)) &&
        LKAS_DW.Memory_PreviousInput_eb) {
      if (!LKAS_DW.Count_MODE) {
        /* InitializeConditions for Memory: '<S374>/Memory' */
        LKAS_DW.Memory_PreviousInput_e0 = ((uint16)0U);
        LKAS_DW.Count_MODE = true;
      }

      /* Sum: '<S374>/Add' incorporates:
       *  Memory: '<S374>/Memory'
       */
      LKAS_B.Saturation_l = (uint16)(1U + LKAS_DW.Memory_PreviousInput_e0);

      /* Saturate: '<S374>/Saturation' */
      if (LKAS_B.Saturation_l >= ((uint16)50000U)) {
        /* Sum: '<S374>/Add' */
        LKAS_B.Saturation_l = ((uint16)50000U);
      }

      /* End of Saturate: '<S374>/Saturation' */

      /* Update for Memory: '<S374>/Memory' */
      LKAS_DW.Memory_PreviousInput_e0 = LKAS_B.Saturation_l;
    } else {
      if (LKAS_DW.Count_MODE) {
        /* Disable for Sum: '<S374>/Add' incorporates:
         *  Outport: '<S374>/Out'
         */
        LKAS_B.Saturation_l = ((uint16)0U);
        LKAS_DW.Count_MODE = false;
      }
    }

    /* End of Logic: '<S342>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S342>/Count' */

    /* Outputs for Enabled SubSystem: '<S377>/Sum Condition1' incorporates:
     *  EnablePort: '<S383>/state = reset'
     */
    if (rtb_Merge_d) {
      if (!LKAS_DW.SumCondition1_MODE_d) {
        /* InitializeConditions for Sum: '<S383>/Add1' incorporates:
         *  Memory: '<S383>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_ps = ((uint16)0U);
        LKAS_DW.SumCondition1_MODE_d = true;
      }

      /* Sum: '<S383>/Add1' incorporates:
       *  Memory: '<S383>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_ps = (uint16)((uint32)rtb_Merge_d +
        LKAS_DW.Memory_PreviousInput_ps);

      /* Saturate: '<S383>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_ps >= ((uint16)1000U)) {
        /* Sum: '<S383>/Add1' */
        LKAS_DW.Memory_PreviousInput_ps = ((uint16)1000U);
      }

      /* End of Saturate: '<S383>/Saturation' */

      /* DataTypeConversion: '<S342>/Cast To Single1' */
      rtb_Saturation9 = fmodf(floorf(rtb_Abs2), 65536.0F);

      /* RelationalOperator: '<S383>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S342>/Cast To Single1'
       *  Sum: '<S342>/Add'
       */
      LKAS_B.RelationalOperator_mu = (LKAS_DW.Memory_PreviousInput_ps <= (uint16)
        ((uint32)(rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
                  rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9) +
         LKAS_B.Saturation_l));
    } else {
      if (LKAS_DW.SumCondition1_MODE_d) {
        /* Disable for Outport: '<S383>/Out' */
        LKAS_B.RelationalOperator_mu = false;
        LKAS_DW.SumCondition1_MODE_d = false;
      }
    }

    /* End of Outputs for SubSystem: '<S377>/Sum Condition1' */

    /* Product: '<S343>/Divide' */
    rtb_Abs2 = rtb_LL_TkOvStChk_tiTDelTime / rtb_LKA_SampleTime;

    /* Outputs for Enabled SubSystem: '<S343>/Sum Condition1' incorporates:
     *  EnablePort: '<S389>/state = reset'
     */
    /* Logic: '<S343>/Logical Operator' incorporates:
     *  Constant: '<S387>/Constant'
     *  Constant: '<S388>/Constant'
     *  Delay: '<S93>/Delay1'
     *  RelationalOperator: '<S387>/Compare'
     *  RelationalOperator: '<S388>/Compare'
     */
    if ((LKAS_DW.Delay1_3_DSTATE == ((uint8)4U)) || (LKAS_DW.Delay1_3_DSTATE ==
         ((uint8)5U))) {
      if (!LKAS_DW.SumCondition1_MODE_o) {
        /* InitializeConditions for Sum: '<S389>/Add1' incorporates:
         *  Memory: '<S389>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_a1 = ((uint16)0U);
        LKAS_DW.SumCondition1_MODE_o = true;
      }

      /* Sum: '<S389>/Add1' incorporates:
       *  Memory: '<S389>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_a1++;

      /* Saturate: '<S389>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_a1 >= ((uint16)100U)) {
        /* Sum: '<S389>/Add1' */
        LKAS_DW.Memory_PreviousInput_a1 = ((uint16)100U);
      }

      /* End of Saturate: '<S389>/Saturation' */

      /* DataTypeConversion: '<S343>/Cast To Single1' */
      rtb_Saturation9 = fmodf(floorf(rtb_Abs2), 65536.0F);

      /* DataTypeConversion: '<S389>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<S343>/Cast To Single1'
       *  RelationalOperator: '<S389>/Relational Operator'
       */
      LKAS_B.DataTypeConversion_c = (LKAS_DW.Memory_PreviousInput_a1 >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.SumCondition1_MODE_o) {
        /* Disable for Outport: '<S389>/Out' */
        LKAS_B.DataTypeConversion_c = false;
        LKAS_DW.SumCondition1_MODE_o = false;
      }
    }

    /* End of Logic: '<S343>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S343>/Sum Condition1' */

    /* Delay: '<S93>/Delay' */
    rtb_LogicalOperator3_o = LKAS_DW.Delay_DSTATE_e;

    /* If: '<S340>/If1' incorporates:
     *  Constant: '<S345>/Constant'
     *  Constant: '<S347>/Constant'
     *  Constant: '<S386>/Constant'
     *  Delay: '<S93>/Delay'
     *  Logic: '<S340>/Logical Operator'
     *  Logic: '<S343>/Logical Operator1'
     *  RelationalOperator: '<S386>/Compare'
     */
    if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.RelationalOperator_mu ||
         ((rtb_IMAPve_d_EPS_LKA_State != ((uint8)3U)) &&
          LKAS_B.DataTypeConversion_c) || LKAS_DW.Delay_DSTATE_e)) {
      /* Outputs for IfAction SubSystem: '<S340>/LKA Deactivation Flag (LKADeactvFlg)' incorporates:
       *  ActionPort: '<S347>/Action Port'
       */
      LKAS_B.Merge1_b = true;

      /* End of Outputs for SubSystem: '<S340>/LKA Deactivation Flag (LKADeactvFlg)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S340>/Default Flag (DflFlg)1' incorporates:
       *  ActionPort: '<S345>/Action Port'
       */
      LKAS_B.Merge1_b = false;

      /* End of Outputs for SubSystem: '<S340>/Default Flag (DflFlg)1' */
    }

    /* End of If: '<S340>/If1' */

    /* Delay: '<S93>/Delay1' */
    rtb_LDW_State = LKAS_DW.Delay1_1_DSTATE;

    /* Switch: '<S613>/Switch25' incorporates:
     *  Constant: '<S613>/LL_Max_LDWS_Warning_Time=5'
     */
    if (LKAS_ConstB.DataTypeConversion61 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion61;
    } else {
      rtb_Saturation9 = LL_Max_LDWS_Warning_Time;
    }

    /* End of Switch: '<S613>/Switch25' */

    /* Product: '<S392>/Divide' */
    rtb_Abs2 = rtb_Saturation9 / rtb_LKA_SampleTime;

    /* If: '<S392>/u1>=3|u1==1&u2==u3' incorporates:
     *  Memory: '<S392>/Memory'
     */
    rtPrevAction = LKAS_DW.u13u11u2u3_ActiveSubsystem;
    LKAS_DW.u13u11u2u3_ActiveSubsystem = (sint8)((rtb_LDW_State != 4) &&
      ((rtb_LDW_State != 5) || (LKAS_DW.Memory_PreviousInput_ms != rtb_LDW_State)));
    switch (LKAS_DW.u13u11u2u3_ActiveSubsystem) {
     case 0:
      if (LKAS_DW.u13u11u2u3_ActiveSubsystem != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S392>/If Action Subsystem' incorporates:
         *  ActionPort: '<S424>/Action Port'
         */
        /* InitializeConditions for If: '<S392>/u1>=3|u1==1&u2==u3' incorporates:
         *  Memory: '<S424>/Memory'
         *  Sum: '<S424>/Add1'
         */
        LKAS_DW.Memory_PreviousInput_pu = 0.0F;

        /* End of InitializeConditions for SubSystem: '<S392>/If Action Subsystem' */
      }

      /* Outputs for IfAction SubSystem: '<S392>/If Action Subsystem' incorporates:
       *  ActionPort: '<S424>/Action Port'
       */
      /* Sum: '<S424>/Add1' incorporates:
       *  Constant: '<S424>/Constant1'
       *  Memory: '<S424>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_pu += (float32)((uint16)1U);

      /* Saturate: '<S424>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_pu > 10000.0F) {
        /* Sum: '<S424>/Add1' */
        LKAS_DW.Memory_PreviousInput_pu = 10000.0F;
      } else {
        if (LKAS_DW.Memory_PreviousInput_pu < 0.0F) {
          /* Sum: '<S424>/Add1' */
          LKAS_DW.Memory_PreviousInput_pu = 0.0F;
        }
      }

      /* End of Saturate: '<S424>/Saturation' */
      /* End of Outputs for SubSystem: '<S392>/If Action Subsystem' */

      /* DataTypeConversion: '<S392>/Cast To Single1' */
      rtb_Saturation9 = fmodf(floorf(rtb_Abs2), 65536.0F);

      /* Outputs for IfAction SubSystem: '<S392>/If Action Subsystem' incorporates:
       *  ActionPort: '<S424>/Action Port'
       */
      /* DataTypeConversion: '<S424>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<S392>/Cast To Single1'
       *  RelationalOperator: '<S424>/Relational Operator'
       */
      rtb_LogicalOperator3_o = (LKAS_DW.Memory_PreviousInput_pu >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));

      /* End of Outputs for SubSystem: '<S392>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S392>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S425>/Action Port'
       */
      /* SignalConversion: '<S425>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
       *  Constant: '<S425>/Constant'
       */
      rtb_LogicalOperator3_o = false;

      /* End of Outputs for SubSystem: '<S392>/If Action Subsystem1' */
      break;
    }

    /* End of If: '<S392>/u1>=3|u1==1&u2==u3' */

    /* Logic: '<S390>/Logical Operator3' incorporates:
     *  Constant: '<S428>/Constant'
     *  Constant: '<S429>/Constant'
     *  Logic: '<S426>/Logical Operator'
     *  Logic: '<S427>/Logical Operator'
     *  RelationalOperator: '<S427>/Relational Operator1'
     *  RelationalOperator: '<S427>/Relational Operator2'
     *  RelationalOperator: '<S428>/Compare'
     *  RelationalOperator: '<S429>/Compare'
     */
    rtb_LogicalOperator3_o = (((LKAS_B.IMAPve_d_LKA_Mode >= ((uint8)1U)) &&
      (((rtb_Gain1 <= rtb_LL_LDW_LatestWarnLine_C) || (rtb_Add5_j <=
      rtb_LL_LDW_LatestWarnLine_C)) == (sint32)true)) || rtb_LogicalOperator3_o ||
      rtb_LogicalOperator2_p);

    /* If: '<S390>/If1' incorporates:
     *  Constant: '<S399>/Constant'
     *  DataTypeConversion: '<S390>/Cast To Single'
     *  DataTypeConversion: '<S390>/Cast To Single1'
     */
    if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode == 2)) &&
        rtb_LogicalOperator3_o) {
      /* Outputs for IfAction SubSystem: '<S390>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S399>/Action Port'
       */
      LKAS_B.Merge1_j = true;

      /* End of Outputs for SubSystem: '<S390>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S390>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S401>/Action Port'
       */
      LKAS_IfActionSubsystem4(&LKAS_B.Merge1_j);

      /* End of Outputs for SubSystem: '<S390>/If Action Subsystem4' */
    }

    /* End of If: '<S390>/If1' */

    /* If: '<S316>/If' */
    if ((rtb_LL_LKA_EarliestWarnLine_C >= rtb_LL_DvtSpdDet_vDvtSpdMin_C) ||
        (rtb_Abs_o >= rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S316>/Ph1SWA' incorporates:
       *  ActionPort: '<S320>/Action Port'
       */
      LKAS_Ph1SWA(&rtb_Merge1_d);

      /* End of Outputs for SubSystem: '<S316>/Ph1SWA' */
    } else if ((rtb_LL_LKA_EarliestWarnLine_C <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)
               || (rtb_Abs_o <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S316>/Ph2SWA' incorporates:
       *  ActionPort: '<S321>/Action Port'
       */
      LKAS_Ph2SWA(&rtb_Merge1_d);

      /* End of Outputs for SubSystem: '<S316>/Ph2SWA' */
    } else {
      /* Outputs for IfAction SubSystem: '<S316>/Ph3SWA' incorporates:
       *  ActionPort: '<S322>/Action Port'
       */
      LKAS_Ph3SWA(&rtb_Merge1_d);

      /* End of Outputs for SubSystem: '<S316>/Ph3SWA' */
    }

    /* End of If: '<S316>/If' */

    /* Product: '<S309>/Divide2' */
    rtb_Abs2 = rtb_TTLC * rtb_LL_ThresDet_lDvtThresUprLDW;

    /* Product: '<S309>/Divide3' */
    rtb_LL_ThresDet_lDvtThresLwrLKA = rtb_TTLC * rtb_LL_ThresDet_tiTTLCThresLDW;

    /* Product: '<S318>/Divide' */
    rtb_Divide_f = rtb_LL_ThresDet_lDvtThresLwrLKA *
      rtb_LogicalOperator3_g_tmp_1;

    /* Product: '<S309>/Divide1' */
    rtb_TTLC *= rtb_LL_ThresDet_lDvtThresLwrLDW;

    /* Switch: '<S323>/Switch' incorporates:
     *  RelationalOperator: '<S323>/UpperRelop'
     */
    if (rtb_Divide_f < rtb_TTLC) {
      rtb_Switch_ob = rtb_TTLC;
    } else {
      rtb_Switch_ob = rtb_Divide_f;
    }

    /* End of Switch: '<S323>/Switch' */

    /* Switch: '<S323>/Switch2' incorporates:
     *  RelationalOperator: '<S323>/LowerRelop1'
     */
    if (rtb_Divide_f > rtb_Abs2) {
      rtb_Switch2_o = rtb_Abs2;
    } else {
      rtb_Switch2_o = rtb_Switch_ob;
    }

    /* End of Switch: '<S323>/Switch2' */

    /* Product: '<S319>/Divide' */
    rtb_Divide_m = rtb_LL_ThresDet_lDvtThresLwrLKA * rtb_LogicalOperator3_g_tmp;

    /* Switch: '<S324>/Switch' incorporates:
     *  RelationalOperator: '<S324>/UpperRelop'
     */
    if (rtb_Divide_m < rtb_TTLC) {
      rtb_Switch_iq = rtb_TTLC;
    } else {
      rtb_Switch_iq = rtb_Divide_m;
    }

    /* End of Switch: '<S324>/Switch' */

    /* Switch: '<S324>/Switch2' incorporates:
     *  RelationalOperator: '<S324>/LowerRelop1'
     */
    if (rtb_Divide_m > rtb_Abs2) {
      rtb_Switch2_g = rtb_Abs2;
    } else {
      rtb_Switch2_g = rtb_Switch_iq;
    }

    /* End of Switch: '<S324>/Switch2' */

    /* Switch: '<S317>/Switch3' incorporates:
     *  Gain: '<S317>/Gain1'
     *  RelationalOperator: '<S319>/Relational Operator2'
     */
    if (rtb_Merge1_d >= 0.0F) {
      /* Switch: '<S317>/Switch2' incorporates:
       *  Constant: '<S317>/Constant2'
       *  DataTypeConversion: '<S317>/Cast To Single'
       *  RelationalOperator: '<S318>/Relational Operator2'
       */
      if (rtb_Merge1_d > 0.0F) {
        rtb_IMAPve_d_BCM_Left_Light = (uint8)(rtb_Saturation5_cw <=
          rtb_Switch2_o);
      } else {
        rtb_IMAPve_d_BCM_Left_Light = ((uint8)0U);
      }

      /* End of Switch: '<S317>/Switch2' */
    } else {
      rtb_IMAPve_d_BCM_Left_Light = (uint8)(((uint32)(rtb_Saturation1_gx <=
        rtb_Switch2_g) * ((uint8)128U)) >> 6);
    }

    /* End of Switch: '<S317>/Switch3' */

    /* If: '<S299>/If' incorporates:
     *  Constant: '<S303>/Constant'
     *  Constant: '<S305>/Constant'
     *  Constant: '<S306>/Constant'
     */
    if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode == 2)) &&
        (rtb_IMAPve_d_BCM_Left_Light == 1) && (rtb_IMAPve_d_BCM_HazardLamp == 1))
    {
      /* Outputs for IfAction SubSystem: '<S299>/LDW Left Active Flag (LDWLftActvFlg)' incorporates:
       *  ActionPort: '<S305>/Action Port'
       */
      LKAS_B.Merge_i = ((uint8)1U);

      /* End of Outputs for SubSystem: '<S299>/LDW Left Active Flag (LDWLftActvFlg)' */
    } else if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode ==
                 2)) && (rtb_IMAPve_d_BCM_Left_Light == 2) &&
               (rtb_IMAPve_d_BCM_HazardLamp == 1)) {
      /* Outputs for IfAction SubSystem: '<S299>/LDW Right Active Flag (LDWRgtActvFlg)' incorporates:
       *  ActionPort: '<S306>/Action Port'
       */
      LKAS_B.Merge_i = ((uint8)2U);

      /* End of Outputs for SubSystem: '<S299>/LDW Right Active Flag (LDWRgtActvFlg)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S299>/Default Flag (DflFlg)' incorporates:
       *  ActionPort: '<S303>/Action Port'
       */
      LKAS_B.Merge_i = ((uint8)0U);

      /* End of Outputs for SubSystem: '<S299>/Default Flag (DflFlg)' */
    }

    /* End of If: '<S299>/If' */

    /* If: '<S355>/If' */
    if ((rtb_Abs_cf >= rtb_LL_DvtSpdDet_vDvtSpdMin_C) || (rtb_LL_DvtComp_C_f >=
         rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S355>/Ph1SWA' incorporates:
       *  ActionPort: '<S359>/Action Port'
       */
      LKAS_Ph1SWA(&rtb_Merge1_dq);

      /* End of Outputs for SubSystem: '<S355>/Ph1SWA' */
    } else if ((rtb_Abs_cf <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C) ||
               (rtb_LL_DvtComp_C_f <= -rtb_LL_DvtSpdDet_vDvtSpdMin_C)) {
      /* Outputs for IfAction SubSystem: '<S355>/Ph2SWA' incorporates:
       *  ActionPort: '<S360>/Action Port'
       */
      LKAS_Ph2SWA(&rtb_Merge1_dq);

      /* End of Outputs for SubSystem: '<S355>/Ph2SWA' */
    } else {
      /* Outputs for IfAction SubSystem: '<S355>/Ph3SWA' incorporates:
       *  ActionPort: '<S361>/Action Port'
       */
      LKAS_Ph3SWA(&rtb_Merge1_dq);

      /* End of Outputs for SubSystem: '<S355>/Ph3SWA' */
    }

    /* End of If: '<S355>/If' */

    /* Product: '<S348>/Divide2' */
    rtb_Abs2 = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ * rtb_LL_ThresDet_lDvtThresUprLDW;

    /* Product: '<S348>/Divide3' */
    rtb_LL_ThresDet_lDvtThresLwrLKA = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ *
      rtb_LL_ThresDet_tiTTLCThresLDW;

    /* Abs: '<S357>/Abs' */
    rtb_Abs_cf = fabsf(rtb_Abs_cf);

    /* Product: '<S357>/Divide' */
    rtb_Divide_kz = rtb_LL_ThresDet_lDvtThresLwrLKA * rtb_Abs_cf;

    /* Product: '<S348>/Divide1' */
    rtb_LL_LKAS_OUT_OF_CONTROL_LAT_ *= rtb_LL_ThresDet_lDvtThresLwrLDW;

    /* Switch: '<S362>/Switch' incorporates:
     *  RelationalOperator: '<S362>/UpperRelop'
     */
    if (rtb_Divide_kz < rtb_LL_LKAS_OUT_OF_CONTROL_LAT_) {
      rtb_Switch_p = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_;
    } else {
      rtb_Switch_p = rtb_Divide_kz;
    }

    /* End of Switch: '<S362>/Switch' */

    /* Switch: '<S362>/Switch2' incorporates:
     *  RelationalOperator: '<S362>/LowerRelop1'
     */
    if (rtb_Divide_kz > rtb_Abs2) {
      rtb_Switch2_ds = rtb_Abs2;
    } else {
      rtb_Switch2_ds = rtb_Switch_p;
    }

    /* End of Switch: '<S362>/Switch2' */

    /* Abs: '<S358>/Abs' */
    rtb_LL_DvtComp_C_f = fabsf(rtb_LL_DvtComp_C_f);

    /* Product: '<S358>/Divide' */
    rtb_Divide_l1 = rtb_LL_ThresDet_lDvtThresLwrLKA * rtb_LL_DvtComp_C_f;

    /* Switch: '<S363>/Switch' incorporates:
     *  RelationalOperator: '<S363>/UpperRelop'
     */
    if (rtb_Divide_l1 < rtb_LL_LKAS_OUT_OF_CONTROL_LAT_) {
      rtb_Switch_pw = rtb_LL_LKAS_OUT_OF_CONTROL_LAT_;
    } else {
      rtb_Switch_pw = rtb_Divide_l1;
    }

    /* End of Switch: '<S363>/Switch' */

    /* Switch: '<S363>/Switch2' incorporates:
     *  RelationalOperator: '<S363>/LowerRelop1'
     */
    if (rtb_Divide_l1 > rtb_Abs2) {
      rtb_Switch2_h = rtb_Abs2;
    } else {
      rtb_Switch2_h = rtb_Switch_pw;
    }

    /* End of Switch: '<S363>/Switch2' */

    /* Switch: '<S356>/Switch3' incorporates:
     *  Gain: '<S356>/Gain1'
     *  RelationalOperator: '<S358>/Relational Operator2'
     */
    if (rtb_Merge1_dq >= 0.0F) {
      /* Switch: '<S356>/Switch2' incorporates:
       *  Constant: '<S356>/Constant2'
       *  DataTypeConversion: '<S356>/Cast To Single'
       *  RelationalOperator: '<S357>/Relational Operator2'
       */
      if (rtb_Merge1_dq > 0.0F) {
        rtb_IMAPve_d_BCM_HazardLamp = (uint8)(rtb_LL_DvtComp_C <= rtb_Switch2_ds);
      } else {
        rtb_IMAPve_d_BCM_HazardLamp = ((uint8)0U);
      }

      /* End of Switch: '<S356>/Switch2' */
    } else {
      rtb_IMAPve_d_BCM_HazardLamp = (uint8)(((uint32)(rtb_LKA_Veh2CamL_C <=
        rtb_Switch2_h) * ((uint8)128U)) >> 6);
    }

    /* End of Switch: '<S356>/Switch3' */

    /* If: '<S340>/If' incorporates:
     *  Constant: '<S344>/Constant'
     *  Constant: '<S346>/Constant'
     */
    if (((LKAS_B.IMAPve_d_LKA_Mode == 1) || (LKAS_B.IMAPve_d_LKA_Mode == 2)) &&
        (rtb_IMAPve_d_BCM_HazardLamp == 0)) {
      /* Outputs for IfAction SubSystem: '<S340>/LDW Deactivation Flag (LDWDeactvFlg)' incorporates:
       *  ActionPort: '<S346>/Action Port'
       */
      LKAS_B.Merge_f = true;

      /* End of Outputs for SubSystem: '<S340>/LDW Deactivation Flag (LDWDeactvFlg)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S340>/Default Flag (DflFlg)' incorporates:
       *  ActionPort: '<S344>/Action Port'
       */
      LKAS_B.Merge_f = false;

      /* End of Outputs for SubSystem: '<S340>/Default Flag (DflFlg)' */
    }

    /* End of If: '<S340>/If' */

    /* Logic: '<S298>/Logical Operator1' incorporates:
     *  Constant: '<S557>/Constant'
     *  Constant: '<S620>/Constant'
     *  RelationalOperator: '<S557>/Compare'
     */
    rtb_LogicalOperator1_l = (((uint8)0U) == ((uint8)1U));

    /* Outputs for Enabled SubSystem: '<S298>/Count 5s3' */
    LKAS_Count5s1(rtb_LogicalOperator1_l, rtb_LKA_SampleTime,
                  &LKAS_B.RelationalOperator_h, &LKAS_DW.Count5s3);

    /* End of Outputs for SubSystem: '<S298>/Count 5s3' */

    /* RelationalOperator: '<S567>/Compare' incorporates:
     *  Constant: '<S567>/Constant'
     *  Constant: '<S621>/Constant'
     */
    rtb_Compare_am = (((uint8)0U) == ((uint8)3U));

    /* Outputs for Enabled SubSystem: '<S298>/Count 5s2' */
    LKAS_Count5s1(rtb_Compare_am, rtb_LKA_SampleTime,
                  &LKAS_B.RelationalOperator_m, &LKAS_DW.Count5s2);

    /* End of Outputs for SubSystem: '<S298>/Count 5s2' */

    /* Logic: '<S298>/Logical Operator2' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S13>/Constant'
     *  Constant: '<S33>/Constant'
     *  Constant: '<S34>/Constant'
     *  Constant: '<S35>/Constant'
     *  Constant: '<S568>/Constant'
     *  Constant: '<S569>/Constant'
     *  Constant: '<S570>/Constant'
     *  Constant: '<S571>/Constant'
     *  Logic: '<S6>/Logical Operator1'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S13>/Compare'
     *  RelationalOperator: '<S33>/Compare'
     *  RelationalOperator: '<S34>/Compare'
     *  RelationalOperator: '<S35>/Compare'
     *  RelationalOperator: '<S568>/Compare'
     *  RelationalOperator: '<S569>/Compare'
     *  RelationalOperator: '<S570>/Compare'
     *  RelationalOperator: '<S571>/Compare'
     */
    rtb_LogicalOperator2_a = (((0.0F == 2.0F) == (sint32)true) || ((0.0F != 0.0F)
      == (sint32)true) || (((0.0F != 0.0F) || (0.0F != 1.0F)) == (sint32)true) ||
      ((0.0F != 0.0F) == (sint32)true));

    /* Outputs for Enabled SubSystem: '<S298>/Count 5s4' */
    LKAS_Count5s1(rtb_LogicalOperator2_a, rtb_LKA_SampleTime,
                  &LKAS_B.RelationalOperator_l, &LKAS_DW.Count5s4);

    /* End of Outputs for SubSystem: '<S298>/Count 5s4' */

    /* Logic: '<S298>/Logical Operator10' incorporates:
     *  Logic: '<S298>/Logical Operator8'
     */
    rtb_LogicalOperator3_o = (LKAS_B.RelationalOperator_h ||
      LKAS_B.RelationalOperator_m);
    LKAS_B.LKA_Fault = (rtb_LogicalOperator3_o || LKAS_B.RelationalOperator_l);

    /* Chart: '<S93>/LDW_State_Machine'
     *
     * Block description for '<S93>/LDW_State_Machine':
     *  Block Name: LDW State Machine
     *  Ab.: LDWSM
     *  No.: 1.1.2.0
     *  Rev: 0.0.1
     *  Update Date: 19-3-26
     */
    LKAS_LDW_State_Machine();

    /* RelationalOperator: '<S562>/Compare' incorporates:
     *  Constant: '<S562>/Constant'
     */
    rtb_Compare_mm = (rtb_IMAPve_d_EPS_LKA_State == ((uint8)4U));

    /* Outputs for Enabled SubSystem: '<S298>/Count 5s1' */
    LKAS_Count5s1(rtb_Compare_mm, rtb_LKA_SampleTime,
                  &LKAS_B.RelationalOperator_f, &LKAS_DW.Count5s1);

    /* End of Outputs for SubSystem: '<S298>/Count 5s1' */

    /* Logic: '<S298>/Logical Operator3' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S23>/Constant'
     *  Constant: '<S581>/Constant'
     *  Logic: '<S6>/Logical Operator4'
     *  RelationalOperator: '<S22>/Compare'
     *  RelationalOperator: '<S23>/Compare'
     *  RelationalOperator: '<S581>/Compare'
     */
    rtb_LogicalOperator3_f = (rtb_LogicalOperator2_a || (((rtb_EPS_LKA_Control ==
      ((uint8)1U)) || (rtb_EPS_LKA_Control == ((uint8)2U))) == (sint32)true));

    /* Outputs for Enabled SubSystem: '<S298>/Count 5s5' */
    LKAS_Count5s1(rtb_LogicalOperator3_f, rtb_LKA_SampleTime,
                  &LKAS_B.RelationalOperator, &LKAS_DW.Count5s5);

    /* End of Outputs for SubSystem: '<S298>/Count 5s5' */

    /* Logic: '<S298>/Logical Operator8' */
    LKAS_B.LKA_Fault = (rtb_LogicalOperator3_o || LKAS_B.RelationalOperator_f ||
                        LKAS_B.RelationalOperator);

    /* Chart: '<S93>/LKA_State_Machine'
     *
     * Block description for '<S93>/LKA_State_Machine':
     *  Block Name: LKA State Machine
     *  Ab.: LKASM
     *  No.: 1.1.3.0
     *  Rev: 0.0.1
     *  Update Date: 19-3-26
     */
    LKAS_LKA_State_Machine();

    /* Outputs for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    /* Sum: '<S251>/Add' incorporates:
     *  Sum: '<S185>/Add1'
     */
    rtb_LL_LDW_LatestWarnLine_C = rtb_L0_C1 + rtb_R0_C1;

    /* End of Outputs for SubSystem: '<S10>/LKA' */

    /* Gain: '<S251>/Gain' incorporates:
     *  Sum: '<S251>/Add'
     */
    rtb_Gain_pe = rtb_LL_LDW_LatestWarnLine_C * 0.5F;

    /* Switch: '<S612>/Switch3' incorporates:
     *  Constant: '<S612>/LL_HdAgPrvwT_C=0.45'
     */
    if (LKAS_ConstB.DataTypeConversion3_i != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion3_i;
    } else {
      rtb_Saturation9 = LL_HdAgPrvwT_C;
    }

    /* End of Switch: '<S612>/Switch3' */

    /* Product: '<S260>/Divide' */
    rtb_Abs2 = rtb_Abs_h * rtb_Saturation9;

    /* Product: '<S258>/Z*Z' incorporates:
     *  Product: '<S256>/Z*Z'
     */
    rtb_Saturation9 = rtb_Abs2 * rtb_Abs2;

    /* Sum: '<S258>/Add' incorporates:
     *  Product: '<S258>/Product3'
     *  Product: '<S258>/Product4'
     *  Product: '<S258>/Z*Z'
     */
    rtb_LL_ThresDet_lDvtThresLwrLDW = (rtb_Add_hn_tmp * rtb_Abs2 + rtb_L0_C1) +
      rtb_R0_TLC * rtb_Saturation9;

    /* Sum: '<S256>/Add' incorporates:
     *  Product: '<S256>/Product3'
     *  Product: '<S256>/Product4'
     */
    rtb_LL_ThresDet_lDvtThresUprLDW = (rtb_Add_jc_tmp * rtb_Abs2 + rtb_R0_C1) +
      rtb_L0_TLC * rtb_Saturation9;

    /* Saturate: '<S230>/Saturation' */
    if (rtb_IMAPve_g_ESC_VehSpd > 150.0F) {
      rtb_Abs2 = 150.0F;
    } else if (rtb_IMAPve_g_ESC_VehSpd < 0.001F) {
      rtb_Abs2 = 0.001F;
    } else {
      rtb_Abs2 = rtb_IMAPve_g_ESC_VehSpd;
    }

    /* End of Saturate: '<S230>/Saturation' */

    /* Gain: '<S287>/kph To mps' incorporates:
     *  Gain: '<S288>/kph To mps'
     */
    rtb_LL_ThresDet_tiTTLCThresLDW = 0.277777791F * rtb_Abs2;

    /* Lookup_n-D: '<S287>/Lookup Table2' */
    rtb_LL_ThresDet_lDvtThresLwrLKA = look1_iflf_pbinlgpw(rtb_Abs2,
      LKAS_ConstP.pooled16, LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex_o, 7U);

    /* Saturate: '<S287>/Saturation1' */
    if (rtb_LL_ThresDet_lDvtThresLwrLKA > 0.0117F) {
      rtb_LL_ThresDet_lDvtThresLwrLKA = 0.0117F;
    } else {
      if (rtb_LL_ThresDet_lDvtThresLwrLKA < 0.00237F) {
        rtb_LL_ThresDet_lDvtThresLwrLKA = 0.00237F;
      }
    }

    /* End of Saturate: '<S287>/Saturation1' */

    /* Switch: '<S612>/Switch7' incorporates:
     *  Constant: '<S612>/LL_LAccMax_C=3'
     */
    if (LKAS_ConstB.DataTypeConversion5 != 0.0F) {
      rtb_Saturation9 = LKAS_ConstB.DataTypeConversion5;
    } else {
      rtb_Saturation9 = LL_LAccMax_C;
    }

    /* End of Switch: '<S612>/Switch7' */

    /* MATLAB Function: '<S287>/MATLAB Function' incorporates:
     *  Gain: '<S287>/kph To mps'
     */
    rtb_LL_TkOvStChk_tiTDelTime = (rtb_LL_ThresDet_lDvtThresLwrLKA *
      rtb_LL_ThresDet_tiTTLCThresLDW * rtb_LL_ThresDet_tiTTLCThresLDW + 1.0F) *
      rtb_Saturation9 * LKAS_B.LKA_StrRatio_C_h * LKAS_B.LKA_WhlBaseL_C_n /
      (rtb_LL_ThresDet_tiTTLCThresLDW * rtb_LL_ThresDet_tiTTLCThresLDW) * 180.0F
      / 3.14F;

    /* Lookup_n-D: '<S288>/Lookup Table2' */
    rtb_Abs2 = look1_iflf_pbinlgpw(rtb_Abs2, LKAS_ConstP.pooled16,
      LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex_oh, 7U);

    /* Saturate: '<S288>/Saturation1' */
    if (rtb_Abs2 > 0.0117F) {
      rtb_Saturation9 = 0.0117F;
    } else if (rtb_Abs2 < 0.00237F) {
      rtb_Saturation9 = 0.00237F;
    } else {
      rtb_Saturation9 = rtb_Abs2;
    }

    /* End of Saturate: '<S288>/Saturation1' */

    /* Switch: '<S612>/Switch4' incorporates:
     *  Constant: '<S612>/LL_LAccRMax_C=5'
     */
    if (LKAS_ConstB.DataTypeConversion10 != 0.0F) {
      rtb_Saturation10 = LKAS_ConstB.DataTypeConversion10;
    } else {
      rtb_Saturation10 = LL_LAccRMax_C;
    }

    /* End of Switch: '<S612>/Switch4' */

    /* MATLAB Function: '<S288>/MATLAB Function' */
    LKAS_B.SWARmax = (rtb_Saturation9 * rtb_LL_ThresDet_tiTTLCThresLDW *
                      rtb_LL_ThresDet_tiTTLCThresLDW + 1.0F) * rtb_Saturation10 *
      LKAS_B.LKA_StrRatio_C_h * LKAS_B.LKA_WhlBaseL_C_n /
      (rtb_LL_ThresDet_tiTTLCThresLDW * rtb_LL_ThresDet_tiTTLCThresLDW) * 180.0F
      / 3.14F;

    /* Abs: '<S276>/Abs6' */
    rtb_Abs2 = fabsf(rtb_L0_C1);

    /* RelationalOperator: '<S276>/Relational Operator2' incorporates:
     *  Constant: '<S276>/Constant1'
     */
    rtb_LogicalOperator3_o = (rtb_Abs2 <= 0.005F);

    /* Abs: '<S276>/Abs7' */
    rtb_Abs2 = fabsf(rtb_R0_C1);

    /* RelationalOperator: '<S276>/Relational Operator3' incorporates:
     *  Constant: '<S276>/Constant1'
     */
    rtb_LogicalOperator2_p = (rtb_Abs2 <= 0.005F);

    /* Abs: '<S276>/Abs4' */
    rtb_Abs2 = fabsf(rtb_L0_C2);

    /* RelationalOperator: '<S276>/Relational Operator' incorporates:
     *  Constant: '<S276>/Constant'
     */
    rtb_RelationalOperator_l0 = (rtb_Abs2 <= 0.0001F);

    /* Abs: '<S276>/Abs5' */
    rtb_Abs2 = fabsf(rtb_R0_C2);

    /* RelationalOperator: '<S276>/Relational Operator1' incorporates:
     *  Constant: '<S276>/Constant'
     */
    rtb_RelationalOperator1_h = (rtb_Abs2 <= 0.0001F);

    /* Abs: '<S276>/Abs2' */
    rtb_Abs2 = rtb_LogicalOperator3_g_tmp_0;

    /* Outputs for Enabled SubSystem: '<S276>/Subsystem' incorporates:
     *  EnablePort: '<S280>/Enable'
     */
    /* Logic: '<S276>/Logical Operator3' incorporates:
     *  Constant: '<S276>/Constant4'
     *  Constant: '<S276>/Constant5'
     *  Constant: '<S278>/Constant'
     *  Constant: '<S279>/Constant'
     *  Logic: '<S276>/Logical Operator'
     *  Logic: '<S276>/Logical Operator1'
     *  Logic: '<S276>/Logical Operator4'
     *  RelationalOperator: '<S276>/Relational Operator6'
     *  RelationalOperator: '<S276>/Relational Operator7'
     *  RelationalOperator: '<S278>/Compare'
     *  RelationalOperator: '<S279>/Compare'
     *  Switch: '<S70>/Switch'
     *  Switch: '<S70>/Switch1'
     */
    if (rtb_LogicalOperator3_o && rtb_LogicalOperator2_p &&
        (rtb_RelationalOperator_l0 && rtb_RelationalOperator1_h) && ((rtb_L0_Q ==
          ((uint8)3U)) && (rtb_R0_Q == ((uint8)3U))) && (rtb_IMAPve_g_ESC_VehSpd
         >= 50.0F) && (rtb_Abs2 <= 1.0F)) {
      if (!LKAS_DW.Subsystem_MODE) {
        /* InitializeConditions for Sum: '<S280>/Add1' incorporates:
         *  Memory: '<S280>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_mo = ((uint16)0U);
        LKAS_DW.Subsystem_MODE = true;
      }

      /* Sum: '<S280>/Add1' incorporates:
       *  Memory: '<S280>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_mo++;

      /* Saturate: '<S280>/Saturation' */
      if (LKAS_DW.Memory_PreviousInput_mo >= ((uint16)3000U)) {
        /* Sum: '<S280>/Add1' */
        LKAS_DW.Memory_PreviousInput_mo = ((uint16)3000U);
      }

      /* End of Saturate: '<S280>/Saturation' */

      /* DataTypeConversion: '<S280>/Cast To Single1' incorporates:
       *  Constant: '<S276>/Constant3'
       *  Product: '<S276>/Divide'
       */
      rtb_Saturation9 = fmodf(floorf(2.0F / rtb_LKA_SampleTime), 65536.0F);

      /* RelationalOperator: '<S280>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S280>/Cast To Single1'
       */
      LKAS_B.RelationalOperator_hy = (LKAS_DW.Memory_PreviousInput_mo >=
        (rtb_Saturation9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-
         rtb_Saturation9 : (sint32)(uint16)rtb_Saturation9));
    } else {
      if (LKAS_DW.Subsystem_MODE) {
        /* Disable for Outport: '<S280>/Out' */
        LKAS_B.RelationalOperator_hy = false;
        LKAS_DW.Subsystem_MODE = false;
      }
    }

    /* End of Logic: '<S276>/Logical Operator3' */
    /* End of Outputs for SubSystem: '<S276>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S228>/Subsystem' incorporates:
     *  EnablePort: '<S275>/Enable'
     */
    if (LKAS_B.RelationalOperator_hy) {
      /* Sum: '<S277>/Add2' incorporates:
       *  Constant: '<S277>/SWACmdSyn_tiSmplT_C4'
       *  Memory: '<S277>/Memory3'
       */
      LKAS_DW.Memory3_PreviousInput += 1.0F;

      /* Saturate: '<S277>/Saturation' */
      if (LKAS_DW.Memory3_PreviousInput > 50.0F) {
        /* Sum: '<S277>/Add2' */
        LKAS_DW.Memory3_PreviousInput = 50.0F;
      } else {
        if (LKAS_DW.Memory3_PreviousInput < 0.0F) {
          /* Sum: '<S277>/Add2' */
          LKAS_DW.Memory3_PreviousInput = 0.0F;
        }
      }

      /* End of Saturate: '<S277>/Saturation' */

      /* Switch: '<S277>/Switch' incorporates:
       *  Constant: '<S275>/Constant'
       *  Product: '<S277>/Divide'
       *  Product: '<S277>/Divide1'
       *  Sum: '<S277>/Add'
       *  Sum: '<S277>/Add1'
       *  UnitDelay: '<S277>/Unit Delay'
       */
      if (LKAS_DW.Memory3_PreviousInput > 1.0F) {
        LKAS_DW.UnitDelay_DSTATE += rtb_LKA_SampleTime / 10.0F *
          (rtb_IMAPve_g_SW_Angle - LKAS_DW.UnitDelay_DSTATE);
      } else {
        LKAS_DW.UnitDelay_DSTATE = rtb_IMAPve_g_SW_Angle;
      }

      /* End of Switch: '<S277>/Switch' */

      /* Saturate: '<S275>/Saturation' incorporates:
       *  UnitDelay: '<S277>/Unit Delay'
       */
      if (LKAS_DW.UnitDelay_DSTATE > 3.0F) {
        LKAS_B.Saturation = 3.0F;
      } else if (LKAS_DW.UnitDelay_DSTATE < (-3.0F)) {
        LKAS_B.Saturation = (-3.0F);
      } else {
        LKAS_B.Saturation = LKAS_DW.UnitDelay_DSTATE;
      }

      /* End of Saturate: '<S275>/Saturation' */
    }

    /* End of Outputs for SubSystem: '<S228>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    if (LKAS_B.LKASM_stLKAActvFlg > 0) {
      if (!LKAS_DW.LKA_MODE) {
        /* InitializeConditions for Memory: '<S118>/Memory' */
        LKAS_DW.Memory_PreviousInput_a = 0.0F;

        /* InitializeConditions for Memory: '<S153>/Memory' */
        LKAS_DW.Memory_PreviousInput_l = ((uint16)0U);

        /* InitializeConditions for Memory: '<S102>/Memory1' */
        LKAS_DW.Memory1_PreviousInput_k = ((uint8)0U);

        /* InitializeConditions for Memory: '<S152>/Memory' */
        LKAS_DW.Memory_PreviousInput_lx = ((uint16)0U);

        /* InitializeConditions for Memory: '<S154>/Memory' */
        LKAS_DW.Memory_PreviousInput_k = ((uint16)0U);

        /* InitializeConditions for Memory: '<S173>/Memory' */
        LKAS_DW.Memory_PreviousInput_h3 = ((uint16)0U);

        /* InitializeConditions for Memory: '<S151>/Memory' */
        LKAS_DW.Memory_PreviousInput_d2 = ((uint16)0U);

        /* InitializeConditions for Memory: '<S150>/Memory' */
        LKAS_DW.Memory_PreviousInput_ko = ((uint16)0U);

        /* InitializeConditions for Memory: '<S149>/Memory' */
        LKAS_DW.Memory_PreviousInput_mm = ((uint16)0U);

        /* InitializeConditions for Memory: '<S128>/Memory' */
        LKAS_DW.Memory_PreviousInput_i0 = 0.0F;

        /* InitializeConditions for Memory: '<S119>/Memory' */
        LKAS_DW.Memory_PreviousInput_g = 0.0F;

        /* InitializeConditions for Memory: '<S120>/Memory' */
        LKAS_DW.Memory_PreviousInput_aw = 0.0F;

        /* InitializeConditions for Memory: '<S117>/Memory3' */
        LKAS_DW.Memory3_PreviousInput_i = 0.0F;

        /* InitializeConditions for Memory: '<S201>/Memory3' */
        LKAS_DW.Memory3_PreviousInput_c = 0.0F;

        /* InitializeConditions for Memory: '<S187>/Memory' */
        LKAS_DW.Memory_PreviousInput_av = 0.0F;

        /* InitializeConditions for UnitDelay: '<S185>/Unit Delay' */
        LKAS_DW.UnitDelay_DSTATE_g = 0.0F;

        /* InitializeConditions for Memory: '<S192>/Memory3' */
        LKAS_DW.Memory3_PreviousInput_h = 0.0F;

        /* InitializeConditions for Memory: '<S196>/Memory' */
        LKAS_DW.Memory_PreviousInput_e4 = ((uint16)0U);

        /* InitializeConditions for UnitDelay: '<S200>/Unit Delay' */
        LKAS_DW.UnitDelay_DSTATE_h = 0.0F;

        /* InitializeConditions for Memory: '<S200>/Memory3' */
        LKAS_DW.Memory3_PreviousInput_j = 0.0F;

        /* InitializeConditions for UnitDelay: '<S180>/Delay Input2'
         *
         * Block description for '<S180>/Delay Input2':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput2_DSTATE = 0.0F;

        /* InitializeConditions for Memory: '<S180>/Memory' */
        LKAS_DW.Memory_PreviousInput_bh = ((uint16)0U);

        /* SystemReset for Atomic SubSystem: '<S108>/Moving Standard Deviation2' */
        MovingStandardDeviation2_Reset(&LKAS_DW.MovingStandardDeviation2);

        /* End of SystemReset for SubSystem: '<S108>/Moving Standard Deviation2' */

        /* SystemReset for Atomic SubSystem: '<S120>/Moving Standard Deviation1' */
        MovingStandardDeviation2_Reset(&LKAS_DW.MovingStandardDeviation1);

        /* End of SystemReset for SubSystem: '<S120>/Moving Standard Deviation1' */

        /* SystemReset for Atomic SubSystem: '<S120>/Moving Standard Deviation2' */
        MovingStandardDeviation2_Reset(&LKAS_DW.MovingStandardDeviation2_e);

        /* End of SystemReset for SubSystem: '<S120>/Moving Standard Deviation2' */
        LKAS_DW.LKA_MODE = true;
      }

      /* Sum: '<S118>/Add2' incorporates:
       *  Memory: '<S118>/Memory'
       */
      rtb_R0_C2 = rtb_LKA_SampleTime + LKAS_DW.Memory_PreviousInput_a;

      /* Saturate: '<S118>/Saturation' */
      if (rtb_Abs_tmp > 0.004F) {
        rtb_Saturation10 = 0.004F;
      } else if (rtb_Abs_tmp < 0.0F) {
        rtb_Saturation10 = 0.0F;
      } else {
        rtb_Saturation10 = rtb_Abs_tmp;
      }

      /* End of Saturate: '<S118>/Saturation' */

      /* RelationalOperator: '<S118>/Relational Operator4' incorporates:
       *  Constant: '<S118>/Constant'
       *  Constant: '<S118>/Constant1'
       *  Product: '<S118>/Divide'
       *  Sum: '<S118>/Add'
       */
      rtb_LogicalOperator3_o = (rtb_R0_C2 >= rtb_LL_LKAExPrcs_tiExitTime1 * 0.5F
        * rtb_Saturation10 / 0.004F + rtb_LL_LKAExPrcs_tiExitTime1);

      /* Sum: '<S153>/Add' incorporates:
       *  Constant: '<S153>/Constant'
       *  Memory: '<S153>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_l);

      /* Saturate: '<S153>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_l = rtb_Add1_hb;
      } else {
        rtb_Saturation1_l = ((uint16)10000U);
      }

      /* End of Saturate: '<S153>/Saturation1' */

      /* If: '<S153>/If' incorporates:
       *  Constant: '<S153>/Constant2'
       */
      if (rtb_Saturation1_l == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S153>/if action ' incorporates:
         *  ActionPort: '<S163>/Action Port'
         */
        LKAS_ifaction(rtb_IMAPve_g_SW_Angle, &LKAS_B.In_d);

        /* End of Outputs for SubSystem: '<S153>/if action ' */
      }

      /* End of If: '<S153>/If' */

      /* Sum: '<S102>/Add' incorporates:
       *  Constant: '<S102>/Constant'
       *  Memory: '<S102>/Memory1'
       */
      rtb_IMAPve_d_BCM_HazardLamp = (uint8)((uint32)((uint8)1U) +
        LKAS_DW.Memory1_PreviousInput_k);

      /* Saturate: '<S102>/Saturation1' */
      if (rtb_IMAPve_d_BCM_HazardLamp < ((uint8)5U)) {
        rtb_Saturation1_ks = rtb_IMAPve_d_BCM_HazardLamp;
      } else {
        rtb_Saturation1_ks = ((uint8)5U);
      }

      /* End of Saturate: '<S102>/Saturation1' */

      /* Lookup_n-D: '<S127>/Lookup Table2' */
      rtb_L0_C2 = look1_iflf_pbinlgpw(rtb_IMAPve_g_ESC_VehSpd,
        LKAS_ConstP.pooled16, LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex_i, 7U);

      /* Saturate: '<S127>/Saturation1' */
      if (rtb_L0_C2 > 0.0117F) {
        LKAS_B.StbFacm_SY = 0.0117F;
      } else if (rtb_L0_C2 < 0.00237F) {
        LKAS_B.StbFacm_SY = 0.00237F;
      } else {
        LKAS_B.StbFacm_SY = rtb_L0_C2;
      }

      /* End of Saturate: '<S127>/Saturation1' */

      /* Sum: '<S152>/Add' incorporates:
       *  Constant: '<S152>/Constant'
       *  Memory: '<S152>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_lx);

      /* Saturate: '<S152>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_la = rtb_Add1_hb;
      } else {
        rtb_Saturation1_la = ((uint16)10000U);
      }

      /* End of Saturate: '<S152>/Saturation1' */

      /* If: '<S147>/If' incorporates:
       *  DataTypeConversion: '<S91>/Cast To Single'
       */
      if (LKAS_B.LKASM_stLKAActvFlg == 1) {
        /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S157>/Action Port'
         */
        LKAS_ifaction3(rtb_LFTTTLC, &rtb_Merge_a);

        /* End of Outputs for SubSystem: '<S147>/If Action Subsystem2' */
      } else if (LKAS_B.LKASM_stLKAActvFlg == 2) {
        /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S156>/Action Port'
         */
        LKAS_ifaction3(rtb_RGTTTLC, &rtb_Merge_a);

        /* End of Outputs for SubSystem: '<S147>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S158>/Action Port'
         */
        LKAS_IfActionSubsystem2(&rtb_Merge_a);

        /* End of Outputs for SubSystem: '<S147>/If Action Subsystem3' */
      }

      /* End of If: '<S147>/If' */

      /* If: '<S152>/If' incorporates:
       *  Constant: '<S152>/Constant2'
       */
      if (rtb_Saturation1_la == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S152>/if action ' incorporates:
         *  ActionPort: '<S162>/Action Port'
         */
        LKAS_ifaction(rtb_Merge_a, &LKAS_B.In_nn);

        /* End of Outputs for SubSystem: '<S152>/if action ' */
      }

      /* End of If: '<S152>/If' */

      /* Saturate: '<S127>/Saturation2' */
      if (LKAS_B.In_nn > 2.0F) {
        LKAS_B.MPInP_tiTTLCIni = 2.0F;
      } else if (LKAS_B.In_nn < 0.6F) {
        LKAS_B.MPInP_tiTTLCIni = 0.6F;
      } else {
        LKAS_B.MPInP_tiTTLCIni = LKAS_B.In_nn;
      }

      /* End of Saturate: '<S127>/Saturation2' */

      /* Sum: '<S154>/Add' incorporates:
       *  Constant: '<S154>/Constant'
       *  Memory: '<S154>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_k);

      /* Saturate: '<S154>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_b = rtb_Add1_hb;
      } else {
        rtb_Saturation1_b = ((uint16)10000U);
      }

      /* End of Saturate: '<S154>/Saturation1' */

      /* If: '<S154>/If' incorporates:
       *  Constant: '<S154>/Constant2'
       */
      if (rtb_Saturation1_b == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S154>/if action ' incorporates:
         *  ActionPort: '<S164>/Action Port'
         */
        LKAS_ifaction(rtb_IMAPve_g_ESC_VehSpd, &LKAS_B.In_f);

        /* End of Outputs for SubSystem: '<S154>/if action ' */
      }

      /* End of If: '<S154>/If' */

      /* Sum: '<S173>/Add' incorporates:
       *  Constant: '<S173>/Constant'
       *  Memory: '<S173>/Memory'
       */
      rtb_Add_p2 = (uint16)((uint32)((uint16)1U) +
                            LKAS_DW.Memory_PreviousInput_h3);

      /* DataTypeConversion: '<S174>/Data Type Conversion' incorporates:
       *  Constant: '<S175>/Constant'
       *  RelationalOperator: '<S175>/Compare'
       */
      rtb_IMAPve_d_BCM_HazardLamp = (uint8)(rtb_Merge_k <= 0.0F);

      /* Switch: '<S612>/Switch5' incorporates:
       *  Constant: '<S612>/LL_LSpdCompT_C=0.4'
       */
      if (LKAS_ConstB.DataTypeConversion13 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion13;
      } else {
        rtb_Saturation9 = LL_LSpdCompT_C;
      }

      /* End of Switch: '<S612>/Switch5' */

      /* Product: '<S174>/Divide' */
      rtb_Add2_p = rtb_Merge_k * rtb_Abs_h * rtb_Saturation9;

      /* Abs: '<S174>/Abs1' incorporates:
       *  Abs: '<S174>/Abs'
       */
      rtb_L0_C2 = fabsf(rtb_Add2_p);
      rtb_Abs1_l = rtb_L0_C2;

      /* Abs: '<S174>/Abs' */
      rtb_Abs_i = rtb_L0_C2;

      /* If: '<S174>/If' incorporates:
       *  DataTypeConversion: '<S91>/Cast To Single'
       */
      if ((LKAS_B.LKASM_stLKAActvFlg == 1) && (rtb_IMAPve_d_BCM_HazardLamp == 0))
      {
        /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem' incorporates:
         *  ActionPort: '<S176>/Action Port'
         */
        LKAS_IfActionSubsystem(rtb_Abs_i, &rtb_Add2_p);

        /* End of Outputs for SubSystem: '<S174>/If Action Subsystem' */
      } else if ((LKAS_B.LKASM_stLKAActvFlg == 2) &&
                 (rtb_IMAPve_d_BCM_HazardLamp == 1)) {
        /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem4' incorporates:
         *  ActionPort: '<S178>/Action Port'
         */
        LKAS_IfActionSubsystem(rtb_Abs1_l, &rtb_Add2_p);

        /* End of Outputs for SubSystem: '<S174>/If Action Subsystem4' */
      } else {
        /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S177>/Action Port'
         */
        LKAS_IfActionSubsystem2(&rtb_Add2_p);

        /* End of Outputs for SubSystem: '<S174>/If Action Subsystem2' */
      }

      /* End of If: '<S174>/If' */

      /* Switch: '<S612>/Switch6' incorporates:
       *  Constant: '<S612>/LL_HdAgExT_C=15'
       */
      if (LKAS_ConstB.DataTypeConversion6_h != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion6_h;
      } else {
        rtb_Saturation9 = LL_HdAgExT_C;
      }

      /* End of Switch: '<S612>/Switch6' */

      /* Switch: '<S610>/Switch11' incorporates:
       *  Constant: '<S610>/LKA_CarWidth=1.8'
       */
      if (LKAS_ConstB.DataTypeConversion22_l != 0.0F) {
        rtb_Saturation10 = LKAS_ConstB.DataTypeConversion22_l;
      } else {
        rtb_Saturation10 = LKA_CarWidth;
      }

      /* End of Switch: '<S610>/Switch11' */

      /* Sum: '<S169>/Add1' incorporates:
       *  Product: '<S169>/Divide'
       *  Product: '<S169>/Divide1'
       *  Sum: '<S169>/Add'
       */
      rtb_Add1_kk = 1.0F / rtb_Saturation9 * (rtb_LaneWidth - rtb_Saturation10) /
        rtb_Abs_h + rtb_Add2_p;

      /* If: '<S130>/If' incorporates:
       *  Constant: '<S172>/Constant2'
       *  DataTypeConversion: '<S91>/Cast To Single'
       */
      if (LKAS_B.LKASM_stLKAActvFlg == 1) {
        /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem' incorporates:
         *  ActionPort: '<S170>/Action Port'
         */
        /* Gain: '<S170>/Gain2' */
        rtb_Merge_mb = (-1.0F) * rtb_Add1_kk;

        /* End of Outputs for SubSystem: '<S130>/If Action Subsystem' */
      } else if (LKAS_B.LKASM_stLKAActvFlg == 2) {
        /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S171>/Action Port'
         */
        LKAS_IfActionSubsystem(rtb_Add1_kk, &rtb_Merge_mb);

        /* End of Outputs for SubSystem: '<S130>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S172>/Action Port'
         */
        rtb_Merge_mb = 0.0F;

        /* End of Outputs for SubSystem: '<S130>/If Action Subsystem2' */
      }

      /* End of If: '<S130>/If' */

      /* Saturate: '<S173>/Saturation1' */
      if (rtb_Add_p2 < ((uint16)10000U)) {
        rtb_Add1_hb = rtb_Add_p2;
      } else {
        rtb_Add1_hb = ((uint16)10000U);
      }

      /* End of Saturate: '<S173>/Saturation1' */

      /* If: '<S173>/If' incorporates:
       *  Constant: '<S173>/Constant2'
       */
      if (rtb_Add1_hb == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S173>/if action ' incorporates:
         *  ActionPort: '<S179>/Action Port'
         */
        LKAS_ifaction(rtb_Merge_mb, &LKAS_B.In_a);

        /* End of Outputs for SubSystem: '<S173>/if action ' */
      }

      /* End of If: '<S173>/If' */

      /* Sum: '<S151>/Add' incorporates:
       *  Constant: '<S151>/Constant'
       *  Memory: '<S151>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_d2);

      /* Saturate: '<S151>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_f = rtb_Add1_hb;
      } else {
        rtb_Saturation1_f = ((uint16)10000U);
      }

      /* End of Saturate: '<S151>/Saturation1' */

      /* If: '<S151>/If' incorporates:
       *  Constant: '<S151>/Constant2'
       */
      if (rtb_Saturation1_f == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S151>/if action ' incorporates:
         *  ActionPort: '<S161>/Action Port'
         */
        LKAS_ifaction(rtb_Gain_pe, &LKAS_B.In_ni);

        /* End of Outputs for SubSystem: '<S151>/if action ' */
      }

      /* End of If: '<S151>/If' */

      /* Sum: '<S150>/Add' incorporates:
       *  Constant: '<S150>/Constant'
       *  Memory: '<S150>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_ko);

      /* Saturate: '<S150>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_b2 = rtb_Add1_hb;
      } else {
        rtb_Saturation1_b2 = ((uint16)10000U);
      }

      /* End of Saturate: '<S150>/Saturation1' */

      /* If: '<S150>/If' incorporates:
       *  Constant: '<S150>/Constant2'
       */
      if (rtb_Saturation1_b2 == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S150>/if action ' incorporates:
         *  ActionPort: '<S160>/Action Port'
         */
        LKAS_ifaction(rtb_Merge_p, &LKAS_B.In_b);

        /* End of Outputs for SubSystem: '<S150>/if action ' */
      }

      /* End of If: '<S150>/If' */

      /* Sum: '<S149>/Add' incorporates:
       *  Constant: '<S149>/Constant'
       *  Memory: '<S149>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_mm);

      /* Saturate: '<S149>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_e = rtb_Add1_hb;
      } else {
        rtb_Saturation1_e = ((uint16)10000U);
      }

      /* End of Saturate: '<S149>/Saturation1' */

      /* If: '<S149>/If' incorporates:
       *  Constant: '<S149>/Constant2'
       */
      if (rtb_Saturation1_e == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S149>/if action ' incorporates:
         *  ActionPort: '<S159>/Action Port'
         */
        LKAS_ifaction(rtb_Merge_kn, &LKAS_B.In_p);

        /* End of Outputs for SubSystem: '<S149>/if action ' */
      }

      /* End of If: '<S149>/If' */

      /* If: '<S155>/If' incorporates:
       *  DataTypeConversion: '<S91>/Cast To Single'
       */
      if (LKAS_B.LKASM_stLKAActvFlg == 1) {
        /* Outputs for IfAction SubSystem: '<S155>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S166>/Action Port'
         */
        /* SignalConversion: '<S166>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
         *  Constant: '<S166>/Constant'
         */
        LKAS_B.Merge = (-1.0F);

        /* End of Outputs for SubSystem: '<S155>/If Action Subsystem2' */
      } else if (LKAS_B.LKASM_stLKAActvFlg == 2) {
        /* Outputs for IfAction SubSystem: '<S155>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S165>/Action Port'
         */
        /* SignalConversion: '<S165>/OutportBuffer_InsertedFor_Out1_at_inport_0' incorporates:
         *  Constant: '<S165>/Constant'
         */
        LKAS_B.Merge = 1.0F;

        /* End of Outputs for SubSystem: '<S155>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S155>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S167>/Action Port'
         */
        LKAS_IfActionSubsystem2(&LKAS_B.Merge);

        /* End of Outputs for SubSystem: '<S155>/If Action Subsystem3' */
      }

      /* End of If: '<S155>/If' */

      /* If: '<S102>/If' incorporates:
       *  Constant: '<S102>/Constant19'
       */
      rtPrevAction = LKAS_DW.If_ActiveSubsystem;
      LKAS_DW.If_ActiveSubsystem = -1;
      if (rtb_Saturation1_ks == ((uint8)1U)) {
        LKAS_DW.If_ActiveSubsystem = 0;
      }

      if (LKAS_DW.If_ActiveSubsystem == 0) {
        if (0 != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' incorporates:
           *  ActionPort: '<S126>/Action Port'
           *
           * Block description for '<S102>/LKA Motion Planning Calculation (LKAMPCal)':
           *  Block Name: LKA Motion Planning Calculation
           *  Ab.: LKAMPCal
           *  No.: 1.2.3.2
           *  Rev: 0.0.1
           *  Update Date: 19-3-26
           */
          /* SystemReset for If: '<S102>/If' */
          LKAMotionPlanningCalculat_Reset();

          /* End of SystemReset for SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' */
        }

        /* Outputs for IfAction SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' incorporates:
         *  ActionPort: '<S126>/Action Port'
         *
         * Block description for '<S102>/LKA Motion Planning Calculation (LKAMPCal)':
         *  Block Name: LKA Motion Planning Calculation
         *  Ab.: LKAMPCal
         *  No.: 1.2.3.2
         *  Rev: 0.0.1
         *  Update Date: 19-3-26
         */
        LKAMotionPlanningCalculationLKA();

        /* End of Outputs for SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' */
      }

      /* End of If: '<S102>/If' */

      /* Memory: '<S128>/Memory' */
      rtb_Add2_p = LKAS_DW.Memory_PreviousInput_i0;

      /* Sum: '<S128>/Add' incorporates:
       *  Gain: '<S128>/Gain1'
       *  Product: '<S128>/Divide'
       *  Product: '<S128>/Product'
       */
      rtb_Add_c3 = rtb_Abs_h * rtb_LKA_SampleTime / (0.277777791F * LKAS_B.In_f)
        + rtb_Add2_p;

      /* MATLAB Function: '<S129>/SWACmd' */
      rtb_SWACmd_phiSWACmd = 0.0F;
      rtb_L0_C2 = (LKAS_B.K1K2Det_phi2PhSWAIni - LKAS_B.In_d) /
        LKAS_B.K1K2Det_dphi1PhSWAGrad;
      rtb_LL_LKAExPrcs_tiExitTime1 = (0.0F - LKAS_B.K1K2Det_phi2PhSWAIni) /
        LKAS_B.K1K2Det_dphi2PhSWAGrad1 + rtb_L0_C2;
      if ((rtb_Add_c3 < rtb_L0_C2) && (rtb_Add_c3 >= 0.0F)) {
        rtb_SWACmd_phiSWACmd = LKAS_B.K1K2Det_dphi1PhSWAGrad * rtb_Add_c3 +
          LKAS_B.In_d;
      } else if ((rtb_Add_c3 <= rtb_LL_LKAExPrcs_tiExitTime1) && (rtb_Add_c3 >=
                  rtb_L0_C2)) {
        rtb_SWACmd_phiSWACmd = LKAS_B.K1K2Det_dphi1PhSWAGrad * rtb_L0_C2 +
          LKAS_B.In_d;
      } else {
        if (rtb_Add_c3 >= rtb_LL_LKAExPrcs_tiExitTime1) {
          rtb_SWACmd_phiSWACmd = LKAS_B.K1K2Det_dphi1PhSWAGrad * rtb_L0_C2 +
            LKAS_B.In_d;
        }
      }

      rtb_T2 = rtb_LL_LKAExPrcs_tiExitTime1;

      /* Saturate: '<S102>/Saturation6' incorporates:
       *  MATLAB Function: '<S129>/SWACmd'
       */
      if (rtb_L0_C2 > 2.0F) {
        rtb_Saturation6_h = 2.0F;
      } else if (rtb_L0_C2 < 0.2F) {
        rtb_Saturation6_h = 0.2F;
      } else {
        rtb_Saturation6_h = rtb_L0_C2;
      }

      /* End of Saturate: '<S102>/Saturation6' */

      /* Memory: '<S119>/Memory' */
      rtb_Add2_p = LKAS_DW.Memory_PreviousInput_g;

      /* Sum: '<S119>/Add2' */
      rtb_Add2_p += rtb_LKA_SampleTime;

      /* Sum: '<S119>/Add' incorporates:
       *  Constant: '<S119>/Constant3'
       */
      rtb_L0_C2 = 0.3F + rtb_LKA_Veh2CamW_C;

      /* Outputs for Enabled SubSystem: '<S119>/Sum Condition1' incorporates:
       *  EnablePort: '<S121>/Enable'
       */
      /* Logic: '<S119>/Logical Operator1' incorporates:
       *  RelationalOperator: '<S119>/Relational Operator2'
       *  RelationalOperator: '<S119>/Relational Operator3'
       *  RelationalOperator: '<S119>/Relational Operator4'
       */
      if ((rtb_Add2_p >= rtb_Saturation6_h) && (u0_tmp_tmp >= rtb_L0_C2) &&
          (u0_tmp_tmp_0 >= rtb_L0_C2)) {
        if (!LKAS_DW.SumCondition1_MODE_b) {
          /* InitializeConditions for Sum: '<S121>/Add1' incorporates:
           *  Memory: '<S121>/Memory'
           */
          LKAS_DW.Memory_PreviousInput_gg = 0.0F;
          LKAS_DW.SumCondition1_MODE_b = true;
        }

        /* Sum: '<S121>/Add1' incorporates:
         *  Memory: '<S121>/Memory'
         */
        LKAS_DW.Memory_PreviousInput_gg += rtb_LKA_SampleTime;

        /* Saturate: '<S121>/Saturation' */
        if (LKAS_DW.Memory_PreviousInput_gg > 10.0F) {
          /* Sum: '<S121>/Add1' */
          LKAS_DW.Memory_PreviousInput_gg = 10.0F;
        } else {
          if (LKAS_DW.Memory_PreviousInput_gg < 0.0F) {
            /* Sum: '<S121>/Add1' */
            LKAS_DW.Memory_PreviousInput_gg = 0.0F;
          }
        }

        /* End of Saturate: '<S121>/Saturation' */

        /* Saturate: '<S119>/Saturation' */
        if (rtb_Abs_tmp > 0.004F) {
          rtb_Saturation10 = 0.004F;
        } else if (rtb_Abs_tmp < 0.0F) {
          rtb_Saturation10 = 0.0F;
        } else {
          rtb_Saturation10 = rtb_Abs_tmp;
        }

        /* End of Saturate: '<S119>/Saturation' */

        /* RelationalOperator: '<S121>/Relational Operator' incorporates:
         *  Constant: '<S119>/Constant'
         *  Constant: '<S119>/Constant1'
         *  Product: '<S119>/Divide'
         *  Sum: '<S119>/Add1'
         */
        LKAS_B.RelationalOperator_k = (LKAS_DW.Memory_PreviousInput_gg >=
          rtb_LL_LKAExPrcs_tiExitTime2 * 0.5F * rtb_Saturation10 / 0.004F +
          rtb_LL_LKAExPrcs_tiExitTime2);
      } else {
        if (LKAS_DW.SumCondition1_MODE_b) {
          /* Disable for Outport: '<S121>/Out' */
          LKAS_B.RelationalOperator_k = false;
          LKAS_DW.SumCondition1_MODE_b = false;
        }
      }

      /* End of Logic: '<S119>/Logical Operator1' */
      /* End of Outputs for SubSystem: '<S119>/Sum Condition1' */

      /* Sum: '<S120>/Add2' incorporates:
       *  Memory: '<S120>/Memory'
       */
      rtb_L0_C2 = rtb_LKA_SampleTime + LKAS_DW.Memory_PreviousInput_aw;

      /* Sum: '<S120>/Add4' */
      rtb_Saturation10 = u0_tmp_tmp + u0_tmp_tmp_0;

      /* Saturate: '<S120>/Saturation1' */
      if (rtb_Saturation10 > 5.5F) {
        rtb_Saturation10 = 5.5F;
      } else {
        if (rtb_Saturation10 < 2.4F) {
          rtb_Saturation10 = 2.4F;
        }
      }

      /* End of Saturate: '<S120>/Saturation1' */

      /* Sum: '<S120>/Add' incorporates:
       *  Constant: '<S120>/Constant4'
       *  Gain: '<S120>/Gain'
       *  Sum: '<S120>/Add5'
       */
      rtb_LL_LKAExPrcs_tiExitTime2 = (0.25F * rtb_Saturation10 - 0.3F) +
        rtb_LKA_Veh2CamW_C;

      /* Outputs for Enabled SubSystem: '<S100>/Subsystem' incorporates:
       *  EnablePort: '<S107>/Enable'
       */
      /* RelationalOperator: '<S106>/Compare' incorporates:
       *  Constant: '<S106>/Constant'
       */
      if (rtb_LL_LKASWASyn_TrqSwaAddSwt > 0.0F) {
        if (!LKAS_DW.Subsystem_MODE_l) {
          LKAS_DW.Subsystem_MODE_l = true;
        }

        /* MATLAB Function: '<S107>/DriverSwaTrqAdd' incorporates:
         *  Switch: '<S612>/Switch42'
         */
        rtb_LL_LKAExPrcs_tiExitTime1 = fmaxf(fminf(u0_tmp_tmp + u0_tmp_tmp_0,
          5.4F), 2.5F);
        if ((rtb_LL_LKAExPrcs_tiExitTime1 > 2.5F) &&
            (rtb_LL_LKAExPrcs_tiExitTime1 < 5.4F)) {
          rtb_LKA_Veh2CamW_C = u0_tmp_tmp / rtb_LL_LKAExPrcs_tiExitTime1;
          rtb_LL_LKAExPrcs_tiExitTime1 = u0_tmp_tmp_0 /
            rtb_LL_LKAExPrcs_tiExitTime1;
        } else {
          rtb_LKA_Veh2CamW_C = 0.5F;
          rtb_LL_LKAExPrcs_tiExitTime1 = 0.5F;
        }

        if (rtb_IMAPve_g_EPS_SW_Trq >= 0.0F) {
          /* Switch: '<S612>/Switch42' incorporates:
           *  Constant: '<S612>/LL_LKASWASyn_TrqMax=1.5'
           */
          if (LKAS_ConstB.DataTypeConversion31_b != 0.0F) {
            rtb_Saturation9 = LKAS_ConstB.DataTypeConversion31_b;
          } else {
            rtb_Saturation9 = LL_LKASWASyn_TrqMax;
          }

          /* Switch: '<S612>/Switch43' incorporates:
           *  Constant: '<S612>/LL_LKASWASyn_SWAaddMax=8'
           */
          if (LKAS_ConstB.DataTypeConversion32_k != 0.0F) {
            rtb_Saturation10 = LKAS_ConstB.DataTypeConversion32_k;
          } else {
            rtb_Saturation10 = LL_LKASWASyn_SWAaddMax;
          }

          rtb_LKA_Veh2CamW_C = (180.0F - fmaxf(fminf(rtb_IMAPve_g_ESC_VehSpd,
            120.0F), 60.0F)) / 120.0F * rtb_Saturation10 * 2.0F *
            rtb_LKA_Veh2CamW_C * (rtb_IMAPve_g_EPS_SW_Trq / rtb_Saturation9);
        } else {
          if (LKAS_ConstB.DataTypeConversion31_b != 0.0F) {
            /* Switch: '<S612>/Switch42' */
            rtb_Saturation9 = LKAS_ConstB.DataTypeConversion31_b;
          } else {
            /* Switch: '<S612>/Switch42' incorporates:
             *  Constant: '<S612>/LL_LKASWASyn_TrqMax=1.5'
             */
            rtb_Saturation9 = LL_LKASWASyn_TrqMax;
          }

          /* Switch: '<S612>/Switch43' incorporates:
           *  Constant: '<S612>/LL_LKASWASyn_SWAaddMax=8'
           */
          if (LKAS_ConstB.DataTypeConversion32_k != 0.0F) {
            rtb_Saturation10 = LKAS_ConstB.DataTypeConversion32_k;
          } else {
            rtb_Saturation10 = LL_LKASWASyn_SWAaddMax;
          }

          rtb_LKA_Veh2CamW_C = (180.0F - fmaxf(fminf(rtb_IMAPve_g_ESC_VehSpd,
            120.0F), 60.0F)) / 120.0F * rtb_Saturation10 * 2.0F *
            rtb_LL_LKAExPrcs_tiExitTime1 * (rtb_IMAPve_g_EPS_SW_Trq /
            rtb_Saturation9);
        }

        /* Sum: '<S110>/Add2' incorporates:
         *  Constant: '<S110>/SWACmdSyn_tiSmplT_C4'
         *  Memory: '<S110>/Memory3'
         */
        LKAS_DW.Memory3_PreviousInput_d += 1.0F;

        /* Saturate: '<S110>/Saturation' */
        if (LKAS_DW.Memory3_PreviousInput_d > 50.0F) {
          /* Sum: '<S110>/Add2' */
          LKAS_DW.Memory3_PreviousInput_d = 50.0F;
        } else {
          if (LKAS_DW.Memory3_PreviousInput_d < 0.0F) {
            /* Sum: '<S110>/Add2' */
            LKAS_DW.Memory3_PreviousInput_d = 0.0F;
          }
        }

        /* End of Saturate: '<S110>/Saturation' */

        /* Switch: '<S110>/Switch' incorporates:
         *  Product: '<S110>/Divide'
         *  Product: '<S110>/Divide1'
         *  Sum: '<S110>/Add'
         *  Sum: '<S110>/Add1'
         *  UnitDelay: '<S110>/Unit Delay'
         */
        if (LKAS_DW.Memory3_PreviousInput_d > 1.0F) {
          /* Switch: '<S612>/Switch50' incorporates:
           *  Constant: '<S612>/LL_LKASWASyn_tiTrqSwaTime=0.3'
           */
          if (LKAS_ConstB.DataTypeConversion50_o != 0.0F) {
            rtb_Saturation9 = LKAS_ConstB.DataTypeConversion50_o;
          } else {
            rtb_Saturation9 = LL_LKASWASyn_tiTrqSwaTime;
          }

          /* End of Switch: '<S612>/Switch50' */
          LKAS_DW.UnitDelay_DSTATE_b += rtb_LKA_SampleTime / rtb_Saturation9 *
            (rtb_LKA_Veh2CamW_C - LKAS_DW.UnitDelay_DSTATE_b);
        } else {
          LKAS_DW.UnitDelay_DSTATE_b = rtb_LKA_Veh2CamW_C;
        }

        /* End of Switch: '<S110>/Switch' */

        /* SampleTimeMath: '<S113>/TSamp' incorporates:
         *  UnitDelay: '<S110>/Unit Delay'
         *
         * About '<S113>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_LKA_Veh2CamW_C = LKAS_DW.UnitDelay_DSTATE_b * 100.0F;

        /* Sum: '<S111>/Add2' incorporates:
         *  Constant: '<S111>/SWACmdSyn_tiSmplT_C4'
         *  Memory: '<S111>/Memory3'
         */
        LKAS_DW.Memory3_PreviousInput_hw += 1.0F;

        /* Saturate: '<S111>/Saturation' */
        if (LKAS_DW.Memory3_PreviousInput_hw > 50.0F) {
          /* Sum: '<S111>/Add2' */
          LKAS_DW.Memory3_PreviousInput_hw = 50.0F;
        } else {
          if (LKAS_DW.Memory3_PreviousInput_hw < 0.0F) {
            /* Sum: '<S111>/Add2' */
            LKAS_DW.Memory3_PreviousInput_hw = 0.0F;
          }
        }

        /* End of Saturate: '<S111>/Saturation' */

        /* Switch: '<S111>/Switch' incorporates:
         *  Product: '<S111>/Divide'
         *  Product: '<S111>/Divide1'
         *  Sum: '<S111>/Add'
         *  Sum: '<S111>/Add1'
         *  Sum: '<S113>/Diff'
         *  UnitDelay: '<S111>/Unit Delay'
         *  UnitDelay: '<S113>/UD'
         *
         * Block description for '<S113>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S113>/UD':
         *
         *  Store in Global RAM
         */
        if (LKAS_DW.Memory3_PreviousInput_hw > 2.0F) {
          /* Switch: '<S612>/Switch52' incorporates:
           *  Constant: '<S612>/LL_LKASWASyn_tiTrqSwaRtTime=0.2'
           */
          if (LKAS_ConstB.DataTypeConversion52_a != 0.0F) {
            rtb_Saturation9 = LKAS_ConstB.DataTypeConversion52_a;
          } else {
            rtb_Saturation9 = LL_LKASWASyn_tiTrqSwaRtTime;
          }

          /* End of Switch: '<S612>/Switch52' */
          LKAS_DW.UnitDelay_DSTATE_m += ((rtb_LKA_Veh2CamW_C -
            LKAS_DW.UD_DSTATE_o) - LKAS_DW.UnitDelay_DSTATE_m) *
            (rtb_LKA_SampleTime / rtb_Saturation9);
        } else {
          LKAS_DW.UnitDelay_DSTATE_m = rtb_LKA_Veh2CamW_C - LKAS_DW.UD_DSTATE_o;
        }

        /* End of Switch: '<S111>/Switch' */

        /* Saturate: '<S107>/Saturation' incorporates:
         *  UnitDelay: '<S111>/Unit Delay'
         */
        if (LKAS_DW.UnitDelay_DSTATE_m > 30.0F) {
          rtb_Saturation9 = 30.0F;
        } else if (LKAS_DW.UnitDelay_DSTATE_m < (-30.0F)) {
          rtb_Saturation9 = (-30.0F);
        } else {
          rtb_Saturation9 = LKAS_DW.UnitDelay_DSTATE_m;
        }

        /* End of Saturate: '<S107>/Saturation' */

        /* Switch: '<S612>/Switch53' incorporates:
         *  Constant: '<S612>/LL_LKASWASyn_TrqSwaRateDiff=-0.2'
         */
        if (LKAS_ConstB.DataTypeConversion53_i != 0.0F) {
          rtb_Saturation10 = LKAS_ConstB.DataTypeConversion53_i;
        } else {
          rtb_Saturation10 = LL_LKASWASyn_TrqSwaRateDiff;
        }

        /* End of Switch: '<S612>/Switch53' */

        /* Sum: '<S112>/Difference Inputs1' incorporates:
         *  Product: '<S107>/Divide1'
         *  Product: '<S107>/Divide3'
         *  Sum: '<S107>/Add'
         *  UnitDelay: '<S110>/Unit Delay'
         *  UnitDelay: '<S112>/Delay Input2'
         *
         * Block description for '<S112>/Difference Inputs1':
         *
         *  Add in CPU
         *
         * Block description for '<S112>/Delay Input2':
         *
         *  Store in Global RAM
         */
        rtb_LL_LKASWASyn_TrqSwaAddSwt = (rtb_LL_LKASWASyn_TrqSwaAddSwt *
          rtb_Saturation9 * rtb_Saturation10 + rtb_LL_LKASWASyn_TrqSwaAddSwt *
          LKAS_DW.UnitDelay_DSTATE_b) - LKAS_DW.DelayInput2_DSTATE_j;

        /* Product: '<S112>/delta rise limit' incorporates:
         *  Constant: '<S107>/Constant1'
         *  SampleTimeMath: '<S112>/sample time'
         *
         * About '<S112>/sample time':
         *  y = K where K = ( w * Ts )
         */
        rtb_LL_LKAExPrcs_tiExitTime1 = 5.0F * 0.01F;

        /* Product: '<S112>/delta fall limit' incorporates:
         *  Constant: '<S107>/Constant2'
         *  SampleTimeMath: '<S112>/sample time'
         *
         * About '<S112>/sample time':
         *  y = K where K = ( w * Ts )
         */
        rtb_LaneWidth = (-5.0F) * 0.01F;

        /* Switch: '<S114>/Switch2' incorporates:
         *  RelationalOperator: '<S114>/LowerRelop1'
         *  RelationalOperator: '<S114>/UpperRelop'
         *  Switch: '<S114>/Switch'
         */
        if (rtb_LL_LKASWASyn_TrqSwaAddSwt > rtb_LL_LKAExPrcs_tiExitTime1) {
          rtb_LL_LKASWASyn_TrqSwaAddSwt = rtb_LL_LKAExPrcs_tiExitTime1;
        } else {
          if (rtb_LL_LKASWASyn_TrqSwaAddSwt < rtb_LaneWidth) {
            /* Switch: '<S114>/Switch' */
            rtb_LL_LKASWASyn_TrqSwaAddSwt = rtb_LaneWidth;
          }
        }

        /* End of Switch: '<S114>/Switch2' */

        /* Sum: '<S112>/Difference Inputs2' incorporates:
         *  UnitDelay: '<S112>/Delay Input2'
         *
         * Block description for '<S112>/Difference Inputs2':
         *
         *  Add in CPU
         *
         * Block description for '<S112>/Delay Input2':
         *
         *  Store in Global RAM
         */
        LKAS_B.DifferenceInputs2_m = rtb_LL_LKASWASyn_TrqSwaAddSwt +
          LKAS_DW.DelayInput2_DSTATE_j;

        /* Update for UnitDelay: '<S113>/UD'
         *
         * Block description for '<S113>/UD':
         *
         *  Store in Global RAM
         */
        LKAS_DW.UD_DSTATE_o = rtb_LKA_Veh2CamW_C;

        /* Update for UnitDelay: '<S112>/Delay Input2'
         *
         * Block description for '<S112>/Delay Input2':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput2_DSTATE_j = LKAS_B.DifferenceInputs2_m;
      } else {
        if (LKAS_DW.Subsystem_MODE_l) {
          /* Disable for Outport: '<S107>/Out1' */
          LKAS_B.DifferenceInputs2_m = 0.0F;
          LKAS_DW.Subsystem_MODE_l = false;
        }
      }

      /* End of RelationalOperator: '<S106>/Compare' */
      /* End of Outputs for SubSystem: '<S100>/Subsystem' */

      /* Outputs for Atomic SubSystem: '<S108>/Moving Standard Deviation2' */
      rtb_Yk1_eq = (float32) LKAS_MovingStandardDeviation2
        (rtb_IMAPve_g_EPS_SW_Trq, &LKAS_DW.MovingStandardDeviation2);

      /* End of Outputs for SubSystem: '<S108>/Moving Standard Deviation2' */

      /* Outputs for Atomic SubSystem: '<S120>/Moving Standard Deviation1' */
      rtb_Gain2_a = (float32) LKAS_MovingStandardDeviation2(rtb_R0_C0,
        &LKAS_DW.MovingStandardDeviation1);

      /* End of Outputs for SubSystem: '<S120>/Moving Standard Deviation1' */

      /* RelationalOperator: '<S120>/Relational Operator6' */
      rtb_RelationalOperator6_f = (rtb_Gain2_a <= rtb_LL_LKAExPrcs_ExitC0Dvt);

      /* Switch: '<S612>/Switch45' incorporates:
       *  Constant: '<S612>/LL_LKAExPrcs_tiExitTime3=0.2'
       */
      if (LKAS_ConstB.DataTypeConversion34_i != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion34_i;
      } else {
        rtb_Saturation9 = LL_LKAExPrcs_tiExitTime3;
      }

      /* End of Switch: '<S612>/Switch45' */

      /* Saturate: '<S120>/Saturation' */
      if (rtb_Abs_tmp > 0.004F) {
        rtb_Abs_tmp = 0.004F;
      } else {
        if (rtb_Abs_tmp < 0.0F) {
          rtb_Abs_tmp = 0.0F;
        }
      }

      /* End of Saturate: '<S120>/Saturation' */

      /* Product: '<S120>/Divide2' incorporates:
       *  Constant: '<S120>/Constant'
       *  Constant: '<S120>/Constant7'
       *  Product: '<S120>/Divide1'
       *  Sum: '<S120>/Add6'
       */
      rtb_Divide2_p = (2.0F * rtb_Abs_tmp / 0.004F + rtb_Saturation9) /
        rtb_LKA_SampleTime;

      /* Outputs for Enabled SubSystem: '<S120>/Sum Condition1' */
      LKAS_SumCondition(rtb_RelationalOperator6_f, rtb_Divide2_p,
                        &LKAS_B.DataTypeConversion, &LKAS_DW.SumCondition1_f);

      /* End of Outputs for SubSystem: '<S120>/Sum Condition1' */

      /* Outputs for Atomic SubSystem: '<S120>/Moving Standard Deviation2' */
      rtb_Gain2_a = (float32) LKAS_MovingStandardDeviation2(rtb_L0_C0,
        &LKAS_DW.MovingStandardDeviation2_e);

      /* End of Outputs for SubSystem: '<S120>/Moving Standard Deviation2' */

      /* RelationalOperator: '<S120>/Relational Operator5' */
      rtb_RelationalOperator5 = (rtb_Gain2_a <= rtb_LL_LKAExPrcs_ExitC0Dvt);

      /* Outputs for Enabled SubSystem: '<S120>/Sum Condition' */
      LKAS_SumCondition(rtb_RelationalOperator5, rtb_Divide2_p,
                        &LKAS_B.DataTypeConversion_i, &LKAS_DW.SumCondition_h);

      /* End of Outputs for SubSystem: '<S120>/Sum Condition' */

      /* Switch: '<S612>/Switch46' incorporates:
       *  Constant: '<S612>/LL_LKAExPrcs_ExitC0Swt=1'
       */
      if (LKAS_ConstB.DataTypeConversion35_e != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion35_e;
      } else {
        rtb_Saturation9 = LL_LKAExPrcs_ExitC0Swt;
      }

      /* End of Switch: '<S612>/Switch46' */

      /* Logic: '<S120>/Logical Operator2' incorporates:
       *  Logic: '<S120>/Logical Operator1'
       *  RelationalOperator: '<S120>/Relational Operator2'
       *  RelationalOperator: '<S120>/Relational Operator3'
       *  RelationalOperator: '<S120>/Relational Operator4'
       */
      rtb_LogicalOperator2_p = ((rtb_L0_C2 >= rtb_Saturation6_h) && (u0_tmp_tmp >=
        rtb_LL_LKAExPrcs_tiExitTime2) && (u0_tmp_tmp_0 >=
        rtb_LL_LKAExPrcs_tiExitTime2) && (LKAS_B.DataTypeConversion != 0) &&
        (LKAS_B.DataTypeConversion_i != 0) && (rtb_Saturation9 != 0.0F));

      /* Fcn: '<S101>/Fcn' incorporates:
       *  DataTypeConversion: '<S101>/Cast To Single'
       */
      rtb_ExNum = (float32)((rtb_LogicalOperator2_p * rtb_LogicalOperator2_p *
        (sint32)3.0F + !rtb_LogicalOperator2_p * LKAS_B.RelationalOperator_k *
        (sint32)2.0F) + ((!LKAS_B.RelationalOperator_k) &&
                         (!rtb_LogicalOperator2_p)) * rtb_LogicalOperator3_o);

      /* Logic: '<S101>/Logical Operator3' */
      LKAS_B.LogicalOperator3 = (rtb_LogicalOperator3_o ||
        LKAS_B.RelationalOperator_k || rtb_LogicalOperator2_p);

      /* Sum: '<S117>/Add2' incorporates:
       *  Memory: '<S117>/Memory3'
       */
      rtb_Saturation10 = rtb_LKA_SampleTime + LKAS_DW.Memory3_PreviousInput_i;

      /* Saturate: '<S117>/Saturation' */
      if (rtb_Saturation10 > 50.0F) {
        rtb_Saturation_d3 = 50.0F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation_d3 = 0.0F;
      } else {
        rtb_Saturation_d3 = rtb_Saturation10;
      }

      /* End of Saturate: '<S117>/Saturation' */

      /* MATLAB Function: '<S108>/MATLAB Function' incorporates:
       *  Constant: '<S612>/LL_LKASWASyn_M2=0.3'
       *  Switch: '<S612>/Switch14'
       */
      if (rtb_Saturation_d3 < rtb_Saturation6_h) {
        rtb_offset += (rtb_LL_LKASWASyn_M1 - rtb_offset) / rtb_Saturation6_h *
          rtb_Saturation_d3;
      } else if ((rtb_Saturation_d3 >= rtb_Saturation6_h) && (rtb_Saturation_d3 <=
                  rtb_Saturation6_h + rtb_LL_LKASWASyn_T2)) {
        /* Switch: '<S612>/Switch14' incorporates:
         *  Constant: '<S612>/LL_LKASWASyn_M2=0.3'
         */
        if (LKAS_ConstB.DataTypeConversion20 != 0.0F) {
          rtb_Saturation9 = LKAS_ConstB.DataTypeConversion20;
        } else {
          rtb_Saturation9 = LL_LKASWASyn_M2;
        }

        rtb_offset = (rtb_Saturation9 - rtb_LL_LKASWASyn_M1) /
          rtb_LL_LKASWASyn_T2 * (rtb_Saturation_d3 - rtb_Saturation6_h) +
          rtb_LL_LKASWASyn_M1;
      } else if (LKAS_ConstB.DataTypeConversion20 != 0.0F) {
        /* Switch: '<S612>/Switch14' */
        rtb_offset = LKAS_ConstB.DataTypeConversion20;
      } else {
        rtb_offset = LL_LKASWASyn_M2;
      }

      /* End of MATLAB Function: '<S108>/MATLAB Function' */

      /* Switch: '<S612>/Switch18' incorporates:
       *  Constant: '<S612>/LL_LKASWASyn_M3K=0.2'
       */
      if (LKAS_ConstB.DataTypeConversion25 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion25;
      } else {
        rtb_Saturation9 = LL_LKASWASyn_M3K;
      }

      /* End of Switch: '<S612>/Switch18' */

      /* Product: '<S108>/Divide' */
      rtb_Saturation10 = rtb_Yk1_eq * rtb_Saturation9;

      /* Saturate: '<S108>/Saturation1' */
      if (rtb_Saturation10 > 0.2F) {
        rtb_Saturation10 = 0.2F;
      } else {
        if (rtb_Saturation10 < 0.0F) {
          rtb_Saturation10 = 0.0F;
        }
      }

      /* End of Saturate: '<S108>/Saturation1' */

      /* Sum: '<S108>/Add1' */
      LKAS_B.Saturation2 = rtb_offset - rtb_Saturation10;

      /* Saturate: '<S108>/Saturation2' */
      if (LKAS_B.Saturation2 > 1.0F) {
        /* Sum: '<S108>/Add1' */
        LKAS_B.Saturation2 = 1.0F;
      } else {
        if (LKAS_B.Saturation2 < 0.0F) {
          /* Sum: '<S108>/Add1' */
          LKAS_B.Saturation2 = 0.0F;
        }
      }

      /* End of Saturate: '<S108>/Saturation2' */

      /* Sum: '<S201>/Add2' incorporates:
       *  Memory: '<S201>/Memory3'
       */
      rtb_Saturation10 = rtb_LKA_SampleTime + LKAS_DW.Memory3_PreviousInput_c;

      /* Saturate: '<S201>/Saturation' */
      if (rtb_Saturation10 > 50.0F) {
        rtb_Saturation_b = 50.0F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation_b = 0.0F;
      } else {
        rtb_Saturation_b = rtb_Saturation10;
      }

      /* End of Saturate: '<S201>/Saturation' */

      /* If: '<S199>/If' incorporates:
       *  DataTypeConversion: '<S91>/Cast To Single'
       *  Inport: '<S207>/Plan'
       *  Inport: '<S207>/T1'
       */
      rtPrevAction = LKAS_DW.If_ActiveSubsystem_j;
      if (LKAS_B.LKASM_stLKAActvFlg == 1) {
        LKAS_DW.If_ActiveSubsystem_j = 0;
      } else if (LKAS_B.LKASM_stLKAActvFlg == 2) {
        LKAS_DW.If_ActiveSubsystem_j = 1;
      } else {
        LKAS_DW.If_ActiveSubsystem_j = 2;
      }

      switch (LKAS_DW.If_ActiveSubsystem_j) {
       case 0:
        if (LKAS_DW.If_ActiveSubsystem_j != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S199>/If Action Subsystem' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          /* InitializeConditions for If: '<S199>/If' incorporates:
           *  Memory: '<S205>/Memory'
           *  UnitDelay: '<S209>/Delay Input1'
           *
           * Block description for '<S209>/Delay Input1':
           *
           *  Store in Global RAM
           */
          LKAS_DW.DelayInput1_DSTATE_jd = false;
          LKAS_DW.Memory_PreviousInput_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S199>/If Action Subsystem' */
        }

        /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem' incorporates:
         *  ActionPort: '<S205>/Action Port'
         */
        /* RelationalOperator: '<S208>/Compare' incorporates:
         *  Constant: '<S208>/Constant'
         */
        rtb_LogicalOperator3_o = (rtb_L0_C1 >= 0.0F);

        /* Logic: '<S205>/Logical Operator' incorporates:
         *  RelationalOperator: '<S205>/Relational Operator'
         *  RelationalOperator: '<S209>/FixPt Relational Operator'
         *  UnitDelay: '<S209>/Delay Input1'
         *
         * Block description for '<S209>/Delay Input1':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput1_DSTATE_jd = (((sint32)rtb_LogicalOperator3_o <
          (sint32)LKAS_DW.DelayInput1_DSTATE_jd) && (rtb_Saturation6_h >=
          rtb_Saturation_b));

        /* Memory: '<S205>/Memory' */
        rtb_Plan_n = LKAS_DW.Memory_PreviousInput_b;

        /* Sum: '<S205>/Add' incorporates:
         *  DataTypeConversion: '<S205>/Cast To Single'
         *  UnitDelay: '<S209>/Delay Input1'
         *
         * Block description for '<S209>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_T1_o = (float32)LKAS_DW.DelayInput1_DSTATE_jd + rtb_Plan_n;

        /* Saturate: '<S205>/Saturation' */
        if (rtb_T1_o > 5.0F) {
          rtb_Saturation_dy = 5.0F;
        } else if (rtb_T1_o < 0.0F) {
          rtb_Saturation_dy = 0.0F;
        } else {
          rtb_Saturation_dy = rtb_T1_o;
        }

        /* End of Saturate: '<S205>/Saturation' */

        /* Outputs for Enabled SubSystem: '<S205>/If Action Subsystem' */
        LKAS_IfActionSubsystem_g(rtb_Saturation_dy, rtb_Saturation_b,
          rtb_SWACmd_phiSWACmd, &LKAS_B.In_o, &LKAS_B.In_n,
          &LKAS_DW.IfActionSubsystem_g);

        /* End of Outputs for SubSystem: '<S205>/If Action Subsystem' */

        /* Outputs for Atomic SubSystem: '<S205>/If Action Subsystem2' */
        LKAS_IfActionSubsystem2_l(rtb_Saturation6_h, rtb_SWACmd_phiSWACmd,
          &rtb_T1_o, &rtb_Plan_n);

        /* End of Outputs for SubSystem: '<S205>/If Action Subsystem2' */

        /* Switch: '<S205>/Switch' incorporates:
         *  Switch: '<S205>/Switch1'
         */
        if (rtb_Saturation_dy > 0.0F) {
          LKAS_B.Merge_p = LKAS_B.In_o;
          LKAS_B.Merge1 = LKAS_B.In_n;
        } else {
          LKAS_B.Merge_p = rtb_T1_o;
          LKAS_B.Merge1 = rtb_Plan_n;
        }

        /* End of Switch: '<S205>/Switch' */

        /* Update for UnitDelay: '<S209>/Delay Input1'
         *
         * Block description for '<S209>/Delay Input1':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput1_DSTATE_jd = rtb_LogicalOperator3_o;

        /* Update for Memory: '<S205>/Memory' */
        LKAS_DW.Memory_PreviousInput_b = rtb_Saturation_dy;

        /* End of Outputs for SubSystem: '<S199>/If Action Subsystem' */
        break;

       case 1:
        if (LKAS_DW.If_ActiveSubsystem_j != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S199>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* InitializeConditions for If: '<S199>/If' incorporates:
           *  Memory: '<S206>/Memory'
           *  UnitDelay: '<S217>/Delay Input1'
           *
           * Block description for '<S217>/Delay Input1':
           *
           *  Store in Global RAM
           */
          LKAS_DW.DelayInput1_DSTATE_n = false;
          LKAS_DW.Memory_PreviousInput_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S199>/If Action Subsystem1' */
        }

        /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S206>/Action Port'
         */
        /* RelationalOperator: '<S216>/Compare' incorporates:
         *  Constant: '<S216>/Constant'
         */
        rtb_LogicalOperator3_o = (rtb_R0_C1 <= 0.0F);

        /* Logic: '<S206>/Logical Operator' incorporates:
         *  RelationalOperator: '<S206>/Relational Operator'
         *  RelationalOperator: '<S217>/FixPt Relational Operator'
         *  UnitDelay: '<S217>/Delay Input1'
         *
         * Block description for '<S217>/Delay Input1':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput1_DSTATE_n = (((sint32)rtb_LogicalOperator3_o <
          (sint32)LKAS_DW.DelayInput1_DSTATE_n) && (rtb_Saturation6_h >=
          rtb_Saturation_b));

        /* Memory: '<S206>/Memory' */
        rtb_Plan = LKAS_DW.Memory_PreviousInput_m;

        /* Sum: '<S206>/Add' incorporates:
         *  DataTypeConversion: '<S206>/Cast To Single'
         *  UnitDelay: '<S217>/Delay Input1'
         *
         * Block description for '<S217>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_T1_f = (float32)LKAS_DW.DelayInput1_DSTATE_n + rtb_Plan;

        /* Saturate: '<S206>/Saturation' */
        if (rtb_T1_f > 5.0F) {
          rtb_Saturation_o = 5.0F;
        } else if (rtb_T1_f < 0.0F) {
          rtb_Saturation_o = 0.0F;
        } else {
          rtb_Saturation_o = rtb_T1_f;
        }

        /* End of Saturate: '<S206>/Saturation' */

        /* Outputs for Enabled SubSystem: '<S206>/If Action Subsystem' */
        LKAS_IfActionSubsystem_g(rtb_Saturation_o, rtb_Saturation_b,
          rtb_SWACmd_phiSWACmd, &LKAS_B.In_i, &LKAS_B.In,
          &LKAS_DW.IfActionSubsystem_ap);

        /* End of Outputs for SubSystem: '<S206>/If Action Subsystem' */

        /* Outputs for Atomic SubSystem: '<S206>/If Action Subsystem2' */
        LKAS_IfActionSubsystem2_l(rtb_Saturation6_h, rtb_SWACmd_phiSWACmd,
          &rtb_T1_f, &rtb_Plan);

        /* End of Outputs for SubSystem: '<S206>/If Action Subsystem2' */

        /* Switch: '<S206>/Switch' incorporates:
         *  Switch: '<S206>/Switch1'
         */
        if (rtb_Saturation_o > 0.0F) {
          LKAS_B.Merge_p = LKAS_B.In_i;
          LKAS_B.Merge1 = LKAS_B.In;
        } else {
          LKAS_B.Merge_p = rtb_T1_f;
          LKAS_B.Merge1 = rtb_Plan;
        }

        /* End of Switch: '<S206>/Switch' */

        /* Update for UnitDelay: '<S217>/Delay Input1'
         *
         * Block description for '<S217>/Delay Input1':
         *
         *  Store in Global RAM
         */
        LKAS_DW.DelayInput1_DSTATE_n = rtb_LogicalOperator3_o;

        /* Update for Memory: '<S206>/Memory' */
        LKAS_DW.Memory_PreviousInput_m = rtb_Saturation_o;

        /* End of Outputs for SubSystem: '<S199>/If Action Subsystem1' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S207>/Action Port'
         */
        LKAS_B.Merge_p = rtb_Saturation6_h;
        LKAS_B.Merge1 = rtb_SWACmd_phiSWACmd;

        /* End of Outputs for SubSystem: '<S199>/If Action Subsystem2' */
        break;
      }

      /* End of If: '<S199>/If' */

      /* Saturate: '<S105>/Saturation6' */
      if (LKAS_B.Merge_p > 0.5F) {
        rtb_LL_LKAExPrcs_tiExitTime2 = 0.5F;
      } else if (LKAS_B.Merge_p < 0.2F) {
        rtb_LL_LKAExPrcs_tiExitTime2 = 0.2F;
      } else {
        rtb_LL_LKAExPrcs_tiExitTime2 = LKAS_B.Merge_p;
      }

      /* End of Saturate: '<S105>/Saturation6' */

      /* Product: '<S105>/Divide' incorporates:
       *  Product: '<S105>/Divide4'
       *  Product: '<S202>/Divide'
       *  Sum: '<S105>/Add2'
       */
      rtb_LL_LKAExPrcs_tiExitTime2 = (rtb_Saturation_b - LKAS_B.Merge_p) /
        rtb_LL_LKAExPrcs_tiExitTime2;

      /* Saturate: '<S105>/Saturation2' incorporates:
       *  Product: '<S105>/Divide'
       */
      if (rtb_LL_LKAExPrcs_tiExitTime2 > 1.0F) {
        rtb_offset = 1.0F;
      } else if (rtb_LL_LKAExPrcs_tiExitTime2 < 0.0F) {
        rtb_offset = 0.0F;
      } else {
        rtb_offset = rtb_LL_LKAExPrcs_tiExitTime2;
      }

      /* End of Saturate: '<S105>/Saturation2' */

      /* Sum: '<S187>/Add1' incorporates:
       *  Gain: '<S183>/Gain'
       *  Memory: '<S187>/Memory'
       *  Product: '<S187>/Divide'
       *  Product: '<S187>/Divide1'
       *  Sum: '<S183>/Add'
       */
      rtb_Add1_f = (rtb_LL_ThresDet_lDvtThresLwrLDW +
                    rtb_LL_ThresDet_lDvtThresUprLDW) * 0.5F *
        LKAS_ConstB.Divide2_f + LKAS_ConstB.Add2_o *
        LKAS_DW.Memory_PreviousInput_av;

      /* MATLAB Function: '<S185>/Saturable Gain Lut (SatGainLut)' incorporates:
       *  Switch: '<S612>/Switch35'
       */
      if (rtb_IMAPve_g_ESC_VehSpd > rtb_LL_LFClb_TFC_vGainLutVehSpd) {
        if (rtb_IMAPve_g_ESC_VehSpd >= rtb_LL_LFClb_TFC_vGainLutVehS_j) {
          /* Switch: '<S612>/Switch35' incorporates:
           *  Constant: '<S612>/LL_LFClb_TFC_facmGainLutGain2_C=40'
           */
          if (LKAS_ConstB.DataTypeConversion17 != 0.0F) {
            rtb_LL_LFClb_TFC_facmGainLutGai = LKAS_ConstB.DataTypeConversion17;
          } else {
            rtb_LL_LFClb_TFC_facmGainLutGai = LL_LFClb_TFC_facmGainLutGain2_C;
          }
        } else {
          if (LKAS_ConstB.DataTypeConversion17 != 0.0F) {
            /* Switch: '<S612>/Switch35' */
            rtb_Saturation9 = LKAS_ConstB.DataTypeConversion17;
          } else {
            /* Switch: '<S612>/Switch35' incorporates:
             *  Constant: '<S612>/LL_LFClb_TFC_facmGainLutGain2_C=40'
             */
            rtb_Saturation9 = LL_LFClb_TFC_facmGainLutGain2_C;
          }

          rtb_LL_LFClb_TFC_facmGainLutGai += (rtb_IMAPve_g_ESC_VehSpd -
            rtb_LL_LFClb_TFC_vGainLutVehSpd) / (rtb_LL_LFClb_TFC_vGainLutVehS_j
            - rtb_LL_LFClb_TFC_vGainLutVehSpd) * (rtb_Saturation9 -
            rtb_LL_LFClb_TFC_facmGainLutGai);
        }
      }

      /* End of MATLAB Function: '<S185>/Saturable Gain Lut (SatGainLut)' */

      /* Switch: '<S612>/Switch32' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_tiKlatPrvwT_C=1'
       */
      if (LKAS_ConstB.DataTypeConversion15 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion15;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_tiKlatPrvwT_C;
      }

      /* End of Switch: '<S612>/Switch32' */

      /* Product: '<S185>/Divide1' */
      rtb_Saturation10 = rtb_Saturation9 * rtb_Abs_h;

      /* Switch: '<S612>/Switch30' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_facmKlat_C=-4.5'
       */
      if (LKAS_ConstB.DataTypeConversion11 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion11;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_facmKlat_C;
      }

      /* End of Switch: '<S612>/Switch30' */

      /* Saturate: '<S185>/Saturation' */
      if (rtb_Saturation10 > 40.0F) {
        rtb_Saturation10 = 40.0F;
      } else {
        if (rtb_Saturation10 < 5.0F) {
          rtb_Saturation10 = 5.0F;
        }
      }

      /* End of Saturate: '<S185>/Saturation' */

      /* Product: '<S185>/Product4' incorporates:
       *  Gain: '<S183>/Gain2'
       *  Product: '<S185>/Divide'
       *  Product: '<S185>/Product1'
       *  Sum: '<S183>/Add1'
       *  Sum: '<S185>/Subtract1'
       */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = ((rtb_L0_C3 + rtb_R0_C3) * 0.5F /
        rtb_Saturation10 * rtb_Saturation9 - rtb_Add1_f) *
        rtb_LL_LFClb_TFC_facmGainLutGai;

      /* Saturate: '<S185>/Saturation2' */
      if (rtb_LL_LFClb_TFC_vGainLutVehSpd > 360.0F) {
        rtb_deltafalllimit_b = 360.0F;
      } else if (rtb_LL_LFClb_TFC_vGainLutVehSpd < (-360.0F)) {
        rtb_deltafalllimit_b = (-360.0F);
      } else {
        rtb_deltafalllimit_b = rtb_LL_LFClb_TFC_vGainLutVehSpd;
      }

      /* End of Saturate: '<S185>/Saturation2' */

      /* Gain: '<S183>/Gain1' incorporates:
       *  Sum: '<S183>/Add2'
       */
      rtb_Yk1_eq = (rtb_Add_hn + rtb_Add_jc) * 0.5F;

      /* Abs: '<S185>/Abs' */
      rtb_Gain2_a = fabsf(rtb_Yk1_eq);

      /* Saturate: '<S185>/Saturation1' */
      rtb_Saturation10 = rtb_Gain2_a;
      if (rtb_Saturation10 > 0.004F) {
        rtb_Gain2_a = 0.004F;
      } else if (rtb_Saturation10 < 1.0E-5F) {
        rtb_Gain2_a = 1.0E-5F;
      } else {
        rtb_Gain2_a = rtb_Saturation10;
      }

      /* End of Saturate: '<S185>/Saturation1' */

      /* Switch: '<S612>/Switch39' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_phiIntegCtlMaxSWA_C=5'
       */
      if (LKAS_ConstB.DataTypeConversion28_l != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion28_l;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_phiIntegCtlMaxSWA_C;
      }

      /* End of Switch: '<S612>/Switch39' */

      /* Sum: '<S185>/Add3' incorporates:
       *  Constant: '<S185>/Constant3'
       *  Constant: '<S185>/Constant4'
       *  Product: '<S185>/Divide4'
       *  Sum: '<S185>/Add5'
       */
      rtb_Gain2_a = (rtb_Saturation9 - 1.0F) * rtb_Gain2_a / 0.004F + 1.0F;

      /* Sum: '<S192>/Add2' incorporates:
       *  Memory: '<S192>/Memory3'
       */
      rtb_Saturation10 = rtb_LKA_SampleTime + LKAS_DW.Memory3_PreviousInput_h;

      /* Saturate: '<S192>/Saturation' */
      if (rtb_Saturation10 > 50.0F) {
        rtb_Saturation_n = 50.0F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation_n = 0.0F;
      } else {
        rtb_Saturation_n = rtb_Saturation10;
      }

      /* End of Saturate: '<S192>/Saturation' */

      /* Switch: '<S185>/Switch2' incorporates:
       *  Product: '<S185>/Divide2'
       *  Sum: '<S185>/Add'
       *  Sum: '<S185>/Add2'
       *  Switch: '<S612>/Switch40'
       *  UnitDelay: '<S185>/Unit Delay'
       */
      if (rtb_Saturation_n - rtb_Saturation6_h >= 0.0F) {
        /* Switch: '<S612>/Switch40' incorporates:
         *  Constant: '<S612>/LL_LFClb_TFC_facmIntegRatio=0.01'
         */
        if (LKAS_ConstB.DataTypeConversion29_b != 0.0F) {
          rtb_Saturation9 = LKAS_ConstB.DataTypeConversion29_b;
        } else {
          rtb_Saturation9 = LL_LFClb_TFC_facmIntegRatio;
        }

        rtb_Switch2_d2 = rtb_LL_LFClb_TFC_vGainLutVehSpd * rtb_Saturation9 +
          LKAS_DW.UnitDelay_DSTATE_g;
      } else {
        if (LKAS_ConstB.DataTypeConversion29_b != 0.0F) {
          /* Switch: '<S612>/Switch40' */
          rtb_Saturation9 = LKAS_ConstB.DataTypeConversion29_b;
        } else {
          /* Switch: '<S612>/Switch40' incorporates:
           *  Constant: '<S612>/LL_LFClb_TFC_facmIntegRatio=0.01'
           */
          rtb_Saturation9 = LL_LFClb_TFC_facmIntegRatio;
        }

        rtb_Switch2_d2 = rtb_LL_LFClb_TFC_vGainLutVehSpd * rtb_Saturation9;
      }

      /* End of Switch: '<S185>/Switch2' */

      /* Gain: '<S185>/Gain' */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = (-1.0F) * rtb_Gain2_a;

      /* Switch: '<S189>/Switch' incorporates:
       *  RelationalOperator: '<S189>/UpperRelop'
       */
      if (rtb_Switch2_d2 < rtb_LL_LFClb_TFC_vGainLutVehSpd) {
        rtb_Switch_b = rtb_LL_LFClb_TFC_vGainLutVehSpd;
      } else {
        rtb_Switch_b = rtb_Switch2_d2;
      }

      /* End of Switch: '<S189>/Switch' */

      /* Switch: '<S189>/Switch2' incorporates:
       *  RelationalOperator: '<S189>/LowerRelop1'
       *  UnitDelay: '<S185>/Unit Delay'
       */
      if (rtb_Switch2_d2 > rtb_Gain2_a) {
        LKAS_DW.UnitDelay_DSTATE_g = rtb_Gain2_a;
      } else {
        LKAS_DW.UnitDelay_DSTATE_g = rtb_Switch_b;
      }

      /* End of Switch: '<S189>/Switch2' */

      /* Product: '<S105>/Divide1' incorporates:
       *  Sum: '<S105>/Add3'
       *  UnitDelay: '<S185>/Unit Delay'
       */
      rtb_LL_LFClb_TFC_vGainLutVehS_j = (rtb_deltafalllimit_b +
        LKAS_DW.UnitDelay_DSTATE_g) * rtb_offset;

      /* Switch: '<S612>/Switch49' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_DiffCtrlMaxSWA=20'
       */
      if (LKAS_ConstB.DataTypeConversion49_c != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion49_c;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_DiffCtrlMaxSWA;
      }

      /* End of Switch: '<S612>/Switch49' */

      /* Product: '<S185>/Divide8' incorporates:
       *  Constant: '<S185>/Constant7'
       *  Constant: '<S185>/Constant8'
       *  Sum: '<S185>/Add4'
       */
      rtb_Gain2_a = (180.0F - rtb_Abs_h) * rtb_Saturation9 / 120.0F;

      /* Sum: '<S191>/Add2' */
      rtb_deltafalllimit_b = rtb_L0_C0 + rtb_R0_C0;

      /* Saturate: '<S191>/Saturation' */
      if (rtb_deltafalllimit_b > 2.0F) {
        rtb_deltafalllimit_b = 2.0F;
      } else {
        if (rtb_deltafalllimit_b < (-2.0F)) {
          rtb_deltafalllimit_b = (-2.0F);
        }
      }

      /* End of Saturate: '<S191>/Saturation' */

      /* Switch: '<S612>/Switch9' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_DiffCtlBalance=1.2'
       */
      if (LKAS_ConstB.DataTypeConversion9 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion9;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_DiffCtlBalance;
      }

      /* End of Switch: '<S612>/Switch9' */

      /* Sum: '<S191>/Add6' */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = rtb_Saturation_k - rtb_Saturation9;

      /* Product: '<S191>/Divide5' incorporates:
       *  Constant: '<S191>/Constant3'
       *  Product: '<S191>/Divide4'
       *  Sum: '<S191>/Add5'
       */
      rtb_Divide5 = (rtb_deltafalllimit_b / rtb_LL_LFClb_TFC_vGainLutVehSpd +
                     1.0F) * rtb_LL_LFClb_TFC_DiffCtrlRatio;

      /* Product: '<S191>/Divide2' incorporates:
       *  Constant: '<S191>/Constant2'
       *  Product: '<S191>/Divide1'
       *  Sum: '<S191>/Add1'
       *  UnaryMinus: '<S191>/Unary Minus'
       */
      rtb_Divide2_d = (-rtb_deltafalllimit_b / rtb_LL_LFClb_TFC_vGainLutVehSpd +
                       1.0F) * rtb_LL_LFClb_TFC_DiffCtrlRatio;

      /* Sum: '<S196>/Add' incorporates:
       *  Constant: '<S196>/Constant'
       *  Memory: '<S196>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_e4);

      /* Saturate: '<S196>/Saturation1' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation1_m = rtb_Add1_hb;
      } else {
        rtb_Saturation1_m = ((uint16)10000U);
      }

      /* End of Saturate: '<S196>/Saturation1' */

      /* If: '<S196>/If' incorporates:
       *  Constant: '<S196>/Constant2'
       *  DataTypeConversion: '<S91>/Cast To Single'
       *  Inport: '<S197>/In'
       */
      if (rtb_Saturation1_m == ((uint16)1U)) {
        /* Outputs for IfAction SubSystem: '<S196>/if action ' incorporates:
         *  ActionPort: '<S197>/Action Port'
         */
        LKAS_B.In_al = LKAS_B.LKASM_stLKAActvFlg;

        /* End of Outputs for SubSystem: '<S196>/if action ' */
      }

      /* End of If: '<S196>/If' */

      /* If: '<S191>/If' */
      if (LKAS_B.In_al == 1) {
        /* Outputs for IfAction SubSystem: '<S191>/If Action Subsystem' incorporates:
         *  ActionPort: '<S193>/Action Port'
         */
        LKAS_IfActionSubsystem_j(rtb_Divide2_d, &rtb_deltafalllimit_b);

        /* End of Outputs for SubSystem: '<S191>/If Action Subsystem' */
      } else if (LKAS_B.In_al == 2) {
        /* Outputs for IfAction SubSystem: '<S191>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S194>/Action Port'
         */
        LKAS_IfActionSubsystem_j(rtb_Divide5, &rtb_deltafalllimit_b);

        /* End of Outputs for SubSystem: '<S191>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S191>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S195>/Action Port'
         */
        LKAS_IfActionSubsystem_j(rtb_LL_LFClb_TFC_DiffCtrlRatio,
          &rtb_deltafalllimit_b);

        /* End of Outputs for SubSystem: '<S191>/If Action Subsystem2' */
      }

      /* End of If: '<S191>/If' */

      /* Saturate: '<S191>/Saturation1' */
      if (rtb_deltafalllimit_b > 1000.0F) {
        rtb_deltafalllimit_b = 1000.0F;
      } else {
        if (rtb_deltafalllimit_b < 0.0F) {
          rtb_deltafalllimit_b = 0.0F;
        }
      }

      /* End of Saturate: '<S191>/Saturation1' */

      /* Product: '<S185>/Divide7' incorporates:
       *  Gain: '<S185>/Gain2'
       */
      rtb_Divide7 = rtb_LL_LDW_LatestWarnLine_C * (-0.5F) * rtb_deltafalllimit_b;

      /* Gain: '<S185>/Gain3' */
      rtb_deltafalllimit_b = (-1.0F) * rtb_Gain2_a;

      /* Switch: '<S190>/Switch' incorporates:
       *  RelationalOperator: '<S190>/UpperRelop'
       */
      if (rtb_Divide7 < rtb_deltafalllimit_b) {
        rtb_Switch_f = rtb_deltafalllimit_b;
      } else {
        rtb_Switch_f = rtb_Divide7;
      }

      /* End of Switch: '<S190>/Switch' */

      /* Switch: '<S190>/Switch2' incorporates:
       *  RelationalOperator: '<S190>/LowerRelop1'
       */
      if (rtb_Divide7 > rtb_Gain2_a) {
        rtb_Switch2_m5 = rtb_Gain2_a;
      } else {
        rtb_Switch2_m5 = rtb_Switch_f;
      }

      /* End of Switch: '<S190>/Switch2' */

      /* Product: '<S105>/Divide4' */
      rtb_Gain2_a = rtb_LL_LKAExPrcs_tiExitTime2;

      /* Saturate: '<S105>/Saturation1' */
      rtb_Saturation10 = rtb_Gain2_a;
      if (rtb_Saturation10 > 1.0F) {
        rtb_Gain2_a = 1.0F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Gain2_a = 0.0F;
      } else {
        rtb_Gain2_a = rtb_Saturation10;
      }

      /* End of Saturate: '<S105>/Saturation1' */

      /* Product: '<S105>/Divide2' */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = rtb_Switch2_m5 * rtb_Gain2_a;

      /* Gain: '<S186>/kph to mps' */
      rtb_Gain2_a = rtb_Abs_h;

      /* Product: '<S186>/Product' */
      rtb_LL_LFClb_TFC_facmGainLutGai = rtb_Gain2_a * rtb_Yk1_eq;

      /* Lookup_n-D: '<S186>/Lookup Table2' */
      rtb_Yk1_eq = look1_iflf_pbinlgpw(rtb_IMAPve_g_ESC_VehSpd,
        LKAS_ConstP.pooled16, LKAS_ConstP.pooled15, &LKAS_DW.m_bpIndex_c, 7U);

      /* Saturate: '<S186>/Saturation1' */
      rtb_Saturation10 = rtb_Yk1_eq;
      if (rtb_Saturation10 > 0.01F) {
        rtb_Yk1_eq = 0.01F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Yk1_eq = 0.0F;
      } else {
        rtb_Yk1_eq = rtb_Saturation10;
      }

      /* End of Saturate: '<S186>/Saturation1' */

      /* Switch: '<S612>/Switch36' incorporates:
       *  Constant: '<S612>/LL_LFClb_TFC_FfCtlRatio_C=1'
       */
      if (LKAS_ConstB.DataTypeConversion18 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion18;
      } else {
        rtb_Saturation9 = LL_LFClb_TFC_FfCtlRatio_C;
      }

      /* End of Switch: '<S612>/Switch36' */

      /* Gain: '<S186>/Gain2' incorporates:
       *  Constant: '<S186>/Constant1'
       *  Gain: '<S186>/rad to deg'
       *  Math: '<S186>/Math Function'
       *  Product: '<S186>/Divide'
       *  Product: '<S186>/Divide1'
       *  Product: '<S186>/Product1'
       *  Product: '<S186>/Product2'
       *  Product: '<S186>/Product3'
       *  Sum: '<S186>/Add'
       *
       * About '<S186>/Math Function':
       *  Operator: magnitude^2
       */
      rtb_Gain2_a = (rtb_Gain2_a * rtb_Gain2_a * rtb_Yk1_eq + 1.0F) /
        (rtb_Gain2_a / LKAS_B.LKA_WhlBaseL_C_n) * (57.2957802F *
        rtb_LL_LFClb_TFC_facmGainLutGai) * rtb_Saturation9 *
        LKAS_B.LKA_StrRatio_C_h * (-1.0F);

      /* Saturate: '<S202>/Saturation4' */
      if (rtb_LL_LKAExPrcs_tiExitTime2 > 1.0F) {
        rtb_LL_LKAExPrcs_tiExitTime2 = 1.0F;
      } else {
        if (rtb_LL_LKAExPrcs_tiExitTime2 < 0.0F) {
          rtb_LL_LKAExPrcs_tiExitTime2 = 0.0F;
        }
      }

      /* End of Saturate: '<S202>/Saturation4' */

      /* Product: '<S105>/Divide5' incorporates:
       *  Constant: '<S202>/Constant1'
       *  Product: '<S202>/Divide8'
       *  Sum: '<S202>/Add1'
       */
      rtb_Yk1_eq = (LKAS_ConstB.Add3 * rtb_LL_LKAExPrcs_tiExitTime2 + 0.0F) *
        rtb_Gain2_a;

      /* Saturate: '<S105>/Saturation3' */
      if (rtb_Merge_k > 0.004F) {
        rtb_deltafalllimit_b = 0.004F;
      } else if (rtb_Merge_k < (-0.004F)) {
        rtb_deltafalllimit_b = (-0.004F);
      } else {
        rtb_deltafalllimit_b = rtb_Merge_k;
      }

      /* End of Saturate: '<S105>/Saturation3' */

      /* Product: '<S105>/Divide3' */
      rtb_Saturation10 = rtb_Saturation_b / LKAS_B.Merge_p;

      /* Saturate: '<S105>/Saturation' */
      if (rtb_Saturation10 > 1.0F) {
        rtb_Saturation10 = 1.0F;
      } else {
        if (rtb_Saturation10 < 0.0F) {
          rtb_Saturation10 = 0.0F;
        }
      }

      /* End of Saturate: '<S105>/Saturation' */

      /* Sum: '<S105>/Add4' incorporates:
       *  Constant: '<S105>/Constant2'
       *  Product: '<S105>/Divide6'
       *  Product: '<S105>/Divide7'
       *  Sum: '<S105>/Add5'
       */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = ((((1.0F - rtb_offset) * LKAS_B.Merge1 +
        rtb_LL_LFClb_TFC_vGainLutVehS_j) + rtb_LL_LFClb_TFC_vGainLutVehSpd) +
        rtb_Yk1_eq) + LKAS_B.DifferenceInputs2_m * rtb_Saturation10;

      /* Memory: '<S200>/Memory3' */
      rtb_Yk1_eq = LKAS_DW.Memory3_PreviousInput_j;

      /* Sum: '<S200>/Add2' incorporates:
       *  Constant: '<S200>/SWACmdSyn_tiSmplT_C4'
       */
      rtb_Yk1_eq += 1.0F;

      /* Saturate: '<S200>/Saturation' */
      rtb_Saturation10 = rtb_Yk1_eq;
      if (rtb_Saturation10 > 50.0F) {
        rtb_Saturation_ge = 50.0F;
      } else if (rtb_Saturation10 < 0.0F) {
        rtb_Saturation_ge = 0.0F;
      } else {
        rtb_Saturation_ge = rtb_Saturation10;
      }

      /* End of Saturate: '<S200>/Saturation' */

      /* Switch: '<S200>/Switch' incorporates:
       *  Constant: '<S105>/Constant1'
       *  Product: '<S200>/Divide'
       *  Product: '<S200>/Divide1'
       *  Sum: '<S200>/Add'
       *  Sum: '<S200>/Add1'
       *  UnitDelay: '<S200>/Unit Delay'
       */
      if (rtb_Saturation_ge > 30.0F) {
        LKAS_DW.UnitDelay_DSTATE_h += rtb_LKA_SampleTime / 0.1F *
          (rtb_LL_LFClb_TFC_vGainLutVehSpd - LKAS_DW.UnitDelay_DSTATE_h);
      } else {
        LKAS_DW.UnitDelay_DSTATE_h = rtb_LL_LFClb_TFC_vGainLutVehSpd;
      }

      /* End of Switch: '<S200>/Switch' */

      /* Switch: '<S612>/Switch17' incorporates:
       *  Constant: '<S612>/LL_CompSWA_C=0'
       */
      if (LKAS_ConstB.DataTypeConversion2_j != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion2_j;
      } else {
        rtb_Saturation9 = LL_CompSWA_C;
      }

      /* End of Switch: '<S612>/Switch17' */

      /* Sum: '<S103>/Add' incorporates:
       *  UnitDelay: '<S200>/Unit Delay'
       */
      rtb_Add_mq = (LKAS_DW.UnitDelay_DSTATE_h - rtb_Saturation9) +
        LKAS_B.Saturation;

      /* Sum: '<S103>/Add1' */
      rtb_Yk1_eq = rtb_Gain2_a + rtb_LL_TkOvStChk_tiTDelTime;

      /* Sum: '<S103>/Add2' incorporates:
       *  Gain: '<S103>/Gain2'
       */
      rtb_deltafalllimit_b = (-1.0F) * rtb_LL_TkOvStChk_tiTDelTime + rtb_Gain2_a;

      /* Switch: '<S181>/Switch' incorporates:
       *  RelationalOperator: '<S181>/UpperRelop'
       */
      if (rtb_Add_mq < rtb_deltafalllimit_b) {
        rtb_Switch_gc = rtb_deltafalllimit_b;
      } else {
        rtb_Switch_gc = rtb_Add_mq;
      }

      /* End of Switch: '<S181>/Switch' */

      /* Switch: '<S181>/Switch2' incorporates:
       *  RelationalOperator: '<S181>/LowerRelop1'
       */
      if (rtb_Add_mq > rtb_Yk1_eq) {
        rtb_Switch2_b = rtb_Yk1_eq;
      } else {
        rtb_Switch2_b = rtb_Switch_gc;
      }

      /* End of Switch: '<S181>/Switch2' */

      /* Sum: '<S180>/Add1' incorporates:
       *  Constant: '<S180>/Constant'
       *  Memory: '<S180>/Memory'
       */
      rtb_Add1_hb = (uint16)((uint32)((uint16)1U) +
        LKAS_DW.Memory_PreviousInput_bh);

      /* Switch: '<S180>/Switch' incorporates:
       *  Constant: '<S180>/LatchTime_SY'
       *  RelationalOperator: '<S180>/Relational Operator'
       *  UnitDelay: '<S180>/Delay Input2'
       *
       * Block description for '<S180>/Delay Input2':
       *
       *  Store in Global RAM
       */
      if (rtb_Add1_hb <= ((uint16)1U)) {
        rtb_Yk1_eq = rtb_Switch2_b;
      } else {
        rtb_Yk1_eq = LKAS_DW.DelayInput2_DSTATE;
      }

      /* End of Switch: '<S180>/Switch' */

      /* Sum: '<S180>/Difference Inputs1'
       *
       * Block description for '<S180>/Difference Inputs1':
       *
       *  Add in CPU
       */
      rtb_UkYk1 = rtb_Switch2_b - rtb_Yk1_eq;

      /* SampleTimeMath: '<S180>/sample time'
       *
       * About '<S180>/sample time':
       *  y = K where K = ( w * Ts )
       */
      rtb_deltafalllimit_b = 0.01F;

      /* Product: '<S180>/delta rise limit' incorporates:
       *  Gain: '<S103>/Gain3'
       */
      rtb_LL_LFClb_TFC_vGainLutVehSpd = 1.4F * LKAS_B.SWARmax *
        rtb_deltafalllimit_b;

      /* Product: '<S180>/delta fall limit' incorporates:
       *  Gain: '<S103>/Gain1'
       */
      rtb_deltafalllimit_b *= (-1.4F) * LKAS_B.SWARmax;

      /* Switch: '<S182>/Switch' incorporates:
       *  RelationalOperator: '<S182>/UpperRelop'
       */
      if (rtb_UkYk1 < rtb_deltafalllimit_b) {
        rtb_Switch_dl = rtb_deltafalllimit_b;
      } else {
        rtb_Switch_dl = rtb_UkYk1;
      }

      /* End of Switch: '<S182>/Switch' */

      /* Switch: '<S182>/Switch2' incorporates:
       *  RelationalOperator: '<S182>/LowerRelop1'
       */
      if (rtb_UkYk1 > rtb_LL_LFClb_TFC_vGainLutVehSpd) {
        rtb_Switch2_lq = rtb_LL_LFClb_TFC_vGainLutVehSpd;
      } else {
        rtb_Switch2_lq = rtb_Switch_dl;
      }

      /* End of Switch: '<S182>/Switch2' */

      /* Sum: '<S180>/Difference Inputs2'
       *
       * Block description for '<S180>/Difference Inputs2':
       *
       *  Add in CPU
       */
      LKAS_B.DifferenceInputs2 = rtb_Switch2_lq + rtb_Yk1_eq;

      /* Saturate: '<S180>/Saturation2' */
      if (rtb_Add1_hb < ((uint16)10000U)) {
        rtb_Saturation2_m = rtb_Add1_hb;
      } else {
        rtb_Saturation2_m = ((uint16)10000U);
      }

      /* End of Saturate: '<S180>/Saturation2' */

      /* MATLAB Function: '<S127>/MATLAB Function' incorporates:
       *  DataTypeConversion: '<S91>/Cast To Single'
       */
      switch (LKAS_B.LKASM_stLKAActvFlg) {
       case 1:
        /* Saturate: '<S127>/Saturation' */
        rtb_Saturation10 = rtb_Gain2_a;
        if (rtb_Saturation10 > 20.0F) {
          rtb_Saturation10 = 20.0F;
        } else {
          if (rtb_Saturation10 < (-20.0F)) {
            rtb_Saturation10 = (-20.0F);
          }
        }

        rtb_phiSWA0 = fminf(rtb_IMAPve_g_SW_Angle, rtb_Saturation10);
        break;

       case 2:
        /* Saturate: '<S127>/Saturation' */
        rtb_Saturation10 = rtb_Gain2_a;
        if (rtb_Saturation10 > 20.0F) {
          rtb_Saturation10 = 20.0F;
        } else {
          if (rtb_Saturation10 < (-20.0F)) {
            rtb_Saturation10 = (-20.0F);
          }
        }

        rtb_phiSWA0 = fmaxf(rtb_IMAPve_g_SW_Angle, rtb_Saturation10);
        break;

       default:
        rtb_phiSWA0 = rtb_IMAPve_g_SW_Angle;
        break;
      }

      /* End of MATLAB Function: '<S127>/MATLAB Function' */

      /* Saturate: '<S120>/Saturation2' */
      if (rtb_L0_C2 > 10.0F) {
        rtb_Saturation2 = 10.0F;
      } else if (rtb_L0_C2 < 0.0F) {
        rtb_Saturation2 = 0.0F;
      } else {
        rtb_Saturation2 = rtb_L0_C2;
      }

      /* End of Saturate: '<S120>/Saturation2' */

      /* Saturate: '<S119>/Saturation2' */
      if (rtb_Add2_p > 10.0F) {
        rtb_Saturation2_g = 10.0F;
      } else if (rtb_Add2_p < 0.0F) {
        rtb_Saturation2_g = 0.0F;
      } else {
        rtb_Saturation2_g = rtb_Add2_p;
      }

      /* End of Saturate: '<S119>/Saturation2' */

      /* Saturate: '<S118>/Saturation2' */
      if (rtb_R0_C2 > 10.0F) {
        rtb_Saturation2_a = 10.0F;
      } else if (rtb_R0_C2 < 0.0F) {
        rtb_Saturation2_a = 0.0F;
      } else {
        rtb_Saturation2_a = rtb_R0_C2;
      }

      /* End of Saturate: '<S118>/Saturation2' */

      /* DataTypeConversion: '<S127>/Cast To Single1' */
      rtb_MPInP_vVehSpd = rtb_IMAPve_g_ESC_VehSpd;
    } else {
      if (LKAS_DW.LKA_MODE) {
        /* Disable for If: '<S102>/If' */
        LKAS_DW.If_ActiveSubsystem = -1;

        /* Disable for Enabled SubSystem: '<S119>/Sum Condition1' */
        if (LKAS_DW.SumCondition1_MODE_b) {
          /* Disable for Outport: '<S121>/Out' */
          LKAS_B.RelationalOperator_k = false;
          LKAS_DW.SumCondition1_MODE_b = false;
        }

        /* End of Disable for SubSystem: '<S119>/Sum Condition1' */

        /* Disable for Enabled SubSystem: '<S100>/Subsystem' */
        if (LKAS_DW.Subsystem_MODE_l) {
          /* Disable for Outport: '<S107>/Out1' */
          LKAS_B.DifferenceInputs2_m = 0.0F;
          LKAS_DW.Subsystem_MODE_l = false;
        }

        /* End of Disable for SubSystem: '<S100>/Subsystem' */

        /* Disable for Enabled SubSystem: '<S120>/Sum Condition1' */
        if (LKAS_DW.SumCondition1_f.SumCondition_MODE) {
          LKAS_SumCondition_Disable(&LKAS_B.DataTypeConversion,
            &LKAS_DW.SumCondition1_f);
        }

        /* End of Disable for SubSystem: '<S120>/Sum Condition1' */

        /* Disable for Enabled SubSystem: '<S120>/Sum Condition' */
        if (LKAS_DW.SumCondition_h.SumCondition_MODE) {
          LKAS_SumCondition_Disable(&LKAS_B.DataTypeConversion_i,
            &LKAS_DW.SumCondition_h);
        }

        /* End of Disable for SubSystem: '<S120>/Sum Condition' */

        /* Disable for If: '<S199>/If' */
        LKAS_DW.If_ActiveSubsystem_j = -1;

        /* Disable for Outport: '<S91>/LKA_ExitFlg' */
        LKAS_B.LogicalOperator3 = false;

        /* Disable for Outport: '<S91>/LKA_phiSWACmd' */
        LKAS_B.DifferenceInputs2 = 0.0F;

        /* Disable for Sum: '<S108>/Add1' incorporates:
         *  Outport: '<S91>/LKA_M'
         */
        LKAS_B.Saturation2 = 0.0F;
        LKAS_DW.LKA_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S10>/LKA' */

    /* SignalConversion: '<S10>/OutportBufferForM' */
    LKAS_B.OutputM = LKAS_B.Saturation2;

    /* SignalConversion: '<S10>/OutportBufferForphiSWACmd' */
    LKAS_B.OutputSWACmd = LKAS_B.DifferenceInputs2;

    /* SignalConversion: '<S10>/BusConversion_InsertedFor_bsLLState_at_inport_0' */
    LKAS_B.LKA_State = LKAS_B.LKASM_stLKAState;

    /* SignalConversion: '<S10>/BusConversion_InsertedFor_bsLLState_at_inport_0' */
    LKAS_B.LDW_State = LKAS_B.LDWSM_stLDWState;

    /* Outputs for Enabled SubSystem: '<S10>/LDW' incorporates:
     *  EnablePort: '<S90>/states'
     *
     * Block description for '<S10>/LDW':
     *  Block Name: Lane Departure Warning
     *  Ab.: LDW
     *  No.: 1.3.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-3-26
     */
    if (LKAS_B.LDWSM_stLDWActvFlg > 0) {
      if (!LKAS_DW.LDW_MODE) {
        LKAS_DW.LDW_MODE = true;
      }

      /* If: '<S94>/If' */
      if (LKAS_B.LDWSM_stLDWActvFlg == 1) {
        /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem' incorporates:
         *  ActionPort: '<S96>/Action Port'
         */
        /* Gain: '<S96>/rad to deg' incorporates:
         *  Gain: '<S96>/Gain'
         */
        LKAS_B.Merge_j = (-1.0F) * rtb_L0_C1 * 57.2957802F;

        /* End of Outputs for SubSystem: '<S94>/If Action Subsystem' */
      } else if (LKAS_B.LDWSM_stLDWActvFlg == 2) {
        /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S97>/Action Port'
         */
        /* Gain: '<S97>/rad to deg' */
        LKAS_B.Merge_j = 57.2957802F * rtb_R0_C1;

        /* End of Outputs for SubSystem: '<S94>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S98>/Action Port'
         */
        LKAS_IfActionSubsystem2(&LKAS_B.Merge_j);

        /* End of Outputs for SubSystem: '<S94>/If Action Subsystem2' */
      }

      /* End of If: '<S94>/If' */

      /* Switch: '<S611>/Switch2' incorporates:
       *  Constant: '<S611>/LL_LDWS_SUPPRESS_HEADING=2'
       */
      if (LKAS_ConstB.DataTypeConversion6 != 0.0F) {
        rtb_Saturation9 = LKAS_ConstB.DataTypeConversion6;
      } else {
        rtb_Saturation9 = LL_LDWS_SUPPRESS_HEADING;
      }

      /* End of Switch: '<S611>/Switch2' */

      /* Outputs for Enabled SubSystem: '<S94>/Sum Condition' incorporates:
       *  EnablePort: '<S99>/state = reset'
       */
      /* RelationalOperator: '<S94>/Relational Operator' */
      if (LKAS_B.Merge_j >= rtb_Saturation9) {
        if (!LKAS_DW.SumCondition_MODE) {
          /* InitializeConditions for Memory: '<S99>/Memory' */
          LKAS_DW.Memory_PreviousInput_e = 0.0F;
          LKAS_DW.SumCondition_MODE = true;
        }

        /* Saturate: '<S99>/Saturation' incorporates:
         *  Memory: '<S99>/Memory'
         *  Sum: '<S99>/Add1'
         */
        if (1.0F + LKAS_DW.Memory_PreviousInput_e > 600.0F) {
          LKAS_DW.Memory_PreviousInput_e = 600.0F;
        } else if (1.0F + LKAS_DW.Memory_PreviousInput_e < 0.0F) {
          LKAS_DW.Memory_PreviousInput_e = 0.0F;
        } else {
          LKAS_DW.Memory_PreviousInput_e++;
        }

        /* End of Saturate: '<S99>/Saturation' */

        /* DataTypeConversion: '<S99>/Data Type Conversion' incorporates:
         *  Constant: '<S94>/Constant'
         *  RelationalOperator: '<S99>/Relational Operator'
         */
        LKAS_B.DataTypeConversion_i2 = (uint8)(LKAS_DW.Memory_PreviousInput_e >=
          5.0F);
      } else {
        if (LKAS_DW.SumCondition_MODE) {
          /* Disable for Outport: '<S99>/Out' */
          LKAS_B.DataTypeConversion_i2 = ((uint8)0U);
          LKAS_DW.SumCondition_MODE = false;
        }
      }

      /* End of RelationalOperator: '<S94>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S94>/Sum Condition' */

      /* MATLAB Function: '<S90>/LDWWarnInfo' */
      if ((LKAS_B.LDWSM_stLDWActvFlg == 1) && (LKAS_B.DataTypeConversion_i2 == 0))
      {
        LKAS_B.LDWWarnInfo = 1U;
      } else if ((LKAS_B.LDWSM_stLDWActvFlg == 2) &&
                 (LKAS_B.DataTypeConversion_i2 == 0)) {
        LKAS_B.LDWWarnInfo = 2U;
      } else {
        LKAS_B.LDWWarnInfo = 0U;
      }

      /* End of MATLAB Function: '<S90>/LDWWarnInfo' */
    } else {
      if (LKAS_DW.LDW_MODE) {
        /* Disable for Enabled SubSystem: '<S94>/Sum Condition' */
        if (LKAS_DW.SumCondition_MODE) {
          /* Disable for Outport: '<S99>/Out' */
          LKAS_B.DataTypeConversion_i2 = ((uint8)0U);
          LKAS_DW.SumCondition_MODE = false;
        }

        /* End of Disable for SubSystem: '<S94>/Sum Condition' */

        /* Disable for Outport: '<S90>/LDW_Flag' */
        LKAS_B.LDWWarnInfo = ((uint8)0U);
        LKAS_DW.LDW_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S10>/LDW' */

    /* Logic: '<S523>/Logical Operator1' incorporates:
     *  RelationalOperator: '<S523>/Relational Operator3'
     *  RelationalOperator: '<S523>/Relational Operator4'
     */
    rtb_LogicalOperator1_b = ((rtb_Gain1 <= rtb_LL_LKA_LatestWarnLine_C) ||
      (rtb_Add5_j <= rtb_LL_LKA_LatestWarnLine_C));

    /* SignalConversion: '<S10>/BusConversion_InsertedFor_bsLLState_at_inport_0' */
    LKAS_B.DACMode = LKAS_B.IMAPve_d_LKA_Mode;

    /* Delay: '<S93>/Delay1' */
    rtb_DACMode = LKAS_DW.Delay1_2_DSTATE;

    /* RelationalOperator: '<S558>/Compare' incorporates:
     *  Constant: '<S558>/Constant'
     *  Constant: '<S620>/Constant9'
     */
    rtb_Compare_mq = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S561>/Compare' incorporates:
     *  Constant: '<S561>/Constant'
     *  Constant: '<S620>/Constant12'
     */
    rtb_Compare_ox = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S563>/Compare' incorporates:
     *  Constant: '<S563>/Constant'
     *  Constant: '<S620>/Constant13'
     */
    rtb_Compare_hlr = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S564>/Compare' incorporates:
     *  Constant: '<S564>/Constant'
     *  Constant: '<S620>/Constant14'
     */
    rtb_Compare_ny = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S565>/Compare' incorporates:
     *  Constant: '<S565>/Constant'
     *  Constant: '<S620>/Constant15'
     */
    rtb_Compare_b0 = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S566>/Compare' incorporates:
     *  Constant: '<S566>/Constant'
     *  Constant: '<S620>/Constant16'
     */
    rtb_Compare_dg = (((uint8)0U) == ((uint8)1U));

    /* RelationalOperator: '<S572>/Compare' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S572>/Constant'
     *  RelationalOperator: '<S36>/Compare'
     */
    rtb_Compare_dk = ((0.0F == 1.0F) == (sint32)true);

    /* RelationalOperator: '<S573>/Compare' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S573>/Constant'
     *  RelationalOperator: '<S37>/Compare'
     */
    rtb_Compare_hv = ((0.0F == 1.0F) == (sint32)true);

    /* RelationalOperator: '<S575>/Compare' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S575>/Constant'
     *  RelationalOperator: '<S14>/Compare'
     */
    rtb_Compare_k5 = ((0.0F == 3.0F) == (sint32)true);

    /* RelationalOperator: '<S576>/Compare' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S576>/Constant'
     *  RelationalOperator: '<S15>/Compare'
     */
    rtb_Compare_l4 = ((0.0F == 3.0F) == (sint32)true);

    /* RelationalOperator: '<S577>/Compare' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S577>/Constant'
     *  RelationalOperator: '<S16>/Compare'
     */
    rtb_Compare_mj = ((0.0F == 7.0F) == (sint32)true);

    /* RelationalOperator: '<S578>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S18>/Constant'
     *  Constant: '<S578>/Constant'
     *  Logic: '<S6>/Logical Operator2'
     *  RelationalOperator: '<S17>/Compare'
     *  RelationalOperator: '<S18>/Compare'
     */
    rtb_Compare_n2g = (((0.0F == 2.0F) || (0.0F == 3.0F)) == (sint32)true);

    /* RelationalOperator: '<S579>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S20>/Constant'
     *  Constant: '<S579>/Constant'
     *  Logic: '<S6>/Logical Operator3'
     *  RelationalOperator: '<S19>/Compare'
     *  RelationalOperator: '<S20>/Compare'
     */
    rtb_Compare_jh = (((0.0F == 2.0F) || (0.0F == 3.0F)) == (sint32)true);

    /* RelationalOperator: '<S580>/Compare' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S580>/Constant'
     *  RelationalOperator: '<S21>/Compare'
     */
    rtb_Compare_bc2 = ((0.0F == 15.0F) == (sint32)true);

    /* RelationalOperator: '<S582>/Compare' incorporates:
     *  Constant: '<S582>/Constant'
     */
    rtb_LogicalOperator3_o = !true;
    rtb_Compare_ad = rtb_LogicalOperator3_o;

    /* RelationalOperator: '<S583>/Compare' */
    rtb_Compare_nvm = rtb_LogicalOperator3_o;

    /* RelationalOperator: '<S584>/Compare' */
    rtb_Compare_ex = rtb_LogicalOperator3_o;

    /* RelationalOperator: '<S586>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     *  Constant: '<S586>/Constant'
     *  RelationalOperator: '<S25>/Compare'
     */
    rtb_Compare_ge = ((rtb_IMAPve_d_EPS_LKA_State == ((uint8)4U)) == (sint32)
                      true);

    /* RelationalOperator: '<S587>/Compare' incorporates:
     *  Constant: '<S29>/Constant'
     *  Constant: '<S587>/Constant'
     *  RelationalOperator: '<S29>/Compare'
     */
    rtb_Compare_f4 = ((rtb_IMAPve_d_EPS_LKA_State > ((uint8)4U)) == (sint32)true);

    /* RelationalOperator: '<S588>/Compare' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S588>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     */
    rtb_Compare_ao = ((rtb_EPS_LKA_Control > ((uint8)2U)) == (sint32)true);

    /* RelationalOperator: '<S589>/Compare' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S589>/Constant'
     *  RelationalOperator: '<S26>/Compare'
     */
    rtb_Compare_kvr = ((0.0F == 15.0F) == (sint32)true);

    /* RelationalOperator: '<S590>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S590>/Constant'
     *  RelationalOperator: '<S27>/Compare'
     */
    rtb_Compare_gvn = ((rtb_EPS_LKA_Control == ((uint8)7U)) == (sint32)true);

    /* RelationalOperator: '<S591>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S591>/Constant'
     *  RelationalOperator: '<S28>/Compare'
     */
    rtb_Compare_k3c = ((0.0F == 3.0F) == (sint32)true);

    /* RelationalOperator: '<S592>/Compare' incorporates:
     *  Constant: '<S592>/Constant'
     *  Constant: '<S6>/Constant9'
     */
    rtb_Compare_kw = (false == true);

    /* RelationalOperator: '<S593>/Compare' incorporates:
     *  Constant: '<S593>/Constant'
     *  Constant: '<S6>/Constant10'
     */
    rtb_Compare_bm = (false == true);

    /* RelationalOperator: '<S594>/Compare' incorporates:
     *  Constant: '<S594>/Constant'
     *  Constant: '<S6>/Constant11'
     */
    rtb_Compare_nw = (false == true);

    /* RelationalOperator: '<S595>/Compare' incorporates:
     *  Constant: '<S595>/Constant'
     *  Constant: '<S6>/Constant12'
     */
    rtb_Compare_cz = (false == true);

    /* RelationalOperator: '<S597>/Compare' incorporates:
     *  Constant: '<S597>/Constant'
     *  Constant: '<S6>/Constant13'
     */
    rtb_Compare_l1 = (false == true);

    /* RelationalOperator: '<S598>/Compare' incorporates:
     *  Constant: '<S598>/Constant'
     *  Constant: '<S6>/Constant14'
     */
    rtb_Compare_m5 = (false == true);

    /* RelationalOperator: '<S599>/Compare' incorporates:
     *  Constant: '<S599>/Constant'
     *  Constant: '<S6>/Constant15'
     */
    rtb_Compare_ng = (false == true);

    /* RelationalOperator: '<S600>/Compare' incorporates:
     *  Constant: '<S600>/Constant'
     *  Constant: '<S6>/Constant16'
     */
    rtb_Compare_jn = (false == true);

    /* RelationalOperator: '<S602>/Compare' incorporates:
     *  Constant: '<S602>/Constant'
     *  Constant: '<S620>/Constant6'
     */
    rtb_Compare_ga = (((uint8)0U) == ((uint8)1U));
  } else {
    if (LKAS_DW.LLOn_MODE) {
      /* Disable for Enabled SubSystem: '<S404>/Count 20s' */
      if (LKAS_DW.Count20s_MODE) {
        /* Disable for Outport: '<S413>/Out' */
        LKAS_B.RelationalOperator_gm = false;
        LKAS_DW.Count20s_MODE = false;
      }

      /* End of Disable for SubSystem: '<S404>/Count 20s' */

      /* Disable for Enabled SubSystem: '<S405>/Sum Condition2' */
      if (LKAS_DW.SumCondition2_MODE) {
        /* Disable for Outport: '<S414>/Out' */
        LKAS_B.RelationalOperator_j = false;
        LKAS_DW.SumCondition2_MODE = false;
      }

      /* End of Disable for SubSystem: '<S405>/Sum Condition2' */

      /* Disable for Enabled SubSystem: '<S415>/Sum Condition1' */
      if (LKAS_DW.SumCondition1_MODE_c) {
        /* Disable for Outport: '<S421>/Out' */
        LKAS_B.RelationalOperator_e = false;
        LKAS_DW.SumCondition1_MODE_c = false;
      }

      /* End of Disable for SubSystem: '<S415>/Sum Condition1' */

      /* Disable for Enabled SubSystem: '<S430>/Sum Condition1' */
      if (LKAS_DW.SumCondition1_MODE) {
        /* Disable for Outport: '<S437>/Out' */
        LKAS_B.RelationalOperator_g = false;
        LKAS_DW.SumCondition1_MODE = false;
      }

      /* End of Disable for SubSystem: '<S430>/Sum Condition1' */

      /* Disable for Enabled SubSystem: '<S342>/Count 0.2s' */
      if (LKAS_DW.Count02s_MODE) {
        /* Disable for Outport: '<S375>/Out' */
        LKAS_B.RelationalOperator_fi = false;
        LKAS_DW.Count02s_MODE = false;
      }

      /* End of Disable for SubSystem: '<S342>/Count 0.2s' */

      /* Disable for Enabled SubSystem: '<S342>/Count' */
      if (LKAS_DW.Count_MODE) {
        /* Disable for Sum: '<S374>/Add' incorporates:
         *  Outport: '<S374>/Out'
         */
        LKAS_B.Saturation_l = ((uint16)0U);
        LKAS_DW.Count_MODE = false;
      }

      /* End of Disable for SubSystem: '<S342>/Count' */

      /* Disable for Enabled SubSystem: '<S377>/Sum Condition1' */
      if (LKAS_DW.SumCondition1_MODE_d) {
        /* Disable for Outport: '<S383>/Out' */
        LKAS_B.RelationalOperator_mu = false;
        LKAS_DW.SumCondition1_MODE_d = false;
      }

      /* End of Disable for SubSystem: '<S377>/Sum Condition1' */

      /* Disable for Enabled SubSystem: '<S343>/Sum Condition1' */
      if (LKAS_DW.SumCondition1_MODE_o) {
        /* Disable for Outport: '<S389>/Out' */
        LKAS_B.DataTypeConversion_c = false;
        LKAS_DW.SumCondition1_MODE_o = false;
      }

      /* End of Disable for SubSystem: '<S343>/Sum Condition1' */

      /* Disable for If: '<S392>/u1>=3|u1==1&u2==u3' */
      LKAS_DW.u13u11u2u3_ActiveSubsystem = -1;

      /* Disable for Enabled SubSystem: '<S298>/Count 5s3' */
      if (LKAS_DW.Count5s3.Count5s1_MODE) {
        LKAS_Count5s1_Disable(&LKAS_B.RelationalOperator_h, &LKAS_DW.Count5s3);
      }

      /* End of Disable for SubSystem: '<S298>/Count 5s3' */

      /* Disable for Enabled SubSystem: '<S298>/Count 5s2' */
      if (LKAS_DW.Count5s2.Count5s1_MODE) {
        LKAS_Count5s1_Disable(&LKAS_B.RelationalOperator_m, &LKAS_DW.Count5s2);
      }

      /* End of Disable for SubSystem: '<S298>/Count 5s2' */

      /* Disable for Enabled SubSystem: '<S298>/Count 5s4' */
      if (LKAS_DW.Count5s4.Count5s1_MODE) {
        LKAS_Count5s1_Disable(&LKAS_B.RelationalOperator_l, &LKAS_DW.Count5s4);
      }

      /* End of Disable for SubSystem: '<S298>/Count 5s4' */

      /* Disable for Enabled SubSystem: '<S298>/Count 5s1' */
      if (LKAS_DW.Count5s1.Count5s1_MODE) {
        LKAS_Count5s1_Disable(&LKAS_B.RelationalOperator_f, &LKAS_DW.Count5s1);
      }

      /* End of Disable for SubSystem: '<S298>/Count 5s1' */

      /* Disable for Enabled SubSystem: '<S298>/Count 5s5' */
      if (LKAS_DW.Count5s5.Count5s1_MODE) {
        LKAS_Count5s1_Disable(&LKAS_B.RelationalOperator, &LKAS_DW.Count5s5);
      }

      /* End of Disable for SubSystem: '<S298>/Count 5s5' */

      /* Disable for Enabled SubSystem: '<S276>/Subsystem' */
      if (LKAS_DW.Subsystem_MODE) {
        /* Disable for Outport: '<S280>/Out' */
        LKAS_B.RelationalOperator_hy = false;
        LKAS_DW.Subsystem_MODE = false;
      }

      /* End of Disable for SubSystem: '<S276>/Subsystem' */

      /* Disable for Enabled SubSystem: '<S10>/LKA'
       *
       * Block description for '<S10>/LKA':
       *  Block Name: Lane Keeping Assistance
       *  Ab.: LKA
       *  No.: 1.2.0.0
       *  Rev: 0.0.1
       *  Update Date: 19-5-13
       */
      if (LKAS_DW.LKA_MODE) {
        /* Disable for If: '<S102>/If' */
        LKAS_DW.If_ActiveSubsystem = -1;

        /* Disable for Enabled SubSystem: '<S119>/Sum Condition1' */
        if (LKAS_DW.SumCondition1_MODE_b) {
          /* Disable for Outport: '<S121>/Out' */
          LKAS_B.RelationalOperator_k = false;
          LKAS_DW.SumCondition1_MODE_b = false;
        }

        /* End of Disable for SubSystem: '<S119>/Sum Condition1' */

        /* Disable for Enabled SubSystem: '<S100>/Subsystem' */
        if (LKAS_DW.Subsystem_MODE_l) {
          /* Disable for Outport: '<S107>/Out1' */
          LKAS_B.DifferenceInputs2_m = 0.0F;
          LKAS_DW.Subsystem_MODE_l = false;
        }

        /* End of Disable for SubSystem: '<S100>/Subsystem' */

        /* Disable for Enabled SubSystem: '<S120>/Sum Condition1' */
        if (LKAS_DW.SumCondition1_f.SumCondition_MODE) {
          LKAS_SumCondition_Disable(&LKAS_B.DataTypeConversion,
            &LKAS_DW.SumCondition1_f);
        }

        /* End of Disable for SubSystem: '<S120>/Sum Condition1' */

        /* Disable for Enabled SubSystem: '<S120>/Sum Condition' */
        if (LKAS_DW.SumCondition_h.SumCondition_MODE) {
          LKAS_SumCondition_Disable(&LKAS_B.DataTypeConversion_i,
            &LKAS_DW.SumCondition_h);
        }

        /* End of Disable for SubSystem: '<S120>/Sum Condition' */

        /* Disable for If: '<S199>/If' */
        LKAS_DW.If_ActiveSubsystem_j = -1;

        /* Disable for Outport: '<S91>/LKA_ExitFlg' */
        LKAS_B.LogicalOperator3 = false;

        /* Disable for Outport: '<S91>/LKA_phiSWACmd' */
        LKAS_B.DifferenceInputs2 = 0.0F;

        /* Disable for Sum: '<S108>/Add1' incorporates:
         *  Outport: '<S91>/LKA_M'
         */
        LKAS_B.Saturation2 = 0.0F;
        LKAS_DW.LKA_MODE = false;
      }

      /* End of Disable for SubSystem: '<S10>/LKA' */

      /* Disable for Enabled SubSystem: '<S10>/LDW'
       *
       * Block description for '<S10>/LDW':
       *  Block Name: Lane Departure Warning
       *  Ab.: LDW
       *  No.: 1.3.0.0
       *  Rev: 0.0.1
       *  Update Date: 19-3-26
       */
      if (LKAS_DW.LDW_MODE) {
        /* Disable for Enabled SubSystem: '<S94>/Sum Condition' */
        if (LKAS_DW.SumCondition_MODE) {
          /* Disable for Outport: '<S99>/Out' */
          LKAS_B.DataTypeConversion_i2 = ((uint8)0U);
          LKAS_DW.SumCondition_MODE = false;
        }

        /* End of Disable for SubSystem: '<S94>/Sum Condition' */

        /* Disable for Outport: '<S90>/LDW_Flag' */
        LKAS_B.LDWWarnInfo = ((uint8)0U);
        LKAS_DW.LDW_MODE = false;
      }

      /* End of Disable for SubSystem: '<S10>/LDW' */

      /* Disable for Outport: '<S10>/bsLLState' */
      LKAS_B.LDW_State = ((uint8)0U);
      LKAS_B.DACMode = ((uint8)0U);
      LKAS_B.LKA_State = ((uint8)0U);

      /* Disable for Outport: '<S10>/phiSWACmd' */
      LKAS_B.OutputSWACmd = 0.0F;

      /* Disable for Outport: '<S10>/M' */
      LKAS_B.OutputM = 0.0F;
      LKAS_DW.LLOn_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/LLOn' */

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/Constant2'
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   *  Constant: '<S9>/Constant6'
   */
  switch (LKAS_B.LKA_State) {
   case 0:
    rtb_EPS_LKA_Control = ((uint8)0U);
    break;

   case 1:
    rtb_EPS_LKA_Control = ((uint8)1U);
    break;

   case 2:
    rtb_EPS_LKA_Control = ((uint8)2U);
    break;

   case 3:
    rtb_EPS_LKA_Control = ((uint8)3U);
    break;

   case 4:
    rtb_EPS_LKA_Control = ((uint8)4U);
    break;

   case 5:
    rtb_EPS_LKA_Control = ((uint8)4U);
    break;

   default:
    rtb_EPS_LKA_Control = ((uint8)5U);
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S9>/Constant7'
   *  RelationalOperator: '<S88>/Compare'
   */
  if (rtb_EPS_LKA_Control == ((uint8)4U)) {
    rtb_R0_C1 = LKAS_B.OutputM;
  } else {
    rtb_R0_C1 = 0.0F;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Outport: '<Root>/LKASve_g_EPS_Factor_Control' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_g_EPS_Factor_Control_1'
   */
  (void) Rte_Write_LKASve_g_EPS_Factor_Control_LKASve_g_EPS_Factor_Control
    (rtb_R0_C1);

  /* Outport: '<Root>/LKASve_y_EPS_State_Control' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_EPS_State_Control_1'
   */
  (void) Rte_Write_LKASve_y_EPS_State_Control_LKASve_y_EPS_State_Control
    (rtb_EPS_LKA_Control);

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S52>/Compare'
   */
  if (rtb_IMAPve_d_EPS_LKA_State == ((uint8)3U)) {
    rtb_Saturation9 = 0.5F;
  } else {
    rtb_Saturation9 = 0.25F;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Logic: '<S50>/Logical Operator2' incorporates:
   *  Abs: '<S50>/Abs'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  Logic: '<S50>/Logical Operator3'
   *  RelationalOperator: '<S50>/Relational Operator'
   *  RelationalOperator: '<S53>/Compare'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S57>/Compare'
   */
  rtb_LogicalOperator3_o = (((LKAS_B.LDW_State == ((uint8)5U)) ||
    (LKAS_B.LDW_State == ((uint8)4U)) || (LKAS_B.LDW_State == ((uint8)3U)) ||
    (rtb_IMAPve_d_EPS_LKA_State == ((uint8)3U)) || (rtb_IMAPve_d_EPS_LKA_State ==
    ((uint8)1U))) && (fabsf(rtb_IMAPve_g_EPS_SW_Trq) <= rtb_Saturation9));

  /* Outputs for Enabled SubSystem: '<S50>/Count 10s' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  if (rtb_LogicalOperator3_o) {
    if (!LKAS_DW.Count10s_MODE) {
      /* InitializeConditions for Sum: '<S58>/Add' incorporates:
       *  Memory: '<S58>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_f = ((uint16)0U);
      LKAS_DW.Count10s_MODE = true;
    }

    /* Sum: '<S58>/Add' incorporates:
     *  Constant: '<S58>/Constant'
     *  Memory: '<S58>/Memory'
     */
    LKAS_DW.Memory_PreviousInput_f = (uint16)((uint32)((uint16)1U) +
      LKAS_DW.Memory_PreviousInput_f);

    /* Saturate: '<S58>/Saturation' */
    if (LKAS_DW.Memory_PreviousInput_f >= ((uint16)2100U)) {
      /* Sum: '<S58>/Add' */
      LKAS_DW.Memory_PreviousInput_f = ((uint16)2100U);
    }

    /* End of Saturate: '<S58>/Saturation' */

    /* RelationalOperator: '<S60>/Compare' incorporates:
     *  Constant: '<S60>/Constant'
     */
    LKAS_B.Compare_d = (LKAS_DW.Memory_PreviousInput_f >= ((uint16)1000U));
  } else {
    if (LKAS_DW.Count10s_MODE) {
      /* Disable for Outport: '<S58>/Out' */
      LKAS_B.Compare_d = false;
      LKAS_DW.Count10s_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S50>/Count 10s' */

  /* MATLAB Function: '<S7>/HMI_Popup_Status' incorporates:
   *  Constant: '<S621>/Constant'
   */
  if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State == 6)) {
    rtb_IMAPve_d_BCM_HazardLamp = 6U;
  } else if (((LKAS_B.IMAPve_d_LKA_Mode == 2) || (LKAS_B.IMAPve_d_LKA_Mode == 1))
             && (((uint8)0U) == 5)) {
    rtb_IMAPve_d_BCM_HazardLamp = 4U;
  } else if (((LKAS_B.IMAPve_d_LKA_Mode == 2) || (LKAS_B.IMAPve_d_LKA_Mode == 1))
             && LKAS_B.Compare_d) {
    rtb_IMAPve_d_BCM_HazardLamp = 2U;
  } else if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State == 2)) {
    rtb_IMAPve_d_BCM_HazardLamp = 1U;
  } else if (LKAS_B.IMAPve_d_LKA_Mode != 2) {
    rtb_IMAPve_d_BCM_HazardLamp = 8U;
  } else {
    rtb_IMAPve_d_BCM_HazardLamp = 7U;
  }

  /* End of MATLAB Function: '<S7>/HMI_Popup_Status' */

  /* Outport: '<Root>/LKASve_y_HMI_Popup_Status' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_HMI_Popup_Status_1'
   */
  (void) Rte_Write_LKASve_y_HMI_Popup_Status_LKASve_y_HMI_Popup_Status
    (rtb_IMAPve_d_BCM_HazardLamp);

  /* Outputs for Enabled SubSystem: '<S50>/Count 15s' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtb_LogicalOperator3_o) {
    if (!LKAS_DW.Count15s_MODE) {
      /* InitializeConditions for Sum: '<S59>/Add' incorporates:
       *  Memory: '<S59>/Memory'
       */
      LKAS_DW.Memory_PreviousInput_bz = ((uint16)0U);
      LKAS_DW.Count15s_MODE = true;
    }

    /* Sum: '<S59>/Add' incorporates:
     *  Constant: '<S59>/Constant'
     *  Memory: '<S59>/Memory'
     */
    LKAS_DW.Memory_PreviousInput_bz = (uint16)((uint32)((uint16)1U) +
      LKAS_DW.Memory_PreviousInput_bz);

    /* Saturate: '<S59>/Saturation' */
    if (LKAS_DW.Memory_PreviousInput_bz >= ((uint16)2100U)) {
      /* Sum: '<S59>/Add' */
      LKAS_DW.Memory_PreviousInput_bz = ((uint16)2100U);
    }

    /* End of Saturate: '<S59>/Saturation' */

    /* RelationalOperator: '<S61>/Compare' incorporates:
     *  Constant: '<S61>/Constant'
     */
    LKAS_B.Compare = (LKAS_DW.Memory_PreviousInput_bz >= ((uint16)1500U));
  } else {
    if (LKAS_DW.Count15s_MODE) {
      /* Disable for Outport: '<S59>/Out' */
      LKAS_B.Compare = false;
      LKAS_DW.Count15s_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S50>/Count 15s' */

  /* MATLAB Function: '<S7>/Hands_off_warning' */
  if (!LKAS_B.Compare) {
    rtb_IMAPve_d_BCM_HazardLamp = 0U;
  } else {
    rtb_IMAPve_d_BCM_HazardLamp = LKAS_B.Compare;
  }

  /* End of MATLAB Function: '<S7>/Hands_off_warning' */

  /* Outport: '<Root>/LKASve_y_Hands_Off_Warning' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_Hands_Off_Warning_1'
   */
  (void) Rte_Write_LKASve_y_Hands_Off_Warning_LKASve_y_Hands_Off_Warning
    (rtb_IMAPve_d_BCM_HazardLamp);

  /* MATLAB Function: '<S7>/LDW_Flag' */
  switch (LKAS_B.IMAPve_d_LKA_Mode) {
   case 1:
    switch (LKAS_B.LDWWarnInfo) {
     case 1:
      rtb_EPS_LKA_Control = 1U;
      break;

     case 2:
      rtb_EPS_LKA_Control = 2U;
      break;

     default:
      rtb_EPS_LKA_Control = 0U;
      break;
    }
    break;

   case 2:
    if ((LKAS_B.LDWWarnInfo == 1) && (LKAS_B.LKA_State == 4)) {
      rtb_EPS_LKA_Control = 1U;
    } else if ((LKAS_B.LDWWarnInfo == 2) && (LKAS_B.LKA_State == 5)) {
      rtb_EPS_LKA_Control = 2U;
    } else {
      rtb_EPS_LKA_Control = 0U;
    }
    break;

   default:
    rtb_EPS_LKA_Control = 0U;
    break;
  }

  /* End of MATLAB Function: '<S7>/LDW_Flag' */

  /* Outport: '<Root>/LKASve_y_LDW_Flag' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_LDW_Flag_1'
   *  DataTypeConversion: '<S7>/Cast To Single3'
   */
  (void) Rte_Write_LKASve_y_LDW_Flag_LKASve_y_LDW_Flag(rtb_EPS_LKA_Control);

  /* MATLAB Function: '<S7>/LDW_Status_Display' */
  if ((LKAS_B.IMAPve_d_LKA_Mode == 1) && (LKAS_B.LDW_State != 6)) {
    rtb_IMAPve_d_BCM_HazardLamp = 1U;
  } else if ((LKAS_B.IMAPve_d_LKA_Mode == 1) && (LKAS_B.LDW_State == 6)) {
    rtb_IMAPve_d_BCM_HazardLamp = 2U;
  } else {
    rtb_IMAPve_d_BCM_HazardLamp = 0U;
  }

  /* End of MATLAB Function: '<S7>/LDW_Status_Display' */

  /* Outport: '<Root>/LKASve_y_LDW_Status_Display' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_LDW_Status_Display_1'
   */
  (void) Rte_Write_LKASve_y_LDW_Status_Display_LKASve_y_LDW_Status_Display
    (rtb_IMAPve_d_BCM_HazardLamp);

  /* MATLAB Function: '<S7>/LKA_action_indication' */
  if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State == 2)) {
    rtb_IMAPve_d_BCM_HazardLamp = 1U;
  } else if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State == 3)) {
    rtb_IMAPve_d_BCM_HazardLamp = 2U;
  } else if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && ((LKAS_B.LKA_State == 4) ||
              (LKAS_B.LKA_State == 5))) {
    rtb_IMAPve_d_BCM_HazardLamp = 3U;
  } else {
    rtb_IMAPve_d_BCM_HazardLamp = 0U;
  }

  /* End of MATLAB Function: '<S7>/LKA_action_indication' */

  /* Outport: '<Root>/LKASve_y_LKA_Action_Indication' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_LKA_Action_Indication_1'
   */
  (void) Rte_Write_LKASve_y_LKA_Action_Indication_LKASve_y_LKA_Action_Indication
    (rtb_IMAPve_d_BCM_HazardLamp);

  /* MATLAB Function: '<S7>/LKA_Status_Display' */
  if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State != 6)) {
    rtb_Switch3_0 = 1;
  } else if ((LKAS_B.IMAPve_d_LKA_Mode == 2) && (LKAS_B.LKA_State == 6)) {
    rtb_Switch3_0 = 2;
  } else {
    rtb_Switch3_0 = 0;
  }

  /* End of MATLAB Function: '<S7>/LKA_Status_Display' */

  /* Outport: '<Root>/LKASve_y_LKA_Status_Display' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_LKA_Status_Display_1'
   *  DataTypeConversion: '<S7>/Cast To Single2'
   */
  (void) Rte_Write_LKASve_y_LKA_Status_Display_LKASve_y_LKA_Status_Display
    ((uint8)(sint32)fmodf((float32)rtb_Switch3_0, 256.0F));

  /* MATLAB Function: '<S7>/Vehicle_Lane_Display' incorporates:
   *  Switch: '<S70>/Switch'
   *  Switch: '<S70>/Switch1'
   */
  switch (LKAS_B.IMAPve_d_LKA_Mode) {
   case 1:
    if ((LKAS_B.LDW_State == 3) && (rtb_L0_Q == 3) && (rtb_R0_Q != 3)) {
      rtb_EPS_LKA_Control = 3U;
    } else if ((LKAS_B.LDW_State == 3) && (rtb_L0_Q != 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 4U;
    } else if ((LKAS_B.LDW_State == 3) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 5U;
    } else if ((LKAS_B.LDW_State == 4) && (rtb_L0_Q == 3) && (rtb_R0_Q != 3)) {
      rtb_EPS_LKA_Control = 6U;
    } else if ((LKAS_B.LDW_State == 5) && (rtb_L0_Q != 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 7U;
    } else if ((LKAS_B.LDW_State == 4) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 8U;
    } else if ((LKAS_B.LDW_State == 5) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 9U;
    } else {
      rtb_EPS_LKA_Control = 1U;
    }
    break;

   case 2:
    if ((LKAS_B.LKA_State == 3) && (rtb_L0_Q == 3) && (rtb_R0_Q != 3)) {
      rtb_EPS_LKA_Control = 3U;
    } else if ((LKAS_B.LKA_State == 3) && (rtb_L0_Q != 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 4U;
    } else if ((LKAS_B.LKA_State == 3) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 5U;
    } else if ((LKAS_B.LKA_State == 4) && (rtb_L0_Q == 3) && (rtb_R0_Q != 3)) {
      rtb_EPS_LKA_Control = 6U;
    } else if ((LKAS_B.LKA_State == 5) && (rtb_L0_Q != 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 7U;
    } else if ((LKAS_B.LKA_State == 4) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 8U;
    } else if ((LKAS_B.LKA_State == 5) && (rtb_L0_Q == 3) && (rtb_R0_Q == 3)) {
      rtb_EPS_LKA_Control = 9U;
    } else {
      rtb_EPS_LKA_Control = 1U;
    }
    break;

   default:
    rtb_EPS_LKA_Control = 0U;
    break;
  }

  /* End of MATLAB Function: '<S7>/Vehicle_Lane_Display' */

  /* Outport: '<Root>/LKASve_y_Vehicle_Lane_Display' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_Vehicle_Lane_Display_1'
   *  DataTypeConversion: '<S7>/Cast To Single'
   */
  (void) Rte_Write_LKASve_y_Vehicle_Lane_Display_LKASve_y_Vehicle_Lane_Display
    (rtb_EPS_LKA_Control);

  /* DataTypeConversion: '<S9>/Cast To Single10' incorporates:
   *  Constant: '<S89>/Constant'
   *  RelationalOperator: '<S89>/Compare'
   */
  rtb_LKA_Switch_State = (uint8)(LKAS_B.DACMode > ((uint8)0U));

  /* DataTypeConversion: '<S9>/Cast To Single13' */
  rtb_LKA_Mode_from_Camera = LKAS_B.DACMode;

  /* Outport: '<Root>/LKASve_g_LKA_SWA_Control' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_g_LKA_SWA_Control_1'
   *  DataTypeConversion: '<S9>/Cast To Single'
   */
  (void) Rte_Write_LKASve_g_LKA_SWA_Control_LKASve_g_LKA_SWA_Control
    (LKAS_B.OutputSWACmd);

  /* Switch: '<S70>/Switch' incorporates:
   *  DataTypeConversion: '<S79>/Cast To Single5'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    rtb_R0_Type = rtb_IMAPve_d_R0_Type;
  } else {
    rtb_R0_Type = rtb_IMAPve_d_L0_Type;
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  Constant: '<S76>/Constant'
   *  DataTypeConversion: '<S1>/IMAPve_d_L1_Q_1'
   *  DataTypeConversion: '<S77>/Cast To Single5'
   *  Inport: '<Root>/IMAPve_d_L1_Q'
   *  Switch: '<S76>/Switch3'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_Type = rtb_IMAPve_d_L0_Type;
    Rte_Read_IMAPve_d_L1_Q_IMAPve_d_L1_Q(&tmpRead_1c);
    rtb_L1_Q = (uint8)tmpRead_1c;
  } else {
    rtb_L0_Type = rtb_IMAPve_d_R0_Type;
    rtb_L1_Q = ((uint16)0U);
  }

  /* Switch: '<S78>/Switch3' incorporates:
   *  Constant: '<S78>/Constant'
   *  DataTypeConversion: '<S1>/IMAPve_d_R1_Q_1'
   *  Inport: '<Root>/IMAPve_d_R1_Q'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    Rte_Read_IMAPve_d_R1_Q_IMAPve_d_R1_Q(&tmpRead_1f);
    rtb_R1_Q = (uint8)tmpRead_1f;
  } else {
    rtb_R1_Q = ((uint16)0U);
  }

  /* End of Switch: '<S78>/Switch3' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_R0_LC' */
  Rte_Read_IMAPve_d_R0_LC_IMAPve_d_R0_LC(&tmpRead_1b);

  /* Inport: '<Root>/IMAPve_d_L0_LC' */
  Rte_Read_IMAPve_d_L0_LC_IMAPve_d_L0_LC(&tmpRead_16);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_d_R0_LC_1' */
  rtb_EPS_LKA_Control = (uint8)tmpRead_1b;

  /* DataTypeConversion: '<S1>/IMAPve_d_L0_LC_1' */
  rtb_IMAPve_d_L0_Type = (uint8)tmpRead_16;

  /* Switch: '<S70>/Switch' incorporates:
   *  DataTypeConversion: '<S79>/Cast To Single8'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    rtb_R0_LC = rtb_EPS_LKA_Control;
  } else {
    rtb_R0_LC = rtb_IMAPve_d_L0_Type;
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  DataTypeConversion: '<S77>/Cast To Single8'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_LC = rtb_IMAPve_d_L0_Type;
  } else {
    rtb_L0_LC = rtb_EPS_LKA_Control;
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_VR' */
  Rte_Read_IMAPve_g_R0_VR_IMAPve_g_R0_VR(&tmpRead_17);

  /* Inport: '<Root>/IMAPve_g_L0_VR' */
  Rte_Read_IMAPve_g_L0_VR_IMAPve_g_L0_VR(&tmpRead_13);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S70>/Switch' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_VR_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_VR_1'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    rtb_R0_VR = tmpRead_17;
  } else {
    rtb_R0_VR = tmpRead_13;
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_VR_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_VR_1'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_VR = tmpRead_13;
  } else {
    rtb_L0_VR = tmpRead_17;
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_g_R0_W' */
  Rte_Read_IMAPve_g_R0_W_IMAPve_g_R0_W(&tmpRead_1a);

  /* Inport: '<Root>/IMAPve_g_L0_W' */
  Rte_Read_IMAPve_g_L0_W_IMAPve_g_L0_W(&tmpRead_15);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Switch: '<S70>/Switch' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_W_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_W_1'
   */
  if (LKAS_B.LaneRSM_stRgtFlg > ((uint8)0U)) {
    rtb_R0_W = tmpRead_1a;
  } else {
    rtb_R0_W = tmpRead_15;
  }

  /* Switch: '<S70>/Switch1' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_g_L0_W_1'
   *  DataTypeConversion: '<S1>/IMAPve_g_R0_W_1'
   */
  if (LKAS_B.LaneRSM_stLftFlg > ((uint8)0U)) {
    rtb_L0_W = tmpRead_15;
  } else {
    rtb_L0_W = tmpRead_1a;
  }

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_Camera_Status' */
  Rte_Read_IMAPve_d_Camera_Status_IMAPve_d_Camera_Status(&tmpRead_1j);

  /* Inport: '<Root>/IMAPve_d_Camera_Signal_Fault' */
  Rte_Read_IMAPve_d_Camera_Signal_Fault_IMAPve_d_Camera_Signal_Fault(&tmpRead_1i);

  /* Inport: '<Root>/IMAPve_d_L1_LC' */
  Rte_Read_IMAPve_d_L1_LC_IMAPve_d_L1_LC(&tmpRead_1e);

  /* Inport: '<Root>/IMAPve_d_L1_Type' */
  Rte_Read_IMAPve_d_L1_Type_IMAPve_d_L1_Type(&tmpRead_1d);

  /* Inport: '<Root>/IMAPve_d_ConsArea' */
  Rte_Read_IMAPve_d_ConsArea_IMAPve_d_ConsArea(&tmpRead_12);

  /* Inport: '<Root>/IMAPve_d_Lane_Valid' */
  Rte_Read_IMAPve_d_Lane_Valid_IMAPve_d_Lane_Valid(&tmpRead_10);

  /* Inport: '<Root>/IMAPve_d_Fusion_Status' */
  Rte_Read_IMAPve_d_Fusion_Status_IMAPve_d_Fusion_Status(&tmpRead_z);

  /* Inport: '<Root>/IMAPve_d_ORI_L0_LC' */
  Rte_Read_IMAPve_d_ORI_L0_LC_IMAPve_d_ORI_L0_LC(&tmpRead_o);

  /* Inport: '<Root>/IMAPve_d_ORI_L0_Q' */
  Rte_Read_IMAPve_d_ORI_L0_Q_IMAPve_d_ORI_L0_Q(&tmpRead_m);

  /* Inport: '<Root>/IMAPve_d_EPS_Steer_Hold_State' */
  Rte_Read_IMAPve_d_EPS_Steer_Hold_State_IMAPve_d_EPS_Steer_Hold_State
    (&tmpRead_i);

  /* Inport: '<Root>/IMAPve_d_ESC_VehSpd_Valid' */
  Rte_Read_IMAPve_d_ESC_VehSpd_Valid_IMAPve_d_ESC_VehSpd_Valid(&tmpRead_h);

  /* Inport: '<Root>/IMAPve_d_ESC_LonAcc_Valid' */
  Rte_Read_IMAPve_d_ESC_LonAcc_Valid_IMAPve_d_ESC_LonAcc_Valid(&tmpRead_a);

  /* Inport: '<Root>/IMAPve_d_ESC_YawRate_Valid' */
  Rte_Read_IMAPve_d_ESC_YawRate_Valid_IMAPve_d_ESC_YawRate_Valid(&tmpRead_9);

  /* Inport: '<Root>/IMAPve_d_ESC_LatAcc_Valid' */
  Rte_Read_IMAPve_d_ESC_LatAcc_Valid_IMAPve_d_ESC_LatAcc_Valid(&tmpRead_8);

  /* Inport: '<Root>/IMAPve_d_EPS_TrqLim_State' */
  Rte_Read_IMAPve_d_EPS_TrqLim_State_IMAPve_d_EPS_TrqLim_State(&tmpRead_7);

  /* Inport: '<Root>/IMAPve_d_EPS_Trq_State' */
  Rte_Read_IMAPve_d_EPS_Trq_State_IMAPve_d_EPS_Trq_State(&tmpRead_4);

  /* Inport: '<Root>/IMAPve_d_LDW_Warn_Mode' */
  Rte_Read_IMAPve_d_LDW_Warn_Mode_IMAPve_d_LDW_Warn_Mode(&tmpRead_1);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_d_Camera_Signal_Fault_1' */
  rtb_IMAPve_d_Camera_Signal_Faul = (uint8)tmpRead_1i;

  /* DataTypeConversion: '<S1>/IMAPve_d_Camera_Status_1' */
  rtb_IMAPve_d_Camera_Status = (uint8)tmpRead_1j;

  /* DataTypeConversion: '<S1>/IMAPve_d_ConsArea_1' */
  rtb_IMAPve_d_ConsArea = (uint8)tmpRead_12;

  /* DataTypeConversion: '<S1>/IMAPve_d_EPS_Steer_Hold_State_1' */
  rtb_IMAPve_d_EPS_Steer_Hold_Sta = (uint8)tmpRead_i;

  /* DataTypeConversion: '<S1>/IMAPve_d_EPS_TrqLim_State_1' */
  rtb_IMAPve_d_EPS_TrqLim_State = (uint8)tmpRead_7;

  /* DataTypeConversion: '<S1>/IMAPve_d_EPS_Trq_State_1' */
  rtb_IMAPve_d_EPS_Trq_State = (uint8)tmpRead_4;

  /* DataTypeConversion: '<S1>/IMAPve_d_ESC_LatAcc_Valid_1' */
  rtb_IMAPve_d_ESC_LatAcc_Valid = (uint8)tmpRead_8;

  /* DataTypeConversion: '<S1>/IMAPve_d_ESC_LonAcc_Valid_1' */
  rtb_IMAPve_d_ESC_LonAcc_Valid = (uint8)tmpRead_a;

  /* DataTypeConversion: '<S1>/IMAPve_d_ESC_VehSpd_Valid_1' */
  rtb_IMAPve_d_ESC_VehSpd_Valid = (uint8)tmpRead_h;

  /* DataTypeConversion: '<S1>/IMAPve_d_ESC_YawRate_Valid_1' */
  rtb_IMAPve_d_ESC_YawRate_Valid = (uint8)tmpRead_9;

  /* DataTypeConversion: '<S1>/IMAPve_d_Fusion_Status_1' */
  rtb_IMAPve_d_Fusion_Status = (uint8)tmpRead_z;

  /* DataTypeConversion: '<S1>/IMAPve_d_L1_LC_1' */
  rtb_IMAPve_d_L1_LC = (uint8)tmpRead_1e;

  /* DataTypeConversion: '<S1>/IMAPve_d_L1_Type_1' */
  rtb_IMAPve_d_L1_Type = (uint8)tmpRead_1d;

  /* DataTypeConversion: '<S1>/IMAPve_d_LDW_Warn_Mode_1' */
  rtb_IMAPve_d_LDW_Warn_Mode = (uint8)tmpRead_1;

  /* DataTypeConversion: '<S1>/IMAPve_d_Lane_Valid_1' */
  rtb_IMAPve_d_Lane_Valid = (uint8)tmpRead_10;

  /* DataTypeConversion: '<S69>/Cast To Single9' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_L0_LC_1'
   */
  rtb_L0_LC_o = (uint8)tmpRead_o;

  /* DataTypeConversion: '<S1>/IMAPve_d_ORI_L0_Q_1' */
  rtb_EPS_LKA_Control = (UInt8)tmpRead_m;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S73>/Constant'
   */
  if (rtb_EPS_LKA_Control >= ((uint8)2U)) {
    rtb_L0_Q_m = ((uint8)3U);
  } else {
    rtb_L0_Q_m = rtb_EPS_LKA_Control;
  }

  /* End of Switch: '<S73>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_ORI_R0_LC' */
  Rte_Read_IMAPve_d_ORI_R0_LC_IMAPve_d_ORI_R0_LC(&tmpRead_u);

  /* Inport: '<Root>/IMAPve_d_ORI_R0_LT' */
  Rte_Read_IMAPve_d_ORI_R0_LT_IMAPve_d_ORI_R0_LT(&tmpRead_t);

  /* Inport: '<Root>/IMAPve_d_ORI_R0_Q' */
  Rte_Read_IMAPve_d_ORI_R0_Q_IMAPve_d_ORI_R0_Q(&tmpRead_s);

  /* Inport: '<Root>/IMAPve_d_ORI_L1_LC' */
  Rte_Read_IMAPve_d_ORI_L1_LC_IMAPve_d_ORI_L1_LC(&tmpRead_r);

  /* Inport: '<Root>/IMAPve_d_ORI_L1_Type' */
  Rte_Read_IMAPve_d_ORI_L1_Type_IMAPve_d_ORI_L1_Type(&tmpRead_q);

  /* Inport: '<Root>/IMAPve_d_ORI_L1_Q' */
  Rte_Read_IMAPve_d_ORI_L1_Q_IMAPve_d_ORI_L1_Q(&tmpRead_p);

  /* Inport: '<Root>/IMAPve_d_ORI_L0_Type' */
  Rte_Read_IMAPve_d_ORI_L0_Type_IMAPve_d_ORI_L0_Type(&tmpRead_n);

  /* Inport: '<Root>/IMAPve_d_ORI_Lane_RoadType' */
  Rte_Read_IMAPve_d_ORI_Lane_RoadType_IMAPve_d_ORI_Lane_RoadType(&tmpRead_l);

  /* Inport: '<Root>/IMAPve_d_ORI_Lane_ConsArea' */
  Rte_Read_IMAPve_d_ORI_Lane_ConsArea_IMAPve_d_ORI_Lane_ConsArea(&tmpRead_k);

  /* Inport: '<Root>/IMAPve_d_ORI_Lane_Valid' */
  Rte_Read_IMAPve_d_ORI_Lane_Valid_IMAPve_d_ORI_Lane_Valid(&tmpRead_j);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S69>/Cast To Single6' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_L0_Type_1'
   */
  rtb_L0_Type_j = (uint8)tmpRead_n;

  /* DataTypeConversion: '<S69>/Cast To Single29' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_L1_LC_1'
   */
  rtb_L1_LC = (uint8)tmpRead_r;

  /* DataTypeConversion: '<S69>/Cast To Single25' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_L1_Q_1'
   */
  rtb_L1_Q_c = (uint8)tmpRead_p;

  /* DataTypeConversion: '<S69>/Cast To Single26' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_L1_Type_1'
   */
  rtb_L1_Type = (uint8)tmpRead_q;

  /* DataTypeConversion: '<S1>/IMAPve_d_ORI_Lane_ConsArea_1' */
  rtb_IMAPve_d_ORI_Lane_ConsArea = (uint8)tmpRead_k;

  /* DataTypeConversion: '<S1>/IMAPve_d_ORI_Lane_RoadType_1' */
  rtb_IMAPve_d_ORI_Lane_RoadType = (uint8)tmpRead_l;

  /* DataTypeConversion: '<S1>/IMAPve_d_ORI_Lane_Valid_1' */
  rtb_IMAPve_d_ORI_Lane_Valid = (uint8)tmpRead_j;

  /* DataTypeConversion: '<S69>/Cast To Single19' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_R0_LC_1'
   */
  rtb_R0_LC_n = (uint8)tmpRead_u;

  /* DataTypeConversion: '<S69>/Cast To Single16' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_R0_LT_1'
   */
  rtb_R0_Type_i = (uint8)tmpRead_t;

  /* DataTypeConversion: '<S1>/IMAPve_d_ORI_R0_Q_1' */
  rtb_EPS_LKA_Control = (UInt8)tmpRead_s;

  /* Switch: '<S72>/Switch1' incorporates:
   *  Constant: '<S72>/Constant1'
   */
  if (rtb_EPS_LKA_Control >= ((uint8)2U)) {
    rtb_R0_Q_n = ((uint8)3U);
  } else {
    rtb_R0_Q_n = rtb_EPS_LKA_Control;
  }

  /* End of Switch: '<S72>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_R1_LC' */
  Rte_Read_IMAPve_d_R1_LC_IMAPve_d_R1_LC(&tmpRead_1h);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_g_R1_TLC_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_TLC'
   */
  Rte_Read_IMAPve_g_R1_TLC_IMAPve_g_R1_TLC(&rtb_IMAPve_g_R1_TLC);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_W_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_W'
   */
  Rte_Read_IMAPve_g_R1_W_IMAPve_g_R1_W(&rtb_IMAPve_g_R1_W);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_Confidence_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_Confidence'
   */
  Rte_Read_IMAPve_g_R1_Confidence_IMAPve_g_R1_Confidence
    (&rtb_IMAPve_g_R1_Confidence);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_R1_Type' */
  Rte_Read_IMAPve_d_R1_Type_IMAPve_d_R1_Type(&tmpRead_1g);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_g_R1_VR_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_VR'
   */
  Rte_Read_IMAPve_g_R1_VR_IMAPve_g_R1_VR(&rtb_IMAPve_g_R1_VR);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_C3_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_C3'
   */
  Rte_Read_IMAPve_g_R1_C3_IMAPve_g_R1_C3(&rtb_IMAPve_g_R1_C3);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_C2_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_C2'
   */
  Rte_Read_IMAPve_g_R1_C2_IMAPve_g_R1_C2(&rtb_IMAPve_g_R1_C2);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_C1_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_C1'
   */
  Rte_Read_IMAPve_g_R1_C1_IMAPve_g_R1_C1(&rtb_IMAPve_g_R1_C1);

  /* DataTypeConversion: '<S1>/IMAPve_g_R1_C0_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R1_C0'
   */
  Rte_Read_IMAPve_g_R1_C0_IMAPve_g_R1_C0(&rtb_IMAPve_g_R1_C0);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_TLC_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_TLC'
   */
  Rte_Read_IMAPve_g_L1_TLC_IMAPve_g_L1_TLC(&rtb_IMAPve_g_L1_TLC);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_W_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_W'
   */
  Rte_Read_IMAPve_g_L1_W_IMAPve_g_L1_W(&rtb_IMAPve_g_L1_W);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_Confidence_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_Confidence'
   */
  Rte_Read_IMAPve_g_L1_Confidence_IMAPve_g_L1_Confidence
    (&rtb_IMAPve_g_L1_Confidence);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_VR_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_VR'
   */
  Rte_Read_IMAPve_g_L1_VR_IMAPve_g_L1_VR(&rtb_IMAPve_g_L1_VR);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_C3_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_C3'
   */
  Rte_Read_IMAPve_g_L1_C3_IMAPve_g_L1_C3(&rtb_IMAPve_g_L1_C3);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_C2_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_C2'
   */
  Rte_Read_IMAPve_g_L1_C2_IMAPve_g_L1_C2(&rtb_IMAPve_g_L1_C2);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_C1_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_C1'
   */
  Rte_Read_IMAPve_g_L1_C1_IMAPve_g_L1_C1(&rtb_IMAPve_g_L1_C1);

  /* DataTypeConversion: '<S1>/IMAPve_g_L1_C0_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L1_C0'
   */
  Rte_Read_IMAPve_g_L1_C0_IMAPve_g_L1_C0(&rtb_IMAPve_g_L1_C0);

  /* DataTypeConversion: '<S1>/IMAPve_g_R0_Confidence_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_R0_Confidence'
   */
  Rte_Read_IMAPve_g_R0_Confidence_IMAPve_g_R0_Confidence
    (&rtb_IMAPve_g_R0_Confidence);

  /* DataTypeConversion: '<S1>/IMAPve_g_L0_Confidence_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_L0_Confidence'
   */
  Rte_Read_IMAPve_g_L0_Confidence_IMAPve_g_L0_Confidence
    (&rtb_IMAPve_g_L0_Confidence);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_Road_Type' */
  Rte_Read_IMAPve_d_Road_Type_IMAPve_d_Road_Type(&tmpRead_11);

  /* Inport: '<Root>/IMAPve_d_Sensor_Status' */
  Rte_Read_IMAPve_d_Sensor_Status_IMAPve_d_Sensor_Status(&tmpRead_y);

  /* Inport: '<Root>/IMAPve_d_ORI_R1_LC' */
  Rte_Read_IMAPve_d_ORI_R1_LC_IMAPve_d_ORI_R1_LC(&tmpRead_x);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S69>/Cast To Single37' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_W'
   */
  Rte_Read_IMAPve_g_ORI_R1_W_IMAPve_g_ORI_R1_W(&rtb_R1_W);

  /* DataTypeConversion: '<S69>/Cast To Single38' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_TLC'
   */
  Rte_Read_IMAPve_g_ORI_R1_TLC_IMAPve_g_ORI_R1_TLC(&rtb_R1_TLC);

  /* DataTypeConversion: '<S69>/Cast To Single34' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_VR'
   */
  Rte_Read_IMAPve_g_ORI_R1_VR_IMAPve_g_ORI_R1_VR(&rtb_R1_VR);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_ORI_R1_LT' */
  Rte_Read_IMAPve_d_ORI_R1_LT_IMAPve_d_ORI_R1_LT(&tmpRead_w);

  /* Inport: '<Root>/IMAPve_d_ORI_R1_Q' */
  Rte_Read_IMAPve_d_ORI_R1_Q_IMAPve_d_ORI_R1_Q(&tmpRead_v);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S69>/Cast To Single30' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_C0'
   */
  Rte_Read_IMAPve_g_ORI_R1_C0_IMAPve_g_ORI_R1_C0(&rtb_R1_C0);

  /* DataTypeConversion: '<S69>/Cast To Single31' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_C1'
   */
  Rte_Read_IMAPve_g_ORI_R1_C1_IMAPve_g_ORI_R1_C1(&rtb_R1_C1);

  /* DataTypeConversion: '<S69>/Cast To Single32' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_C2'
   */
  Rte_Read_IMAPve_g_ORI_R1_C2_IMAPve_g_ORI_R1_C2(&rtb_R1_C2);

  /* DataTypeConversion: '<S69>/Cast To Single33' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R1_C3'
   */
  Rte_Read_IMAPve_g_ORI_R1_C3_IMAPve_g_ORI_R1_C3(&rtb_R1_C3);

  /* DataTypeConversion: '<S69>/Cast To Single17' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_W'
   */
  Rte_Read_IMAPve_g_ORI_R0_W_IMAPve_g_ORI_R0_W(&rtb_R0_W_l);

  /* DataTypeConversion: '<S69>/Cast To Single18' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_TLC'
   */
  Rte_Read_IMAPve_g_ORI_R0_TLC_IMAPve_g_ORI_R0_TLC(&rtb_R0_TLC_a);

  /* DataTypeConversion: '<S69>/Cast To Single14' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_VR'
   */
  Rte_Read_IMAPve_g_ORI_R0_VR_IMAPve_g_ORI_R0_VR(&rtb_R0_VR_i);

  /* DataTypeConversion: '<S69>/Cast To Single10' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_C0'
   */
  Rte_Read_IMAPve_g_ORI_R0_C0_IMAPve_g_ORI_R0_C0(&rtb_R0_C0_p);

  /* DataTypeConversion: '<S69>/Cast To Single11' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_C1'
   */
  Rte_Read_IMAPve_g_ORI_R0_C1_IMAPve_g_ORI_R0_C1(&rtb_R0_C1_o);

  /* DataTypeConversion: '<S69>/Cast To Single12' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_C2'
   */
  Rte_Read_IMAPve_g_ORI_R0_C2_IMAPve_g_ORI_R0_C2(&rtb_R0_C2_c);

  /* DataTypeConversion: '<S69>/Cast To Single13' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_R0_C3'
   */
  Rte_Read_IMAPve_g_ORI_R0_C3_IMAPve_g_ORI_R0_C3(&rtb_R0_C3_c);

  /* DataTypeConversion: '<S69>/Cast To Single27' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_W'
   */
  Rte_Read_IMAPve_g_ORI_L1_W_IMAPve_g_ORI_L1_W(&rtb_L1_W);

  /* DataTypeConversion: '<S69>/Cast To Single28' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_TLC'
   */
  Rte_Read_IMAPve_g_ORI_L1_TLC_IMAPve_g_ORI_L1_TLC(&rtb_L1_TLC);

  /* DataTypeConversion: '<S69>/Cast To Single24' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_VR'
   */
  Rte_Read_IMAPve_g_ORI_L1_VR_IMAPve_g_ORI_L1_VR(&rtb_L1_VR);

  /* DataTypeConversion: '<S69>/Cast To Single20' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_C0'
   */
  Rte_Read_IMAPve_g_ORI_L1_C0_IMAPve_g_ORI_L1_C0(&rtb_L1_C0);

  /* DataTypeConversion: '<S69>/Cast To Single21' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_C1'
   */
  Rte_Read_IMAPve_g_ORI_L1_C1_IMAPve_g_ORI_L1_C1(&rtb_L1_C1);

  /* DataTypeConversion: '<S69>/Cast To Single22' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_C2'
   */
  Rte_Read_IMAPve_g_ORI_L1_C2_IMAPve_g_ORI_L1_C2(&rtb_L1_C2);

  /* DataTypeConversion: '<S69>/Cast To Single23' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L1_C3'
   */
  Rte_Read_IMAPve_g_ORI_L1_C3_IMAPve_g_ORI_L1_C3(&rtb_L1_C3);

  /* DataTypeConversion: '<S69>/Cast To Single7' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_W'
   */
  Rte_Read_IMAPve_g_ORI_L0_W_IMAPve_g_ORI_L0_W(&rtb_L0_W_l);

  /* DataTypeConversion: '<S69>/Cast To Single8' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_TLC'
   */
  Rte_Read_IMAPve_g_ORI_L0_TLC_IMAPve_g_ORI_L0_TLC(&rtb_L0_TLC_k);

  /* DataTypeConversion: '<S69>/Cast To Single4' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_VR'
   */
  Rte_Read_IMAPve_g_ORI_L0_VR_IMAPve_g_ORI_L0_VR(&rtb_L0_VR_n);

  /* DataTypeConversion: '<S69>/Cast To Single' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_C0'
   */
  Rte_Read_IMAPve_g_ORI_L0_C0_IMAPve_g_ORI_L0_C0(&rtb_L0_C0_l);

  /* DataTypeConversion: '<S69>/Cast To Single1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_C1'
   */
  Rte_Read_IMAPve_g_ORI_L0_C1_IMAPve_g_ORI_L0_C1(&rtb_L0_C1_c);

  /* DataTypeConversion: '<S69>/Cast To Single2' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_C2'
   */
  Rte_Read_IMAPve_g_ORI_L0_C2_IMAPve_g_ORI_L0_C2(&rtb_L0_C2_a);

  /* DataTypeConversion: '<S69>/Cast To Single3' incorporates:
   *  Inport: '<Root>/IMAPve_g_ORI_L0_C3'
   */
  Rte_Read_IMAPve_g_ORI_L0_C3_IMAPve_g_ORI_L0_C3(&rtb_L0_C3_l);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_SWS_Failure_Status' */
  Rte_Read_IMAPve_d_SWS_Failure_Status_IMAPve_d_SWS_Failure_Status(&tmpRead_g);

  /* Inport: '<Root>/IMAPve_d_SWS_Fault_Code' */
  Rte_Read_IMAPve_d_SWS_Fault_Code_IMAPve_d_SWS_Fault_Code(&tmpRead_f);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S1>/IMAPve_g_EMS_RealPedal_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_EMS_RealPedal'
   */
  Rte_Read_IMAPve_g_EMS_RealPedal_IMAPve_g_EMS_RealPedal
    (&rtb_IMAPve_g_EMS_RealPedal);

  /* DataTypeConversion: '<S1>/IMAPve_g_SW_Angle_Speed_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_SW_Angle_Speed'
   */
  Rte_Read_IMAPve_g_SW_Angle_Speed_IMAPve_g_SW_Angle_Speed
    (&rtb_IMAPve_g_SW_Angle_Speed);

  /* DataTypeConversion: '<S1>/IMAPve_g_ESC_Brake_Press_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ESC_Brake_Press'
   */
  Rte_Read_IMAPve_g_ESC_Brake_Press_IMAPve_g_ESC_Brake_Press
    (&rtb_IMAPve_g_ESC_Brake_Press);

  /* DataTypeConversion: '<S1>/IMAPve_g_ESC_UnYawRate_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ESC_UnYawRate'
   */
  Rte_Read_IMAPve_g_ESC_UnYawRate_IMAPve_g_ESC_UnYawRate
    (&rtb_IMAPve_g_ESC_UnYawRate);

  /* DataTypeConversion: '<S1>/IMAPve_g_ESC_YawRate_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_ESC_YawRate'
   */
  Rte_Read_IMAPve_g_ESC_YawRate_IMAPve_g_ESC_YawRate(&rtb_IMAPve_g_ESC_YawRate);

  /* DataTypeConversion: '<S1>/IMAPve_g_EPS_LKA_Current_1' incorporates:
   *  Inport: '<Root>/IMAPve_g_EPS_LKA_Current'
   */
  Rte_Read_IMAPve_g_EPS_LKA_Current_IMAPve_g_EPS_LKA_Current
    (&rtb_IMAPve_g_EPS_LKA_Current);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* Inport: '<Root>/IMAPve_d_SAS_Trim_State' */
  Rte_Read_IMAPve_d_SAS_Trim_State_IMAPve_d_SAS_Trim_State(&tmpRead_6);

  /* Inport: '<Root>/IMAPve_d_SAS_Clb_State' */
  Rte_Read_IMAPve_d_SAS_Clb_State_IMAPve_d_SAS_Clb_State(&tmpRead_5);

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* DataTypeConversion: '<S69>/Cast To Single39' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_R1_LC_1'
   */
  rtb_R1_LC = (uint8)tmpRead_x;

  /* DataTypeConversion: '<S69>/Cast To Single36' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_R1_LT_1'
   */
  rtb_R1_Type = (uint8)tmpRead_w;

  /* DataTypeConversion: '<S69>/Cast To Single35' incorporates:
   *  DataTypeConversion: '<S1>/IMAPve_d_ORI_R1_Q_1'
   */
  rtb_R1_Q_k = (uint8)tmpRead_v;

  /* DataTypeConversion: '<S1>/IMAPve_d_R1_LC_1' */
  rtb_IMAPve_d_R1_LC = (uint8)tmpRead_1h;

  /* DataTypeConversion: '<S1>/IMAPve_d_R1_Type_1' */
  rtb_IMAPve_d_R1_Type = (uint8)tmpRead_1g;

  /* DataTypeConversion: '<S1>/IMAPve_d_Road_Type_1' */
  rtb_IMAPve_d_Road_Type = (uint8)tmpRead_11;

  /* DataTypeConversion: '<S1>/IMAPve_d_SAS_Clb_State_1' */
  rtb_IMAPve_d_SAS_Clb_State = (uint8)tmpRead_5;

  /* DataTypeConversion: '<S1>/IMAPve_d_SAS_Trim_State_1' */
  rtb_IMAPve_d_SAS_Trim_State = (uint8)tmpRead_6;

  /* DataTypeConversion: '<S1>/IMAPve_d_SWS_Failure_Status_1' */
  rtb_IMAPve_d_SWS_Failure_Status = (uint8)tmpRead_g;

  /* DataTypeConversion: '<S1>/IMAPve_d_SWS_Fault_Code_1' */
  rtb_IMAPve_d_SWS_Fault_Code = (uint8)tmpRead_f;

  /* DataTypeConversion: '<S1>/IMAPve_d_Sensor_Status_1' */
  rtb_IMAPve_d_Sensor_Status = (uint8)tmpRead_y;

  /* Outport: '<Root>/LKASve_y_EPS_LKA_Control' incorporates:
   *  DataTypeConversion: '<S1>/LKASve_y_EPS_LKA_Control_1'
   *  DataTypeConversion: '<S4>/Cast To Single9'
   */
  (void) Rte_Write_LKASve_y_EPS_LKA_Control_LKASve_y_EPS_LKA_Control
    (LKAS_ConstB.Permit_to_know_if_LKA_or_LP);

  /* Switch: '<S612>/Switch12' incorporates:
   *  Constant: '<S612>/LL_NomTAhd_C=0.2'
   */
  if (LKAS_ConstB.DataTypeConversion23_c != 0.0F) {
    rtb_LL_NomTAhd_C = LKAS_ConstB.DataTypeConversion23_c;
  } else {
    rtb_LL_NomTAhd_C = LL_NomTAhd_C;
  }

  /* End of Switch: '<S612>/Switch12' */

  /* Switch: '<S613>/Switch18' incorporates:
   *  Constant: '<S613>/LL_LKAS_OUT_OF_CONTROL_TTLC=0.3'
   */
  if (LKAS_ConstB.DataTypeConversion38 != 0.0F) {
    rtb_LL_LKAS_OUT_OF_CONTROL_TTLC = LKAS_ConstB.DataTypeConversion38;
  } else {
    rtb_LL_LKAS_OUT_OF_CONTROL_TTLC = LL_LKAS_OUT_OF_CONTROL_TTLC;
  }

  /* End of Switch: '<S613>/Switch18' */

  /* Update for Enabled SubSystem: '<S2>/LLOn' incorporates:
   *  EnablePort: '<S10>/states'
   */
  if (LKAS_DW.LLOn_MODE) {
    /* Update for Memory: '<S547>/Memory' */
    LKAS_DW.Memory_PreviousInput_d = rtb_Saturation_e;

    /* Update for Delay: '<S92>/Delay' */
    LKAS_DW.Delay_DSTATE = LKAS_B.LKASM_stLKAActvFlg;

    /* Update for UnitDelay: '<S507>/UD'
     *
     * Block description for '<S507>/UD':
     *
     *  Store in Global RAM
     */
    LKAS_DW.UD_DSTATE = rtb_TSamp;

    /* Update for Memory: '<S491>/Memory' */
    LKAS_DW.Memory_PreviousInput_p = rtb_Saturation_d;

    /* Update for UnitDelay: '<S408>/UD'
     *
     * Block description for '<S408>/UD':
     *
     *  Store in Global RAM
     */
    LKAS_DW.UD_DSTATE_c = rtb_TSamp_n;

    /* Update for UnitDelay: '<S417>/Delay Input1'
     *
     * Block description for '<S417>/Delay Input1':
     *
     *  Store in Global RAM
     */
    LKAS_DW.DelayInput1_DSTATE = rtb_Compare_ef;

    /* Update for UnitDelay: '<S415>/Unit Delay' */
    LKAS_DW.UnitDelay_DSTATE_ba = LKAS_B.RelationalOperator_e;

    /* Update for UnitDelay: '<S416>/Delay Input1'
     *
     * Block description for '<S416>/Delay Input1':
     *
     *  Store in Global RAM
     */
    LKAS_DW.DelayInput1_DSTATE_j = rtb_Compare_oq;

    /* Update for Delay: '<S93>/Delay1' */
    LKAS_DW.Delay1_3_DSTATE = LKAS_B.LKASM_stLKAState;

    /* Update for UnitDelay: '<S379>/Delay Input1'
     *
     * Block description for '<S379>/Delay Input1':
     *
     *  Store in Global RAM
     */
    LKAS_DW.DelayInput1_DSTATE_b = rtb_Compare_cg;

    /* Update for UnitDelay: '<S377>/Unit Delay' */
    LKAS_DW.UnitDelay_DSTATE_c = LKAS_B.RelationalOperator_mu;

    /* Update for UnitDelay: '<S378>/Delay Input1'
     *
     * Block description for '<S378>/Delay Input1':
     *
     *  Store in Global RAM
     */
    LKAS_DW.DelayInput1_DSTATE_p = rtb_Compare_ki;

    /* Update for Memory: '<S342>/Memory' */
    LKAS_DW.Memory_PreviousInput_eb = LKAS_B.RelationalOperator_mu;

    /* Update for Delay: '<S93>/Delay' */
    LKAS_DW.Delay_DSTATE_e = LKAS_B.LogicalOperator3;

    /* Update for Delay: '<S93>/Delay1' */
    LKAS_DW.Delay1_1_DSTATE = LKAS_B.LDWSM_stLDWState;

    /* Update for Memory: '<S392>/Memory' */
    LKAS_DW.Memory_PreviousInput_ms = rtb_LDW_State;

    /* Update for Enabled SubSystem: '<S10>/LKA' incorporates:
     *  EnablePort: '<S91>/states = reset'
     *
     * Block description for '<S10>/LKA':
     *  Block Name: Lane Keeping Assistance
     *  Ab.: LKA
     *  No.: 1.2.0.0
     *  Rev: 0.0.1
     *  Update Date: 19-5-13
     */
    if (LKAS_DW.LKA_MODE) {
      /* Update for Memory: '<S118>/Memory' */
      LKAS_DW.Memory_PreviousInput_a = rtb_Saturation2_a;

      /* Update for Memory: '<S153>/Memory' */
      LKAS_DW.Memory_PreviousInput_l = rtb_Saturation1_l;

      /* Update for Memory: '<S102>/Memory1' */
      LKAS_DW.Memory1_PreviousInput_k = rtb_Saturation1_ks;

      /* Update for Memory: '<S152>/Memory' */
      LKAS_DW.Memory_PreviousInput_lx = rtb_Saturation1_la;

      /* Update for Memory: '<S154>/Memory' */
      LKAS_DW.Memory_PreviousInput_k = rtb_Saturation1_b;

      /* Update for Memory: '<S173>/Memory' */
      LKAS_DW.Memory_PreviousInput_h3 = rtb_Add_p2;

      /* Update for Memory: '<S151>/Memory' */
      LKAS_DW.Memory_PreviousInput_d2 = rtb_Saturation1_f;

      /* Update for Memory: '<S150>/Memory' */
      LKAS_DW.Memory_PreviousInput_ko = rtb_Saturation1_b2;

      /* Update for Memory: '<S149>/Memory' */
      LKAS_DW.Memory_PreviousInput_mm = rtb_Saturation1_e;

      /* Update for Memory: '<S128>/Memory' */
      LKAS_DW.Memory_PreviousInput_i0 = rtb_Add_c3;

      /* Update for Memory: '<S119>/Memory' */
      LKAS_DW.Memory_PreviousInput_g = rtb_Saturation2_g;

      /* Update for Memory: '<S120>/Memory' */
      LKAS_DW.Memory_PreviousInput_aw = rtb_Saturation2;

      /* Update for Memory: '<S117>/Memory3' */
      LKAS_DW.Memory3_PreviousInput_i = rtb_Saturation_d3;

      /* Update for Memory: '<S201>/Memory3' */
      LKAS_DW.Memory3_PreviousInput_c = rtb_Saturation_b;

      /* Update for Memory: '<S187>/Memory' */
      LKAS_DW.Memory_PreviousInput_av = rtb_Add1_f;

      /* Update for Memory: '<S192>/Memory3' */
      LKAS_DW.Memory3_PreviousInput_h = rtb_Saturation_n;

      /* Update for Memory: '<S196>/Memory' */
      LKAS_DW.Memory_PreviousInput_e4 = rtb_Saturation1_m;

      /* Update for Memory: '<S200>/Memory3' */
      LKAS_DW.Memory3_PreviousInput_j = rtb_Saturation_ge;

      /* Update for UnitDelay: '<S180>/Delay Input2'
       *
       * Block description for '<S180>/Delay Input2':
       *
       *  Store in Global RAM
       */
      LKAS_DW.DelayInput2_DSTATE = LKAS_B.DifferenceInputs2;

      /* Update for Memory: '<S180>/Memory' */
      LKAS_DW.Memory_PreviousInput_bh = rtb_Saturation2_m;
    }

    /* End of Update for SubSystem: '<S10>/LKA' */

    /* Update for Delay: '<S93>/Delay1' */
    LKAS_DW.Delay1_2_DSTATE = LKAS_B.IMAPve_d_LKA_Mode;
  }

  /* End of Update for SubSystem: '<S2>/LLOn' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */
}

/* Model initialize function */
void Runnable_LKAS_Init(void)
{
  /* Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* Start for Enabled SubSystem: '<S2>/LLOn' */
  /* Start for If: '<S392>/u1>=3|u1==1&u2==u3' */
  LKAS_DW.u13u11u2u3_ActiveSubsystem = -1;

  /* Start for Enabled SubSystem: '<S10>/LKA'
   *
   * Block description for '<S10>/LKA':
   *  Block Name: Lane Keeping Assistance
   *  Ab.: LKA
   *  No.: 1.2.0.0
   *  Rev: 0.0.1
   *  Update Date: 19-5-13
   */
  /* Start for If: '<S102>/If' */
  LKAS_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<S199>/If' */
  LKAS_DW.If_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S10>/LKA' */
  /* End of Start for SubSystem: '<S2>/LLOn' */
  /* End of Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' incorporates:
   *  SubSystem: '<Root>/LKAS'
   */
  /* InitializeConditions for Memory: '<S87>/Memory' */
  LKAS_DW.Memory_PreviousInput = 3.2F;

  /* InitializeConditions for Memory: '<S81>/Memory' */
  LKAS_DW.Memory_PreviousInput_o = (-1.75F);

  /* InitializeConditions for Memory: '<S82>/Memory' */
  LKAS_DW.Memory_PreviousInput_i = 1.75F;

  /* SystemInitialize for Enabled SubSystem: '<S2>/LLOn' */
  /* InitializeConditions for Memory: '<S547>/Memory' */
  LKAS_DW.Memory_PreviousInput_d = 0.0F;

  /* InitializeConditions for Delay: '<S92>/Delay' */
  LKAS_DW.Delay_DSTATE = ((uint8)0U);

  /* InitializeConditions for UnitDelay: '<S507>/UD'
   *
   * Block description for '<S507>/UD':
   *
   *  Store in Global RAM
   */
  LKAS_DW.UD_DSTATE = 0.0F;

  /* InitializeConditions for Memory: '<S491>/Memory' */
  LKAS_DW.Memory_PreviousInput_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S408>/UD'
   *
   * Block description for '<S408>/UD':
   *
   *  Store in Global RAM
   */
  LKAS_DW.UD_DSTATE_c = 0.0F;

  /* InitializeConditions for UnitDelay: '<S417>/Delay Input1'
   *
   * Block description for '<S417>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE = false;

  /* InitializeConditions for UnitDelay: '<S415>/Unit Delay' */
  LKAS_DW.UnitDelay_DSTATE_ba = false;

  /* InitializeConditions for UnitDelay: '<S416>/Delay Input1'
   *
   * Block description for '<S416>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE_j = false;

  /* InitializeConditions for Delay: '<S93>/Delay1' */
  LKAS_DW.Delay1_3_DSTATE = ((uint8)0U);

  /* InitializeConditions for UnitDelay: '<S379>/Delay Input1'
   *
   * Block description for '<S379>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE_b = false;

  /* InitializeConditions for UnitDelay: '<S377>/Unit Delay' */
  LKAS_DW.UnitDelay_DSTATE_c = false;

  /* InitializeConditions for UnitDelay: '<S378>/Delay Input1'
   *
   * Block description for '<S378>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE_p = false;

  /* InitializeConditions for Memory: '<S342>/Memory' */
  LKAS_DW.Memory_PreviousInput_eb = false;

  /* InitializeConditions for Delay: '<S93>/Delay' */
  LKAS_DW.Delay_DSTATE_e = false;

  /* InitializeConditions for Delay: '<S93>/Delay1' */
  LKAS_DW.Delay1_1_DSTATE = ((uint8)0U);

  /* InitializeConditions for Memory: '<S392>/Memory' */
  LKAS_DW.Memory_PreviousInput_ms = ((uint8)0U);

  /* InitializeConditions for Delay: '<S93>/Delay1' */
  LKAS_DW.Delay1_2_DSTATE = ((uint8)0U);

  /* SystemInitialize for Enabled SubSystem: '<S404>/Count 20s' */
  /* InitializeConditions for Sum: '<S413>/Add' incorporates:
   *  Memory: '<S413>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_i3 = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S404>/Count 20s' */

  /* SystemInitialize for Enabled SubSystem: '<S405>/Sum Condition2' */
  /* InitializeConditions for Sum: '<S414>/Add1' incorporates:
   *  Memory: '<S414>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_p0 = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S405>/Sum Condition2' */

  /* SystemInitialize for Enabled SubSystem: '<S415>/Sum Condition1' */
  /* InitializeConditions for Sum: '<S421>/Add1' incorporates:
   *  Memory: '<S421>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_h = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S415>/Sum Condition1' */

  /* SystemInitialize for Enabled SubSystem: '<S430>/Sum Condition1' */
  /* InitializeConditions for Sum: '<S437>/Add1' incorporates:
   *  Memory: '<S437>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_c = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S430>/Sum Condition1' */

  /* SystemInitialize for Enabled SubSystem: '<S342>/Count 0.2s' */
  /* InitializeConditions for Sum: '<S375>/Add' incorporates:
   *  Memory: '<S375>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_n = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S342>/Count 0.2s' */

  /* SystemInitialize for Enabled SubSystem: '<S342>/Count' */
  /* InitializeConditions for Memory: '<S374>/Memory' */
  LKAS_DW.Memory_PreviousInput_e0 = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S342>/Count' */

  /* SystemInitialize for Enabled SubSystem: '<S377>/Sum Condition1' */
  /* InitializeConditions for Sum: '<S383>/Add1' incorporates:
   *  Memory: '<S383>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_ps = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S377>/Sum Condition1' */

  /* SystemInitialize for Enabled SubSystem: '<S343>/Sum Condition1' */
  /* InitializeConditions for Sum: '<S389>/Add1' incorporates:
   *  Memory: '<S389>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_a1 = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S343>/Sum Condition1' */

  /* SystemInitialize for IfAction SubSystem: '<S392>/If Action Subsystem' */
  /* InitializeConditions for Sum: '<S424>/Add1' incorporates:
   *  Memory: '<S424>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_pu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S392>/If Action Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S298>/Count 5s3' */
  LKAS_Count5s1_Init(&LKAS_DW.Count5s3);

  /* End of SystemInitialize for SubSystem: '<S298>/Count 5s3' */

  /* SystemInitialize for Enabled SubSystem: '<S298>/Count 5s2' */
  LKAS_Count5s1_Init(&LKAS_DW.Count5s2);

  /* End of SystemInitialize for SubSystem: '<S298>/Count 5s2' */

  /* SystemInitialize for Enabled SubSystem: '<S298>/Count 5s4' */
  LKAS_Count5s1_Init(&LKAS_DW.Count5s4);

  /* End of SystemInitialize for SubSystem: '<S298>/Count 5s4' */

  /* SystemInitialize for Enabled SubSystem: '<S298>/Count 5s1' */
  LKAS_Count5s1_Init(&LKAS_DW.Count5s1);

  /* End of SystemInitialize for SubSystem: '<S298>/Count 5s1' */

  /* SystemInitialize for Enabled SubSystem: '<S298>/Count 5s5' */
  LKAS_Count5s1_Init(&LKAS_DW.Count5s5);

  /* End of SystemInitialize for SubSystem: '<S298>/Count 5s5' */

  /* SystemInitialize for Enabled SubSystem: '<S276>/Subsystem' */
  /* InitializeConditions for Sum: '<S280>/Add1' incorporates:
   *  Memory: '<S280>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_mo = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S276>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/LKA'
   *
   * Block description for '<S10>/LKA':
   *  Block Name: Lane Keeping Assistance
   *  Ab.: LKA
   *  No.: 1.2.0.0
   *  Rev: 0.0.1
   *  Update Date: 19-5-13
   */
  /* InitializeConditions for Memory: '<S118>/Memory' */
  LKAS_DW.Memory_PreviousInput_a = 0.0F;

  /* InitializeConditions for Memory: '<S153>/Memory' */
  LKAS_DW.Memory_PreviousInput_l = ((uint16)0U);

  /* InitializeConditions for Memory: '<S102>/Memory1' */
  LKAS_DW.Memory1_PreviousInput_k = ((uint8)0U);

  /* InitializeConditions for Memory: '<S152>/Memory' */
  LKAS_DW.Memory_PreviousInput_lx = ((uint16)0U);

  /* InitializeConditions for Memory: '<S154>/Memory' */
  LKAS_DW.Memory_PreviousInput_k = ((uint16)0U);

  /* InitializeConditions for Memory: '<S173>/Memory' */
  LKAS_DW.Memory_PreviousInput_h3 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S151>/Memory' */
  LKAS_DW.Memory_PreviousInput_d2 = ((uint16)0U);

  /* InitializeConditions for Memory: '<S150>/Memory' */
  LKAS_DW.Memory_PreviousInput_ko = ((uint16)0U);

  /* InitializeConditions for Memory: '<S149>/Memory' */
  LKAS_DW.Memory_PreviousInput_mm = ((uint16)0U);

  /* InitializeConditions for Memory: '<S128>/Memory' */
  LKAS_DW.Memory_PreviousInput_i0 = 0.0F;

  /* InitializeConditions for Memory: '<S119>/Memory' */
  LKAS_DW.Memory_PreviousInput_g = 0.0F;

  /* InitializeConditions for Memory: '<S120>/Memory' */
  LKAS_DW.Memory_PreviousInput_aw = 0.0F;

  /* InitializeConditions for Memory: '<S117>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_i = 0.0F;

  /* InitializeConditions for Memory: '<S201>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_c = 0.0F;

  /* InitializeConditions for Memory: '<S187>/Memory' */
  LKAS_DW.Memory_PreviousInput_av = 0.0F;

  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay' */
  LKAS_DW.UnitDelay_DSTATE_g = 0.0F;

  /* InitializeConditions for Memory: '<S192>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_h = 0.0F;

  /* InitializeConditions for Memory: '<S196>/Memory' */
  LKAS_DW.Memory_PreviousInput_e4 = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S200>/Unit Delay' */
  LKAS_DW.UnitDelay_DSTATE_h = 0.0F;

  /* InitializeConditions for Memory: '<S200>/Memory3' */
  LKAS_DW.Memory3_PreviousInput_j = 0.0F;

  /* InitializeConditions for UnitDelay: '<S180>/Delay Input2'
   *
   * Block description for '<S180>/Delay Input2':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for Memory: '<S180>/Memory' */
  LKAS_DW.Memory_PreviousInput_bh = ((uint16)0U);

  /* SystemInitialize for IfAction SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)'
   *
   * Block description for '<S102>/LKA Motion Planning Calculation (LKAMPCal)':
   *  Block Name: LKA Motion Planning Calculation
   *  Ab.: LKAMPCal
   *  No.: 1.2.3.2
   *  Rev: 0.0.1
   *  Update Date: 19-3-26
   */
  LKAMotionPlanningCalculati_Init();

  /* End of SystemInitialize for SubSystem: '<S102>/LKA Motion Planning Calculation (LKAMPCal)' */

  /* SystemInitialize for Enabled SubSystem: '<S119>/Sum Condition1' */
  /* InitializeConditions for Sum: '<S121>/Add1' incorporates:
   *  Memory: '<S121>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_gg = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S119>/Sum Condition1' */

  /* SystemInitialize for Atomic SubSystem: '<S108>/Moving Standard Deviation2' */
  L_MovingStandardDeviation2_Init(&LKAS_DW.MovingStandardDeviation2);

  /* End of SystemInitialize for SubSystem: '<S108>/Moving Standard Deviation2' */

  /* SystemInitialize for Atomic SubSystem: '<S120>/Moving Standard Deviation1' */
  L_MovingStandardDeviation2_Init(&LKAS_DW.MovingStandardDeviation1);

  /* End of SystemInitialize for SubSystem: '<S120>/Moving Standard Deviation1' */

  /* SystemInitialize for Enabled SubSystem: '<S120>/Sum Condition1' */
  LKAS_SumCondition_Init(&LKAS_DW.SumCondition1_f);

  /* End of SystemInitialize for SubSystem: '<S120>/Sum Condition1' */

  /* SystemInitialize for Atomic SubSystem: '<S120>/Moving Standard Deviation2' */
  L_MovingStandardDeviation2_Init(&LKAS_DW.MovingStandardDeviation2_e);

  /* End of SystemInitialize for SubSystem: '<S120>/Moving Standard Deviation2' */

  /* SystemInitialize for Enabled SubSystem: '<S120>/Sum Condition' */
  LKAS_SumCondition_Init(&LKAS_DW.SumCondition_h);

  /* End of SystemInitialize for SubSystem: '<S120>/Sum Condition' */

  /* SystemInitialize for IfAction SubSystem: '<S199>/If Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S209>/Delay Input1'
   *
   * Block description for '<S209>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE_jd = false;

  /* InitializeConditions for Memory: '<S205>/Memory' */
  LKAS_DW.Memory_PreviousInput_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S199>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S199>/If Action Subsystem1' */
  /* InitializeConditions for UnitDelay: '<S217>/Delay Input1'
   *
   * Block description for '<S217>/Delay Input1':
   *
   *  Store in Global RAM
   */
  LKAS_DW.DelayInput1_DSTATE_n = false;

  /* InitializeConditions for Memory: '<S206>/Memory' */
  LKAS_DW.Memory_PreviousInput_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S199>/If Action Subsystem1' */

  /* SystemInitialize for Merge: '<S199>/Merge' */
  LKAS_B.Merge_p = 1.0F;

  /* SystemInitialize for Merge: '<S199>/Merge1' */
  LKAS_B.Merge1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S10>/LKA' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/LDW'
   *
   * Block description for '<S10>/LDW':
   *  Block Name: Lane Departure Warning
   *  Ab.: LDW
   *  No.: 1.3.0.0
   *  Rev: 0.0.1
   *  Update Date: 19-3-26
   */
  /* SystemInitialize for Merge: '<S94>/Merge' */
  LKAS_B.Merge_j = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S94>/Sum Condition' */
  /* InitializeConditions for Memory: '<S99>/Memory' */
  LKAS_DW.Memory_PreviousInput_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S94>/Sum Condition' */
  /* End of SystemInitialize for SubSystem: '<S10>/LDW' */
  /* End of SystemInitialize for SubSystem: '<S2>/LLOn' */

  /* SystemInitialize for Enabled SubSystem: '<S50>/Count 10s' */
  /* InitializeConditions for Sum: '<S58>/Add' incorporates:
   *  Memory: '<S58>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_f = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S50>/Count 10s' */

  /* SystemInitialize for Enabled SubSystem: '<S50>/Count 15s' */
  /* InitializeConditions for Sum: '<S59>/Add' incorporates:
   *  Memory: '<S59>/Memory'
   */
  LKAS_DW.Memory_PreviousInput_bz = ((uint16)0U);

  /* End of SystemInitialize for SubSystem: '<S50>/Count 15s' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Runnable_LKAS_Step_at_outport_1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
