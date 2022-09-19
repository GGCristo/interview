#include <person/patient.hpp>

#include <iostream>
#include <stdexcept>
#include <utility>

void Patient::addNote(const std::string &note) { notes_.push_back(note); }

const std::vector<std::string> &Patient::getNotes() const {
  return notes_;
}

std::ostream &Patient::print(std::ostream &os) const {
  const auto *delimiter = "----------\n";
  os << delimiter;
  Person::print(os);
  if (!notes_.empty()) {
    os << "Notes:\n";
    auto showNote = [&os](const std::string &note) {
      os << "- " << note << '\n';
    };
    std::for_each(notes_.begin(), notes_.end(), showNote);
  }
  os << delimiter;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Patient &p) {
  return p.print(os);
}
