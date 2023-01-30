#ifndef REGISTRAR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <DerivedFrom<ITest> TestType>
TestFactory<TestType>::TestFactory(TestSuite& suite) noexcept {
  suite.RegisterTest(MakeUniquePtr<TestType>());
}

}  // namespace crutch