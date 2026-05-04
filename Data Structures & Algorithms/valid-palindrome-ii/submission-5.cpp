#include <string>
class Solution {
    bool is_valid(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
    bool compare(char a, char b) { return (a == b ? true : tolower(a) == tolower(b)); }

    bool valid_palindrome_sub(string::iterator l, string::iterator r) {
        while (l < r) {
            bool is_l_valid{is_valid(*l)};
            bool is_r_valid{is_valid(*r)};
            if (is_l_valid && is_r_valid) {
                if (!compare(*l, *r)) {
                    return false;
                }
                ++l;
                --r;
            } else if (!is_l_valid) {
                ++l;
            } else if (!is_r_valid) {
                --r;
            }
        }
        return true;
    }

   public:
    bool validPalindrome(string s) {
        auto l{s.begin()};
        auto r{s.end() - 1};
        while (l < r) {
            bool is_l_valid{is_valid(*l)};
            bool is_r_valid{is_valid(*r)};
            if (is_l_valid && is_r_valid) {
                if (!compare(*l, *r)) {
                    return valid_palindrome_sub(l + 1, r) || valid_palindrome_sub(l, r - 1);
                }
                ++l;
                --r;
            } else if (!is_l_valid) {
                ++l;
            } else if (!is_r_valid) {
                --r;
            }
        }
        return true;
    }
};