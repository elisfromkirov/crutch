#include <wheels/allocator/allocator.hpp>

#include <wheels/memory/default.hpp>

namespace wheels {

IAllocator* GetDefaultAllocator() {
  static Allocator default_allocator{};
  return &default_allocator;
}

}  // namespace wheels