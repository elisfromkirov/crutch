#pragma once

#include <wheels/concept/constructible.hpp>

#include <wheels/core/core.hpp>

#include <wheels/memory/allocate.hpp>
#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>
#include <wheels/memory/placement.hpp>

#include <wheels/ptr/unique_ptr.hpp>

#include <wheels/ptr/detail/default_deleter.hpp>

namespace wheels {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
UniquePtr<Type> MakeUniquePtr(Arguments&&... arguments);

}  // namespace wheels

#define MAKE_UNIQUE_PTR_IMPL
#include <wheels/ptr/make_unique_ptr.ipp>
#undef MAKE_UNIQUE_PTR_IMPL