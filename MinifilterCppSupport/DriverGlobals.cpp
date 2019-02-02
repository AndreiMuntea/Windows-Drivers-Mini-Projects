#include "DriverGlobals.hpp"
#include "DriverStartRoutines.hpp"

EXTERN_C_START

DRIVER_GLOBAL_DATA gDrvData;

static CONST FLT_OPERATION_REGISTRATION Callbacks[] = 
{
    { IRP_MJ_OPERATION_END }
};

static CONST FLT_REGISTRATION FilterRegistration = 
{
    sizeof(FLT_REGISTRATION),   //  Size
    FLT_REGISTRATION_VERSION,   //  Version
    0,                          //  Flags

    nullptr,                    //  Context
    Callbacks,                  //  Operation callbacks

    DriverUnload,               //  MiniFilterUnload

    nullptr,                    //  InstanceSetup
    nullptr,                    //  InstanceQueryTeardown
    nullptr,                    //  InstanceTeardownStart
    nullptr,                    //  InstanceTeardownComplete

    nullptr,                    //  GenerateFileName
    nullptr,                    //  GenerateDestinationFileName
    nullptr                     //  NormalizeNameComponent

};


void 
DrvInitializeGlobalData()
{
    gDrvData.FilterHandle = nullptr;
    gDrvData.FilterRegistration = FilterRegistration;
}

void 
DrvUninitializeGlobalData()
{
    gDrvData.FilterHandle = nullptr;
}

EXTERN_C_END