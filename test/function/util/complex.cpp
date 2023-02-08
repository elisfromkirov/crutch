#include <function/util/complex.hpp>

ComplexArgument::ComplexArgument(const crutch::CopyOnly& copy_only, crutch::MoveOnly&& move_only)
    : copy_only{copy_only},
      move_only{std::move(move_only)} {
}