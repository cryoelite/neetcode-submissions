#include <array>
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        array<int, 3> count{};
        for (int e : nums) {
            ++count[e];
        }

        for (size_t i{0}; i < nums.size(); ++i) {
            if (count[0]) {
                nums[i] = 0;
                --count[0];
                continue;
            } else if (count[1]) {
                nums[i] = 1;
                --count[1];
                continue;
            } else {
                nums[i] = 2;
                --count[2];
                continue;
            }
        }
    }
};