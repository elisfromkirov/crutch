#include <crutch/test/move_only.hpp>

namespace crutch {

MoveOnly::MoveOnly(int value) noexcept
    : value{value} {
}

}  // namespace crutch