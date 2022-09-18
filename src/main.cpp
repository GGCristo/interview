#include <iostream>
#include <memory>
#include <utility>

#include "../include/person/doctor.h"
#include "../include/person/patient.h"
#include "../include/registry/queueStrategyHeap.h"
#include "../include/registry/queueStrategySort.h"
#include "../include/registry/registry.h"

int main() {
  const int age = 22;
  Registry registry(std::make_unique<QueueStrategySort<wl::Container>>());
  registry.add(std::make_unique<Patient>("Maria", age, Person::Gender::female,
                                         PersonCondition::goodCondition));
  registry.add(std::make_unique<Patient>("Pepe", age, Person::Gender::male,
                                         PersonCondition::seriousIllness));
  registry.add(std::make_unique<Doctor>("Manolo", age, Person::Gender::other,
                                        Doctor::Specialty::Anesthesiologists));
  registry.add(std::make_unique<Patient>("Carla", age, Person::Gender::other,
                                         PersonCondition::slightIllness));
  std::cout << registry;
  registry.showWaitingList(std::cout);
  Patient p1("Luisa", age, Person::Gender::male, PersonCondition::criticalCondition);
  return 0;
}
