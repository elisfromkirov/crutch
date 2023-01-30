#pragma once

#include <crutch/concept/deleter_for.hpp>

#include <crutch/core/core.hpp>

namespace crutch {

namespace detail {

template <typename Type, DeleterFor<Type> Deleter>
class UniquePtrBase : private Deleter {
 public:
  UniquePtrBase(Type* pointer, Deleter&& deleter) noexcept;

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

}  // namespace crutch

#define UNIQUE_PTR_BASE_IMPL
#include <crutch/ptr/detail/unique_ptr_base.ipp>
#undef UNIQUE_PTR_BASE_IMPL