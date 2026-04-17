// Problem: https://neetcode.io/problems/majority-element

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
    int count{0};
    for (size_t i{0}; i < n; ++i) {
      if (arr[i] != result) {
        if (count - 1 < 0) {
          result = arr[i];
          count = 1;
        } else {
          --count;
        }
      } else {
        ++count;
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
  int majorityElement(std::vector<int> &nums) {
    return Alg(nums.size(), std::move(nums)).compute();
  }
};

