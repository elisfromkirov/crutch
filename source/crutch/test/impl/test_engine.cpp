#include <crutch/test/impl/test_engine.hpp>

namespace crutch {

TestEngine& TestEngine::Instance() noexcept {
  static TestEngine test_engine{};
  return test_engine;
}

void TestEngine::RegisterSuite(TestSuite* suite) {
  ASSERT(suite != nullptr, "suite must be a valid pointer");

  suites_.emplace_back(suite);
}

void TestEngine::RunAllSuites(ITestReporter& reporter) noexcept {
  for (auto& suite : suites_) {
    suite->RunAllTests(reporter);
  }
}

}  // namespace crutch