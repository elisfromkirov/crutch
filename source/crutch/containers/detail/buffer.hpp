#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>
#include <crutch/core/utility.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class Buffer {
 public:
  Buffer(Type* data, SizeType size, SizeType capacity) noexcept;

  template <typename... ArgTypes>
  void ConstructAtEnd(ArgTypes&&... args);

  void DestroyAtEnd() noexcept;

  void DestroyAll() noexcept;

  void CopyToEnd(const Buffer& other);

  void MoveToEnd(Buffer&& other) noexcept;

 protected:
  Type* data_;
  SizeType size_;
  SizeType capacity_;
};

}  // namespace detail

}  // namespace crutch

#define VECTOR_IMPL_IMPL
#include <crutch/containers/detail/buffer.ipp>
#undef VECTOR_IMPL_IMPL