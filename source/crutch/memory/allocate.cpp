#include <crutch/memory/allocate.hpp>

namespace crutch {

RawPtr Allocate(IAllocator* allocator, SizeType bytes, SizeType alignment) {
  return RawPtr{allocator->Allocate(bytes, alignment), allocator, bytes, alignment};
}

}  // namespace crutch