#include <iostream>
#include <vector>
#include <functional>
//
#include "Handler.h"
#include "OneParameter.h"
#include "TwoParameter.h"

int main() {
  std::vector<int> vc = {1, 2, 3};

  std::vector<std::function<int(int )>> funcVector = {
      sum<int>,
      squaring<int>
  };

  auto res = Handler::DoWork(vc, funcVector);

  for (auto& it : res) {
    for (auto& it2 : it) {
      std::cout << it2 << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}