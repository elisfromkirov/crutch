#ifndef FORMATTER_IMPL
#error Do not include this file directly
#endif

namespace wheels {

namespace detail {

template <typename Type, typename... Types>
String Formatter<Type, Types...>::Format(StringBuilder& builder, const char* format, const Type& value,
                                         const Types&... values) {
  while (*format != '\0') {
    if (*format == '{') {
      ++format;
      if (*format == '}') {
        ++format;
        FormatTraits<Type>::Format(builder, value);
        return Formatter<Types...>::Format(builder, format, values...);
      }
    } else {
      builder.PushBack(*format);
      ++format;
    }
  }
  return ::std::move(builder).ToString();
};

}  // namespace detail

}  // namespace wheels