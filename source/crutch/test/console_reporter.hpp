#pragma once

#include <crutch/test/test_reporter.hpp>

namespace crutch {

class ConsoleReporter : public ITestReporter {
 public:
  void TestSuiteStarted(const TestSuite& test_suite) noexcept override;

  void TestSuiteFinished(const TestSuite& test_suite, SizeType num_passed_tests) noexcept override;

  void TestStarted(const ITest& test) noexcept override;

  void TestPassed(const ITest& test) noexcept override;

  void AssertionFailureOccurred(const ITest& test, const AssertionFailure& assertion_failure) noexcept override;

  void UnhandledExceptionThrown(const ITest& test, const std::exception& exception) noexcept override;

  void UnhandledUnknownExceptionThrown(const ITest& test) noexcept override;

 private:
  StringView suite_name_;
};

}  // namespace crutch