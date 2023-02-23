#include <wheels/test/test_framework.hpp>

struct ComplexArgument {
  ComplexArgument(const wheels::CopyOnly& copy_only, wheels::MoveOnly&& move_only);

  wheels::CopyOnly copy_only;
  wheels::MoveOnly move_only;
};