// Problem: https://neetcode.io/problems/is-anagram

#include <array>
#include <iostream>
#include <string>
class Alg {
public:
  std::string s{};
  std::string t{};

  Alg() {
    std::getline(std::cin >> std::ws, s);
    std::getline(std::cin >> std::ws, t);
  }
  Alg(std::string &&s, std::string &&t) : s(std::move(s)), t(std::move(t)) {}

  bool compute() {
    auto f{std::array<int, 26>()};
    for (char elem : s) {
      ++f[static_cast<int>(elem) % 26];
    }
    for (char elem : t) {
      --f[static_cast<int>(elem) % 26];
    }

    for (int i{0}; i < 26; ++i) {
      if (f[i] != 0) {
        return false;
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
  bool isAnagram(std::string s, std::string t) {
    return Alg(std::move(s), std::move(t)).compute();
  }
};
