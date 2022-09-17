#pragma once

#include <fmt/core.h>

#include <string_view>

// Medical Registry Number
using MRN = std::string;
inline constexpr const bool DEBUG = true;

template <typename... T>
constexpr void dout(const std::string_view msg, const T &...args) {
  if (DEBUG) {
    (fmt::print("Debug Warning: {}\nData: {}\n", msg, args), ...);
  }
}
