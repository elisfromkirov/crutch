#pragma once

#include <wheel/core/core.hpp>

#include <wheel/test/test_reporter.hpp>
#include <wheel/test/test_suite.hpp>

#include <wheel/vector/vector.hpp>

namespace wheel {

class TestEngine {
 public:
  static TestEngine& Instance() noexcept;

 public:
  void RegisterSuite(TestSuite* suite);

  void RunAllSuites(ITestReporter& reporter) noexcept;

 private:
  Vector<TestSuite*> suites_;
};

}  // namespace wheel