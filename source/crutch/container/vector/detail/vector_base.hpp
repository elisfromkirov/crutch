#pragma once

#include <crutch/allocator/core/alignment.hpp>
#include <crutch/allocator/core/allocator.hpp>

#include <crutch/core/concept/copy_constructible.hpp>
#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

#include <crutch/container/vector/detail/buffer.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class VectorBase : protected Buffer<Type> {
 public:
  VectorBase(IAllocator* allocator, SizeType capacity);

  VectorBase(const VectorBase& other) requires CopyConstructible<Type>;
  VectorBase& operator=(const VectorBase& other) requires CopyConstructible<Type>;

  VectorBase(VectorBase&& other) noexcept;
  VectorBase& operator=(VectorBase&& other);

 protected:
  ~VectorBase() noexcept;

 protected:
  void Swap(VectorBase& other) noexcept;

 protected:
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_BASE_IMPL
#include <crutch/container/vector/detail/vector_base.ipp>
#undef VECTOR_BASE_IMPL