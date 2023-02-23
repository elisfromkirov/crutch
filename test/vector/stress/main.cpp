#include <wheels/macro/abort.hpp>
#include <wheels/vector/vector.hpp>
#include <wheels/test/test_framework.hpp>

#include <random>
#include <vector>

TEST_SUITE(VectorStress) {
  TEST(Stress) {
    wheels::Vector<int> vector{};
    std::vector<int> adversary;

    std::mt19937 gen{524287};

    constexpr wheels::SizeType kIterations{100000};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto value = static_cast<int>(gen());
      adversary.push_back(value);
      vector.PushBack(value);
    }
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
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
          wheels::SizeType index = static_cast<wheels::SizeType>(gen()) % vector.Size();
          ASSERT_EQ(adversary[index], vector[index]);          
        } break;
        default: {
          ABORT();
        }
      }
    }
  }
}