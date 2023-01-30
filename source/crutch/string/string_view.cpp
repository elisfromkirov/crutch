#include <crutch/string/string_view.hpp>

namespace crutch {

StringView::StringView(const char* data) noexcept
    : data_{data},
      size_{::std::strlen(data)} {
  ASSERT(data != nullptr, "data must be a valid pointer");
}

StringView::StringView(const char* data, SizeType size) noexcept
    : data_{data},
      size_{size} {
  ASSERT(data != nullptr, "data must be a valid pointer");
}

const char& StringView::operator[](SizeType index) const noexcept {
  ASSERT(data_ != nullptr, "string view is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

const char& StringView::At(SizeType index) const noexcept {
  ASSERT(data_ != nullptr, "string view is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

const char* StringView::Data() const noexcept {
  ASSERT(data_ != nullptr, "string view is invalid");

  return data_;
}

SizeType StringView::Size() const noexcept {
  ASSERT(data_ != nullptr, "string view is invalid");

  return size_;
}

}  // namespace crutch