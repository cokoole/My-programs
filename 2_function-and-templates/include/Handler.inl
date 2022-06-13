#pragma once
#include <iostream>
#include "Handler.h"

template<class T>
std::vector<std::vector<T>> Handler::DoWork(const std::vector<T> &vc, const std::vector<std::function<T(T)>> &funcVector) {
  std::vector<std::vector<T>> result;

  for (auto& func : funcVector) {
    std::vector<T> buf;
    for (auto& element : vc) {
      buf.push_back(func(element));
    }
    result.template emplace_back(buf);
  }

  return result;
}

template<typename T>
std::vector<std::vector<T>> Handler::DoWork(std::vector<std::pair<T, T>> &vc,
                                            std::vector<std::function<T(T, T)>> funcVector) {
  std::vector<std::vector<T>> result;

  for (auto& func : funcVector) {
    std::vector<T> buf;
    for (auto& element : vc) {
      buf.push_back(func(element.first, element.second));
    }
    result.template emplace_back(buf);
  }

  return result;
}
