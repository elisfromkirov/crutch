#pragma once

#include <wheel/test/test_suite.hpp>

namespace wheel {

class TestSuiteRegistrar {
 public:
  explicit TestSuiteRegistrar(TestSuite* suite) noexcept;
};

}  // namespace wheel