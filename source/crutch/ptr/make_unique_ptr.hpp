#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/allocate.hpp>
#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>
#include <crutch/memory/placement.hpp>

#include <crutch/ptr/unique_ptr.hpp>

#include <crutch/ptr/detail/default_deleter.hpp>

namespace crutch {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
UniquePtr<Type> MakeUniquePtr(Arguments&&... arguments);

}  // namespace crutch

#define MAKE_UNIQUE_PTR_IMPL
#include <crutch/ptr/make_unique_ptr.ipp>
#undef MAKE_UNIQUE_PTR_IMPL