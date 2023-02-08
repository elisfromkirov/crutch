#include <intrusive/util/node.hpp>

Node::Node(int value) noexcept
    : crutch::IntrusiveNode<Node>{},
      value{value} {
}