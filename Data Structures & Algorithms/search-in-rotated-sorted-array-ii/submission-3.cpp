class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int l{0};
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return true;
            }

            if (nums[l] == nums[m]) {
                l=l+1; //The reason we do l+1 and not directly shift
                //l to m+1 is because a value can appear between l and m
                //that is smaller, like in [1,0,1,1,1].
            } else {
                if (nums[l] <= nums[m]) {
                    if (target >= nums[l] && target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if (target <= nums[r] && target > nums[m]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }

        return false;
    }
};