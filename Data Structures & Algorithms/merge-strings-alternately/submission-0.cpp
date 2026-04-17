// Problem: https://neetcode.io/problems/merge-strings-alternately

#include <iostream>
#include <string>
class Alg {
public:
  std::string a{};
  std::string b{};

  Alg() {
    std::getline(std::cin >> std::ws, a);
    std::getline(std::cin >> std::ws, b);
  }
  Alg(std::string &&a, std::string &&b) : a(std::move(a)), b(std::move(b)) {}

  std::string compute() {
    std::string result{};

    const size_t m{a.length()};
    const size_t n{b.length()};
    result.reserve(m + n);
    for (size_t i{0}; i < std::max(m, n); ++i) {
      if (i < m) {
        result.push_back(a[i]);
      }
      if (i < n) {
        result.push_back(b[i]);
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
  std::string mergeAlternately(std::string word1, std::string word2) {
    return Alg(std::move(word1), std::move(word2)).compute();
  }
};

