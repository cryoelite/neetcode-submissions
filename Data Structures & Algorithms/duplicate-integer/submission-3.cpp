// Problem: https://neetcode.io/problems/duplicate-integer

#include <iostream>
#include <unordered_set>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> arr{};

  Alg() {
    std::cin >> n;
    arr = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
  }
  Alg(size_t n, std::vector<int> &&arr) : n(n), arr(std::move(arr)) {}

  bool compute() {
    bool result{false};
    std::unordered_set t{std::unordered_set<int>()};
    t.reserve(n);

    for (size_t i{0}; i < n; ++i) {
      if (t.find(arr[i]) == t.end()) {
        t.insert(arr[i]);
      } else {
        result = true;
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
  bool hasDuplicate(std::vector<int> &nums) {
    return Alg(nums.size(), std::move(nums)).compute();
  }
};

