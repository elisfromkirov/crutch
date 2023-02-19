#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
Type* Construct(RawPtr<Type> ptr, Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>);

template <typename Type>
RawPtr<Type> Destroy(Type* object, IAllocator* allocator) noexcept;

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
Type* ConstructAt(Type* ptr, Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>);

template <typename Type>
void DestroyAt(Type* object) noexcept;

}  // namespace crutch

#define PLACEMENT_IMPL
#include <crutch/memory/placement.ipp>
#undef PLACEMENT_IMPL