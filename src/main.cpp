#include "../include/patient.hpp"
#include "../include/doctor.hpp"
#include "../include/registry.hpp"
#include <iostream>
#include <memory>

int main() {
  Patient pepe("pepe", Gender::male, 22, "Stable condition", "The patient has recovered");
  Patient maria("pepe", Gender::male, 22);
  Registry registry;
  registry.add(pepe);
  registry.show(std::cout);
  return 0;
}
