#include <crutch/memory/allocate_aligned.hpp>

namespace crutch {

AlignedRawPtr AllocateAligned(IAllocator* allocator, SizeType bytes, SizeType alignment) {
  return AlignedRawPtr{allocator->Allocate(bytes, alignment), allocator, bytes, alignment};
}

}  // namespace crutch