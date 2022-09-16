#include "../include/person/doctor.hpp"
#include "../include/person/patient.hpp"
#include "../include/registry/queueStrategyHeap.hpp"
#include "../include/registry/queueStrategySort.hpp"
#include "../include/registry/registry.hpp"

#include <iostream>
#include <memory>

int main() {
  Registry registry(WlStrategy::sort);
  std::cout << "before add\n";
  registry.add(std::make_unique<Patient>("Maria", 22, Gender::female, Status::goodCondition));
  std::cout << "after add\n";
  registry.add(std::make_unique<Patient>("Pepe", 22, Gender::male, Status::seriousIllness));
  registry.add(
      std::make_unique<Doctor>("Manolo", 22, Gender::other, Specialty::Anesthesiologists));
  registry.add(std::make_unique<Patient>("Carla", 22, Gender::other, Status::slightIllness));
  std::cout << registry;
  // registry.show(std::cout);
  registry.showWaitingList(std::cout);
  return 0;
}
