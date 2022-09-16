#pragma once

#include <fmt/ranges.h>

#include <iostream>
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

// Containers: std::vector, std::deque, std::list.
template <typename Container, typename Element>
class WaitingList {
 public:
  explicit WaitingList(WlStrategy WlStrategy = WlStrategy::heap) {
    switch (WlStrategy) {
      case WlStrategy::heap:
        queueStrategy_ =
            std::make_unique<QueueStrategyHeap<Container, Element>>();
        break;
      case WlStrategy::sort:
        queueStrategy_ =
            std::make_unique<QueueStrategySort<Container, Element>>();
        break;
    }
  }

  void Insert(Element&& value) {
    queueStrategy_->Insert(container_, std::move(value));
  }

  void Remove(const Element& value) {
    queueStrategy_->Remove(container_, value);
  }

  Element Pick() { return queueStrategy_->Pick(container_); }

  std::ostream& show(std::ostream& os) const {
    std::cout << "[Waiting List]\n";
    return os << fmt::format("{}\n", container_);
  }

 private:
  Container container_;
  std::unique_ptr<QueueStrategyI<Container, Element>> queueStrategy_;
};
