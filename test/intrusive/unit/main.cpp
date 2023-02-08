#include <crutch/test/test_framework.hpp>

#include <crutch/intrusive/intrusive_list.hpp>
#include <crutch/intrusive/intrusive_node.hpp>

#include <intrusive/util/node.hpp>

TEST_SUITE(IntrusiveUnit) {
  TEST(Iterator) {
    crutch::IntrusiveList<Node> list{};

    Node nodes[] = {Node{1}, Node{2}, Node{3}, Node{4}, Node{5}, Node{6}, Node{7}, Node{8}};

    for (crutch::SizeType i = 0; i < 8; ++i) {
      list.PushBack(&nodes[i]);
    }
    
    crutch::SizeType index = 0;
    for (crutch::IntrusiveNode<Node>* node = list.Begin(); node != list.End(); node = node->Next()) {
      ASSERT_EQ(node->AsValuePtr()->value, nodes[index++].value);
    }
  }

  TEST(IsEmpty) {
    crutch::IntrusiveList<Node> list{};

    Node node{0};

    ASSERT_TRUE(list.IsEmpty());

    list.PushFront(&node);

    ASSERT_FALSE(list.IsEmpty());

    list.PopFront();

    ASSERT_TRUE(list.IsEmpty());

    list.PushBack(&node);

    ASSERT_FALSE(list.IsEmpty());

    list.PopBack();

    ASSERT_TRUE(list.IsEmpty());
  }

  TEST(PushFront) {
    crutch::IntrusiveList<Node> list{};

    Node nodes[] = {Node{1}, Node{2}, Node{3}};

    list.PushFront(&nodes[0]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[0].value);

    list.PushFront(&nodes[1]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[1].value);

    list.PushFront(&nodes[2]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[2].value);
  }

  TEST(PushBack) {
    crutch::IntrusiveList<Node> list{};

    Node nodes[] = {Node{4}, Node{5}, Node{6}};

    list.PushBack(&nodes[0]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[0].value);

    list.PushBack(&nodes[1]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[1].value);

    list.PushBack(&nodes[2]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[2].value);
  }

  TEST(PopFront) {
    crutch::IntrusiveList<Node> list{};

    Node nodes[] = {Node{7}, Node{8}, Node{9}};

    list.PushFront(&nodes[0]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[0].value);

    list.PushFront(&nodes[1]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[1].value);

    list.PushFront(&nodes[2]);
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[2].value);

    list.PopFront();
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[1].value);

    list.PopFront();
    ASSERT_EQ(list.Front()->AsValuePtr()->value, nodes[0].value);
  }

  TEST(PopBack) {
    crutch::IntrusiveList<Node> list{};

    Node nodes[] = {Node{1}, Node{2}, Node{3}};

    list.PushBack(&nodes[0]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[0].value);

    list.PushBack(&nodes[1]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[1].value);

    list.PushBack(&nodes[2]);
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[2].value);

    list.PopBack();
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[1].value);

    list.PopBack();
    ASSERT_EQ(list.Back()->AsValuePtr()->value, nodes[0].value);
  }
}