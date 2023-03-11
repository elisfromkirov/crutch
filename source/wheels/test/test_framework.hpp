#pragma once

#include <wheels/macro/concat.hpp>
#include <wheels/macro/here.hpp>
#include <wheels/macro/to_string.hpp>

#include <wheels/test/assertion_failure.hpp>
#include <wheels/test/console_reporter.hpp>
#include <wheels/test/copy_only.hpp>
#include <wheels/test/move_only.hpp>
#include <wheels/test/test.hpp>
#include <wheels/test/test_engine.hpp>
#include <wheels/test/test_factory.hpp>
#include <wheels/test/test_suite.hpp>
#include <wheels/test/test_suite_registrar.hpp>

#define ASSERT_EXPRESSION_IMPL(expression)                             \
  do {                                                                 \
    if (!(expression)) {                                               \
      throw ::wheels::AssertionFailure(TO_STRING(expression), HERE()); \
    }                                                                  \
  } while (false)


#define TEST_SUITE_IMPL(test_suite_namespace, name)                   \
  namespace test_suite_namespace {                                    \
    static ::wheels::TestSuite kSuite{name};                          \
                                                                      \
    static ::wheels::TestSuiteRegistrar kTestSuiteRegistrar{&kSuite}; \
  }                                                                   \
                                                                      \
  namespace test_suite_namespace

#define TEST_IMPL(TestRoutine, Test, name, kTestFactory)   \
  void TestRoutine();                                      \
                                                           \
  class Test : public ::wheels::ITest {                    \
   public:                                                 \
    ::wheels::StringView Name() const noexcept override {  \
      return ::wheels::StringView{name};                   \
    }                                                      \
                                                           \
    ::wheels::StringView Suite() const noexcept override { \
      return kSuite.Name();                                \
    }                                                      \
                                                           \
    void Run() override {                                  \
      TestRoutine();                                       \
    }                                                      \
  };                                                       \
                                                           \
  static ::wheels::TestFactory<Test> kTestFactory{kSuite}; \
                                                           \
  void TestRoutine()

#define RUN_ALL_SUITES_IMPL()                                        \
  int main() {                                                       \
    ::wheels::ConsoleReporter console_reporter{};                    \
    ::wheels::TestEngine::Instance().RunAllSuites(console_reporter); \
    return 0;                                                        \
  }

#define ASSERT_EQ(x, y) ASSERT_EXPRESSION_IMPL((x) == (y))

#define ASSERT_NE(x, y) ASSERT_EXPRESSION_IMPL((x) != (y))

#define ASSERT_LT(x, y) ASSERT_EXPRESSION_IMPL((x) < (y))

#define ASSERT_LE(x, y) ASSERT_EXPRESSION_IMPL((x) <= (y))

#define ASSERT_GT(x, y) ASSERT_EXPRESSION_IMPL((x) > (y))

#define ASSERT_GE(x, y) ASSERT_EXPRESSION_IMPL((x) >= (y))

#define ASSERT_TRUE(expression) ASSERT_EXPRESSION_IMPL((expression))

#define ASSERT_FALSE(expression) ASSERT_EXPRESSION_IMPL(!(expression))

#define ASSERT_EXPRESSION(expression) ASSERT_EXPRESSION_IMPL((expression))

#define TEST_SUITE(name) TEST_SUITE_IMPL(CONCAT(TestSuite, name), TO_STRING(name))

#define TEST(name) TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), TO_STRING(name), CONCAT(kTestFactory, name))

#define RUN_ALL_SUITES() RUN_ALL_SUITES_IMPL()