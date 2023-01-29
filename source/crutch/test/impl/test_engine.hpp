#pragma once

#include <crutch/core/macro/assert.hpp>

#include <crutch/test/impl/test_reporter.hpp>
#include <crutch/test/impl/test_suite.hpp>

#include <vector>

namespace crutch {

class TestEngine {
 public:
  static TestEngine& Instance() noexcept;

 public:
  void RegisterSuite(TestSuite* suite);

  void RunAllSuites(ITestReporter& reporter) noexcept;

 private:
  ::std::vector<TestSuite*> suites_;
};

}  // namespace crutch