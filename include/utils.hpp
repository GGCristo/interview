#pragma once
#include <fmt/core.h>

#include <person/conditionEnum.hpp>
#include <string_view>
#include <vector>

// Medical Registry Number
using MRN = std::string;

namespace wl {
using Container = std::vector<std::pair<PersonCondition, MRN>>;
}

inline constexpr const bool DEBUG = true;
template <typename... T>
constexpr void dout(const std::string_view msg, T &&...args) {
  if (DEBUG) {
    (fmt::print("Debug Warning: {}\nData: {}\n", msg, std::forward<T>(args)),
     ...);
  }
}
