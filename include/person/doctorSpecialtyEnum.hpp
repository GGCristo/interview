#pragma once

#include "magic_enum.hpp"
#include <fmt/ranges.h>
#include <string_view>

enum class Specialty {
  Allergists,
  Anesthesiologists,
  Cardiologists,
  Dermatologists,
  Endocrinologists,
  Hematologists,
  Internists,
  Nephrologists,
  Neurologists,
  Oncologists,
  Osteopaths,
  Pathologists,
  Pediatricians,
  Physiatrists,
  Podiatrists,
  Psychiatrists,
  Pulmonologists,
  Radiologists,
  Rheumatologists,
  Urologists,
};

inline std::ostream &operator<<(std::ostream &os, Specialty s) {
  return os << fmt::format("{}", s);
}

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template<> struct fmt::formatter<Specialty>: formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Specialty g, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(g), ctx);
  }
};
