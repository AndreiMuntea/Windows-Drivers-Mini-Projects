#ifndef __CPP_PAGED_OBJECT_HPP__ 
#define __CPP_PAGED_OBJECT_HPP__ 

#include "cpp_object.hpp"

template <typename ULONG Tag>
class CppPagedObject : public CppObject<PagedPool, Tag>
{
};


#endif //__CPP_PAGED_OBJECT_HPP__