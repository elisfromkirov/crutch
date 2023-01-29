#pragma once

#include <crutch/core/concept/derived_from.hpp>

#include <crutch/test/impl/test_suite.hpp>
#include <crutch/test/impl/test.hpp>

namespace crutch {

template <DerivedFrom<ITest> TestType>
class TestFactory {
 public:
  explicit TestFactory(TestSuite& suite) noexcept;
};

}  // namespace crutch

#define REGISTRAR_IMPL
#include <crutch/test/impl/test_factory.ipp>
#undef REGISTRAR_IMPL