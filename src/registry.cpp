#include "../include/registry/registry.hpp"

Registry::Registry(WlStrategy wlStrategy) : waitingList_(wlStrategy) {}

void Registry::add(std::unique_ptr<Person> &&person) {
    std::cout << "Hello\n";
  const std::string mrn = person->getMRN();
  const Status status = person->getStatus();
  const auto inserted = registry_.insert({mrn, std::move(person)});
  // The generator of combinations should already control that identifiers are
  // unique
  assert(inserted.second && "MRN identifiers should be unique in the registry");
  if (status != Status::employee) {
    waitingList_.Insert(std::make_pair(status, mrn));
  }
}

void Registry::remove(const MRN &mrn) {}

std::ostream &Registry::print(std::ostream &os) const {
  os << "[Registry]\n";
  for (const auto &person : registry_) {
    const auto &[mrn, info] = person;
    os << "Medical Registry Number: " << mrn << '\n';
    os << *info;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const Registry &r) {
  return r.print(os);
}

std::ostream &Registry::showWaitingList(std::ostream &os) const {
  return waitingList_.show(os);
}
