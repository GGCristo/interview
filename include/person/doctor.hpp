#pragma once

#include "person.hpp"
#include "doctorSpecialtyEnum.hpp"
#include <ostream>

class Doctor : public Person {
private:
  Specialty specialty_;
public:
  Doctor(std::string name, int age, Gender gender, Specialty specialty);
  [[nodiscard]] Specialty getSpecialty() const;
  std::ostream &print(std::ostream &os) const override;
};

std::ostream &operator<<(std::ostream &os, const Doctor& d);
