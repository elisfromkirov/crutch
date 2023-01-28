#include <crutch/allocator/core/default.hpp>

#include <crutch/allocator/impl/allocator.hpp>

namespace crutch {

IAllocator* GetDefaultAllocator() {
  static Allocator default_allocator{};
  return &default_allocator;
}

}  // namespace crutch