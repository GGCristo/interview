#include "../include/registry.hpp"

void Registry::add(const Person &person) {
  registry_.insert({person.getName(), std::make_unique<Person>(person)});
}

std::ostream &Registry::show(std::ostream &os) const {
  for (const auto &person : registry_) {
    const auto &[name, info] = person;
    os << name << '\n';
  }
  return os;
}
