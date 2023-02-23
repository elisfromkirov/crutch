#include <wheels/test/test_engine.hpp>

namespace wheels {

TestEngine& TestEngine::Instance() noexcept {
  static TestEngine test_engine{};
  return test_engine;
}

void TestEngine::RegisterSuite(TestSuite* suite) {
  ASSERT(suite != nullptr, "suite must be a valid pointer");

  suites_.PushBack(suite);
}

void TestEngine::RunAllSuites(ITestReporter& reporter) noexcept {
  for (SizeType index = 0; index < suites_.Size(); ++index) {
    suites_[index]->RunAllTests(reporter);
  }
}

}  // namespace wheels