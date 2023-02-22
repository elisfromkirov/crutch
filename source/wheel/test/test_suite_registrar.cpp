#include <wheel/test/test_suite_registrar.hpp>
#include <wheel/test/test_engine.hpp>

namespace wheel {

TestSuiteRegistrar::TestSuiteRegistrar(TestSuite* suite) noexcept {
  TestEngine::Instance().RegisterSuite(suite);
}

}  // namespace wheel