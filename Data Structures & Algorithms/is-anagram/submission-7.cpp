#include <array>
class Solution {
    static constexpr int N{26};

   public:
    bool isAnagram(string s, string t) {
        array<int, N> f{};
        size_t n_s{s.size()};
        size_t n_t{t.size()};
        for (size_t i{0}; i < max(n_s, n_t); ++i) {
            if (i < n_s) {
                
                ++f[static_cast<int>(s[i])%N];
            }
            if (i < n_t) {
                --f[static_cast<int>(t[i])%N];
            }
        }

        for (size_t i{0}; i < N; ++i) {
            
            if (f[i]) { //meaning some character exists in either that is not in the other
                return false; //s isn't an anagram of t
            }
        }

        return true;
    }
};
