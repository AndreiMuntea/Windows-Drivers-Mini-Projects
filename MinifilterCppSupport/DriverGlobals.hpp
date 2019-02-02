#ifndef __DRIVER_GLOBALS_HPP__ 
#define __DRIVER_GLOBALS_HPP__ 

#include <fltKernel.h>

EXTERN_C_START

typedef struct _DRIVER_GLOBAL_DATA
{
    PFLT_FILTER         FilterHandle;
    FLT_REGISTRATION    FilterRegistration;
}DRIVER_GLOBAL_DATA, *PDRIVER_GLOBAL_DATA;

extern DRIVER_GLOBAL_DATA gDrvData;

void DrvInitializeGlobalData();
void DrvUninitializeGlobalData();

EXTERN_C_END

#endif //__DRIVER_GLOBALS_HPP__