#include <wheels/macro/abort.hpp>
#include <wheels/intrusive/intrusive_list.hpp>
#include <wheels/test/test_framework.hpp>

#include <intrusive/util/node.hpp>

#include <list>
#include <random>

TEST_SUITE(IntrusiveStress) {
  TEST(Stress) {
    wheels::IntrusiveList<Node> list{};
    std::list<int> adversary;

    std::mt19937 gen{524287};

    constexpr wheels::SizeType kIterations{100000};

    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
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

    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      auto action = gen() % 2;
      switch (action) {
        case 0: {
          auto node = list.Front()->AsValuePtr();
          list.PopFront();
          delete node;
          adversary.pop_front();
        } break;
        case 1: {
          auto node = list.Back()->AsValuePtr();
          list.PopBack();
          delete node;
          adversary.pop_back();
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