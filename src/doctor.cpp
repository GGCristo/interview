#include "../include/person/doctor.hpp"

#include <fmt/core.h>

Doctor::Doctor(std::string name, int age, Gender gender, Specialty specialty)
    : Person(std::move(name), gender, Status::employee, age),
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
