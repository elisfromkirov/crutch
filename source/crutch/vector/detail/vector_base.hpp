#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <crutch/vector/detail/buffer.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class VectorBase : public Buffer<Type> {
 public:
  VectorBase(IAllocator* allocator, SizeType capacity);

  VectorBase(const VectorBase& other) requires CopyConstructible<Type>;
  VectorBase& operator=(const VectorBase& other) requires CopyConstructible<Type>;

  VectorBase(VectorBase&& other) noexcept;
  VectorBase& operator=(VectorBase&& other);

  ~VectorBase() noexcept;

 protected:
  void Swap(VectorBase& other) noexcept;

 protected:
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_BASE_IMPL
#include <crutch/vector/detail/vector_base.ipp>
#undef VECTOR_BASE_IMPL