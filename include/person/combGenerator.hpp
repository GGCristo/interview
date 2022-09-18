#pragma once

#include <optional>
#include <queue>
#include <string>

class CombGenerator {
public:
  explicit CombGenerator(size_t size) noexcept;
  std::optional<std::string> next();
  void free(std::string freeNumber);

private:
  int number_ = 0;
  size_t size_;
  std::queue<std::string>
      freeNumbers_; // Available numbers to reuse
};
