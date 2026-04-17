#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int,26> f{};
        for(char c: s) {
            ++f[static_cast<int>(c)%26];
        }
        for(char c: t) {
            --f[static_cast<int>(c)%26];
        }
        for(int i{0};i<26;++i) {
            if(f[i]!=0){
                return false;
            }
        }
        return true;
    }
};
