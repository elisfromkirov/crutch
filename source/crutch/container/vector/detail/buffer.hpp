#pragma once

#include <crutch/allocator/core/placement.hpp>

#include <crutch/core/concept/constructible.hpp>
#include <crutch/core/concept/copy_constructible.hpp>
#include <crutch/core/concept/move_constructible.hpp>

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class Buffer {
 public:
  Buffer(Type* data, SizeType size, SizeType capacity) noexcept;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes...>
  void ConstructAtEnd(ArgTypes&&... args);

  void DestroyAtEnd() noexcept;

  void DestroyAll() noexcept;

  void CopyToEnd(const Buffer& other) requires CopyConstructible<Type>;

  void MoveToEnd(Buffer&& other) noexcept requires MoveConstructible<Type>;

 protected:
  Type* data_;
  SizeType size_;
  SizeType capacity_;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_IMPL_IMPL
#include <crutch/container/vector/detail/buffer.ipp>
#undef VECTOR_IMPL_IMPL