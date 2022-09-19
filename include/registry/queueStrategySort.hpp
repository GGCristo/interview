#pragma once

#include <algorithm>

#include <utils.hpp>
#include <registry/queueStrategyI.hpp>

// Sort:
// Insert: nlogn ||
// Delete: nlogn ||
// Pick: 1
template <typename Container>
class QueueStrategySort : public QueueStrategyI<Container> {
  using Element = typename Container::value_type;
  void Insert(Container &container, Element &&value) override {
    if (container.empty()) {
      container.push_back(std::forward<Element>(value));
      return;
    }
    container.insert(
        std::lower_bound(container.begin(), container.end(), value),
        std::forward<Element>(value));
  }

  bool Remove(Container &container, const Element &value) override {
    const auto it = std::lower_bound(container.begin(), container.end(), value);
    if (it == container.end() || *it != value) {
      dout("QueueStrategySort, Remove. The element is not in the container",
           container, value);
      return false;
    }
    container.erase(it);
    return true;
  }

  std::optional<Element> Pick(Container &container) override {
    if (container.empty()) {
      dout("QueueStrategySort, Pick. Empty container");
      return std::nullopt;
    }
    const auto last = std::move(container.back());
    container.pop_back();
    return last;
  };
};
