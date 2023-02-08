#include <crutch/function/unique_function.hpp>
#include <crutch/test/test_framework.hpp>

#include <function/util/complex.hpp>

TEST_SUITE(UniqueFunctionUnit) {
  TEST(EmptyLambda) {
    crutch::UniqueFunction<void()> unique_function{[]() {
    }};

    unique_function();
  }

  TEST(LambdaWithReturnValue) {
    crutch::UniqueFunction<int()> unique_function{[]() {
      return 42;
    }};

    ASSERT_EQ(unique_function(), 42);
  }

  TEST(LambdaWithArguments) {
    crutch::UniqueFunction<int(int, int)> unique_function{[](int x, int y) {
      return x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 20);
  }

  TEST(LambdaWithComplexArgument) {
    crutch::UniqueFunction<int(const ComplexArgument&)>
        unique_function{[](const ComplexArgument& x) {
          return x.copy_only.value + x.move_only.value;
        }};

    ASSERT_EQ(unique_function(ComplexArgument{crutch::CopyOnly{5}, crutch::MoveOnly{5}}), 10);
  }

  TEST(CopyOnlyLambda) {
    crutch::CopyOnly value{5};

    crutch::UniqueFunction<int(int, int)> unique_function{[lambda_value = value](int x, int y) {
      return lambda_value.value + x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 25);
  }

  TEST(MoveOnlyLambda) {
    crutch::MoveOnly value{5};

    crutch::UniqueFunction<int(int, int)> unique_function{[lambda_value = std::move(value)](int x, int y) {
      return lambda_value.value + x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 25);
  }

  TEST(Move) {
    crutch::MoveOnly value{5};

    crutch::UniqueFunction<int(int, int)> unique_function{[lambda_value = std::move(value)](int x, int y) {
      return lambda_value.value + x + y;
    }};

    auto moved_unique_function = ::std::move(unique_function);

    ASSERT_EQ(moved_unique_function(13, 7), 25);
  }
}