#ifndef REGISTRAR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <DerivedFrom<ITest> TestType>
TestFactory<TestType>::TestFactory(TestSuite& suite) noexcept {
  suite.RegisterTest(new(std::nothrow) TestType());
}

}  // namespace crutch