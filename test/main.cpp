#include <crutch/test/framework.hpp>

int Factorial(int number) {
  if (number < 0) {
    return 0;
  }
  if (number == 0) {
    return 1;
  }
  return number * Factorial(number - 1);
}

TEST_SUITE(Factorial) {
  TEST(Zero) {
    int number = 0;
  
    int factorial = Factorial(number);

    ASSERT_EQ(factorial, 1);
  }
}

int main() {
  
  return 0;
}

// [========] Running {num_tests} tests from suite {suite}
// [  RUN   ] {suite}::{test}
// [ PASSED ] {suite}::{test} passed
// [ FAILED ] {suite}::{test} failed, because  
