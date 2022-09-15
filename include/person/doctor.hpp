#pragma once

#include <ostream>
#include "person.hpp"

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

class Doctor : public Person {
private:
  Specialty specialty_;
public:
  Doctor(std::string name, int age, Gender gender, Specialty specialty);
  [[nodiscard]] Specialty getSpecialty() const;
  std::ostream &show(std::ostream &os) const override;
};
