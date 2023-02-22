#include <wheel/macro/abort.hpp>

#include <wheel/test/assertion_failure.hpp>
#include <wheel/test/console_reporter.hpp>
#include <wheel/test/test.hpp>
#include <wheel/test/test_suite.hpp>

#include <cstdio>

/*
Run test <name:blue> from suite <name:blue>
Test <passed:green>
<Note:cyan>: elapsed time <time> seconds

 Run test <name:blue> from suite <name:blue>
 Test <failed:red>
 <Assertion failure: red>: <text> in <source location>

 All tests form suite <name:blue> <passed:blue>
 */

//  Black           30  40
//  Red             31  41
//  Green           32  42
//  Yellow          33  43
//  Blue            34  44
//  Magenta         35  45
//  Cyan            36  46
//  White           37  47

namespace wheel {

void ConsoleReporter::TestSuiteStarted(const TestSuite& test_suite) noexcept {
  suite_name_ = test_suite.Name();
}

void ConsoleReporter::TestSuiteFinished(const TestSuite& test_suite, SizeType num_passed_tests) noexcept {
  if (num_passed_tests != test_suite.NumTests()) {
    ABORT();
  }
}

void ConsoleReporter::TestStarted(const ITest& test) noexcept {
  std::printf("--------------------------------------------------------------------------------\n");
  std::printf("Run test \033[34m%s\033[m from suite \033[34m%s\033[m\n", test.Name().Data(), suite_name_.Data());
}

void ConsoleReporter::TestPassed(const ITest& test) noexcept {
  std::printf("Test \033[34m%s\033[m \033[32mpassed\033[m\n", test.Name().Data());
  std::printf("\033[36mNote:\033[m elapsed time\n\n");
}

void ConsoleReporter::AssertionFailureOccurred(const ITest& test, const AssertionFailure& assertion_failure) noexcept {
  std::printf("Test \033[34m%s\033[m \033[31mfailed\033[m by assertion\n", test.Name().Data());
  std::printf("\033[31mAssertion failure:\033[m %s in %s:%zu\n\n",
              assertion_failure.Expression().Data(),
              assertion_failure.Location().File().Data(),
              assertion_failure.Location().Line());
}

void ConsoleReporter::UnhandledExceptionThrown(const ITest& test, const std::exception& exception) noexcept {
  std::printf("Test \033[34m%s\033[m \033[32mfailed\033[m by exception\n", test.Name().Data());
  std::printf("\033[31mWhat:\033[m %s\n\n", exception.what());
}

void ConsoleReporter::UnhandledUnknownExceptionThrown(const ITest& test) noexcept {
  std::printf("Test \033[34m%s\033[m \033[32mfailed\033[m by unknown exception\n", test.Name().Data());
  std::printf("\033[31mWhat:\033[m ?\n\n");
}

}  // namespace wheel