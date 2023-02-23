#pragma once

#include <wheels/concept/deleter_for.hpp>

#include <wheels/core/core.hpp>

namespace wheels {

namespace detail {

template <typename Type, DeleterFor<Type> Deleter>
class UniquePtrBase : private Deleter {
 public:
  UniquePtrBase(Type* pointer, const Deleter& deleter) noexcept;

  UniquePtrBase(const UniquePtrBase& other) = delete;
  UniquePtrBase& operator=(const UniquePtrBase& other) = delete;

  UniquePtrBase(UniquePtrBase&& other) noexcept;
  UniquePtrBase& operator=(UniquePtrBase&& other) noexcept;

 protected:
  ~UniquePtrBase() noexcept;

  void Swap(UniquePtrBase& other) noexcept;

  Deleter& GetDeleter() noexcept;

 protected:
  Type* pointer_;
};

}  // namespace detail

}  // namespace wheels

#define UNIQUE_PTR_BASE_IMPL
#include <wheels/ptr/detail/unique_ptr_base.ipp>
#undef UNIQUE_PTR_BASE_IMPL