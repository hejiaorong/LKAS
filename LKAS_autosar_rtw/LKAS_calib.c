/*
 * File: LKAS_calib.c
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

#include "rtwtypes.h"
#include "LKAS_types.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
float32 LKA_CarWidth = 1.8F;
float32 LKA_SampleTime = 0.01F;
float32 LKA_StrRatio_C = 15.3F;
float32 LKA_Veh2CamL_C = 1.56F;
float32 LKA_Veh2CamW_C = 0.9F;
float32 LKA_WhlBaseL_C = 2.65F;
float32 LL_CompSWA_C = 0.0F;
float32 LL_CrvtPrvwT_C = 0.45F;
float32 LL_DesDvt_C = 0.2F;
float32 LL_DvtComp_C = 0.0F;
float32 LL_DvtPrvwT_C = 0.45F;
float32 LL_DvtSpdDet_vDvtSpdMin_C = 0.0F;
float32 LL_HdAgExT_C = 15.0F;
float32 LL_HdAgPrvwT_C = 0.45F;
float32 LL_LAccMax_C = 3.0F;
float32 LL_LAccRMax_C = 5.0F;
float32 LL_LDWS_SUPPRESS_HEADING = 2.0F;
float32 LL_LDW_EarliestWarnLine_C = 0.3F;
float32 LL_LDW_LatestWarnLine_C = -0.4F;
float32 LL_LFClb_TFC_DiffCtlBalance = 0.0F;
float32 LL_LFClb_TFC_DiffCtrlMaxSWA = 20.0F;
float32 LL_LFClb_TFC_DiffCtrlRatio = 400.0F;
float32 LL_LFClb_TFC_FfCtlRatio_C = 1.0F;
float32 LL_LFClb_TFC_facmGainLutGain1_C = 40.0F;
float32 LL_LFClb_TFC_facmGainLutGain2_C = 40.0F;
float32 LL_LFClb_TFC_facmIntegRatio = 0.002F;
float32 LL_LFClb_TFC_facmKlat_C = -9.0F;
float32 LL_LFClb_TFC_phiIntegCtlMaxSWA_C = 5.0F;
float32 LL_LFClb_TFC_tiKlatPrvwT_C = 2.0F;
float32 LL_LFClb_TFC_vGainLutVehSpdLwr_C = 60.0F;
float32 LL_LFClb_TFC_vGainLutVehSpdUpr_C = 120.0F;
float32 LL_LKAExPrcs_ExitC0Dvt = 0.01F;
float32 LL_LKAExPrcs_ExitC0Swt = 1.0F;
float32 LL_LKAExPrcs_tiExitTime1 = 8.0F;
float32 LL_LKAExPrcs_tiExitTime2 = 4.0F;
float32 LL_LKAExPrcs_tiExitTime3 = 0.2F;
float32 LL_LKASWASyn_M0 = 0.4F;
float32 LL_LKASWASyn_M1 = 0.8F;
float32 LL_LKASWASyn_M2 = 0.3F;
float32 LL_LKASWASyn_M3K = 0.2F;
float32 LL_LKASWASyn_SWAaddMax = 8.0F;
float32 LL_LKASWASyn_T2 = 4.0F;
float32 LL_LKASWASyn_TrqMax = 1.5F;
float32 LL_LKASWASyn_TrqSwaAddSwt = 0.0F;
float32 LL_LKASWASyn_TrqSwaRateDiff = -0.2F;
float32 LL_LKASWASyn_tiTrqSwaRtTime = 0.2F;
float32 LL_LKASWASyn_tiTrqSwaTime = 0.3F;
float32 LL_LKAS_OUT_OF_CONTROL_LAT_VEL = 1.5F;
float32 LL_LKAS_OUT_OF_CONTROL_TTLC = 0.3F;
float32 LL_LKA_EarliestWarnLine_C = 0.3F;
float32 LL_LKA_LatestWarnLine_C = -0.5F;
float32 LL_LSpdCompT_C = 0.4F;
float32 LL_MAX_DELAY_EPSSTAR_TIME = 0.5F;
float32 LL_MAX_DRIVER_TORQUE_DISABLE = 2.25F;
float32 LL_MAX_DRIVER_TORQUE_ENABLE = 3.0F;
float32 LL_MAX_LANE_WIDTH_DISABLE = 5.5F;
float32 LL_MAX_LANE_WIDTH_ENABLE = 5.4F;
float32 LL_MAX_LAT_ACC_DISABLE = 3.5F;
float32 LL_MAX_LAT_ACC_ENABLE = 3.0F;
float32 LL_MAX_LDWS_SPEED_DISABLE = 150.0F;
float32 LL_MAX_LDWS_SPEED_ENABLE = 140.0F;
float32 LL_MAX_LKAS_SPEED_DISABLE = 150.0F;
float32 LL_MAX_LKAS_SPEED_ENABLE = 140.0F;
float32 LL_MAX_LONG_ACC_DISABLE = 3.5F;
float32 LL_MAX_LONG_ACC_ENABLE = 3.0F;
float32 LL_MAX_LONG_DECEL_DISABLE = 2.5F;
float32 LL_MAX_LONG_DECEL_ENABLE = 2.0F;
float32 LL_MAX_STEER_ANGLE_DISABLE = 70.0F;
float32 LL_MAX_STEER_ANGLE_ENABLE = 60.0F;
float32 LL_MAX_STEER_SPEED_DISABLE = 5000.0F;
float32 LL_MAX_STEER_SPEED_ENABLE = 5000.0F;
float32 LL_MAX_SYSTEM_CURVATURE_DISABLE = 0.0055F;
float32 LL_MAX_SYSTEM_CURVATURE_ENABLE = 0.0045F;
float32 LL_MIN_LANE_WIDTH_DISABLE = 2.4F;
float32 LL_MIN_LANE_WIDTH_ENABLE = 2.5F;
float32 LL_MIN_LKAS_SPEED_DISABLE = 55.0F;
float32 LL_MIN_LKAS_SPEED_ENABLE = 60.0F;
float32 LL_Max_LDWS_Warning_Time = 5.0F;
float32 LL_NomTAhd_C = 0.2F;
float32 LL_ThresDet_lDvtThresLwrLDW = 0.15F;
float32 LL_ThresDet_lDvtThresLwrLKA = 0.3F;
float32 LL_ThresDet_lDvtThresUprLDW = 0.3F;
float32 LL_ThresDet_lDvtThresUprLKA = 0.6F;
float32 LL_ThresDet_tiTTLCThresLDW = 0.75F;
float32 LL_ThresDet_tiTTLCThresLKA = 1.5F;
float32 LL_TkOvStChk_tiTDelTime = 2.0F;
float32 LL_TkOvStChk_tiTrqChkT = 0.1F;
float32 LL_lStpLngth_C = 5.0F;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
