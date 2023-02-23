#pragma once

#include <wheels/ptr/unique_ptr.hpp>

#include <wheels/test/test.hpp>
#include <wheels/test/test_reporter.hpp>

#include <wheels/vector/vector.hpp>

namespace wheels {

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

}  // namespace wheels