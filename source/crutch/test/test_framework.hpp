#pragma once

#include <crutch/macro/concat.hpp>
#include <crutch/macro/here.hpp>
#include <crutch/macro/to_string.hpp>

#include <crutch/test/assertion_failure.hpp>
#include <crutch/test/console_reporter.hpp>
#include <crutch/test/copy_only.hpp>
#include <crutch/test/move_only.hpp>
#include <crutch/test/test.hpp>
#include <crutch/test/test_engine.hpp>
#include <crutch/test/test_factory.hpp>
#include <crutch/test/test_suite.hpp>
#include <crutch/test/test_suite_registrar.hpp>

#define ASSERT_EXPRESSION(expression)                                  \
  do {                                                                 \
    if (!(expression)) {                                               \
      throw ::crutch::AssertionFailure(TO_STRING(expression), HERE()); \
    }                                                                  \
  } while (false)


#define TEST_SUITE_IMPL(test_suite_namespace, name)                   \
  namespace test_suite_namespace {                                    \
    static ::crutch::TestSuite kSuite{name};                          \
                                                                      \
    static ::crutch::TestSuiteRegistrar kTestSuiteRegistrar{&kSuite}; \
  }                                                                   \
                                                                      \
  namespace test_suite_namespace

#define TEST_IMPL(TestRoutine, Test, name, kTestFactory)   \
  void TestRoutine();                                      \
                                                           \
  class Test : public ::crutch::ITest {                    \
   public:                                                 \
    ::crutch::StringView Name() const noexcept override {  \
      return ::crutch::StringView{name};                   \
    }                                                      \
                                                           \
    ::crutch::StringView Suite() const noexcept override { \
      return kSuite.Name();                                \
    }                                                      \
                                                           \
    void Run() override {                                  \
      TestRoutine();                                       \
    }                                                      \
  };                                                       \
                                                           \
  static ::crutch::TestFactory<Test> kTestFactory{kSuite}; \
                                                           \
  void TestRoutine()

#define RUN_ALL_SUITES_IMPL()                                        \
  int main() {                                                       \
    ::crutch::ConsoleReporter console_reporter{};                    \
    ::crutch::TestEngine::Instance().RunAllSuites(console_reporter); \
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