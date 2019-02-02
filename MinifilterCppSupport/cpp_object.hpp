#ifndef __CPP_OBJECT_HPP__ 
#define __CPP_OBJECT_HPP__

#include <fltKernel.h>

template <typename POOL_TYPE PoolType, typename ULONG Tag>
class CppObject
{
public:
    void* __cdecl operator new(_In_ SIZE_T Size)
    {
        return ExAllocatePoolWithTag(PoolType, Size, Tag);
    }

    void* __cdecl operator new[](_In_ SIZE_T Size)
    {
        return ExAllocatePoolWithTag(PoolType, Size, Tag);
    }

    void __cdecl operator delete(_Inout_ PVOID Block)
    {
        ExFreePoolWithTag(Block, Tag);
    }

    void __cdecl operator delete[](_Inout_ PVOID Block)
    {
        ExFreePoolWithTag(Block, Tag);
    }

private:

};

#endif //__CPP_OBJECT_HPP__