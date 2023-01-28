#pragma once

#include <crutch/string/view.hpp>

namespace crutch {

class ITest {
 public:
  virtual ~ITest() noexcept = default;

  [[nodiscard]]
  virtual StringView Name() const noexcept = 0;

  [[nodiscard]]
  virtual StringView Suite() const noexcept = 0;

  virtual void Run() = 0;
};

}  // namespace crutch