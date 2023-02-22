#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

template <typename DerivedType, typename BaseType>
concept DerivedFrom = ::std::is_base_of_v<BaseType, DerivedType>;

}  // namespace wheel