#pragma once

#include <optional>
// Containers: std::vector, std::deque, std::list.
template <typename Container, typename T>
class QueueStrategyI {
public:
  virtual ~QueueStrategyI() = default;
  virtual void Insert(Container &container, T &&value) = 0;
  virtual void Remove(Container &container, const T &value) = 0;
  virtual std::optional<T> Pick(Container &container) = 0;
};
