// Problem: https://neetcode.io/problems/add-binary

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
class Alg {
public:
  std::string a;
  std::string b;

  Alg() {
    std::getline(std::cin >> std::ws, a);
    std::getline(std::cin >> std::ws, b);
  }
  Alg(std::string a, std::string b) : a(a), b(b) {}

  int char_bit_to_int(char elem) {
    return (static_cast<int>(elem) - static_cast<int>('0'));
  }
  char int_to_char_bit(int elem) {
    return (static_cast<char>((elem) + static_cast<int>('0')));
  }

  /// Results are reversed, that is if the result of `01` + `01` = `10` then
  /// this will return `01`
  std::array<char, 2> rev_adder(int x, int y, int carry) {
    int sum{x + y + carry};
    auto res{std::array<char, 2>({'0', '0'})};
    res[0] = int_to_char_bit(sum & 1);
    res[1] = int_to_char_bit((sum & (1 << 1)) != 0);

    return res;
  }
  std::string compute() {
    std::string result{};
    int carry{0};

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (size_t i{0}; i < std::max(a.size(), b.size()); ++i) {
      int val1{0};
      int val2{0};

      if (i < a.size()) {
        val1 = char_bit_to_int(a[i]);
      }
      if (i < b.size()) {
        val2 = char_bit_to_int(b[i]);
      }
      auto res{rev_adder(val1, val2, carry)};
      carry = char_bit_to_int(res[1]);
      result += res[0];
    }
    if (carry) {
      result += int_to_char_bit(carry);
    }
    std::reverse(result.begin(), result.end());

    return result;
  }

  void compute_and_output() {
    std::cout << compute();
    std::cout << std::endl;
  }
};

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    return Alg(a, b).compute();
  }
};

