#include <wheel/allocator/allocator.hpp>

#include <wheel/memory/default.hpp>

namespace wheel {

IAllocator* GetDefaultAllocator() {
  static Allocator default_allocator{};
  return &default_allocator;
}

}  // namespace wheel