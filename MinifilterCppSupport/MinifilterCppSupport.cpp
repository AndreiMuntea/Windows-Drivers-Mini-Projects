#include <fltKernel.h>

#include "DriverGlobals.hpp"
#include "cpp_nonpaged_object.hpp"
#include "cpp_allocation_tags.hpp"


class Test : public CppNonPagedObject<MEM_TAG_TST>
{
public:
    Test() = default;
    Test(int f1, int f2) : f1{ f1 }, f2{ f2 } {};
    ~Test() = default;
private:
    int f1 = 5;
    int f2 = 4;
};


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

    auto t = new Test(1, 2);
    delete t;

    auto c = new Test[100];
    delete[] c;

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
    DrvUninitializeGlobalData();

    return STATUS_SUCCESS;
}

EXTERN_C_END