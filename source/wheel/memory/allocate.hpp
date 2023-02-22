#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>
#include <wheel/memory/raw_ptr.hpp>

namespace wheel {

template <typename Type>
RawPtr<Type> Allocate(IAllocator* allocator);

}  // namespace wheel

#define ALLOCATE_IMPL
#include <wheel/memory/allocate.ipp>
#undef ALLOCATE_IMPL