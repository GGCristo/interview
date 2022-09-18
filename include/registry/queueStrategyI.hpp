#pragma once

#include <optional>
#include <memory>
// Containers: std::vector, std::deque, std::list.
template <typename Container, typename Element = typename Container::value_type>
class QueueStrategyI {
public:
  virtual ~QueueStrategyI() = default;
  virtual void Insert(Container &container, Element &&value) = 0;
  virtual void Remove(Container &container, const Element &value) = 0;
  virtual std::optional<Element> Pick(Container &container) = 0;
};
