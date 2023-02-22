#pragma once

#include <wheel/ptr/unique_ptr.hpp>

#include <wheel/test/test.hpp>
#include <wheel/test/test_reporter.hpp>

#include <wheel/vector/vector.hpp>

namespace wheel {

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

}  // namespace wheel