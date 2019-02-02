#include "cpp_crt_static_class_support.hpp"
#include "cpp_nonpaged_object.hpp"
#include "cpp_allocation_tags.hpp"

typedef struct _CPP_DESTRUCTOR
{
    LIST_ENTRY Entry;
    PVFV       Destructor;
}CPP_DESTRUCTOR, *PCPP_DESTRUCTOR;

static CPP_DESTRUCTOR gDestructorsList;

int
CppRegisterDestructor(
    _In_ PVFV Destructor
)
{
    auto entry = (PCPP_DESTRUCTOR)ExAllocatePoolWithTag(NonPagedPool, sizeof(CPP_DESTRUCTOR), MEM_TAG_CPP);
    if (!entry)
    {
        return -1;
    }

    entry->Destructor = Destructor;
    InsertTailList(&gDestructorsList.Entry, &entry->Entry);

    return 0;
}

void
CppInitializeDestructorsList()
{
    InitializeListHead(&gDestructorsList.Entry);
    gDestructorsList.Destructor = nullptr;
}

void
CppCallAllDestructors()
{
    while (!IsListEmpty(&gDestructorsList.Entry))
    {
        auto destructorEntry = (PCPP_DESTRUCTOR)RemoveHeadList(&gDestructorsList.Entry);
        if (destructorEntry->Destructor)
        {
            destructorEntry->Destructor();
        }
        ExFreePoolWithTag(destructorEntry, MEM_TAG_CPP);
    }
}

void
CppCallAllConstructors(
    _In_ PVFV* FirstPVFVEntry,
    _In_ PVFV* LastPVFVEntry
)
{
    for (auto currentPVFVEntry = FirstPVFVEntry; currentPVFVEntry < LastPVFVEntry; ++currentPVFVEntry)
    {
        if (*currentPVFVEntry)
        {
            (**currentPVFVEntry)();
        }
    }
}

int __cdecl
atexit(
    _In_ PVFV Destructor
)
{
    return CppRegisterDestructor(Destructor);
}