#pragma once
#include <ostream>
#include <string>

enum class Gender {
  male,
  female,
  other,
};

enum class Status {
  employee,
  goodCondition,
  slightIllness,
  seriousIllness,
  criticalCondition,
};

class Person {
public:
  virtual ~Person() = default;

  Person &operator=(const Person &) = delete;
  [[nodiscard]] std::string getName() const;
  [[nodiscard]] Gender getGender() const;
  [[nodiscard]] int getAge() const;
  virtual std::ostream &show(std::ostream &os) const;

protected:
  Person(std::string name, Gender gender, int age);

private:
  std::string name_;
  Gender gender_;
  Status status_;
  int age_;
};
