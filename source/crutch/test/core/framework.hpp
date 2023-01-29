#pragma once

#include <crutch/core/macro/concat.hpp>
#include <crutch/core/macro/here.hpp>
#include <crutch/core/macro/to_string.hpp>

#include <crutch/test/impl/assertion_failure.hpp>
#include <crutch/test/impl/test.hpp>
#include <crutch/test/impl/test_engine.hpp>
#include <crutch/test/impl/test_factory.hpp>
#include <crutch/test/impl/test_suite.hpp>
#include <crutch/test/impl/test_suite_registrar.hpp>

#include <crutch/test/reporter/console.hpp>

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

#define TEST_SUITE_IMPL(test_suite_namespace, name)                   \
  namespace test_suite_namespace {                                    \
    static ::crutch::TestSuite kSuite{name};                          \
                                                                      \
    static ::crutch::TestSuiteRegistrar kTestSuiteRegistrar{&kSuite}; \
  }                                                                   \
                                                                      \
  namespace test_suite_namespace

#define TEST_SUITE(name) \
  TEST_SUITE_IMPL(CONCAT(TestSuite, name), TO_STRING(name))

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

#define TEST(name)                                                          \
  TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), TO_STRING(name), \
            CONCAT(kTestFactory, name))

#define RUN_ALL_TESTS()                                              \
  int main() {                                                       \
    ::crutch::ConsoleReporter console_reporter{};                    \
    ::crutch::TestEngine::Instance().RunAllSuites(console_reporter); \
    return 0;                                                        \
  }