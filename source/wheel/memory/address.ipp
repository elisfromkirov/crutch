#ifndef ADDRESS_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <typename Type>
Type* AddressOf(Type& value) {
  return ::std::addressof(value);
}

template <typename Type>
const Type* AddressOf(const Type& value) {
  return ::std::addressof(value);
}

}  // namespace wheel