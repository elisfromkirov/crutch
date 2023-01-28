#pragma once

#include <crutch/core/concept/constructible.hpp>
#include <crutch/core/type/size.hpp>

#include <crutch/memory/raw/raw_ptr.hpp>

#include <new>

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void ConstructAt(RawPtr place, ArgTypes&&... args);

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void ConstructAt(Type* place, ArgTypes&&... args);

template <typename Type>
void DestroyAt(Type* place) noexcept;

}  // namespace crutch

#define PLACEMENT_IMPL
#include <crutch/allocator/core/placement.ipp>
#undef PLACEMENT_IMPL