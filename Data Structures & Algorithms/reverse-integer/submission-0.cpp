// Problem: https://neetcode.io/problems/reverse-integer

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

class Alg {
public:
  int x{};
  Alg() { std::cin >> x; }
  Alg(int x) : x(x) {}

  int compute() {
    int result{0};
    bool is_pos{x > 0};
    if (!is_pos) {
      x *= -1;
    }
    int n{static_cast<int>(std::floor(log10(x)))};
    while (x > 0) {
      int digit{x % 10};
      x = static_cast<int>(std::round(x / 10));
      if (digit != 0 && digit > (std::numeric_limits<int>::max() /
                                 static_cast<int>(std::pow(10, n)))) {
        return 0;
      }
      int value{digit * static_cast<int>(std::pow(10, n))};
      if (value > 0 && result > std::numeric_limits<int>::max() - value) {
        return 0;
      }
      result += value;
      --n;
    }

    if (!is_pos) {
      result *= -1;
    }
    return result;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {

public:
  int reverse(int x) { return Alg(x).compute(); }
};

