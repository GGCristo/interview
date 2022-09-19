#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <person/patient.hpp>

#include "registry/queueStrategyHeap.hpp"

TEST_CASE("Patient. Negative age") {
    REQUIRE_THROWS(Patient("NONE", -10, Person::Gender::other,
                           PersonCondition::criticalCondition));
}
