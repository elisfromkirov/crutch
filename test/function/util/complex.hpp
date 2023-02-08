#include <crutch/test/test_framework.hpp>

struct ComplexArgument {
  ComplexArgument(const crutch::CopyOnly& copy_only, crutch::MoveOnly&& move_only);

  crutch::CopyOnly copy_only;
  crutch::MoveOnly move_only;
};