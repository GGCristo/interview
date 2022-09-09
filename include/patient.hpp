#include "./gender.hpp"
#include <ostream>
#include <string>
#include <vector>

class Patient {
private:
  std::string name_;
  Gender gender_;
  int age_;
  std::vector<std::string> notes_;
public:
  Patient();
  Patient(std::string name, Gender gender, int age);
  void addNote(const std::string &note);
  std::ostream& show(std::ostream &os) const;
};
