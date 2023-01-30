#include <crutch/memory/allocate.hpp>

namespace crutch {

RawPtr Allocate(IAllocator* allocator, SizeType bytes) {
  return RawPtr{allocator->Allocate(bytes), allocator, bytes};
}

}  // namespace crutch