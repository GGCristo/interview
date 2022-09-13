#include <iostream>
#include <utility>

#include "../include/person.hpp"

Person::Person(std::string name, Gender gender, int age)
    : name_(std::move(name)), gender_(gender), age_(age){};

std::string Person::getName() const { return name_; }

Gender Person::getGender() const { return gender_; }

int Person::getAge() const { return age_; }

std::ostream &Person::show(std::ostream &os) const {
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
  case Gender::other:
    os << "Other";
    break;
  }
  os << '\n';
  return os;
}
