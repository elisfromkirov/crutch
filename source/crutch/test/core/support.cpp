#include <crutch/test/core/support.hpp>

namespace crutch {

CopyOnly::CopyOnly(int value) noexcept
    : value{value} {
}

MoveOnly::MoveOnly(int value) noexcept
    : value{value} {
}

Complex::Complex(CopyOnly copy_only, MoveOnly move_only) noexcept
    : value{copy_only.value + move_only.value} {
}

}  // namespace crutch