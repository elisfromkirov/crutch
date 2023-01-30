#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/aligned_raw_ptr.hpp>

namespace crutch {

AlignedRawPtr AllocateAligned(IAllocator* allocator, SizeType bytes, SizeType alignment);

}  // namespace crutch