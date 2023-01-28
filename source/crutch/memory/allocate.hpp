#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

RawPtr Allocate(IAllocator* allocator, SizeType bytes, SizeType alignment = MaxAlignment);

}  // namespace crutch