#pragma once

#include "../person/patient.hpp"
#include "../person/person.hpp"
#include "waitingList.hpp"

#include <algorithm>
#include <cassert>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

using wlElement = std::pair<Status, MRN>;
using wlContainer = std::vector<wlElement>;

class Registry {
public:
  Registry() = default;
  explicit Registry(WlStrategy wlStrategy);
  void add(std::unique_ptr<Person> &&person);
  void remove(const MRN &);

  std::ostream &print(std::ostream &os) const;
  std::ostream &showWaitingList(std::ostream &os) const;

private:
  std::unordered_map<MRN, std::unique_ptr<Person>> registry_;
  WaitingList<wlContainer, wlElement> waitingList_;
};

std::ostream &operator<<(std::ostream &os, const Registry& r);
