#include "../include/patient.hpp"
#include <iostream>

int main() {
  Patient pepe("pepe", Gender::male, 22);
  pepe.addNote("pepe is in a stable condition");
  pepe.show(std::cout);
  return 0;
}
