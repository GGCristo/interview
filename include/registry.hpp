#pragma once

#include "patient.hpp"
#include "person.hpp"
#include <algorithm>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>
class Registry {
public:
  void add(Person &person);
  // void add(Person &&person);
  std::ostream &show(std::ostream &os) const;
  std::ostream &showQueue(std::ostream &os) const;

private:
  std::unordered_map<std::string, std::unique_ptr<Person>> registry_;
  std::vector<std::pair<std::string, Status>> queue_;
};
