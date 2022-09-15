#include "../include/doctor.hpp"
#include "../include/patient.hpp"
#include "../include/registry.hpp"
#include "../include/queueStrategyHeap.hpp"
#include "../include/queueStrategySort.hpp"
#include <iostream>
#include <memory>

int main() {
  Registry registry;
  registry.add(Patient("Maria", 22, Gender::female, Status::goodCondition));
  registry.add(Patient("Pepe", 22, Gender::male, Status::seriousIllness));
  registry.add(
      Doctor("Manolo", 22, Gender::other, Specialty::Anesthesiologists));
  registry.add(Patient("Carla", 22, Gender::other, Status::slightIllness));
  registry.show(std::cout);
  registry.showWaitingList(std::cout);
  return 0;
}
