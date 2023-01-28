#pragma once

#include <crutch/test/test_reporter.hpp>
#include <crutch/test/test_suite.hpp>

#include <list>

namespace crutch {

class TestEngine {
 public:
  static TestEngine& Instance() noexcept;

 public:
  TestSuite& MakeTestSuite(const char* name) noexcept;

  void RunAllTests(ITestReporter& reporter) noexcept;

 private:
  ::std::list<TestSuite> suites_;
};

}  // namespace crutch