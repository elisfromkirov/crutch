#pragma once

#include <wheels/test/test_suite.hpp>

namespace wheels {

class TestSuiteRegistrar {
 public:
  explicit TestSuiteRegistrar(TestSuite* suite) noexcept;
};

}  // namespace wheels