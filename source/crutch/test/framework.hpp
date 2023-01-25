#pragma once

#include <crutch/core/macros.hpp>

#include <crutch/test/assertion_failure.hpp>
#include <crutch/test/console_reporter.hpp>
#include <crutch/test/test.hpp>
#include <crutch/test/test_engine.hpp>
#include <crutch/test/test_registrar.hpp>
#include <crutch/test/test_suite.hpp>


#define ASSERT_EXPRESSION(expression)                                \
  if (!(expression)) {                                               \
    throw ::crutch::AssertionFailure(TO_STRING(expression), HERE()); \
  }

#define ASSERT_EQ(x, y) \
  ASSERT_EXPRESSION((x) == (y))

#define ASSERT_NE(x, y) \
  ASSERT_EXPRESSION((x) != (y))

#define ASSERT_LT(x, y) \
  ASSERT_EXPRESSION((x) < (y))

#define ASSERT_LE(x, y) \
  ASSERT_EXPRESSION((x) <= (y))

#define ASSERT_GT(x, y) \
  ASSERT_EXPRESSION((x) > (y))

#define ASSERT_GE(x, y) \
  ASSERT_EXPRESSION((x) >= (y))

#define TEST_SUITE_IMPL(test_suite_namespace, name)                                            \
  namespace test_suite_namespace {                                                             \
    static ::crutch::TestSuite& kSuite = ::crutch::TestEngine::Instance().MakeTestSuite(name); \
  }                                                                                            \
                                                                                               \
  namespace test_suite_namespace

#define TEST_SUITE(name) \
  TEST_SUITE_IMPL(CONCAT(TestSuite, name), TO_STRING(name))

#define TEST_IMPL(TestRoutine, Test, name, kTestRegistrar)     \
  void TestRoutine();                                          \
                                                               \
  class Test : public ::crutch::ITest {                        \
   public:                                                     \
    ::crutch::StringView Name() const noexcept override {      \
      return ::crutch::StringView{name};                       \
    }                                                          \
                                                               \
    ::crutch::StringView Suite() const noexcept override {     \
      return kSuite.Name();                                    \
    }                                                          \
                                                               \
    void Run() override {                                      \
      TestRoutine();                                           \
    }                                                          \
  };                                                           \
                                                               \
  static ::crutch::TestRegistrar<Test> kTestRegistrar{kSuite}; \
                                                               \
  void TestRoutine()

#define TEST(name)                                                          \
  TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), TO_STRING(name), \
            CONCAT(kTestRegistrar, name))

#define RUN_ALL_TESTS()                                             \
  int main() {                                                      \
    ::crutch::ConsoleReporter console_reporter{};                   \
    ::crutch::TestEngine::Instance().RunAllTests(console_reporter); \
    return 0;                                                       \
  }