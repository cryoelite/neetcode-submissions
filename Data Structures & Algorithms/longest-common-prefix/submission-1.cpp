// Problem: https://neetcode.io/problems/longest-common-prefix

#include <iostream>
#include <string>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<std::string> arr{};

  Alg() {
    std::cin >> n;
    arr = std::vector<std::string>(n, "");

    for (size_t i = 0; i < n; i++) {
      std::getline(std::cin >> std::ws, arr[i]);
    }
  }
  Alg(size_t n, std::vector<std::string> &&arr) : n(n), arr(std::move(arr)) {}

  std::string compute() {
    std::string res{
        arr[0]}; // Can be used because arr is guaranteed to be >=1 element
    for (size_t i{1}; i < n; ++i) {
      while (res.size() >= 1) {
        if (arr[i].starts_with(res)) {
          break;
        } else {
          res = res.substr(0,res.size() - 1);
        }
      }
    }
    return res;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    return Alg(strs.size(), std::move(strs)).compute();
  }
};

