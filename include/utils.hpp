#pragma once

#include "fmt/core.h"
// #include <deque>
// #include <iostream>
// #include <list>
// #include <magic_enum.hpp>
#include <string_view>
// #include <vector>

// using namespace magic_enum::ostream_operators;

// Medical Registry Number
using MRN = std::string;
inline constexpr const bool DEBUG = true;

template <typename... T>
constexpr void dout(const std::string_view msg, T... args) {
  if (DEBUG) {
    (fmt::print("Debug Warning: {}\nData: {}\n", msg, args), ...);
  }
}

// namespace detail {
// template <typename T>
// std::ostream &print(std::ostream &os, const T &p) {
//   os << p;
//   return os;
// }
//
// template <typename T1, typename T2>
// std::ostream &print(std::ostream &os, const std::pair<T1, T2> &p) {
//   os << "{ ";
//   os << "1: ";
//   print(os, p.first);
//   os << ", 2: ";
//   print(os, p.second);
//   os << " }";
//   return os;
// }
//
// template <typename T>
// std::ostream &printContainer(std::ostream &os, const T &v) {
//   os << "[ ";
//   if (v.empty()) {
//     os << " ]\n";
//     return os;
//   }
//   detail::print(os, *v.begin());
//   for (const auto e : v) {
//     os << ", ";
//     detail::print(os, e);
//   }
//   os << " ]\n";
//   return os;
// }
//
// template <typename T>
// std::ostream &print(std::ostream &os, const std::vector<T> &p) {
//   return printContainer(os, p);
// }
//
// template <typename T>
// std::ostream &print(std::ostream &os, const std::list<T> &p) {
//   return printContainer(os, p);
// }
//
// template <typename T>
// std::ostream &print(std::ostream &os, const std::deque<T> &p) {
//   return printContainer(os, p);
// }
// } // namespace detail
//
// template <typename T>
// std::ostream &print(const T &p, std::ostream &os = std::cout) {
//   if (DEBUG) {
//     detail::print(os, p);
//     os << '\n';
//   }
//   return os;
// }
