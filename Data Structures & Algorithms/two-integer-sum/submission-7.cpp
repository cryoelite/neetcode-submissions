class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,0);
        unordered_map<int,int> t{};
        for(size_t i{0};i<nums.size();++i) {
            int diff{target-nums[i]};
            auto it{t.find(diff)};
            if(it == t.end()) {
                t.insert({nums[i],i});
            } else {
                res[0]= it->second;
                res[1]= i;
                break;
            }
        }
        return res;
    }
};
