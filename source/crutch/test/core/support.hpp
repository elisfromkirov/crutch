#pragma once

namespace crutch {

struct CopyOnly {
  explicit CopyOnly(int value) noexcept;

  CopyOnly(const CopyOnly& other) = default;
  CopyOnly& operator=(const CopyOnly& other) = default;

  CopyOnly(CopyOnly&& other) noexcept = delete;
  CopyOnly& operator=(CopyOnly&& other) noexcept = delete;

  ~CopyOnly() noexcept = default;

  int value;
};

struct MoveOnly {
  explicit MoveOnly(int value) noexcept;

  MoveOnly(const MoveOnly& other) = delete;
  MoveOnly& operator=(const MoveOnly& other) = delete;

  MoveOnly(MoveOnly&& other) noexcept = default;
  MoveOnly& operator=(MoveOnly&& other) noexcept = default;

  ~MoveOnly() noexcept = default;

  int value;
};

struct Complex {
  Complex(CopyOnly copy_only, MoveOnly move_only) noexcept;

  int value;
};

}  // namespace crutch