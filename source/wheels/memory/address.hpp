#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
Type* AddressOf(Type& value);

template <typename Type>
const Type* AddressOf(const Type& value);

}  // namespace wheels

#define ADDRESS_IMPL
#include <wheels/memory/address.ipp>
#undef ADDRESS_IMPL