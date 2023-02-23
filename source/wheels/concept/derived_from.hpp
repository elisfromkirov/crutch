#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename DerivedType, typename BaseType>
concept DerivedFrom = ::std::is_base_of_v<BaseType, DerivedType>;

}  // namespace wheels