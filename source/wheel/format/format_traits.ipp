#ifndef FORMAT_TRAITS_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <typename Type>
void FormatTraits<Type>::Format(StringBuilder& builder, const Type& value) {
  builder.PushBack(value);
}

}  // namespace wheel
