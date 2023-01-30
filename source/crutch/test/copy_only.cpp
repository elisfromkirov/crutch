#include <crutch/test/copy_only.hpp>

namespace crutch {

CopyOnly::CopyOnly(int value) noexcept
    : value{value} {
}

}  // namespace crutch