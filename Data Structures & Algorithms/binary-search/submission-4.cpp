class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // Iterative Binary Search
        int l{0}, r{static_cast<int>(nums.size()) - 1};

        while (l <= r) {
            int m = l + ((r - l) / 2);  // could overflow if we do l+r/2 as l+r can exceed int limit
            
            // cout<<"l: "<<l<<" m: "<<m<<" r: "<<r<<'\n';
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
