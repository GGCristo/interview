#include <catch2/catch_test_macros.hpp>
#include <registry/waitingList.hpp>
#include <list>
#include <deque>

template<typename Container>
void test(Container& container) {
  REQUIRE(container.strategy() == WlStrategy::heap);
  SECTION("Basic Insert") {
    container.Insert(1);
    REQUIRE(container.size() == 1);
    SECTION("Basic Remove") {
      container.Remove(1);
      REQUIRE(container.size() == 0);
    }
    SECTION("Remove non existing value") {
      REQUIRE_NOTHROW(container.Remove(0));
      REQUIRE(container.size() == 1);
    }
  }
  SECTION("Remove empty") {
    REQUIRE_NOTHROW(container.Remove(3));
    REQUIRE(container.size() == 0);
  }
}

TEST_CASE("Waiting list. vector heap") {
  WaitingList<std::vector<int>, int> container;
  REQUIRE(container.strategy() == WlStrategy::heap);
  test(container);
}

TEST_CASE("Waiting list. vector sort") {
  WaitingList<std::vector<int>, int> container(WlStrategy::sort);
  REQUIRE(container.strategy() == WlStrategy::sort);
  test(container);
}

TEST_CASE("Waiting list. deque heap") {
  WaitingList<std::deque<int>, int> container;
  REQUIRE(container.strategy() == WlStrategy::heap);
  test(container);
}

TEST_CASE("Waiting list. deque sort") {
  WaitingList<std::deque<int>, int> container(WlStrategy::sort);
  REQUIRE(container.strategy() == WlStrategy::sort);
  test(container);
}
