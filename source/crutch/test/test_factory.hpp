#pragma once

#include <crutch/concept/derived_from.hpp>

#include <crutch/ptr/make_unique_ptr.hpp>

#include <crutch/test/test_suite.hpp>
#include <crutch/test/test.hpp>

namespace crutch {

template <DerivedFrom<ITest> TestType>
class TestFactory {
 public:
  explicit TestFactory(TestSuite& suite) noexcept;
};

}  // namespace crutch

#define REGISTRAR_IMPL
#include <crutch/test/test_factory.ipp>
#undef REGISTRAR_IMPL