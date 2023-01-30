#include <crutch/allocator/allocator.hpp>

#include <crutch/memory/default.hpp>

namespace crutch {

IAllocator* GetDefaultAllocator() {
  static Allocator default_allocator{};
  return &default_allocator;
}

}  // namespace crutch