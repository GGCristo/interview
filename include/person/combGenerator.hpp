#pragma once

#include <optional>
#include <queue>
#include <string>

class CombGenerator {
public:
  explicit CombGenerator(size_t size) noexcept;
  std::optional<std::string> next();
  void free(std::string &freeNumber);

private:
  int number_ = 0;
  size_t size_;
  // Available numbers to reuse
  std::queue<std::string>
      freeNumbers_; // Should I use a std::list as underlying container?
};
