#include <crutch/macro/abort.hpp>
#include <crutch/intrusive/intrusive_list.hpp>
#include <crutch/test/test_framework.hpp>

#include <intrusive/util/node.hpp>

#include <list>
#include <random>

TEST_SUITE(IntrusiveStress) {
  TEST(Stress) {
    crutch::IntrusiveList<Node> list{};
    std::list<int> adversary;

    std::mt19937 gen{524287};

    constexpr crutch::SizeType kIterations{100000};

    for (crutch::SizeType interation = 0; interation < kIterations; ++interation) {
      auto action = static_cast<unsigned int>(gen()) % static_cast<unsigned int>(2);
      auto value = static_cast<int>(gen());
      switch (action) {
        case 0: {
          auto node = new Node(value);
          list.PushFront(node);
          adversary.push_front(value);
        } break;       
        case 1: {
          auto node = new Node(value);
          list.PushBack(node);
          adversary.push_back(value);
        } break;
        default: {
          ABORT();
        }
      }
      ASSERT_EQ(list.IsEmpty(), adversary.empty());
      ASSERT_EQ(list.Front()->AsValuePtr()->value, adversary.front());
      ASSERT_EQ(list.Back()->AsValuePtr()->value, adversary.back());
    }

    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto action = gen() % 2;
      switch (action) {
        case 0: {
          auto node = list.Front();
          list.PopFront();
          adversary.pop_front();
          delete node;
        } break;       
        case 1: {
          auto node = list.Back();
          list.PopBack();
          adversary.pop_back();
          delete node;
        } break;
        default: {
          ABORT();
        }
      }

      ASSERT_EQ(list.IsEmpty(), adversary.empty());
      if (!list.IsEmpty() && !adversary.empty()) {
        ASSERT_EQ(list.Front()->AsValuePtr()->value, adversary.front());
        ASSERT_EQ(list.Back()->AsValuePtr()->value, adversary.back());
      }
    }
  }
}