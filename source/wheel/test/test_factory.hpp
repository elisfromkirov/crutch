#pragma once

#include <wheel/concept/derived_from.hpp>

#include <wheel/ptr/make_unique_ptr.hpp>

#include <wheel/test/test_suite.hpp>
#include <wheel/test/test.hpp>

namespace wheel {

template <DerivedFrom<ITest> TestType>
class TestFactory {
 public:
  explicit TestFactory(TestSuite& suite) noexcept;
};

}  // namespace wheel

#define REGISTRAR_IMPL
#include <wheel/test/test_factory.ipp>
#undef REGISTRAR_IMPL