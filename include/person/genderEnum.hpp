#pragma once

#include "magic_enum.hpp"
#include <fmt/ranges.h>
#include <string_view>

enum class Gender {
  male,
  female,
  other,
};

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template<> struct fmt::formatter<Gender>: formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Gender g, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(g), ctx);
  }
};
