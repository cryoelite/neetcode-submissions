#include <array>
class Solution {
   public:
    bool isAnagram(string s, string t) {
        constexpr int N{26};
        array<int, N> f{};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i{0}; i < s.size(); ++i) {
            ++f[s[i] % N];
            --f[t[i] % N];
        }

        for (int i{0}; i < N; ++i) {
            if (f[i]) {
                return false;  // Since one array increased f[i], other decreased
                // f[i], if not all values of f are 0 by the end
                // it means the strings/arrays don't match.
            }
        }

        return true;
    }
};
