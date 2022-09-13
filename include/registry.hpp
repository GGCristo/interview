#pragma once

#include "patient.hpp"
#include "person.hpp"
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>
class Registry {
public:
  void add(const Person &person);
  // void add(Person &&person);
  std::ostream &show(std::ostream &os) const;

private:
  // std::vector<std::unique_ptr<Person>> registry_;
  std::unordered_map<std::string, std::unique_ptr<Person>> registry_;
};
