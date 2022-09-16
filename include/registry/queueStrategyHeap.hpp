#pragma once

#include "queueStrategyI.hpp"
#include <algorithm>
// Heap:
// Insert: logn ||
// Delete: nlogn
// Pick: logn ||
template <typename Container, typename T>
class QueueStrategyHeap : public QueueStrategyI<Container, T> {
  void Insert(Container &container, T &&value) override {
    container.push_back(std::move(value));
    std::push_heap(container.begin(), container.end());
  }

  void Remove(Container &container, const T &value) override {
    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
      return;
    }
    // Erase
    std::swap(*it, container.back());
    container.pop_back();

    std::make_heap(container.begin(), container.end());
  }

  std::optional<T> Pick(Container &container) override {
    if (container.empty()) {
      return std::nullopt;
    }
    std::pop_heap(container.begin(), container.end());
    auto result = std::move(container.back());
    container.pop_back();
    return result;
  }
};
