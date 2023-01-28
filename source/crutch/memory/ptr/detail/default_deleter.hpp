#pragma once

namespace crutch {

namespace detail {

template <typename Type>
struct DefaultDeleter {
 public:
  static void Delete(Type* pointer) noexcept;
};

}  // namespace detail

}  // namespace crutch

#define DEFAULT_DELETER_IMPL
#include "default_deleter.ipp"
#undef DEFAULT_DELETER_IMPL