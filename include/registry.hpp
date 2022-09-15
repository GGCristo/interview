#pragma once

#include "patient.hpp"
#include "person.hpp"
#include "waitingList.hpp"

#include <algorithm>
#include <cassert>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

// Medical Registry Number
using MRN = std::string;

using wlElement = std::pair<Status, MRN>;
using wlContainer = std::vector<wlElement>;

class Registry {
public:
  Registry() = default;
  explicit Registry(WlStrategy wlStrategy);
  void add(Person &&person);
  void remove(const MRN &);
  std::ostream &show(std::ostream &os) const;
  std::ostream &showWaitingList(std::ostream &os) const;

private:
  std::unordered_map<MRN, std::unique_ptr<Person>> registry_;
  WaitingList<wlContainer, wlElement> waitingList_;
};
