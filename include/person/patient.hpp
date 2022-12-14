#pragma once

#include <algorithm>
#include <cassert>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include <person/person.hpp>

class Patient : public Person {
 public:
  template <typename... T>
  Patient(std::string name, int age, Gender gender, PersonCondition status,
          const T... notes)
      : Person(std::move(name), gender, status, age) {
    assert(status != PersonCondition::employee);
    (notes_.push_back(notes), ...);
  }
  void addNote(const std::string &note);
  [[nodiscard]] const std::vector<std::string> &getNotes() const;
  std::ostream &print(std::ostream &os) const override;

 private:
  std::vector<std::string> notes_;
};

std::ostream &operator<<(std::ostream &os, const Patient &p);
