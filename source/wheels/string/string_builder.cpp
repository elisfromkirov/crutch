#include <wheels/string/string_builder.hpp>

namespace wheels {

StringBuilder::StringBuilder(String&& string) noexcept
    : detail::StringBuilderBase{string.data_, string.size_, string.capacity_, string.allocator_} {
  string.data_ = nullptr;
  string.size_ = 0;
  string.capacity_ = 0;
}

StringBuilder::StringBuilder(SizeType capacity, IAllocator* allocator)
    : detail::StringBuilderBase{capacity, allocator} {
}

char StringBuilder::Back() noexcept {
  ASSERT(IsValid(), "string builder is invalid");
  ASSERT(!IsEmpty(), "string builder must not be empty");

  return data_[size_ - 1];
}

char* StringBuilder::Data() noexcept {
  ASSERT(IsValid(), "string builder is invalid");

  return data_;
}

bool StringBuilder::IsEmpty() const noexcept {
  ASSERT(IsValid(), "string builder is invalid");

  return size_ == 0;
}

SizeType StringBuilder::Size() const noexcept {
  ASSERT(IsValid(), "string builder is invalid");

  return size_;
}

SizeType StringBuilder::Capacity() const noexcept {
  ASSERT(IsValid(), "string builder is invalid");

  return capacity_;
}

void StringBuilder::Reserve(SizeType capacity) {
  ASSERT(IsValid(), "string builder is invalid");
  ASSERT(capacity < capacity_, "capacity must be greater than current capacity");

  StringBuilder tmp{capacity, allocator_};
  tmp.PushBack(StringView{data_, size_});
  Swap(tmp);
}

void StringBuilder::PushBack(char character) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(1, "%c", character);
}

void StringBuilder::PushBack(Int8 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Int8>::kDigits, "%" PRIi8, value);
}

void StringBuilder::PushBack(Uint8 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Uint8>::kDigits, "%" PRIu8, value);
}

void StringBuilder::PushBack(Int16 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Int16>::kDigits, "%" PRIi16, value);
}

void StringBuilder::PushBack(Uint16 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Uint16>::kDigits, "%" PRIu16, value);
}

void StringBuilder::PushBack(Int32 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Int32>::kDigits, "%" PRIi32, value);
}

void StringBuilder::PushBack(Uint32 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Uint32>::kDigits, "%" PRIu32, value);
}

void StringBuilder::PushBack(Int64 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Int64>::kDigits, "%" PRIi64, value);
}

void StringBuilder::PushBack(Uint64 value) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(Limits<Uint64>::kDigits, "%" PRIu64, value);
}

void StringBuilder::PushBack(StringView string) {
  ASSERT(IsValid(), "string builder is invalid");

  PushBackImpl(string.Size(), "%s", string.Data());
}

void StringBuilder::PopBack() noexcept {
  ASSERT(IsValid(), "string builder is invalid");
  ASSERT(!IsEmpty(), "string builder must not be empty");

  size_--;
  data_[size_] = '\0';
}

String StringBuilder::ToString() && noexcept {
  auto data = Exchange(data_, nullptr);
  auto size = Exchange(size_, 0);
  auto capacity = Exchange(capacity_, 0);
  auto allocator = allocator_;
  return String{data, size, capacity, allocator};
}

bool StringBuilder::IsValid() const noexcept {
  return data_ != nullptr && size_ < capacity_ && capacity_ != 0 && allocator_ != nullptr;
}

void StringBuilder::Ensure(SizeType required_space) {
  if (size_ + required_space >= capacity_) {
    Reserve(capacity_ * kDefaultGrowthFactor);
  }
}

template <typename Type>
void StringBuilder::PushBackImpl(SizeType required_space, const char* format, Type value) {
  Ensure(required_space);
  size_ += ::snprintf(data_ + size_, capacity_ - size_, format, value);
}

}  // namespace wheels