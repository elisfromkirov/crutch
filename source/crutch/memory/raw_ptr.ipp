#ifndef RAW_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
RawPtr<Type>::RawPtr(Type* pointer, IAllocator* allocator) noexcept
    : detail::RawPtrBase<Type>{pointer, allocator} {
  ASSERT(pointer != nullptr, "pointer must be a valid pointer");
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");
}

template <typename Type>
Type* RawPtr<Type>::Get() const noexcept {
  return this->pointer_;
}

template <typename Type>
void RawPtr<Type>::Release() noexcept {
  this->pointer_ = nullptr;
}

}  // namespace crutch