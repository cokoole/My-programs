#pragma once
#include <vector>
#include <functional>

class Handler {
 public:
  template<class T>
  static std::vector<std::vector<T>> DoWork(const std::vector<T> &vc, const std::vector<std::function<T(T)>> &funcVector);

  template<typename T>
  static std::vector<std::vector<T>> DoWork(std::vector<std::pair<T, T>> &vc, std::vector<std::function<T(T, T)>> funcVector);
};

#include "Handler.inl"