#include <fltKernel.h>

#include "DriverGlobals.hpp"
#include "cpp_nonpaged_object.hpp"
#include "cpp_allocation_tags.hpp"
#include "cpp_crt_static_class_support.hpp"


EXTERN_C_START

NTSTATUS
DriverEntry (
    _In_ PDRIVER_OBJECT     DriverObject,
    _In_ PUNICODE_STRING    RegistryPath
)
{
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    UNREFERENCED_PARAMETER(RegistryPath);

    DrvInitializeGlobalData();

    status = FltRegisterFilter(DriverObject, &gDrvData.FilterRegistration, &gDrvData.FilterHandle );
    if (!NT_SUCCESS(status))
    {
        goto Exit;
    }

    status = FltStartFiltering(gDrvData.FilterHandle);
    if (!NT_SUCCESS(status)) 
    {
        FltUnregisterFilter(gDrvData.FilterHandle);
        goto Exit;
    }

    CppInitializeDestructorsList();
    CppCallAllConstructors(__crtXca, __crtXcz);

Exit:
    return status;
}

NTSTATUS
DriverUnload (
    _In_ FLT_FILTER_UNLOAD_FLAGS Flags
)
{
    PAGED_CODE();
    UNREFERENCED_PARAMETER(Flags);

    FltUnregisterFilter(gDrvData.FilterHandle);
    CppCallAllDestructors();
    DrvUninitializeGlobalData();

    return STATUS_SUCCESS;
}

EXTERN_C_END