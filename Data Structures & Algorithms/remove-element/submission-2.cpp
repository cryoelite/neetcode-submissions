// Problem: https://neetcode.io/problems/remove-element

#include <iostream>
#include <vector>
class Alg {
public:
  size_t n{};
  std::vector<int> arr{};
  int val{};

  Alg() {
    std::cin >> n >> val;
    arr = std::vector<int>(n, 0);

    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }
  }
  Alg(size_t n, std::vector<int> &&arr, int val)
      : n(n), arr(std::move(arr)), val(val) {}

  int compute() {
    int result{0};
    auto l{arr.begin()};
    auto r{arr.end() - 1};

    while (l != r && r > l) {
      if (*l == val) {
        std::iter_swap(l, r);
        --r;
        ++result;
      } else {
        ++l;
      }
    }
    if (*(arr.end() - 1) == val) {
      ++result;
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
  int removeElement(std::vector<int> &nums, int val) {
        int result{0};
    auto l{nums.begin()};
    auto r{nums.end() - 1};

    while (l <= r && l != nums.end()) {
      if (*l == val) {
        std::iter_swap(l, r);
        --r;
      } else {
        ++l;
        ++result;
      }
    }

    return result;;
  }
};


