#ifndef __DRIVER_START_ROUTINES_HPP__
#define __DRIVER_START_ROUTINES_HPP__ 

#include <fltKernel.h>

EXTERN_C_START

NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT     DriverObject,
    _In_ PUNICODE_STRING    RegistryPath
);

NTSTATUS
DriverUnload(
    _In_ FLT_FILTER_UNLOAD_FLAGS Flags
);

EXTERN_C_END


#endif //__DRIVER_START_ROUTINES_HPP__