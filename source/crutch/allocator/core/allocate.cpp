#include <crutch/allocator/core/allocate.hpp>

namespace crutch {

RawPtr Allocate(IAllocator* allocator, SizeType bytes, SizeType alignment) {
  return RawPtr{allocator->Allocate(bytes, alignment), allocator, bytes, alignment};
}

}  // namespace crutch