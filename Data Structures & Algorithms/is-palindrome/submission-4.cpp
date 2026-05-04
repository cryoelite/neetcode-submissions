class Solution {
    bool is_valid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool compare(char a, char b) { return (a == b ? true : tolower(a) == tolower(b)); }

   public:
    bool isPalindrome(string s) {
        auto l{s.begin()};
        auto r{s.end() - 1};
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
};
