#pragma once

#include <crutch/test/test_suite.hpp>

namespace crutch {

class TestSuiteRegistrar {
 public:
  explicit TestSuiteRegistrar(TestSuite* suite) noexcept;
};

}  // namespace crutch