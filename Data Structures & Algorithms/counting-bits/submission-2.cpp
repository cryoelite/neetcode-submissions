// Problem: https://neetcode.io/problems/counting-bits

#include <cmath>
#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> result;
  Alg() { std::cin >> n; }
  Alg(int in_n) {
    if (in_n < 0) {
      throw;
    }
    n = static_cast<size_t>(in_n);
  }
  void compute() {
    result = std::vector<int>(n + 1, 0);
    if (n > 0) {
      result[0] = 0;
      result[1] = 1;
    }
    for (size_t i{2}; i <= n; ++i) {
      result[i] = 1 + result[i - static_cast<size_t>(
                                     std::pow(2, std::floor(std::log2(i))))];
    }
  }

  void compute_and_output() {
    compute();
    for (int elem : result) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
};

class Solution {

public:
  std::vector<int> countBits(int n) {
    Alg alg{Alg(n)};
    alg.compute();
    return alg.result;
  }
};


