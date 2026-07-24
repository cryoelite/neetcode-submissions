class Solution {
   public:
    // A simple solution with brute force, where we directly go through all subsets of the set nums,
    // and decide whether to include each element or not and sum both possibilities
    /*     int dfs(vector<int>& nums, size_t i, int total) {
            if (i==nums.size()) {
                return total;
            }

            return dfs(nums, i+1, total^nums[i]) + dfs(nums, i+1, total);
        }
        int subsetXORSum(vector<int>& nums) {
            return dfs(nums,0,0);
        } */

    int subsetXORSum(vector<int>& nums) {
        int res{0};
        for (int elem : nums) {
            res |= elem;
        }
        return res << (nums.size()-1);
    }
};