#pragma once

#include <crutch/memory/ptr/unique_ptr.hpp>

#include <crutch/test/impl/test.hpp>
#include <crutch/test/impl/test_reporter.hpp>

#include <vector>

namespace crutch {

class TestSuite {
 public:
  explicit TestSuite(const char* name) noexcept;

  [[nodiscard]]
  StringView Name() const noexcept;

  [[nodiscard]]
  SizeType NumTests() const noexcept;

  void RegisterTest(ITest* test) noexcept;

  void RunAllTests(ITestReporter& reporter) noexcept;

 private:
  StringView name_;
  ::std::vector<UniquePtr<ITest>> tests_;
};

}  // namespace crutch