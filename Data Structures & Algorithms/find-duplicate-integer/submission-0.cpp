class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow{nums[0]}; //comparing values, not indices
        int fast{nums[nums[0]]}; 
        
        while(fast!=slow) {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        int slow2{0};
        
        while(slow2!=slow) {
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};
