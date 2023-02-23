#pragma once

namespace wheels {

struct CopyOnly {
  explicit CopyOnly(int value) noexcept;

  CopyOnly(const CopyOnly& other) = default;
  CopyOnly& operator=(const CopyOnly& other) = default;

  CopyOnly(CopyOnly&& other) noexcept = delete;
  CopyOnly& operator=(CopyOnly&& other) noexcept = delete;

  ~CopyOnly() noexcept = default;

  int value;
};

}  // namespace wheels