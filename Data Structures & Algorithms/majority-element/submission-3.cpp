class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count{0};
        int cur{nums[0]};
        for(int elem: nums) {
            if(elem==cur){
                ++count;
            } else{
                if(count==0){
                    cur=elem;
                    count=1;
                } else {
                    --count;
                }
            }
        }
        return cur;
    }
};