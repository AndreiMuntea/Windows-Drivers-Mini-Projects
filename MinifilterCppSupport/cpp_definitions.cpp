#include "cpp_definitions.hpp"
#include "cpp_allocation_tags.hpp"

void* __cdecl
operator new(
    _In_ size_t Size
)
{
    NT_ASSERTMSG("Global operator new. Please override this!", false);
    return ExAllocatePoolWithTag(PagedPool, Size, MEM_TAG_DEF);
}

void* __cdecl
operator new[](
    _In_ size_t Size
    )
{
    NT_ASSERTMSG("Global operator new[]. Please override this!", false);
    return ExAllocatePoolWithTag(PagedPool, Size, MEM_TAG_DEF);
}

void __cdecl
operator delete(
    _Inout_  PVOID Block
)
{
    NT_ASSERTMSG("Global operator delete. Please override this!", false);
    ExFreePoolWithTag(Block, MEM_TAG_DEF);
}

void __cdecl
operator delete[](
    _Inout_  PVOID Block
)
{
    NT_ASSERTMSG("Global operator delete[]. Please override this!", false);
    ExFreePoolWithTag(Block, MEM_TAG_DEF);
}