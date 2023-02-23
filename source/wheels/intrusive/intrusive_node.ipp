#ifndef NODE_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type>
IntrusiveNode<Type>::IntrusiveNode() noexcept
    : next_{this},
      prev_{this} {
}

template <typename Type>
IntrusiveNode<Type>::IntrusiveNode(IntrusiveNode* next, IntrusiveNode* prev) noexcept
    : next_{next},
      prev_{prev} {
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveNode<Type>::Next() noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");

  return next_;
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveNode<Type>::Prev() noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");

  return prev_;
}

template <typename Type>
Type* IntrusiveNode<Type>::AsValuePtr() noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");

  return static_cast<Type*>(this);
}

template <typename Type>
Type& IntrusiveNode<Type>::AsValueRef() noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");

  return *static_cast<Type*>(this);
}

template <typename Type>
bool IntrusiveNode<Type>::IsLinked() const noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");

  return !(prev_ == this && next_ == this);
}

template <typename Type>
void IntrusiveNode<Type>::LinkAfter(IntrusiveNode* node) noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");
  ASSERT(node != nullptr, "node must be a valid pointer");
  ASSERT(!node->IsLinked(), "unable to link already linked node");

  next_->prev_ = node;
  node->next_ = next_;
  next_ = node;
  node->prev_ = this;
}

template <typename Type>
void IntrusiveNode<Type>::LinkBefore(IntrusiveNode* node) noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");
  ASSERT(node != nullptr, "node must be a valid pointer");
  ASSERT(!node->IsLinked(), "unable to link already linked node");

  prev_->next_ = node;
  node->prev_ = prev_;
  prev_ = node;
  node->next_ = this;
}

template <typename Type>
void IntrusiveNode<Type>::Unlink() noexcept {
  ASSERT(IsValid(), "intrusive list is invalid");
  ASSERT(IsLinked(), "unable to unlink already unlinked node");

  prev_->next_ = next_;
  next_->prev_ = prev_;
  prev_ = this;
  next_ = this;
}

template <typename Type>
bool IntrusiveNode<Type>::IsValid() const noexcept {
  return next_ != nullptr && prev_ != nullptr &&
         ((prev_ == this && next_ == this) || (prev_ != this && next_ != this));
}

}  // namespace wheels