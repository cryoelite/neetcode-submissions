class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i{0}, l{0}, r{static_cast<int>(nums.size())-1}; i<=r;) {
          if(nums[i] == 0){
            swap(nums[i], nums[l]);
            ++l;
            ++i;
          } else if(nums[i]==2){
            swap(nums[i], nums[r]);
            --r;
          } else {
            ++i;
          }
        }
    }
};