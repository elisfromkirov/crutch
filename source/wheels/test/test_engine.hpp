#pragma once

#include <wheels/core/core.hpp>

#include <wheels/test/test_reporter.hpp>
#include <wheels/test/test_suite.hpp>

#include <wheels/vector/vector.hpp>

namespace wheels {

class TestEngine {
 public:
  static TestEngine& Instance() noexcept;

 public:
  void RegisterSuite(TestSuite* suite);

  void RunAllSuites(ITestReporter& reporter) noexcept;

 private:
  Vector<TestSuite*> suites_;
};

}  // namespace wheels