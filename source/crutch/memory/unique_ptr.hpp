#pragma once

#include <crutch/concept/deleter_for.hpp>
#include <crutch/concept/is_not_reference.hpp>

#include <crutch/memory/detail/default_deleter.hpp>
#include <crutch/memory/detail/unique_ptr_base.hpp>

namespace crutch {

template <typename Type, typename Deleter = detail::DefaultDeleter<Type>>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
class UniquePtr final : private detail::UniquePtrBase<Type, Deleter> {
 public:
  explicit UniquePtr(Type* pointer) noexcept;

  Type* Get() const noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;
};

}  // namespace crutch

#define UNIQUE_PTR_IMPL
#include <crutch/memory/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL