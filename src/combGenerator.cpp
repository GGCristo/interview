#include "../include/person/combGenerator.hpp"
#include <algorithm>

CombGenerator::CombGenerator(std::size_t size) noexcept : size_(size) {}

std::optional<std::string> CombGenerator::next() {
  if (!freeNumbers_.empty()) {
    std::string strN = freeNumbers_.front();
    freeNumbers_.pop();
    return strN;
  }
  std::string strN = std::to_string(number_++);
  if (strN.size() > size_) {
    return std::nullopt;
  }
  return std::string(size_ - strN.size(), '0') + strN;
}

void CombGenerator::free(std::string &freeNumber) {
  freeNumbers_.push(std::move(freeNumber));
}
