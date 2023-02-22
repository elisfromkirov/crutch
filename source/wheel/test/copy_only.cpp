#include <wheel/test/copy_only.hpp>

namespace wheel {

CopyOnly::CopyOnly(int value) noexcept
    : value{value} {
}

}  // namespace wheel