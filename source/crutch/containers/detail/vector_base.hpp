#pragma once

#include <crutch/containers/detail/buffer.hpp>

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>
#include <crutch/core/utility.hpp>

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
class VectorBase : protected Allocator,
                   protected Buffer<Type> {
 public:
  VectorBase(SizeType capacity, const Allocator& allocator);

  VectorBase(const VectorBase& other);
  VectorBase& operator=(const VectorBase& other);

  VectorBase(VectorBase&& other) noexcept;
  VectorBase& operator=(VectorBase&& other) noexcept;

 protected:
  ~VectorBase() noexcept;

 protected:
  void Swap(VectorBase& other) noexcept;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_BASE_IMPL
#include <crutch/containers/detail/vector_base.ipp>
#undef VECTOR_BASE_IMPL