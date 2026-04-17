class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string t{strs[0]};
        for(string_view s: strs) {

            while(t.size()>0 && !s.starts_with(t)){
                t=t.substr(0,t.size()-1);
            }
            if(t.size()==0) {
                break;
            }             
        }
        return t;
    }
};