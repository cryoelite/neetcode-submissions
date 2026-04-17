// Problem: https://neetcode.io/problems/valid-palindrome-ii

#include <iostream>
#include <vector>
class Alg {
public:
  std::string s{};

  Alg() { std::getline(std::cin >> std::ws, s); }
  Alg(std::string s) : s(s) {}

  bool is_palindrome(std::string::iterator l, std::string::iterator r) {
    std::printf("l: %c r: %c \n", *l, *r);
    while (l < r) {
      if (*l != *r) {
        return false;
      }
      ++l;
      --r;
    }
    return true;
  }
  bool compute() {
    auto l{s.begin()};
    auto r{s.end()-1};

    while (l < r) {
      if (*l != *r) {
        return is_palindrome(l + 1, r) || is_palindrome(l, r - 1);
      }

      ++l;
      --r;
    }

    return true;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {

public:
  bool validPalindrome(std::string s) { return Alg(std::move(s)).compute(); }
};

