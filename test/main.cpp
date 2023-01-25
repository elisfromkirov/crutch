#include <crutch/test/console_reporter.hpp>
#include <crutch/test/framework.hpp>

int Factorial(int number) {
  if (number < 0) {
    return 0;
  }

  if (number == 0) {
    return 0;
  }

  int factorial = 1;
  while (number != 0) {
    factorial *= number;
    --number;
  }
  return factorial;
}

TEST_SUITE(Factorial) {
  TEST(Zero) {
    int number = 0;
  
    int factorial = Factorial(number);

    ASSERT_EQ(factorial, 1);
  }

  TEST(One) {
    int number = 1;

    int factorial = Factorial(number);

    ASSERT_EQ(factorial, 1);
  }
}

int main() {
  crutch::ConsoleReporter console_reporter{};
  TestSuiteFactorial::kSuite.RunAllTests(console_reporter);
  return 0;
}
