// Problem: https://neetcode.io/problems/reverse-bits

#include <iostream>
#include <vector>
class Alg {
public:
  uint32_t n{};

  Alg() { std::cin >> n; }
  Alg(uint32_t &n) : n(n) {}

  uint32_t compute() {
    uint32_t result{0};

    for (size_t i{0}; i < 32; ++i) {
      if (n & (1 << i)) {
        result |= (1 << (31 - i));
      }
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
  uint32_t reverseBits(uint32_t n) { return Alg(n).compute(); }
};

