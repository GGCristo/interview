#include <iostream>
#include <utility>

#include "../include/person/patient.hpp"

void Patient::addNote(const std::string &note) { notes_.push_back(note); }

std::ostream &Patient::show(std::ostream &os) const {
  const auto *delimiter = "----------\n";
  os << delimiter;
  Person::show(os);
  os << "Notes:\n";
  auto showNote = [&os](const std::string &note) {
    os << "- " << note << '\n';
  };
  std::for_each(notes_.begin(), notes_.end(), showNote);
  os << delimiter;
  return os;
}
