#pragma once

#include <wheel/concept/constructible.hpp>
#include <wheel/concept/deleter_for.hpp>
#include <wheel/concept/derived_from.hpp>

#include <wheel/core/core.hpp>

#include <wheel/ptr/detail/default_deleter.hpp>
#include <wheel/ptr/detail/unique_ptr_base.hpp>

namespace wheel {

template <typename Type, DeleterFor<Type> Deleter = detail::DefaultDeleter<Type>>
class UniquePtr final : private detail::UniquePtrBase<Type, Deleter> {
 public:
  explicit UniquePtr(Type* pointer, const Deleter& deleter = Deleter()) noexcept;

  template <DerivedFrom<Type> DerivedType, DeleterFor<DerivedType> DerivedTypeDeleter>
  UniquePtr(UniquePtr<DerivedType, DerivedTypeDeleter>&& other, const Deleter& deleter = Deleter()) noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;

  Type* Get() const noexcept;

  void Release() noexcept;

  void Swap(UniquePtr& other) noexcept;
};

}  // namespace wheel

#define UNIQUE_PTR_IMPL
#include <wheel/ptr/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL