class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        // Upper Bound Binary search
        int l{0};
        int r{static_cast<int>(nums.size())};
        while (l < r) {
            int m{l + ((r - l) / 2)};
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l > 0 && nums[l-1]==target) {
            return l - 1;
        } else {
            return l;
        }
    }
};