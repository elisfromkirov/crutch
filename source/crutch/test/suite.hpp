#pragma once

#include <crutch/memory/unique_ptr.hpp>

#include <crutch/test/reporter.hpp>
#include <crutch/test/test.hpp>

#include <vector>

namespace crutch {

class TestSuite {
 public:
  explicit TestSuite(const char* name) noexcept;

  [[nodiscard]]
  StringView Name() const noexcept;

  [[nodiscard]]
  SizeType NumberOfTests() const noexcept;

  void RegisterTest(ITest* test) noexcept;

  void RunAllTests(ITestReporter& reporter) noexcept;

 private:
  StringView name_;
  ::std::vector<UniquePtr<ITest>> tests_;
};

}  // namespace crutch