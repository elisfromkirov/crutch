#pragma once

namespace wheel {

struct MoveOnly {
  explicit MoveOnly(int value) noexcept;

  MoveOnly(const MoveOnly& other) = delete;
  MoveOnly& operator=(const MoveOnly& other) = delete;

  MoveOnly(MoveOnly&& other) noexcept = default;
  MoveOnly& operator=(MoveOnly&& other) noexcept = default;

  ~MoveOnly() noexcept = default;

  int value;
};

}  // namespace wheel