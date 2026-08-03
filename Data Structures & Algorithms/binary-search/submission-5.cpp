class Solution {
   public:
    /*     int search(vector<int>& nums, int target) {
            // Iterative Binary Search
            int l{0}, r{static_cast<int>(nums.size()) - 1};

            while (l <= r) {
                int m = l + ((r - l) / 2);  // could overflow if we do l+r/2, as l+r can exceed int
       limit, another alg here could be l/2 + r/2 but we have to do float division because the
       exponents do matter, say l is 5 and r is 11, then m is 8 but int division would give 7
       because it will add 2+5, but if we do float division then we will get 2.5+5.5 and then we can
       floor the result. Same can be tested when l =1 and r=1.

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
        } */

    /* int search(vector<int>& nums, int target) {
        // Upper Bound Binary Search
        int l{0}, r{static_cast<int>(nums.size())};

        while (l < r) {
            int m = l + ((r - l) / 2);
            if (nums[m] <= target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m;
            }
        }
        if (l > 0 && nums[l - 1] == target) {
            return l - 1;
        }
        return -1;
    } */

    int search(vector<int>& nums, int target) {
        // Lower Bound Binary Search
        // The difference between Upper bound and lower bound is, upper bound finds the first value
        // that is greater than m, which means on the l. Whereas the lower bound finds the first
        // occurence of the value or a value greater than it, meaning if there are duplicates then
        // it finds the first occurence.
        int l{0}, r{static_cast<int>(nums.size())};

        while (l < r) {
            int m = l + ((r - l) / 2);
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (static_cast<size_t>(l) < nums.size() && nums[l] == target) {
            return l;
        }
        return -1;
    }
};
