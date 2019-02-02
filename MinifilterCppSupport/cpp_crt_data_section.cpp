#include "cpp_crt_data_section.hpp"

#pragma section(".CRT$XCA")
PVFV __crtXca[] = { nullptr };

#pragma section(".CRT$XCZ")
PVFV __crtXcz[] = { nullptr };

#pragma data_seg()
#pragma comment(linker, "/merge:.CRT=.rdata")