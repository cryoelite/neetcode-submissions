// Problem: https://neetcode.io/problems/reverse-string

#include <iostream>
#include <vector>
class Solution {
public:
  void reverseString(std::vector<char> &s) {
    if (s.size() <= 1) {
      return;
    }

    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {

      std::iter_swap(l++, r--);
    }
    return;
  }
};