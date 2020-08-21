/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "LKAS"
   ARXML schema: "4.2"
   File generated on: "21-Aug-2020 16:34:08"  */

#define MEMMAP_ERROR

/* START_SEC Symbols */
#ifdef LKAS_START_SEC_CODE
#undef LKAS_START_SEC_CODE
#undef MEMMAP_ERROR
#elif defined( LKAS_START_SEC_CONST)
#undef LKAS_START_SEC_CONST
#undef MEMMAP_ERROR
#elif defined( LKAS_START_SEC_VAR)
#undef LKAS_START_SEC_VAR
#undef MEMMAP_ERROR
#endif

/* STOP_SEC symbols */
#ifdef LKAS_STOP_SEC_CODE
#undef LKAS_STOP_SEC_CODE
#undef MEMMAP_ERROR
#elif defined( LKAS_STOP_SEC_CONST)
#undef LKAS_STOP_SEC_CONST
#undef MEMMAP_ERROR
#elif defined( LKAS_STOP_SEC_VAR)
#undef LKAS_STOP_SEC_VAR
#undef MEMMAP_ERROR

/* Error out if none of the expected Memory Section keywords are defined */
#ifdef MEMMAP_ERROR
#error "LKAS_MemMap.h wrong pragma command"
#endif
#endif
