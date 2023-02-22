#include <function/util/complex.hpp>

ComplexArgument::ComplexArgument(const wheel::CopyOnly& copy_only, wheel::MoveOnly&& move_only)
    : copy_only{copy_only},
      move_only{std::move(move_only)} {
}