#include <wheels/test/copy_only.hpp>

namespace wheels {

CopyOnly::CopyOnly(int value) noexcept
    : value{value} {
}

}  // namespace wheels