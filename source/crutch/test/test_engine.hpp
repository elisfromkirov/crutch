#pragma once

#include <crutch/core/core.hpp>

#include <crutch/test/test_reporter.hpp>
#include <crutch/test/test_suite.hpp>

#include <crutch/vector/vector.hpp>

namespace crutch {

class TestEngine {
 public:
  static TestEngine& Instance() noexcept;

 public:
  void RegisterSuite(TestSuite* suite);

  void RunAllSuites(ITestReporter& reporter) noexcept;

 private:
  Vector<TestSuite*> suites_;
};

}  // namespace crutch