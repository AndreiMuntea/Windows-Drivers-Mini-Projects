#ifndef __CPP_NONPAGED_OBJECT_HPP__ 
#define __CPP_NONPAGED_OBJECT_HPP__ 

#include "cpp_object.hpp"

template <typename ULONG Tag>
class CppNonPagedObject : public CppObject<NonPagedPool, Tag>
{
};


#endif //__CPP_NONPAGED_OBJECT_HPP__