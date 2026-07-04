#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set s(nums.begin(), nums.end());
        int res{0};
        for(int i: nums) {
            if((i-1) < i && s.find(i-1)!=s.end()) {
                continue;
            }
            else {
                int cur{1};
                int val{i+1};
                auto it{s.find(val)};
                while(it!=s.end()){
                    ++cur;
                    ++val;
                    it=s.find(val);
                }
                res=max(res,cur);
            }
        }

        return res;
    }
};
