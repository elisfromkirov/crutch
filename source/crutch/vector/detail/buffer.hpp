#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/placement.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class Buffer {
 public:
  Buffer(Type* data, SizeType size, SizeType capacity) noexcept;

  template <typename... ArgTypes>
  void ConstructAtEnd(ArgTypes&&... args) requires Constructible<Type, ArgTypes&&...>;

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
#include <crutch/vector/detail/buffer.ipp>
#undef VECTOR_IMPL_IMPL