#pragma once

#include <wheel/concept/constructible.hpp>

#include <wheel/core/core.hpp>

#include <wheel/memory/raw_ptr.hpp>

namespace wheel {

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

}  // namespace wheel

#define PLACEMENT_IMPL
#include <wheel/memory/placement.ipp>
#undef PLACEMENT_IMPL