// Problem: https://neetcode.io/problems/is-palindrome

#include <iostream>
#include <vector>
class Alg {
public:
  std::string s{};

  Alg() { std::getline(std::cin >> std::ws, s); }
  Alg(std::string &&s) : s(std::move(s)) {}

  bool is_char_in_range(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= '0' && c < '9'));
  }
  bool compute() {
    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {
      char l_lower{char(tolower(*l))};
      char r_lower{char(tolower(*r))};
      if (!is_char_in_range(l_lower)) {
        ++l;
        continue;
      }
      if (!is_char_in_range(r_lower)) {
        --r;
        continue;
      }
      if (l_lower != r_lower) {
        return false;
      } else {
        ++l;
        --r;
      }
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
  bool isPalindrome(std::string s) { return Alg(std::move(s)).compute(); }
};

