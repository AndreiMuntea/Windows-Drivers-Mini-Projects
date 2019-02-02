#ifndef __CPP_DEFINITIONS_HPP__ 
#define __CPP_DEFINITIONS_HPP__ 

#include <fltKernel.h>

void* __cdecl
operator new(
    _In_ size_t Size
);

void* __cdecl
operator new[](
    _In_ size_t Size
);

void __cdecl 
operator delete(
    _Inout_  PVOID Block
);

void __cdecl
operator delete[](
    _Inout_  PVOID Block
);

#endif //__CPP_DEFINITIONS_HPP__