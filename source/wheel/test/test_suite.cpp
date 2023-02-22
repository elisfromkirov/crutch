#include <wheel/test/assertion_failure.hpp>
#include <wheel/test/test_suite.hpp>

namespace wheel {

TestSuite::TestSuite(const char* name) noexcept
    : name_{name} {
}

StringView TestSuite::Name() const noexcept {
  return name_;
}

SizeType TestSuite::NumTests() const noexcept {
  return tests_.Size();
}

void TestSuite::RegisterTest(UniquePtr<ITest> test) noexcept {
  tests_.PushBack(::std::move(test));
}

void TestSuite::RunAllTests(ITestReporter& reporter) noexcept {
  SizeType num_passed_tests{0};
  reporter.TestSuiteStarted(*this);
  for (SizeType index = 0; index < tests_.Size(); ++index) {
    auto& test = tests_[index];
    reporter.TestStarted(*test);
    try {
      test->Run();
      reporter.TestPassed(*test);
      num_passed_tests++;
    } catch (const AssertionFailure& assertion_failure) {
      reporter.AssertionFailureOccurred(*test, assertion_failure);
    } catch (const std::exception& exception) {
      reporter.UnhandledExceptionThrown(*test, exception);
    } catch (...) {
      reporter.UnhandledUnknownExceptionThrown(*test);
    }
  }
  reporter.TestSuiteFinished(*this, num_passed_tests);
}

}  // namespace wheel