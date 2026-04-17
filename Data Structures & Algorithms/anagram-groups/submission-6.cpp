// Problem: https://neetcode.io/problems/anagram-groups

#include <array>
#include <iostream>
#include <map>
#include <sstream>
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

  std::string get_unique_key(const std::string_view s) {
    auto f_arr{std::array<int, 26>()};
    auto res{std::stringstream()};
    for (char c : s) {
      ++f_arr[static_cast<int>(c) % 26];
    }
    for (int i{0}; i < 26; ++i) {
      res << i << ":" << f_arr[i] << " ";
    }
    return res.str();
  }

  std::vector<std::vector<std::string>> compute() {
    auto res{std::vector<std::vector<std::string>>()};
    auto cache{std::map<std::string, std::vector<size_t>>()};

    for (size_t i{0}; i < n; ++i) {
      std::string signature{get_unique_key(strs[i])};
      auto it{cache.find(signature)};
      if (it != cache.end()) {
        it->second.emplace_back(i);
      } else {
        cache.insert({signature, std::vector<size_t>({i})});
      }
    }
    for (auto &elem : cache) {
      res.emplace_back(std::vector<std::string>());
      for (auto index : elem.second) {
        (res.end() - 1)->emplace_back(strs[index]);
      }
    }

    return res;
  }

  void compute_and_output() {
    auto res{compute()};
    for (auto &elem : res) {
      for (auto &sub_elem : elem) {
        std::cout << sub_elem << ' ';
      }
      std::cout << '\n';
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


