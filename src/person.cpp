#include <person/person.hpp>
#include <sstream>
#include <stdexcept>

#include "magic_enum.hpp"

NumGenerator Person::
    numGenerator_(  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
        idSize);

Person::Person(std::string name, Gender gender, PersonCondition status, int age)
    : name_(std::move(name)), gender_(gender), status_(status), age_(age) {
  std::optional<std::string> mrn = Person::numGenerator_.next();
  if (age < 0) {
    throw std::invalid_argument("Age cannot be negative:\n Age: " +
                                std::to_string(age));
  }
  if (mrn) {
    mrn_ = *mrn;
  } else {
    std::stringstream personStr;
    print(personStr);
    throw std::runtime_error(
        fmt::format("The system can't generate more unique identifiers\n",
                    personStr.str()));
  }
};

Person::~Person() {
  if (!mrn_.empty()) {
    Person::numGenerator_.free(mrn_);
  }
}

Person::Person(Person &&o) noexcept
    : mrn_(std::move(o.mrn_)),
      name_(std::move(o.name_)),
      gender_(o.gender_),
      status_(o.status_),
      age_(o.age_) {
  o.mrn_ = "";
}

std::string Person::getName() const noexcept { return name_; }

Person::Gender Person::getGender() const noexcept { return gender_; }

int Person::getAge() const noexcept { return age_; }

PersonCondition Person::getStatus() const noexcept { return status_; };

std::string Person::getMRN() const noexcept { return mrn_; };

std::ostream &Person::print(std::ostream &os) const {
  return os << fmt::format("MRN: {}\nName: {}, Age: {}, Gender {}\n", mrn_,
                           name_, age_, gender_);
}

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return p.print(os);
}

// https://fmt.dev/latest/api.html#formatting-user-defined-types
template <>
struct fmt::formatter<Person::Gender> : formatter<std::string_view> {
  template <typename FormatContext>
  auto format(Person::Gender g, FormatContext &ctx) const {
    return formatter<std::string_view>::format(magic_enum::enum_name(g), ctx);
  }
};
