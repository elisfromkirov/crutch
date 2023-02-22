#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

class AssertionFailure;
class TestSuite;
class ITest;

}  // namespace wheel

namespace wheel {

class ITestReporter {
 public:
  virtual ~ITestReporter() noexcept = default;

  virtual void TestSuiteStarted(const TestSuite& test_suite) noexcept = 0;

  virtual void TestSuiteFinished(const TestSuite& test_suite, SizeType num_passed_tests) noexcept = 0;

  virtual void TestStarted(const ITest& test) noexcept = 0;

  virtual void TestPassed(const ITest& test) noexcept = 0;

  virtual void AssertionFailureOccurred(const ITest& test, const AssertionFailure& assertion_failure) noexcept = 0;

  virtual void UnhandledExceptionThrown(const ITest& test, const std::exception& exception) noexcept = 0;

  virtual void UnhandledUnknownExceptionThrown(const ITest& test) noexcept = 0;
};

}  // namespace wheel