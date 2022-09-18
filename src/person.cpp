#include "../include/person/person.hpp"
#include "magic_enum.hpp"

CombGenerator Person::
    combGenerator_( // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        idSize);

Person::Person(std::string name, Gender gender, PersonCondition status, int age)
    : name_(std::move(name)), gender_(gender), status_(status), age_(age) {
  std::optional<std::string> mrn = Person::combGenerator_.next();
  if (mrn) {
    MRN_ = *mrn;
  } else {
    throw "Pepe"; // TODO
  }
};

Person::~Person() {
  if (!MRN_.empty()) {
    Person::combGenerator_.free(MRN_);
  }
}

Person::Person(Person &&o) noexcept
    : MRN_(std::move(o.MRN_)), name_(std::move(o.name_)), gender_(o.gender_),
      status_(o.status_), age_(o.age_) {
  o.MRN_ = "";
}

std::string Person::getName() const noexcept { return name_; }

Person::Gender Person::getGender() const noexcept { return gender_; }

int Person::getAge() const noexcept { return age_; }

PersonCondition Person::getStatus() const noexcept { return status_; };

std::string Person::getMRN() const noexcept { return MRN_; };

std::ostream &Person::print(std::ostream &os) const {
  return os << fmt::format("Name: {}, Age: {}, Gender {}\n", name_, age_, gender_);
}

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return p.print(os);
}

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template<> struct fmt::formatter<Person::Gender>: formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Person::Gender g, FormatContext& ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(g), ctx);
  }
};
