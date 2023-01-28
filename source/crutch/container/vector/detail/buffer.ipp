#ifndef VECTOR_IMPL_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
Buffer<Type>::Buffer(Type* data, SizeType size, SizeType capacity) noexcept
    : data_{data},
      size_{size},
      capacity_{capacity} {
}

template <typename Type>
template <typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void Buffer<Type>::ConstructAtEnd(ArgTypes&&... args) {
  ConstructAt(data_ + size_, ::std::forward<ArgTypes>(args)...);
  size_++;
}

template <typename Type>
void Buffer<Type>::DestroyAtEnd() noexcept {
  size_--;
  DestroyAt(data_ + size_);
}

template <typename Type>
void Buffer<Type>::DestroyAll() noexcept {
  while (size_ != 0) {
    DestroyAtEnd();
  }
}

template <typename Type>
void Buffer<Type>::CopyToEnd(const Buffer& other) requires CopyConstructible<Type> {
  for (SizeType i = 0; i < other.size_; ++i) {
    ConstructAtEnd(other.data_[i]);
  }
}

template <typename Type>
void Buffer<Type>::MoveToEnd(Buffer&& other) noexcept requires MoveConstructible<Type> {
  for (SizeType i = 0; i < other.size_; ++i) {
    ConstructAtEnd(::std::move(other.data_[i]));
  }
}

}  // namespace detail

}  // namespace crutch