#pragma once

#include <crutch/core/concept/deleter_for.hpp>

#include <crutch/memory/ptr/detail/default_deleter.hpp>
#include <crutch/memory/ptr/detail/unique_ptr_base.hpp>

namespace crutch {

template <typename Type, DeleterFor<Type> Deleter = detail::DefaultDeleter<Type>>
class UniquePtr final : private detail::UniquePtrBase<Type, Deleter> {
 public:
  explicit UniquePtr(Type* pointer) noexcept;

  Type* Get() const noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;
};

}  // namespace crutch

#define UNIQUE_PTR_IMPL
#include <crutch/memory/ptr/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL