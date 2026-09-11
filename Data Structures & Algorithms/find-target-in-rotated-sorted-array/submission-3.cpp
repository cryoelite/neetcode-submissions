class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l{0};
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            if (nums[m] == target) {
                return m;
            }
            // The key intuition is, figuring out where m is,
            // whether it and hence you, are in the left sorted portion
            // or in the right sorted portion.
            // Once you figure that out, you can easily know if the target
            // is a part of the current subarray or not and hence lead m
            // in the right direction.
            if (nums[l] <= nums[m]) {  // Meaning m is a part of the left
                // sorted portion
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {  // This is when the left sorted portion, i.e., l..m,
                    // do not have all the values that could be a part of it
                    // like if we had [2,3,4,5,1] and m was at 4, target was 5,
                    // then you can see that we will need to go to the right even
                    // though target is >l
                    l = m + 1;
                }
            } else {  // We are in the right sorted portion. Like if we had
                //[5,1,2,3,4] and m was at 2
                if (target <= nums[r] && target > nums[m]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
