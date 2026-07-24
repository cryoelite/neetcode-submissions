class Solution {
public:
    int dfs(vector<int>& nums, size_t i, int total) {
        if (i==nums.size()) {
            return total;
        }

        return dfs(nums, i+1, total^nums[i]) + dfs(nums, i+1, total);
    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums,0,0);
    }
};