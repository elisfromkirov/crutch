#pragma once

#include <crutch/concept/derived_from.hpp>

#include <crutch/test/test_suite.hpp>
#include <crutch/test/test.hpp>

namespace crutch {

template <typename TestType>
requires DerivedFrom<TestType, ITest>
class TestRegistrar {
 public:
  explicit TestRegistrar(TestSuite& suite) noexcept;
};

}  // namespace crutch

#define REGISTRAR_IMPL
#include <crutch/test/test_registrar.ipp>
#undef REGISTRAR_IMPL