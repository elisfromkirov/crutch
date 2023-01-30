#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename DerivedType, typename BaseType>
concept DerivedFrom = ::std::is_base_of_v<BaseType, DerivedType>;

}  // namespace crutch