// Problem: https://neetcode.io/problems/longest-common-prefix

#include <iostream>
#include <string>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<std::string> strs{};

  Alg() {
    std::cin >> n;
    strs = std::vector<std::string>(n, "");

    for (size_t i = 0; i < n; i++) {
      std::getline(std::cin >> std::ws, strs[i]);
    }
  }
  Alg(size_t n, std::vector<std::string> &&strs)
      : n(n), strs(std::move(strs)) {}

  /// Returns true if string x starts with y
  bool starts_with(std::string_view x, std::string_view y) {

    if (x.size() < y.size()) {

      return false;
    }
    for (size_t i{0}; i < x.size(); ++i) {
      if (i >= y.size()) {
        break;
      }
      if (x[i] != y[i]) {

        return false;
      }
    }

    return true;
  }
  std::string compute() {
    std::string result{strs[0]};
    for (std::string &str : strs) {
      while (!starts_with(str, result)) {
        if (result.size() == 0) {
          break;
        }
        result = result.substr(0, result.size() - 1);
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
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    return Alg(strs.size(), std::move(strs)).compute();
  }
};

