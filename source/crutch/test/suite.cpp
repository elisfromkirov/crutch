#include <crutch/test/assertion_failure.hpp>
#include <crutch/test/suite.hpp>

namespace crutch {

TestSuite::TestSuite(const char* name) noexcept
    : name_{name} {
}

StringView TestSuite::Name() const noexcept {
  return name_;
}

SizeType TestSuite::NumberOfTests() const noexcept {
  return tests_.size();
}

void TestSuite::RegisterTest(ITest* test) noexcept {
  ASSERT(test != nullptr, "test must be a valid pointer");

  tests_.emplace_back(test);
}

void TestSuite::RunAllTests(ITestReporter& reporter) noexcept {
  reporter.TestSuiteStarted(*this);
  for (const auto& test : tests_) {
    reporter.TestStarted(*test);
    try {
      test->Run();
      reporter.TestPassed(*test);
    } catch (const AssertionFailure& assertion_failure) {
      reporter.AssertionFailureOccurred(*test, assertion_failure);
    } catch (std::exception& exception) {
      reporter.UnhandledExceptionThrown(*test, exception);
    } catch (...) {
      reporter.UnhandledUnknownExceptionThrown(*test);
    }
  }
  reporter.TestSuiteFinished(*this);
}

}  // namespace crutch