class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count{0};
        int res{nums[0]};
        for(int elem: nums) {
            if(res==elem){
                ++count;
            } else{
                if(count==0) {
                    res=elem;
                    count=1;
                } else {
                    --count;
                }
            }
        }

        return res;
    }
};