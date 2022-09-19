#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <person/patient.hpp>
#include <registry/registry.hpp>
#include <utils.hpp>

const constexpr int someAge = 22;

Person &createPepe(Registry &re) {
  return re.add(std::make_unique<Patient>("Pepe", someAge, Person::Gender::male,
                                          PersonCondition::goodCondition,
                                          "Good condition", "Stable"));
}

std::pair<Registry, Person &> base() {
  Registry re;
  auto &it = createPepe(re);
  return {std::move(re), it};
}

TEST_CASE("Registry Add") {
  auto [re, inserted] = base();
  REQUIRE(re.size() == 1);
  REQUIRE(inserted.getName() == "Pepe");
  REQUIRE(inserted.getAge() == someAge);
  REQUIRE(inserted.getGender() == Person::Gender::male);
  REQUIRE(inserted.getStatus() == PersonCondition::goodCondition);
}

TEST_CASE("Register. Remove") {
  auto [re, inserted] = base();
  bool wasRemoved = re.remove(inserted.getMRN());
  REQUIRE(re.size() == 0);
  REQUIRE(wasRemoved);
}

TEST_CASE("Register. Find") {
  auto [registry, inserted] = base();
  std::optional<std::reference_wrapper<Person>> person =
      registry.find(inserted.getMRN());
  REQUIRE(person != std::nullopt);
  SECTION("I can change the value") {
    std::string msg = "He has fully recovered";
    auto *patient = dynamic_cast<Patient *>(&person.value().get());
    // NOLINTNEXTLINE
    assert(patient != nullptr &&
           "The person inserted is not a Patient");  // NOLINT
    patient->addNote(msg);
    std::optional<std::reference_wrapper<Person>> person =
        registry.find(inserted.getMRN());
    REQUIRE(person != std::nullopt);
    patient = dynamic_cast<Patient *>(&person.value().get());
    // NOLINTNEXTLINE
    assert(patient != nullptr && "The person inserted is not a Patient");
    REQUIRE(patient->getNotes().back() == msg);
  }
}

TEST_CASE("Register. Find by name") { 
  auto [registry, inserted] = base();
  createPepe(registry);
  auto vec = registry.findByName("Pepe");
  REQUIRE(vec.size() == 2);
  REQUIRE(vec[0].get().getName() == "Pepe");
  REQUIRE(vec[1].get().getName() == "Pepe");
}
