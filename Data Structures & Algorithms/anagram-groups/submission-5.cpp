// Problem: https://neetcode.io/problems/anagram-groups

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<std::string> strs{};
  static constexpr int T{26};

  Alg() {
    std::cin >> n;
    strs = std::vector<std::string>(n, "");

    for (size_t i = 0; i < n; i++) {
      std::getline(std::cin >> std::ws, strs[i]);
    }
  }
  Alg(size_t n, std::vector<std::string> &&strs)
      : n(n), strs(std::move(strs)) {}

  std::string get_unique_str_key(std::string_view x) {
    std::string key{""};
    std::array<int, T> res{};
    std::fill(res.begin(), res.end(), 0);

    for (auto &elem : x) {
      ++res[static_cast<int>(elem) % T];
    }
    for (int i{0}; i < T; ++i) {
      key += std::to_string(res[i]) + ",";
    }
    return key;
  }

  std::vector<std::vector<std::string>> compute() {
    auto res{std::vector<std::vector<std::string>>()};
    auto t{std::unordered_map<std::string, std::vector<std::string>>()};
    for (size_t i{0}; i < n; ++i) {
      std::string c{get_unique_str_key(strs[i])};

      if (t.find(c) == t.end()) {
        t[c] = std::vector<std::string>({strs[i]});
      } else {
        t[c].emplace_back(strs[i]);
      }
    }

    for (auto &elem : t) {
      res.emplace_back(elem.second);
    }

    return res;
  }

  void compute_and_output() {
    auto res{compute()};
    for (auto &elem : res) {
      std::cout << "[ ";
      for (auto sub_elem : elem) {
        std::cout << sub_elem << ",";
      }
      std::cout << " ]\n";
    }
    std::cout << std::endl;
  }
};

class Solution {

public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    return Alg(strs.size(), std::move(strs)).compute();
  }
};

