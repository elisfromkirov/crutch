#include <crutch/intrusive/intrusive_node.hpp>

struct Node : crutch::IntrusiveNode<Node> {
  explicit Node(int value) noexcept;

  int value;
};