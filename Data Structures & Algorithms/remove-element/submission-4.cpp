class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t n{nums.size()};
        
        if (n==0) {
            return 0;
        }
        int p_1{0};
        int p_2{static_cast<int>(n)-1};
        int res{0};

        while(p_1<p_2) {
            if(nums[p_1] == val) {
                swap(nums[p_1], nums[p_2]);
                --p_2;
                
            }
            else {
                ++p_1;
            }
        }

        for(int elem: nums) {
            if(elem==val) {
                break;
            } else {
                ++res;
            }
        }
        
        return res;
    }
};