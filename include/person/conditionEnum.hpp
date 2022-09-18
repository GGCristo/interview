#pragma once

#include <fmt/ranges.h>

#include <string_view>

#include "magic_enum.hpp"

enum class PersonCondition {
  employee,
  goodCondition,
  slightIllness,
  seriousIllness,
  criticalCondition,
};

// Boilerplate: https://fmt.dev/latest/api.html#formatting-user-defined-types +
// magic_enum
template <>
struct fmt::formatter<PersonCondition> : formatter<std::string_view> {
  template <typename FormatContext>
  auto format(PersonCondition s, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(s), ctx);
  }
};
