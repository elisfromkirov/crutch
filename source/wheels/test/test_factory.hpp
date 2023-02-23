#pragma once

#include <wheels/concept/derived_from.hpp>

#include <wheels/ptr/make_unique_ptr.hpp>

#include <wheels/test/test_suite.hpp>
#include <wheels/test/test.hpp>

namespace wheels {

template <DerivedFrom<ITest> TestType>
class TestFactory {
 public:
  explicit TestFactory(TestSuite& suite) noexcept;
};

}  // namespace wheels

#define REGISTRAR_IMPL
#include <wheels/test/test_factory.ipp>
#undef REGISTRAR_IMPL