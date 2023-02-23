#pragma once

#include <wheels/concept/constructible.hpp>
#include <wheels/concept/deleter_for.hpp>
#include <wheels/concept/derived_from.hpp>

#include <wheels/core/core.hpp>

#include <wheels/ptr/detail/default_deleter.hpp>
#include <wheels/ptr/detail/unique_ptr_base.hpp>

namespace wheels {

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

}  // namespace wheels

#define UNIQUE_PTR_IMPL
#include <wheels/ptr/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL