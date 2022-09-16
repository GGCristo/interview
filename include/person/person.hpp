#pragma once
#include <ostream>
#include <string>

#include "combGenerator.hpp"
#include "statusEnum.hpp"
#include "genderEnum.hpp"
#include "../utils.hpp"

constexpr size_t idSize = 5;

class Person {
public:
  virtual ~Person() = 0;
  Person(Person &&o) noexcept;
  Person(const Person &) = delete;
  Person& operator=(const Person &) = delete;
  Person& operator=(Person &&) = delete;

  [[nodiscard]] std::string getName() const noexcept;
  [[nodiscard]] Gender getGender() const noexcept;
  [[nodiscard]] Status getStatus() const noexcept;
  [[nodiscard]] int getAge() const noexcept;
  [[nodiscard]] std::string getMRN() const noexcept;

  virtual std::ostream &print(std::ostream &os) const;

protected:
  Person(std::string name, Gender gender, Status status, int age);

private:
  /* Warning "Variable 'combGenerator_' is non-const and globally accessible,
   * consider making it const" is a clang-tidy bug
   * References:
   * https://bugs.llvm.org/show_bug.cgi?id=48040,
   * https://github.com/llvm/llvm-project/issues/47384
   * cppcoreguidelines-avoid-non-const-global-variables
   */
  static CombGenerator
      combGenerator_; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
  // Medical registry number
  MRN MRN_;
  std::string name_;
  Gender gender_;
  Status status_;
  int age_;
};

std::ostream &operator<<(std::ostream &os, const Person& p);
