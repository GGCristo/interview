#pragma once

#include "queueStrategyI.hpp"
#include <algorithm>
#include <type_traits>
#include <memory>

// Heap:
// Insert: logn ||
// Delete: nlogn
// Pick: logn ||
template <typename Container, typename Element = typename Container::value_type>
class QueueStrategyHeap : public QueueStrategyI<Container, Element> {
  void Insert(Container &container, Element &&value) override {
    container.push_back(std::forward<Element>(value));
    std::push_heap(container.begin(), container.end());
  }

  void Remove(Container &container, const Element &value) override {
    auto it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
      return;
    }
    // Erase
    std::swap(*it, container.back());
    container.pop_back();

    std::make_heap(container.begin(), container.end());
  }

  std::optional<Element> Pick(Container &container) override {
    if (container.empty()) {
      return std::nullopt;
    }
    std::pop_heap(container.begin(), container.end());
    auto result = std::move(container.back());
    container.pop_back();
    return result;
  }
};
