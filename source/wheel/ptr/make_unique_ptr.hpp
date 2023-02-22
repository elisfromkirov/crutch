#pragma once

#include <wheel/concept/constructible.hpp>

#include <wheel/core/core.hpp>

#include <wheel/memory/allocate.hpp>
#include <wheel/memory/allocator.hpp>
#include <wheel/memory/default.hpp>
#include <wheel/memory/placement.hpp>

#include <wheel/ptr/unique_ptr.hpp>

#include <wheel/ptr/detail/default_deleter.hpp>

namespace wheel {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
UniquePtr<Type> MakeUniquePtr(Arguments&&... arguments);

}  // namespace wheel

#define MAKE_UNIQUE_PTR_IMPL
#include <wheel/ptr/make_unique_ptr.ipp>
#undef MAKE_UNIQUE_PTR_IMPL