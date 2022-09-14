#include "../include/registry.hpp"

void Registry::add(Person &person) {
  registry_.insert({person.getName(), std::make_unique<Person>(std::move(person))});
  if (person.getStatus() != Status::employee) {
    queue_.emplace_back(person.getName(), person.getStatus());
    std::push_heap(queue_.begin(), queue_.end());
  }
}

std::ostream &Registry::show(std::ostream &os) const {
  for (const auto &person : registry_) {
    const auto &[name, info] = person;
    os << name << '\n';
  }
  return os;
}

std::ostream &Registry::showQueue(std::ostream &os) const {
  for (const auto &person : queue_) {
    const auto &[name, state] = person;
    os << name << '\n';
  }
  return os;
}
