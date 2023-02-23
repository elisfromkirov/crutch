#include <intrusive/util/node.hpp>

Node::Node(int value) noexcept
    : wheels::IntrusiveNode<Node>{},
      value{value} {
}