#include <iostream>
#include <string>
//
#include "gtest/gtest.h"
#include "Handler.h"
#include "OneParameter.h"
#include "TwoParameter.h"


TEST(TestHandler, TestBasic1) {
  std::vector<int> vc = {1, 2, 3};

  std::vector<std::function<int(int)>> funcVector;

  funcVector.emplace_back([](int a) {
    return a * 2;
  });

  funcVector.emplace_back([](int a) {
    return a * a;
  });

  auto result = Handler::DoWork(vc, funcVector);

  std::vector<std::vector<int>> expected = {
      {2, 4, 6},
      {1, 4, 9}
  };

  ASSERT_EQ(result, expected);
}

TEST(TestHandler, TestBasic2) {
  std::vector<std::pair<int, int>> vc = {
      {1, 2},
      {3, 4},
      {5, 6}
  };

  std::vector<std::function<int(int, int)>> funcVector;

  funcVector.emplace_back([](int a, int b) {
    return a * b;
  });

  funcVector.emplace_back([](int a, int b) {
    return a + b;
  });

  auto result = Handler::DoWork(vc, funcVector);

  std::vector<std::vector<int>> expected = {
      {2, 12, 30},
      {3, 7, 11}
  };

  ASSERT_EQ(result, expected);
}

TEST(TestOneParameter, TestBasic) {
  int num1 = 5;
  std::string str = "123";

  ASSERT_EQ(squaring(num1), 25);
  ASSERT_EQ(sum(num1), 10);
  ASSERT_EQ(sum(str), "123123");
}

TEST(TestTwoParameter, TestBasic) {
  int num1 = 5;
  int num2 = 10;
  std::string str1 = "123";
  std::string str2 = "567";

  ASSERT_EQ(multiplication(num1, num2), 50);
  ASSERT_EQ(sum(num1, num2), 15);
  ASSERT_EQ(sum(str1, str2), "123567");
}