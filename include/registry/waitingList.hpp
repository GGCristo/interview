#pragma once

#include <fmt/ranges.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <person/person.hpp>
#include <registry/queueStrategyHeap.hpp>
#include <registry/queueStrategyI.hpp>
#include <registry/queueStrategySort.hpp>
#include <utils.hpp>
#include <vector>

// Containers: std::vector, std::deque, std::list(only sort).
template <typename Container>
class WaitingList {
  using Element = typename Container::value_type;

 public:
  explicit WaitingList(std::unique_ptr<QueueStrategyI<Container>>&& strategy =
                           std::make_unique<QueueStrategyHeap<Container>>())
      : queueStrategy_(std::move(strategy)) {
    assert(queueStrategy_ != nullptr &&
           "QueueStrategy has not been initialized");
  }

  void insert(Element&& value) {
    queueStrategy_->Insert(container_, std::forward<Element>(value));
  }
  // void insert(Element&& value) {
  //   queueStrategy_->Insert(container_, std::move(value));
  // }
  //
  // void insert(Element& value) { // TODO perfect forward?
  //   queueStrategy_->Insert(container_, value);
  // }

  bool remove(const Element& value) {
    return queueStrategy_->Remove(container_, value);
  }

  std::optional<Element> pick() { return queueStrategy_->Pick(container_); }

  [[nodiscard]] size_t size() const { return container_.size(); }

  [[nodiscard]] const std::unique_ptr<QueueStrategyI<Container>>& strategy()
      const {
    return queueStrategy_;
  }

  // Useful for testing
  template <typename Container2>
  bool isPermutation(const WaitingList<Container2>& other) const {
    return std::is_permutation(std::begin(container_), std::end(container_),
                               std::begin(other.container_));
  }

  std::ostream& show(std::ostream& os) const {
    std::cout << "[Waiting List]\n";
    return os << fmt::format("{}\n", container_);
  }

 private:
  Container container_;
  std::unique_ptr<QueueStrategyI<Container>> queueStrategy_;
};
