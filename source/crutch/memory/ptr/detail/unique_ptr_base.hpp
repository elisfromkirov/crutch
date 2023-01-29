#pragma once

#include <crutch/core/concept/deleter_for.hpp>

#include <utility>

namespace crutch {

namespace detail {

template <typename Type, DeleterFor<Type> Deleter>
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
#include <crutch/memory/ptr/detail/unique_ptr_base.ipp>
#undef UNIQUE_PTR_BASE_IMPL