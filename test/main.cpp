#include <catch2/catch_test_macros.hpp>
#include <deque>
#include <list>
#include <registry/waitingList.hpp>

template <typename SubContainer, typename Strategy = typename Strategy<SubContainer>>
void test() {
  WaitingList<SubContainer> container(std::make_unique<Strategy<SubContainer>>());
  REQUIRE(dynamic_cast<Strategy*>(
              container.strategy().get()) != nullptr);
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
  test<std::vector<int>, QueueStrategyHeap<std::vector<int>>>();
}
//
// TEST_CASE("Waiting list. vector sort") {
//   WaitingList<std::vector<int>, int> container(WlStrategy::sort);
//   REQUIRE(container.strategy() == WlStrategy::sort);
//   test(container);
// }
//
// TEST_CASE("Waiting list. deque heap") {
//   WaitingList<std::deque<int>, int> container;
//   REQUIRE(container.strategy() == WlStrategy::heap);
//   test(container);
// }
//
// TEST_CASE("Waiting list. deque sort") {
//   WaitingList<std::deque<int>, int> container(WlStrategy::sort);
//   REQUIRE(container.strategy() == WlStrategy::sort);
//   test(container);
// }
