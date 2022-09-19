#pragma once

#include <algorithm>
#include <cassert>
#include <memory>
#include <ostream>
#include <person/patient.hpp>
#include <person/person.hpp>
#include <registry/waitingList.hpp>
#include <unordered_map>
#include <vector>

class Registry {
 public:
  using RegistryT = std::unordered_map<MRN, std::unique_ptr<Person>>;
  Registry() = default;
  explicit Registry(
      std::unique_ptr<QueueStrategyI<wl::Container>> &&wlStrategy);
  Person &add(std::unique_ptr<Person> &&person);
  bool remove(const MRN &);
  std::optional<std::reference_wrapper<Person>> find(const MRN &mrn);
  std::vector<std::reference_wrapper<Person>> findByName(std::string_view name);
  std::optional<wl::Container::value_type> pick();

  [[nodiscard]] size_t size() const;

  std::ostream &print(std::ostream &os) const;
  std::ostream &showWaitingList(std::ostream &os) const;  // TODO change this

 private:
  RegistryT registry_;
  WaitingList<wl::Container> waitingList_;
};

std::ostream &operator<<(std::ostream &os, const Registry &r);
