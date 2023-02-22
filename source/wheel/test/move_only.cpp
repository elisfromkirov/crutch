#include <wheel/test/move_only.hpp>

namespace wheel {

MoveOnly::MoveOnly(int value) noexcept
    : value{value} {
}

}  // namespace wheel