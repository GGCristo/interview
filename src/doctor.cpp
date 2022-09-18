#include "../include/person/doctor.hpp"

#include <fmt/core.h>

Doctor::Doctor(std::string name, int age, Gender gender, Specialty specialty)
    : Person(std::move(name), gender, PersonCondition::employee, age),
      specialty_(specialty) {}

std::ostream &Doctor::print(std::ostream &os) const {
  const auto *delimiter = "----------\n";
  os << delimiter;
  Person::print(os);
  return os << fmt::format("Specialty: \n{}\n{}", specialty_, delimiter);
}

std::ostream &operator<<(std::ostream &os, const Doctor &d) {
  return d.print(os);
}
// https://fmt.dev/latest/api.html#formatting-user-defined-types
template<> struct fmt::formatter<Doctor::Specialty>: formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Doctor::Specialty g, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(g), ctx);
  }
};

inline std::ostream &operator<<(std::ostream &os, Doctor::Specialty s) {
  return os << fmt::format("{}", s);
}
