#include <string>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        auto s1{word1.size()};
        auto s2{word2.size()};
        size_t n{max(s1,s2)};
        string res{""};
        res.reserve(n);
        for(size_t i{0}; i<n; ++i) {
            if(i<s1){
                res.push_back(word1[i]);
            }
            if(i<s2){
                res.push_back(word2[i]);
            }
        }
        return res;
    }
};