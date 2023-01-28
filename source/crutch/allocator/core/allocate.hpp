#pragma once

#include <crutch/core/type/size.hpp>

#include <crutch/allocator/core/alignment.hpp>
#include <crutch/allocator/core/allocator.hpp>

#include <crutch/memory/raw/raw_ptr.hpp>

namespace crutch {

RawPtr Allocate(IAllocator* allocator, SizeType bytes, SizeType alignment = kMaxAlignment);

}  // namespace crutch