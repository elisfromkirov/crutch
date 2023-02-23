#include <wheels/test/test_suite_registrar.hpp>
#include <wheels/test/test_engine.hpp>

namespace wheels {

TestSuiteRegistrar::TestSuiteRegistrar(TestSuite* suite) noexcept {
  TestEngine::Instance().RegisterSuite(suite);
}

}  // namespace wheels