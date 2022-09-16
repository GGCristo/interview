#pragma once

#include "magic_enum.hpp"
#include <fmt/ranges.h>
#include <string_view>

enum class Status {
  employee,
  goodCondition,
  slightIllness,
  seriousIllness,
  criticalCondition,
};

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template<> struct fmt::formatter<Status>: formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Status s, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(s), ctx);
  }
};
