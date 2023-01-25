#pragma once

#include <crutch/concept/deleter_for.hpp>
#include <crutch/concept/is_not_reference.hpp>

namespace crutch {

namespace detail {

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
class UniquePtrBase {
 public:
  explicit UniquePtrBase(Type* pointer) noexcept;

  UniquePtrBase(const UniquePtrBase& other) = delete;
  UniquePtrBase& operator=(const UniquePtrBase& other) = delete;

  UniquePtrBase(UniquePtrBase&& other) noexcept;
  UniquePtrBase& operator=(UniquePtrBase&& other) noexcept;

 protected:
  ~UniquePtrBase() noexcept;

  void Swap(UniquePtrBase& other) noexcept;

 protected:
  Type* pointer_;
};

}  // namespace detail

}  // namespace crutch

#define UNIQUE_PTR_BASE_IMPL
#include <crutch/memory/detail/unique_ptr_base.ipp>
#undef UNIQUE_PTR_BASE_IMPL