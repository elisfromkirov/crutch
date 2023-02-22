#include <wheel/test/test_framework.hpp>

struct ComplexArgument {
  ComplexArgument(const wheel::CopyOnly& copy_only, wheel::MoveOnly&& move_only);

  wheel::CopyOnly copy_only;
  wheel::MoveOnly move_only;
};