#include <wheel/macro/abort.hpp>
#include <wheel/vector/vector.hpp>
#include <wheel/test/test_framework.hpp>

#include <random>
#include <vector>

TEST_SUITE(VectorStress) {
  TEST(Stress) {
    wheel::Vector<int> vector{};
    std::vector<int> adversary;

    std::mt19937 gen{524287};

    constexpr wheel::SizeType kIterations{100000};
    for (wheel::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto value = static_cast<int>(gen());
      adversary.push_back(value);
      vector.PushBack(value);
    }
    for (wheel::SizeType iteration = 0; iteration < kIterations; ++iteration) {
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
          wheel::SizeType index = static_cast<wheel::SizeType>(gen()) % vector.Size();
          ASSERT_EQ(adversary[index], vector[index]);          
        } break;
        default: {
          ABORT();
        }
      }
    }
  }
}