// Problem: https://neetcode.io/problems/sum-of-two-integers?list=neetcode250

#include <bitset>
#include <iostream>
#include <vector>
class Alg {
public:
  int a;
  int b;

  Alg() { std::cin >> a >> b; }
  Alg(int a, int b) : a(a), b(b) {}

  int compute() {
    int result{a ^ b};
    int carry{(a & b) << 1};
    while (carry != 0) {
      int tmp{((result & carry) << 1)};
      result = result ^ carry;
      carry = tmp;
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
  int getSum(int a, int b) { return Alg(a, b).compute(); }
};
