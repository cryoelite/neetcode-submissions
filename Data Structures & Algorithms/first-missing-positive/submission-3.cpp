class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        // 3 intuitions for the solution
        // 1. Given size n for nums, the solution is going to be between 1 and n+1.
        // Why? Because that's the maximum value of n, that is NOT in nums.
        // Like if we have n=3, then arr=[1,2,3] in which case n=4, res can never be 5
        // with n=3 because at most the 3 smallest +ve consecutive elements in nums
        // will be between 1 to n, otherwise, they can be any int, +ve or -ve, and
        // leave space for a +ve int to exist between 1 to n+1 (inclusive).
        //
        // That means we only need to query a data structure for values
        // in the nums, between 1 to n and if we find all, res is n+1, if we find
        // none then 1 is the res and so on. So we can use a hashmap, or,
        // even the input array itself as memory.
        //
        // 2. -ve values have no use towards finding our res. So we can discard
        // all of them and it wouldn't change our result. So we can 0 them all.
        //
        // 3. We can use the input array as the aux memory, making SC O(n).
        // And we do this by making any given int's position -ve, to denote
        // that this element does exist somewhere in the array (i.e., that position
        // will access this position and change it to a -ve int), this way,
        // we hold 2 literal bits of information, 1 that this int here at this
        // position still exists here so the value hasn't been erased, and 2., since
        // this is -ve that means this position's int does exist in the array.
        // Hence, we create an aux memory from the input array which contains
        // only the +ve int's values and then uses the signs to denote existence
        // and we can loop from 1 to n+1 to find the smallest int, hence res.
        // An edge case is when the int accesses a position where value
        // is 0, what in that case? In that case we store -(n+1) there
        // because this is an int that wouldn't affect the solution (as it's
        // larger than n so even if we loop over here, it wouldn't access any
        // position inside the array and hence make any change to the
        // final iteration), and it would still hold the sign
        // and hence the data that this position's int exists.
        int n = nums.size();

        // Zeroing the -ve values
        for (int i{0}; i < n; ++i) {
            nums[i] = (nums[i] < 0 ? 0 : nums[i]);
        }

        // Now going over the array and storing existences
        for (int i{0}; i < n; ++i) {
            int index{abs(nums[i]) - 1};    // converting values to 
                                            // respect 0th indexing.
            if (index >= n || index<0) {
                continue;
            }
            if (nums[index] == 0) {
                nums[index] = (n + 1) * -1;
            } else if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }

        for(int i: nums){
            cout<<i<<" ";
        }
        
        // Finally finding the smallest +ve int from 1 to n+1
        int res{n+1};
        for (int i{0}; i < n; ++i) {
            if (nums[i] >= 0) {  // if its 0 or +ve then this int doesn't exist,
                // hence answer
                res=i+1;
                break;
            }
        }

        return res;
    }
};