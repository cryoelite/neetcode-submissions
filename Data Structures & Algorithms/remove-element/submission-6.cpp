class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()<1){
            return 0;
        }
        auto l{nums.begin()};
        auto r{nums.end() - 1};
        
        int k{0};
        while (l < r) {
            if (*r == val) {
                --r;
                continue;
            }
            if (*l == val) {
                iter_swap(l, r);
                --r;
            }
            ++l;
        }
        

        for (int elem : nums) {
            if (elem == val) {
                break;
            } else {
                ++k;
            }
        }

        return k;
    }
};