#pragma once

#include "./person.hpp"
#include <algorithm>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

class Patient : public Person {
public:
  template <typename... T>
  Patient(std::string name, Gender gender, int age, const T... notes)
      : Person(std::move(name), gender, age) {
    (notes_.push_back(notes), ...);
  }
  void addNote(const std::string &note);
  std::ostream &show(std::ostream &os) const override;

private:
  std::vector<std::string> notes_;
};
