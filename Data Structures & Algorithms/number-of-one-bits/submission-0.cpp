// Problem: https://neetcode.io/problems/number-of-one-bits

#include <iostream>
#include <vector>
class Alg {
public:
  unsigned long int n;

  Alg() { std::cin >> n; }
  Alg(unsigned long int n) : n(n) {}

  int compute() {
    int result{0};
    while (n) {
      ++result;
      n &= (n - 1);
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
  int hammingWeight(uint32_t n) { return Alg(n).compute(); }
};


