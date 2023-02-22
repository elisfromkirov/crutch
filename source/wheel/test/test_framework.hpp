#pragma once

#include <wheel/macro/concat.hpp>
#include <wheel/macro/here.hpp>
#include <wheel/macro/to_string.hpp>

#include <wheel/test/assertion_failure.hpp>
#include <wheel/test/console_reporter.hpp>
#include <wheel/test/copy_only.hpp>
#include <wheel/test/move_only.hpp>
#include <wheel/test/test.hpp>
#include <wheel/test/test_engine.hpp>
#include <wheel/test/test_factory.hpp>
#include <wheel/test/test_suite.hpp>
#include <wheel/test/test_suite_registrar.hpp>

#define ASSERT_EXPRESSION(expression)                                  \
  do {                                                                 \
    if (!(expression)) {                                               \
      throw ::wheel::AssertionFailure(TO_STRING(expression), HERE()); \
    }                                                                  \
  } while (false)


#define TEST_SUITE_IMPL(test_suite_namespace, name)                   \
  namespace test_suite_namespace {                                    \
    static ::wheel::TestSuite kSuite{name};                          \
                                                                      \
    static ::wheel::TestSuiteRegistrar kTestSuiteRegistrar{&kSuite}; \
  }                                                                   \
                                                                      \
  namespace test_suite_namespace

#define TEST_IMPL(TestRoutine, Test, name, kTestFactory)   \
  void TestRoutine();                                      \
                                                           \
  class Test : public ::wheel::ITest {                    \
   public:                                                 \
    ::wheel::StringView Name() const noexcept override {  \
      return ::wheel::StringView{name};                   \
    }                                                      \
                                                           \
    ::wheel::StringView Suite() const noexcept override { \
      return kSuite.Name();                                \
    }                                                      \
                                                           \
    void Run() override {                                  \
      TestRoutine();                                       \
    }                                                      \
  };                                                       \
                                                           \
  static ::wheel::TestFactory<Test> kTestFactory{kSuite}; \
                                                           \
  void TestRoutine()

#define RUN_ALL_SUITES_IMPL()                                        \
  int main() {                                                       \
    ::wheel::ConsoleReporter console_reporter{};                    \
    ::wheel::TestEngine::Instance().RunAllSuites(console_reporter); \
    return 0;                                                        \
  }

#define ASSERT_EQ(x, y) ASSERT_EXPRESSION((x) == (y))

#define ASSERT_NE(x, y) ASSERT_EXPRESSION((x) != (y))

#define ASSERT_LT(x, y) ASSERT_EXPRESSION((x) < (y))

#define ASSERT_LE(x, y) ASSERT_EXPRESSION((x) <= (y))

#define ASSERT_GT(x, y) ASSERT_EXPRESSION((x) > (y))

#define ASSERT_GE(x, y) ASSERT_EXPRESSION((x) >= (y))

#define ASSERT_TRUE(expression) ASSERT_EXPRESSION((expression))

#define ASSERT_FALSE(expression) ASSERT_EXPRESSION(!(expression))

#define TEST_SUITE(name) TEST_SUITE_IMPL(CONCAT(TestSuite, name), TO_STRING(name))

#define TEST(name) TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), TO_STRING(name), CONCAT(kTestFactory, name))

#define RUN_ALL_SUITES() RUN_ALL_SUITES_IMPL()