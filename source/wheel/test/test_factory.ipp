#ifndef REGISTRAR_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <DerivedFrom<ITest> TestType>
TestFactory<TestType>::TestFactory(TestSuite& suite) noexcept {
  suite.RegisterTest(MakeUniquePtr<TestType>());
}

}  // namespace wheel