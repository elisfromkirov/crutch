#pragma once

#include <crutch/ptr/unique_ptr.hpp>

#include <crutch/test/test.hpp>
#include <crutch/test/test_reporter.hpp>

#include <crutch/vector/vector.hpp>

namespace crutch {

class TestSuite {
 public:
  explicit TestSuite(const char* name) noexcept;

  [[nodiscard]]
  StringView Name() const noexcept;

  [[nodiscard]]
  SizeType NumTests() const noexcept;

  void RegisterTest(UniquePtr<ITest> test) noexcept;

  void RunAllTests(ITestReporter& reporter) noexcept;

 private:
  StringView name_;
  Vector<UniquePtr<ITest>> tests_;
};

}  // namespace crutch