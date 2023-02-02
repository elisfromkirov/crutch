#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/placement.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class VectorBase {
 public:
  VectorBase(SizeType capacity, IAllocator* allocator);

  VectorBase(VectorBase&& other) noexcept;
  VectorBase& operator=(VectorBase&& other) noexcept;

 protected:
  ~VectorBase() noexcept;

  void Swap(VectorBase& other) noexcept;

  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  void ConstructAtEnd(Arguments&&... arguments);

  void DestroyAtEnd() noexcept;

 protected:
  Type* data_;
  SizeType size_;
  SizeType capacity_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_BASE_IMPL
#include <crutch/vector/detail/vector_base.ipp>
#undef VECTOR_BASE_IMPL