#include <catch2/catch_test_macros.hpp>
#include <deque>
#include <list>
#include <registry/queueStrategySort.hpp>
#include <registry/waitingList.hpp>
#include <string_view>

using Pair = std::pair<int, std::string>;

using Vec = std::vector<int>;

using VecPair = std::vector<Pair>;

using Deq = std::deque<int>;

using DeqPair = std::deque<Pair>;

using List = std::list<int>;

using ListPair = std::list<Pair>;

template <typename Container, typename Strategy>
void wlTest() {
  WaitingList<Container> container(std::make_unique<Strategy>());
  REQUIRE(dynamic_cast<Strategy*>(container.strategy().get()) != nullptr);
  SECTION("Basic Insert") {
    container.insert(1);
    REQUIRE(container.size() == 1);
    SECTION("Basic Remove") {
      container.remove(1);
      REQUIRE(container.size() == 0);
    }
    SECTION("Remove non existing value") {
      REQUIRE_NOTHROW(container.remove(0));
      REQUIRE(container.size() == 1);
    }
  }
  SECTION("Remove empty") {
    REQUIRE_NOTHROW(container.remove(3));
    REQUIRE(container.size() == 0);
  }
}

template <typename Container, typename Strategy>
void wlTestPair() {
  WaitingList<Container> container(std::make_unique<Strategy>());
  REQUIRE(dynamic_cast<Strategy*>(container.strategy().get()) != nullptr);
  SECTION("Basic Insert") {
    container.insert({1, "uno"});
    REQUIRE(container.size() == 1);
    SECTION("Basic Remove") {
      container.remove({1, "uno"});
      REQUIRE(container.size() == 0);
    }
    SECTION("Remove non existing value") {
      REQUIRE_NOTHROW(container.remove({0, "cero"}));
      REQUIRE(container.size() == 1);
    }
  }
  SECTION("Remove empty") {
    REQUIRE_NOTHROW(container.remove({4, "I shouldn't be here"}));
    REQUIRE(container.size() == 0);
  }
}

TEST_CASE("Waiting list. vectorInt heap") {
  wlTest<Vec, QueueStrategyHeap<Vec>>();
}

TEST_CASE("Waiting list. vectorInt sort") {
  wlTest<Vec, QueueStrategySort<Vec>>();
}

TEST_CASE("Waiting list. vectorPair heap") {
  wlTestPair<VecPair, QueueStrategySort<VecPair>>();
}

TEST_CASE("Waiting list. vectorPair sort") {
  wlTestPair<VecPair, QueueStrategySort<VecPair>>();
}

TEST_CASE("Waiting list. dequeInt heap") {
  wlTest<Deq, QueueStrategyHeap<Deq>>();
}

TEST_CASE("Waiting list. deque sort") { wlTest<Deq, QueueStrategySort<Deq>>(); }

TEST_CASE("Waiting list. dequePair heap") {
  wlTestPair<DeqPair, QueueStrategyHeap<DeqPair>>();
}

TEST_CASE("Waiting list. dequePair sort") {
  wlTestPair<DeqPair, QueueStrategySort<DeqPair>>();
}

TEST_CASE("Waiting list. listInt sort") {
  wlTest<List, QueueStrategySort<List>>();
}

TEST_CASE("Waiting list. listPair sort") {
  wlTestPair<ListPair, QueueStrategySort<ListPair>>();
}

// TEST_CASE("Waiting List. Permutation equality") {
//   WaitingList<Vec> wl1;
//   WaitingList<List> wl2(std::make_unique<QueueStrategySort<List>>());
//   for (int i = 0; i < 4; ++i) {
//     wl1.insert(std::move(i));
//   }
//   for (int i = 0; i < 4; ++i) {
//     wl2.insert(std::move(i));
//   }
//   wl1.isPermutation<List>(wl2);
// }
