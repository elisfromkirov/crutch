#pragma once

#include <crutch/concept/constructible.hpp>
#include <crutch/concept/deleter_for.hpp>
#include <crutch/concept/derived_from.hpp>

#include <crutch/core/core.hpp>

#include <crutch/ptr/detail/default_deleter.hpp>
#include <crutch/ptr/detail/unique_ptr_base.hpp>

namespace crutch {

template <typename Type, DeleterFor<Type> Deleter = detail::DefaultDeleter<Type>>
class UniquePtr final : private detail::UniquePtrBase<Type, Deleter> {
 public:
  explicit UniquePtr(Type* pointer, const Deleter& deleter = Deleter()) noexcept;

  template <DerivedFrom<Type> DerivedType, DeleterFor<DerivedType> DerivedTypeDeleter>
  UniquePtr(UniquePtr<DerivedType, DerivedTypeDeleter>&& other, const Deleter& = Deleter()) noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;

  Type* Get() const noexcept;

  void Release() noexcept;

  void Swap(UniquePtr& other) noexcept;
};

}  // namespace crutch

#define UNIQUE_PTR_IMPL
#include <crutch/ptr/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL