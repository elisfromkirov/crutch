#include <crutch/macro/abort.hpp>
#include <crutch/vector/vector.hpp>
#include <crutch/test/test_framework.hpp>

#include <random>
#include <vector>

TEST_SUITE(VectorStress) {
  TEST(Stress) {
    crutch::Vector<int> vector{};
    std::vector<int> adversary;

    std::mt19937 gen{524287};

    constexpr crutch::SizeType kIterations{100000};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto value = static_cast<int>(gen());
      adversary.push_back(value);
      vector.PushBack(value);
    }
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto action = static_cast<unsigned int>(gen()) % static_cast<unsigned int>(3);
      switch (action) {
        case 0: {
          auto value = static_cast<int>(gen());
          adversary.push_back(value);
          vector.PushBack(value);
        } break;
        case 1: {
          adversary.pop_back();
          vector.PopBack();
        } break;
        case 2: {
          crutch::SizeType index = static_cast<crutch::SizeType>(gen()) % vector.Size();
          ASSERT_EQ(adversary[index], vector[index]);          
        } break;
        default: {
          ABORT();
        }
      }
    }
  }
}