#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/raw_ptr.hpp>

namespace wheels {

template <typename Type>
RawPtr<Type> Allocate(IAllocator* allocator);

}  // namespace wheels

#define ALLOCATE_IMPL
#include <wheels/memory/allocate.ipp>
#undef ALLOCATE_IMPL