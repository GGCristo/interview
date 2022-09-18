#pragma once

#include <person/patient.hpp>
#include <person/person.hpp>
#include <registry/waitingList.hpp>

#include <algorithm>
#include <cassert>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

class Registry {
public:
  explicit Registry(std::unique_ptr<QueueStrategyI<wl::Container>> &&wlStrategy);
  void add(std::unique_ptr<Person> &&person);
  void remove(const MRN &);

  std::ostream &print(std::ostream &os) const;
  std::ostream &showWaitingList(std::ostream &os) const; // TODO change this

private:
  std::unordered_map<MRN, std::unique_ptr<Person>> registry_;
  WaitingList<wl::Container> waitingList_;
};

std::ostream &operator<<(std::ostream &os, const Registry& r);
