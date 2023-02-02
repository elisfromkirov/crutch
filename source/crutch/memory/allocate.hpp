#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

template <typename Type>
RawPtr<Type> Allocate(IAllocator* allocator);

}  // namespace crutch

#define ALLOCATE_IMPL
#include <crutch/memory/allocate.ipp>
#undef ALLOCATE_IMPL