#include<string>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t larger_n{max(word1.size(),word2.size())};
        string res{""};
        res.reserve(larger_n);
        for(size_t i{0}; i<larger_n;++i){
            if(i<word1.size()){
                res+=word1[i];
            }
            if(i<word2.size()){
                res+=word2[i];
            }
        }
        return res;
    }
};