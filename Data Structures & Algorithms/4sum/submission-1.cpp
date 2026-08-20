class Solution {
    vector<vector<int>> res{};
    vector<int> temp{};

   public:
    void kSum(int k, int start, vector<int>& nums, long long target) {
        // base case
        if (k == 2) {  // Two Sum II
            int l{start};
            int r{static_cast<int>(nums.size()) - 1};
            while (l < r) {
                long long sum{nums[l] + nums[r]};
                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    res.push_back(temp);
                    res.back().insert(res.back().end(), {nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                }
            }
            return;
        }

        // Other cases
        for (int i{start}; i < (static_cast<int>(nums.size()) - k+1); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            kSum(k - 1, i + 1, nums, target - nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        kSum(4, 0, nums, target);
        return res;
    }
};