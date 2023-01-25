#include <crutch/test/suite.hpp>

namespace crutch {

TestSuite::TestSuite(const char* name) noexcept
    : name_{name} {
}

StringView TestSuite::Name() const noexcept {
  return name_;
}

void TestSuite::RegisterTest(ITest* test) noexcept {
  ASSERT(test != nullptr, "test must be a valid pointer");

  tests_.emplace_back(test);
}

void TestSuite::RunAllTests(ITestReporter& reporter) noexcept {
  for (const auto& test : tests_) {
    reporter.TestStarted(*test);
    try {
      test->Run();
      reporter.TestPassed(*test);
    } catch (const AssertionFailure& assertion_failure) {
      reporter.AssertionFailureOccurred(assertion_failure);
    } catch (std::exception& exception) {
      reporter.UnhandledExceptionThrown(exception);
    } catch (...) {
      reporter.UnhandledUnknownExceptionThrown();
    }
  }
}

}  // namespace crutch