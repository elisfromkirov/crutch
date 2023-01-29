#pragma once

#include <crutch/test/impl/test_suite.hpp>

namespace crutch {

class TestSuiteRegistrar {
 public:
  explicit TestSuiteRegistrar(TestSuite* suite) noexcept;
};

}  // namespace crutch