#pragma once

#include <algorithm>

#include "../utils.hpp"
#include "queueStrategyI.hpp"

// Sort:
// Insert: nlogn
// Delete: nlogn
// Pick: 1
template <typename Container, typename T>
class QueueStrategySort : public QueueStrategyI<Container, T> {
  void Insert(Container &container, T &&value) override {
    if (container.empty()) {
      container.push_back(std::forward<T>(value));
      return;
    }
    container.insert(
        std::lower_bound(container.begin(), container.end(), value),
        std::forward<T>(value));
  }

  void Remove(Container &container, const T &value) override {
    const auto it = std::lower_bound(container.begin(), container.end(), value);
    if (it == container.end() || *it != value) {
      dout("QueueStrategySort, Remove. The element is not in the container",
           container, value);
      return;
    }
    container.erase(it);
  }

  std::optional<T> Pick(Container &container) override {
    if (container.empty()) {
      dout("QueueStrategySort, Pick. Empty container");
      return std::nullopt;
    }
    const auto last = std::move(container.back());
    container.pop_back();
    return last;
  };
};
