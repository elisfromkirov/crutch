#include <wheels/string/string_comparison.hpp>

namespace wheels {

bool Less(const String& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) < 0;
}

bool Less(const StringView& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) < 0;
}

bool Less(const String& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) < 0;
}

bool Less(const StringView& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) < 0;
}

bool Equal(const String& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) == 0;
}

bool Equal(const StringView& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) == 0;
}

bool Equal(const String& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) == 0;
}

bool Equal(const StringView& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) == 0;
}

bool Greater(const String& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) > 0;
}

bool Greater(const StringView& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) > 0;
}

bool Greater(const String& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) > 0;
}

bool Greater(const StringView& lhs, const StringView& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) > 0;
}

}  // namespace wheels