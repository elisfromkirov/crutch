#include <wheels/intrusive/intrusive_node.hpp>

struct Node : wheels::IntrusiveNode<Node> {
  explicit Node(int value) noexcept;

  int value;
};