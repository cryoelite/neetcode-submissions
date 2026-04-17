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
    constexpr int k_int_max{std::numeric_limits<int>::max()};
    constexpr int k_int_min{std::numeric_limits<int>::min()};
    int result{0};
    while (x != 0) {
      if (result > k_int_max / 10 || result < k_int_min / 10) {
        return 0;
      }
      result = result * 10 + x % 10;
      x /= 10;
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

