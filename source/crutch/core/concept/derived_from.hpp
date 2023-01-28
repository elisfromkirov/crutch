#pragma once

#include <type_traits>

namespace crutch {

template <typename BaseType, typename DerivedType>
concept DerivedFrom = ::std::is_base_of_v<BaseType, DerivedType>;

}  // namespace crutch