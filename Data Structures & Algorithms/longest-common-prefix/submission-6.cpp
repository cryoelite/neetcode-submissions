#include <string>
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res{strs[0]};
        for (const string& str : strs) {
            while (!res.empty() && !str.starts_with(res)) {
                res.pop_back();
            }
            if(res.empty()){
                break;
            }
        }

        return res;
    }
};