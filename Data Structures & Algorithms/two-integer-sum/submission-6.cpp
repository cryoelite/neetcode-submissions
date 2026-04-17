// Problem: https://neetcode.io/problems/two-integer-sum

#include <iostream>
#include <unordered_map>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> arr{};
  int target{};

  Alg() {
    std::cin >> n >> target;
    arr = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
  }
  Alg(size_t n, std::vector<int> &&arr, int target)
      : n(n), arr(std::move(arr)), target(target) {}

  std::vector<int> compute() {
    auto result{std::vector<int>(2, 0)};
    auto cache{std::unordered_map<int, int>()};

    for (size_t i{0}; i < n; ++i) {
      int &elem{arr[i]};
      int diff{target - elem};
      auto f{cache.find(diff)};
      if (f == cache.end()) {
        cache.insert({elem, i});
      } else {
        result[0] = f->second;
        result[1] = i;
      }
    }
    return result;
  }

  void compute_and_output() {
    auto res{compute()};
    std::cout << res[0] << " " << res[1];
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    return Alg(nums.size(), std::move(nums), target).compute();
  }
};


