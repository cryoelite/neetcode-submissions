#include <array>

class Solution {
public:
    string get_unique_key(string_view s) {
        array<int,26> t{};
        for(char c: s) {
            ++t[c-'a'];
        }
        string res{};
        res.reserve(26*7);
        for(int count: t)
        {
            res.push_back('#');
            res += to_string(count);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res{};
        unordered_map<string, vector<string>> t{};

        for(string& s: strs) {
            string uq{get_unique_key(s)};
            t[uq].push_back(s);
        }
        for(auto &elem: t) {
            res.emplace_back(std::move(elem.second));
        }
        return res;
    }
};
//TC: O(N*K) SC: O(N)