#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
Type* Construct(RawPtr pointer, ArgTypes&&... args);

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
void ConstructAt(Type* place, ArgTypes&&... args);

template <typename Type>
void DestroyAt(Type* place) noexcept;

}  // namespace crutch

#define PLACEMENT_IMPL
#include <crutch/memory/placement.ipp>
#undef PLACEMENT_IMPL