// Problem: https://neetcode.io/problems/missing-number

#include <iostream>
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

  int compute() {
    int result{0};

    for (size_t i{0}; i <= n; ++i) {
      result ^= i;
      if (i<n) {
        result ^= arr[i];
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
  int missingNumber(std::vector<int> &nums) {
    return Alg(nums.size(), std::move(nums)).compute();
  }
};

