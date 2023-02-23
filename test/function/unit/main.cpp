#include <wheels/function/unique_function.hpp>
#include <wheels/test/test_framework.hpp>

#include <function/util/complex.hpp>

TEST_SUITE(UniqueFunctionUnit) {
  TEST(EmptyLambda) {
    wheels::UniqueFunction<void()> unique_function{[]() {
    }};

    unique_function();
  }

  TEST(LambdaWithReturnValue) {
    wheels::UniqueFunction<int()> unique_function{[]() {
      return 42;
    }};

    ASSERT_EQ(unique_function(), 42);
  }

  TEST(LambdaWithArguments) {
    wheels::UniqueFunction<int(int, int)> unique_function{[](int x, int y) {
      return x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 20);
  }

  TEST(LambdaWithComplexArgument) {
    wheels::UniqueFunction<int(const ComplexArgument&)>
        unique_function{[](const ComplexArgument& x) {
          return x.copy_only.value + x.move_only.value;
        }};

    ASSERT_EQ(unique_function(ComplexArgument{wheels::CopyOnly{5}, wheels::MoveOnly{5}}), 10);
  }

  TEST(CopyOnlyLambda) {
    wheels::CopyOnly value{5};

    wheels::UniqueFunction<int(int, int)> unique_function{[lambda_value = value](int x, int y) {
      return lambda_value.value + x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 25);
  }

  TEST(MoveOnlyLambda) {
    wheels::MoveOnly value{5};

    wheels::UniqueFunction<int(int, int)> unique_function{[lambda_value = std::move(value)](int x, int y) {
      return lambda_value.value + x + y;
    }};

    ASSERT_EQ(unique_function(13, 7), 25);
  }

  TEST(Move) {
    wheels::MoveOnly value{5};

    wheels::UniqueFunction<int(int, int)> unique_function{[lambda_value = std::move(value)](int x, int y) {
      return lambda_value.value + x + y;
    }};

    auto moved_unique_function = ::std::move(unique_function);

    ASSERT_EQ(moved_unique_function(13, 7), 25);
  }
}