#include <iostream>
#include <utility>

#include "../include/person.hpp"

CombGenerator Person::
    combGenerator_( // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        idSize);

Person::Person(std::string name, Gender gender, Status status, int age)
    : name_(std::move(name)), gender_(gender), status_(status), age_(age) {
  std::optional<std::string> mrn = Person::combGenerator_.next();
  if (mrn) {
    MRN_ = *mrn;
  } else {
    throw "Pepe";
  }
};

Person::~Person() {
  if (!MRN_.empty()) {
    std::cout << "Liberando numero de: " << name_ << '\n';
    Person::combGenerator_.free(MRN_);
  }
}

Person::Person(Person &&o) noexcept
    : MRN_(std::move(o.MRN_)), name_(std::move(o.name_)), gender_(o.gender_),
      status_(o.status_), age_(o.age_) {
  o.MRN_ = "";
}

std::string Person::getName() const noexcept { return name_; }

Gender Person::getGender() const noexcept { return gender_; }

int Person::getAge() const noexcept { return age_; }

Status Person::getStatus() const noexcept { return status_; };

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
