#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
class IntrusiveNode {
 public:
  IntrusiveNode() noexcept;

  IntrusiveNode(IntrusiveNode* next, IntrusiveNode* prev) noexcept;

  [[nodiscard]]
  IntrusiveNode* Next() noexcept;

  [[nodiscard]]
  IntrusiveNode* Prev() noexcept;

  [[nodiscard]]
  Type* AsValuePtr() noexcept;

  [[nodiscard]]
  Type& AsValueRef() noexcept;

  [[nodiscard]]
  bool IsLinked() const noexcept;

  void LinkAfter(IntrusiveNode* node) noexcept;

  void LinkBefore(IntrusiveNode* node) noexcept;

  void Unlink() noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;

 private:
  IntrusiveNode* next_;
  IntrusiveNode* prev_;
};

}  // namespace wheels

#define NODE_IMPL
#include <wheels/intrusive/intrusive_node.ipp>
#undef NODE_IMPL