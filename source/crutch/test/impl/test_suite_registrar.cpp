#include <crutch/test/impl/test_suite_registrar.hpp>
#include <crutch/test/impl/test_engine.hpp>

namespace crutch {

TestSuiteRegistrar::TestSuiteRegistrar(TestSuite* suite) noexcept {
  TestEngine::Instance().RegisterSuite(suite);
}

}  // namespace crutch