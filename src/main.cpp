#include <iostream>
#include <memory>
#include <utility>

#include "../include/person/doctor.hpp"
#include "../include/person/patient.hpp"
#include "../include/registry/queueStrategyHeap.hpp"
#include "../include/registry/queueStrategySort.hpp"
#include "../include/registry/registry.hpp"

int main() {
  Registry registry(std::make_unique<QueueStrategySort<wl::Container>>());
  registry.add(std::make_unique<Patient>("Maria", 22, Person::Gender::female,
                                         PersonCondition::goodCondition));
  registry.add(std::make_unique<Patient>("Pepe", 22, Person::Gender::male,
                                         PersonCondition::seriousIllness));
  registry.add(std::make_unique<Doctor>("Manolo", 22, Person::Gender::other,
                                        Doctor::Specialty::Anesthesiologists));
  registry.add(std::make_unique<Patient>("Carla", 22, Person::Gender::other,
                                         PersonCondition::slightIllness));
  std::cout << registry;
  registry.showWaitingList(std::cout);
  return 0;
}
