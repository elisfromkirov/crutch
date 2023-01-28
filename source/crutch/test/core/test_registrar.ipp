#ifndef REGISTRAR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename TestType>
requires DerivedFrom<TestType, ITest>
TestRegistrar<TestType>::TestRegistrar(TestSuite& suite) noexcept {
  suite.RegisterTest(new(std::nothrow) TestType());
}

}  // namespace crutch