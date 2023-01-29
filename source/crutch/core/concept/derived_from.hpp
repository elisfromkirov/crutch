#pragma once

#include <type_traits>

namespace crutch {

template <typename DerivedType, typename BaseType>
concept DerivedFrom = ::std::is_base_of_v<BaseType, DerivedType>;

}  // namespace crutch