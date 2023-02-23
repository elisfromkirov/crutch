#include <wheels/test/move_only.hpp>

namespace wheels {

MoveOnly::MoveOnly(int value) noexcept
    : value{value} {
}

}  // namespace wheels