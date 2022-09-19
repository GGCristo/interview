#pragma once

#include <memory>
#include <optional>
// Containers: std::vector, std::deque, std::list(sortStrategy).
template <typename Container>
class QueueStrategyI {
  using Element = typename Container::value_type;

 public:
  virtual ~QueueStrategyI() = default;
  virtual void Insert(Container &container, Element &&value) = 0;
  virtual bool Remove(Container &container, const Element &value) = 0;
  virtual std::optional<Element> Pick(Container &container) = 0;
};
