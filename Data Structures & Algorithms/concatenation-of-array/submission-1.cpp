class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t n {nums.size()};
        auto ans {std::vector<int>(2*n,0)};
        
        for(size_t i{0}; i<n; ++i) {
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
    }
};