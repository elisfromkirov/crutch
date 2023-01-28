#pragma once

#include <memory>

namespace crutch {

template <typename Type>
Type* AddressOf(Type& value);

template <typename Type>
const Type* AddressOf(const Type& value);

}  // namespace crutch

#define ADDRESS_IMPL
#include <crutch/allocator/core/address.ipp>
#undef ADDRESS_IMPL