#include <utility>

#include "../include/doctor.hpp"

Doctor::Doctor(std::string name, int age, Gender gender, Specialty specialty)
    : Person(std::move(name), gender, Status::employee, age), specialty_(specialty) {}

std::ostream &Doctor::show(std::ostream &os) const {
  const auto *delimiter = "----------\n";
  os << delimiter;
  Person::show(os);
  os << "Specialty: ";
  switch (specialty_) {
  case Specialty::Allergists:
    os << "Allergists";
    break;
  case Specialty::Anesthesiologists:
    os << "Anesthesiologists";
    break;
  case Specialty::Cardiologists:
    os << "Cardiologists";
    break;
  case Specialty::Dermatologists:
    os << "Dermatologists";
    break;
  case Specialty::Endocrinologists:
    os << "Endocrinologists";
    break;
  case Specialty::Hematologists:
    os << "Hematologists";
    break;
  case Specialty::Internists:
    os << "Internists";
    break;
  case Specialty::Nephrologists:
    os << "Nephrologists";
    break;
  case Specialty::Neurologists:
    os << "Neurologists";
    break;
  case Specialty::Oncologists:
    os << "Oncologists";
    break;
  case Specialty::Osteopaths:
    os << "Osteopaths";
    break;
  case Specialty::Pathologists:
    os << "Pathologists";
    break;
  case Specialty::Pediatricians:
    os << "Pediatricians";
    break;
  case Specialty::Physiatrists:
    os << "Physiatrists";
    break;
  case Specialty::Podiatrists:
    os << "Podiatrists";
    break;
  case Specialty::Psychiatrists:
    os << "Psychiatrists";
    break;
  case Specialty::Pulmonologists:
    os << "Pulmonologists";
    break;
  case Specialty::Radiologists:
    os << "Radiologists";
    break;
  case Specialty::Rheumatologists:
    os << "Rheumatologists";
    break;
  case Specialty::Urologists:
    os << "Urologists";
    break;
  }
  os << '\n' << delimiter;
  return os;
}
