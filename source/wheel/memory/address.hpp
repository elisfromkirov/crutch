#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

template <typename Type>
Type* AddressOf(Type& value);

template <typename Type>
const Type* AddressOf(const Type& value);

}  // namespace wheel

#define ADDRESS_IMPL
#include <wheel/memory/address.ipp>
#undef ADDRESS_IMPL