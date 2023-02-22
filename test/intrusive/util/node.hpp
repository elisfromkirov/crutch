#include <wheel/intrusive/intrusive_node.hpp>

struct Node : wheel::IntrusiveNode<Node> {
  explicit Node(int value) noexcept;

  int value;
};