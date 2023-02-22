#include <intrusive/util/node.hpp>

Node::Node(int value) noexcept
    : wheel::IntrusiveNode<Node>{},
      value{value} {
}