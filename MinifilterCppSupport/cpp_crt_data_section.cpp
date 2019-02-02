#include "cpp_crt_data_section.hpp"

#define _CRTALLOC(x) __declspec(allocate(x))

#pragma section(".CRT$XCA", long, read)
#pragma section(".CRT$XCZ", long, read)

_CRTALLOC(".CRT$XCA") PVFV __crtXca[] = { nullptr };
_CRTALLOC(".CRT$XCZ") PVFV __crtXcz[] = { nullptr };

#pragma comment(linker, "/merge:.CRT=.rdata")