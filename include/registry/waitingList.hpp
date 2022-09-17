#pragma once

#include <fmt/ranges.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

#include "../person/person.hpp"
#include "../utils.hpp"
#include "queueStrategyHeap.hpp"
#include "queueStrategyI.hpp"
#include "queueStrategySort.hpp"

enum class WlStrategy {
  heap,
  sort,
};

// Containers: std::vector, std::deque.
template <typename Container, typename Element>
class WaitingList {
 public:
  explicit WaitingList(WlStrategy WlStrategy = WlStrategy::heap) {
    switch (WlStrategy) {
      case WlStrategy::heap:
        queueStrategy_ =
            std::make_unique<QueueStrategyHeap<Container, Element>>();
        strategyName_ = WlStrategy::heap;
        break;
      case WlStrategy::sort:
        queueStrategy_ =
            std::make_unique<QueueStrategySort<Container, Element>>();
        strategyName_ = WlStrategy::sort;
        break;
    }
    assert(queueStrategy_ != nullptr &&
           "QueueStrategy has not been initialized");
  }

  void Insert(Element&& value) {
    queueStrategy_->Insert(container_, std::move(value));
  }

  void Remove(const Element& value) {
    queueStrategy_->Remove(container_, value);
  }

  Element Pick() { return queueStrategy_->Pick(container_); }

  [[nodiscard]] WlStrategy strategy() const { return strategyName_; }

  [[nodiscard]] size_t size() const { return container_.size(); }

  // Useful for testing
  bool isPermutation(const Container& other) const {
    return std::is_permutation(std::begin(container_), std::end(container_),
                               std::begin(other));
  }

  std::ostream& show(std::ostream& os) const {
    std::cout << "[Waiting List]\n";
    return os << fmt::format("{}\n", container_);
  }

 private:
  Container container_;
  WlStrategy strategyName_;
  std::unique_ptr<QueueStrategyI<Container, Element>> queueStrategy_;
};
