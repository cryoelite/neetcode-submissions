// Problem: https://neetcode.io/problems/duplicate-integer

#include <iostream>
#include <unordered_map>
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
    auto nums_map{std::unordered_map<int, int>()};
    for (int elem : arr) {
      if (nums_map.find(elem) == nums_map.end()) {
        nums_map.insert({elem, 0});
      } else {
        return true;
      }
    }
    return false;
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