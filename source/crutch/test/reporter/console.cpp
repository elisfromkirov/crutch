#include <crutch/test/impl/assertion_failure.hpp>
#include <crutch/test/impl/test.hpp>
#include <crutch/test/impl/test_suite.hpp>

#include <crutch/test/reporter/console.hpp>

#include <iostream>

namespace crutch {

void ConsoleReporter::TestSuiteStarted(const TestSuite& test_suite) noexcept {
  std::cout << "[----------] Running " << test_suite.NumTests() << " tests from suite "
            << test_suite.Name().Data() << std::endl;
}

void ConsoleReporter::TestSuiteFinished(const TestSuite& test_suite) noexcept {
  std::cout << "[----------]" << std::endl;
}

void ConsoleReporter::TestStarted(const ITest& test) noexcept {
  std::cout << "[ RUN      ] " << test.Name().Data() << std::endl;
}

void ConsoleReporter::TestPassed(const ITest& test) noexcept {
  std::cout << "[     PASS ] " << test.Name().Data() << std::endl;
  std::cout << "[     NOTE ] Elapsed time" << std::endl;
}

void ConsoleReporter::AssertionFailureOccurred(const ITest& test,
                                               const AssertionFailure& assertion_failure) noexcept {
  std::cout << "[     FAIL ] " << test.Name().Data() << " because assertion failure occurred"
            << std::endl;
  std::cout << "[     NOTE ] Assertion failure: " << assertion_failure.Expression().Data() << " in "
            << assertion_failure.Location().File() << ":"
            << assertion_failure.Location().Line() << std::endl;
}

void ConsoleReporter::UnhandledExceptionThrown(const ITest& test,
                                               const std::exception& exception) noexcept {
  std::cout << "[     FAIL ] " << test.Name().Data() << "because unhandled exception thrown"
            << std::endl;
  std::cout << "[     NOTE ] What: " << exception.what() << std::endl;
}


void ConsoleReporter::UnhandledUnknownExceptionThrown(const ITest& test) noexcept {
  std::cout << "[     FAIL ] " << test.Name().Data() << "because unhandled unknown exception thrown"
            << std::endl;
  std::cout << "[     NOTE ]" << std::endl;
}

}  // namespace crutch