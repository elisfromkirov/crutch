#ifndef FORMAT_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type, typename... Types>
String Format(StringBuilder& builder, const char* format, const Types&... values) {
  return detail::Formatter<Types...>::Format(builder, format, values...);
}

template <typename... Types>
String Format(const char* format, const Types&... values) {
   StringBuilder builder{};
   return detail::Formatter<Types...>::Format(builder, format, values...);
}

}  // namespace wheels