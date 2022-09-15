#include "../include/registry/registry.hpp"

Registry::Registry(WlStrategy wlStrategy) : waitingList_(wlStrategy) {}

void Registry::add(Person &&person) {
  const std::string mrn = person.getMRN();
  const Status status = person.getStatus();
  const auto it =
      registry_.insert({mrn, std::make_unique<Person>(std::move(person))});
  // The generator of combinations should already control that identifiers are
  // unique
  assert(it.second && "MRN identifiers should be unique in the registry");
  if (status != Status::employee) {
    waitingList_.Insert(
        std::make_pair(status, mrn));
  }
}

void Registry::remove(const MRN &mrn) {}

// Sort:
// Insert: n
// Pick: 1
// Delete: nlogn

std::ostream &Registry::show(std::ostream &os) const {
  for (const auto &person : registry_) {
    const auto &[mrn, info] = person;
    os << mrn << '\n';
  }
  return os;
}

std::ostream &Registry::showWaitingList(std::ostream &os) const {
  return waitingList_.show(os);
}
