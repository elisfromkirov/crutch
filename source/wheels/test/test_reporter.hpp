#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

class AssertionFailure;
class TestSuite;
class ITest;

}  // namespace wheels

namespace wheels {

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

}  // namespace wheels