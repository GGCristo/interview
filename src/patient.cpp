#include <iostream>

#include "../include/patient.hpp"

Patient::Patient(std::string name, Gender gender, int age)
    : name_(std::move(name)), gender_(gender), age_(age) {}

void Patient::addNote(const std::string &note) {
  notes_.push_back(note);
}

std::ostream &Patient::show(std::ostream &os) const {
  const auto *delimiter = "----------\n";
  os << delimiter;
  os << "Name: " << name_ << '\n';
  os << "Age: " << age_ << '\n';
  os << "Gender: ";
  switch (gender_) {
  case Gender::male:
    os << "Male";
    break;
  case Gender::female:
    os << "Female";
    break;
  }
  os << '\n';
  os << "Notes:\n";
  for (std::size_t i = 0; i < notes_.size(); i++) {
    os << '(' << i + 1 << ")\n";
    os << notes_[i];
  }
  os << '\n' << delimiter;
  return os;
}
