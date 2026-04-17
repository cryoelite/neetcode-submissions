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
    bool is_x_pos{x >= 0};
    if (!is_x_pos) {
      x *= -1;
    }
    int n{static_cast<int>(std::floor(std::log10(x)))};
    constexpr int k_int_max{std::numeric_limits<int>::max()};

    std::cout << "n: " << n << " x: " << x << "\n";
    while (x > 0) {
      int curr{static_cast<int>(x % 10)};
      std::cout << "curr: " << curr << '\n';
      int mult{static_cast<int>(std::pow(10, n))};
      std::cout << "mult: " << mult << '\n';
      if (mult != 0 && curr > (k_int_max / mult)) {
        return 0;
      } else {
        curr *= mult;
      }
      std::cout << "curr: " << curr << '\n';
      x = static_cast<int>(x / 10);
      std::cout << "x: " << x << '\n';
      result += curr;
      std::cout << "result: " << result << '\n';
      --n;
    }

    if (!is_x_pos) {
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

