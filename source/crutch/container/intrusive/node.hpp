#pragma once

#include "crutch/core/macro/assert.hpp"

namespace crutch {

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
  [[nodiscard]] bool IsValid() const noexcept;

 private:
  IntrusiveNode* next_;
  IntrusiveNode* prev_;
};

}  // namespace crutch

#define NODE_IMPL
#include "node.ipp"
#undef NODE_IMPL