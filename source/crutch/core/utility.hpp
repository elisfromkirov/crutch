#pragma once

#include <new>
#include <type_traits>
#include <utility>

namespace crutch {

template <typename Type, typename... ArgTypes>
void ConstructAt(Type* place, ArgTypes&&... args);

template <typename Type>
void DestroyAt(Type* place) noexcept;

}  // namespace crutch

#define UTILITY_IMPL
#include <crutch/core/utility.ipp>
#undef UTILITY_IMPL