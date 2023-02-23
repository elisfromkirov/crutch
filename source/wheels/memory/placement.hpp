#pragma once

#include <wheels/concept/constructible.hpp>

#include <wheels/core/core.hpp>

#include <wheels/memory/raw_ptr.hpp>

namespace wheels {

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

}  // namespace wheels

#define PLACEMENT_IMPL
#include <wheels/memory/placement.ipp>
#undef PLACEMENT_IMPL