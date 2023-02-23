#pragma once

#include <wheels/core/core.hpp>

#include <wheels/string/string.hpp>
#include <wheels/string/string_view.hpp>

namespace wheels {

bool Less(const String& lhs, const String& rhs) noexcept;

bool Less(const StringView& lhs, const String& rhs) noexcept;

bool Less(const String& lhs, const StringView& rhs) noexcept;

bool Less(const StringView& lhs, const StringView& rhs) noexcept;

bool Equal(const String& lhs, const String& rhs) noexcept;

bool Equal(const StringView& lhs, const String& rhs) noexcept;

bool Equal(const String& lhs, const StringView& rhs) noexcept;

bool Equal(const StringView& lhs, const StringView& rhs) noexcept;

bool Greater(const String& lhs, const String& rhs) noexcept;

bool Greater(const StringView& lhs, const String& rhs) noexcept;

bool Greater(const String& lhs, const StringView& rhs) noexcept;

bool Greater(const StringView& lhs, const StringView& rhs) noexcept;

}  // namespace wheels