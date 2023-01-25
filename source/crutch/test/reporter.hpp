#pragma once

#include <crutch/test/test.hpp>

#include <crutch/utiltiy/assertion_failure.hpp>

#include <exception>

namespace crutch {

class ITestReporter {
 public:
  virtual ~ITestReporter() noexcept = default;

  virtual void TestStarted(const ITest& test) noexcept = 0;

  virtual void TestPassed(const ITest& test) noexcept = 0;

  virtual void AssertionFailureOccurred(const AssertionFailure& assertion_failure) noexcept = 0;

  virtual void UnhandledExceptionThrown(const std::exception& exception) noexcept = 0;

  virtual void UnhandledUnknownExceptionThrown() noexcept = 0;
};

}  // namespace crutch