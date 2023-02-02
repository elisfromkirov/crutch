#include "crutch/vector/vector.hpp"

#include "crutch/test/test_framework.hpp"

#include <random>
#include <vector>

TEST_SUITE(VectorStress) {
  TEST(Stress) {
    std::vector<int> sample;

    crutch::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{10000};

    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      sample.push_back(value);
      vector.PushBack(value);
    }

    std::mt19937 action_gen{23};

    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int action = static_cast<int>(action_gen()) % 3;
      switch (action) {
        case 0: {
          int value{static_cast<int>(gen())};
          sample.push_back(value);
          vector.PushBack(value);
        } break;
        case 1: {
          sample.pop_back();
          vector.PopBack();
        } break;
        case 2: {
          crutch::SizeType index = static_cast<crutch::SizeType>(gen()) % vector.Size();
          ASSERT_EQ(sample[index], vector[index]);
        } break;
        default: ASSERT(false, "unreachable");
      }
    }
  }
}