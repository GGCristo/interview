#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>

constexpr const bool DEBUG = true;

namespace internal {
template <typename T>
std::ostream& print(std::ostream &os, const T &p) {
  os << p;
  return os;
}

template <typename T1, typename T2>
std::ostream &print(std::ostream &os, const std::pair<T1, T2> &p) {
  os << "{ ";
  os << "1: ";
  print(os, p.first);
  os << ", 2: ";
  print(os, p.second);
  os << " }";
  return os;
}

template <typename T>
std::ostream &printContainer(std::ostream &os, const T &v) {
  os << "[ ";
  if (v.empty()) {
    os << " ]\n";
    return os;
  }
  internal::print(os, *v.begin());
  for (const auto e : v) {
    os << ", ";
    internal::print(os, e);
  }
  os << " ]\n";
  return os;
}

template <typename T>
std::ostream &print(std::ostream &os, const std::vector<T> &p) {
  return printContainer(os, p);
}

template <typename T>
std::ostream &print(std::ostream &os, const std::list<T> &p) {
  return printContainer(os, p);
}

template <typename T>
std::ostream &print(std::ostream &os, const std::deque<T> &p) {
  return printContainer(os, p);
}
} // namespace internal

template <typename T>
std::ostream &print(const T &p, std::ostream &os = std::cout) {
  if (DEBUG) {
    internal::print(os, p);
    os << '\n';
  }
  return os;
}
