#include <crutch/test/test_engine.hpp>

namespace crutch {

TestEngine& TestEngine::Instance() noexcept {
  static TestEngine test_engine{};
  return test_engine;
}

TestSuite& TestEngine::MakeTestSuite(const char* name) noexcept {
  suites_.emplace_back(name);
  return suites_.back();
}

void TestEngine::RunAllTests(ITestReporter& reporter) noexcept {
  for (auto& suite : suites_) {
    suite.RunAllTests(reporter);
  }
}

}  // namespace crutch