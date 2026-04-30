#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res{strs[0]};
        for(string& elem: strs){
            while(!elem.starts_with(res)){
                res.pop_back();
            }
            if(res.empty()){
                break;
            }
        }

        return res;
    }
};