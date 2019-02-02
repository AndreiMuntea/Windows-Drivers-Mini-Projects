#ifndef __CPP_CRT_STATIC_CLASS_SUPPORT_HPP__ 
#define __CPP_CRT_STATIC_CLASS_SUPPORT_HPP__ 

#include <fltKernel.h>
#include "cpp_crt_data_section.hpp"

void
CppInitializeDestructorsList();

void
CppCallAllDestructors();

void
CppCallAllConstructors(
    _In_ PVFV* FirstPVFVEntry,
    _In_ PVFV* LastPVFVEntry
);

int
CppRegisterDestructor(
    _In_ PVFV Destructor
);

#endif //__CPP_CRT_STATIC_CLASS_SUPPORT_HPP__