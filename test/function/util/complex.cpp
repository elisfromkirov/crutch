#include <function/util/complex.hpp>

ComplexArgument::ComplexArgument(const wheels::CopyOnly& copy_only, wheels::MoveOnly&& move_only)
    : copy_only{copy_only},
      move_only{std::move(move_only)} {
}