#include <iostream>
#include <string>
#include <map>
#include <random>
//
#include "functions.h"

int main() {

  std::string path = "../dir", what = "words";
  int totalFiles = 1, maxAmount = 10, minAmount = 10;

  std::cout << "Input path: ";
  std::cin >> path;

  std::cout << "Input total files: ";
  std::cin >> totalFiles;

  std::cout << "Input 'what': ";
  std::cin >> what;

  std::cout << "Input max 'maxAmount': ";
  std::cin >> maxAmount;

  std::cout << "Input max 'minAmount': ";
  std::cin >> minAmount;

  int n = totalFiles;
  int i = 0;

  while (n > 0) {
    n /= 10;
    ++i;
  }

  std::string idFile = "";
  idFile.append(i, '0');

  for (int j = 0; j < totalFiles; ++j) {
    std::random_device rd;
    std::default_random_engine defEngine;
    std::uniform_int_distribution<int> intDistro(minAmount, maxAmount);

    std::string amount = std::to_string(intDistro(defEngine));
    std::map<std::string, std::string> map {{"what", what}, {"amount", amount}};

    incrementId(idFile);
    if (!saveText(path, parsTextXML(postLipsum(map)), idFile))
      break;
  }

  return 0;
}

