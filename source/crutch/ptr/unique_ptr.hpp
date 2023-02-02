#pragma once

#include <crutch/concept/constructible.hpp>
#include <crutch/concept/deleter_for.hpp>
#include <crutch/concept/derived_from.hpp>

#include <crutch/core/core.hpp>

#include <crutch/ptr/detail/default_deleter.hpp>
#include <crutch/ptr/detail/unique_ptr_base.hpp>

#include <memory>

namespace crutch {

template <typename Type, DeleterFor<Type> Deleter = detail::DefaultDeleter<Type>>
class UniquePtr final : private detail::UniquePtrBase<Type, Deleter> {
  template <typename OtherType, DeleterFor<OtherType> OtherDeleter>
  friend class UniquePtr;

 public:
  explicit UniquePtr(Type* pointer, Deleter&& deleter = Deleter()) noexcept;

  template <DerivedFrom<Type> OtherType, DeleterFor<OtherType> OtherDeleter>
  requires Constructible<Deleter, OtherDeleter&&>
  UniquePtr(UniquePtr<OtherType, OtherDeleter>&& other) noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;

  Type* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace crutch

#define UNIQUE_PTR_IMPL
#include <crutch/ptr/unique_ptr.ipp>
#undef UNIQUE_PTR_IMPL