class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> temp{};
        vector<int> res(2,0);
        for(size_t i{0}; i<nums.size();++i) {
            auto elem{temp.find(target-nums[i])};
            if(elem!=temp.end()){
                res[0]=elem->second;
                res[1]=i;
                break;
            } else {
                temp[nums[i]]=i;
            }
        }

        return res;
    }
};
