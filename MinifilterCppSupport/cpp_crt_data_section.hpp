#ifndef __CPP_CRT_DATA_SECTION_HPP__ 
#define __CPP_CRT_DATA_SECTION_HPP__ 

typedef void(__cdecl *PVFV)(void);

extern "C" {
    PVFV __crtXca[];
    PVFV __crtXcz[];
}

#endif //__CPP_CRT_DATA_SECTION_HPP__