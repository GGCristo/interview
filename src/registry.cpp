#include <registry/registry.hpp>

Registry::Registry(std::unique_ptr<QueueStrategyI<wl::Container>> &&wlStrategy)
    : waitingList_(std::move(wlStrategy)) {}

Person &Registry::add(std::unique_ptr<Person> &&person) {
  const std::string mrn = person->getMRN();
  const PersonCondition status = person->getStatus();
  const auto [inserted, isInserted] =
      registry_.insert({mrn, std::move(person)});
  // The generator of combinations should already control that identifiers are
  // unique
  // NOLINTNEXTLINE
  assert(isInserted && "MRN identifiers should be unique in the registry");
  if (status != PersonCondition::employee) {
    waitingList_.insert(std::make_pair(status, mrn));
  }
  return *inserted->second;
}

bool Registry::remove(const MRN &mrn) {
  auto it = registry_.find(mrn);
  if (it == registry_.end()) {
    return false;
  }
  const auto &[_, personPtr] = *it;
  bool rmLst = waitingList_.remove({personPtr->getStatus(), mrn});
  if (!rmLst) {
    return false;
  }
  registry_.erase(it);
  return true;
}

std::optional<wl::Container::value_type> Registry::pick() {
  return waitingList_.pick();
}

std::optional<std::reference_wrapper<Person>> Registry::find(const MRN &mrn) {
  auto it = registry_.find(mrn);
  if (it == registry_.end()) {
    return std::nullopt;
  }
  return *it->second;
}

std::vector<std::reference_wrapper<Person>> Registry::findByName(
    std::string_view name) {
  std::vector<std::reference_wrapper<Person>> result;
  for (const auto &[mrn, personPtr] : registry_) {
    if (personPtr->getName() == name) {
      result.emplace_back(*personPtr);
    }
  }
  return result;
}

size_t Registry::size() const { return registry_.size(); }

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
