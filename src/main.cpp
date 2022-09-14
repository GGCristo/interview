#include "../include/patient.hpp"
#include "../include/doctor.hpp"
#include "../include/registry.hpp"
#include <iostream>
#include <memory>

int main() {
  // Patient pepe("pepe", 22, Gender::male, Status::criticalCondition, "Stable condition", "The patient has recovered");
  Patient maria("maria", 22, Gender::female, Status::goodCondition);
  Registry registry;
  registry.add(maria);
  registry.show(std::cout);
  maria.show(std::cout);
  // registry.showQueue(std::cout);
  return 0;
}
