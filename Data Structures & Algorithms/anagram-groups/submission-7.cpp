#include <array>
#include<sstream>
class Solution {
public:
    string get_unique_key(string_view s) {
        array<int,26> t{};
        for(char c: s) {
            ++t[static_cast<int>(c)%26];
        }
        stringstream ss{};
        for(int i{0}; i<26; ++i)
        {
            ss<<i<<":"<<t[i]<<" ";
        }
        return ss.str();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res{};
        unordered_map<string, vector<string>> t{};

        for(string& s: strs) {
            string uq{get_unique_key(s)};
            auto it{t.find(uq)};
            if(it==t.end()) {
                t.insert({uq, vector<string>({s})});
            } else {
                it->second.emplace_back(s);
            }
        }
        for(auto &elem: t) {
            res.emplace_back(std::move(elem.second));
        }
        return res;
    }
};
