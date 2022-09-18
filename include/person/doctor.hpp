#pragma once

#include <ostream>

#include "person.hpp"

class Doctor : public Person {
 public:
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
  Doctor(std::string name, int age, Gender gender, Specialty specialty);
  [[nodiscard]] Specialty getSpecialty() const;
  std::ostream &print(std::ostream &os) const override;

 private:
  Specialty specialty_;
};

std::ostream &operator<<(std::ostream &os, const Doctor &d);
