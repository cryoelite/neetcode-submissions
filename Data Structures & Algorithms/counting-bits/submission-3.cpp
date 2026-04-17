// Problem: https://neetcode.io/problems/counting-bits


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
    int offset{1};
    for (size_t i{1}; i <= n; ++i) {
        if (offset * 2 == i) {
            offset=i;
        }
      result[i] = 1 + result[i - offset];
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


