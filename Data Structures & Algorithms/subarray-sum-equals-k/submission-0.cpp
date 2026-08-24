#include <unordered_map>
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ps{};
        ps[0] = 1;
        int res{0};
        int sum{0};
        for (int elem : nums) {
            sum+=elem;
            res += ps[sum-k];
            ++ps[sum];
        }
        return res;
    }
};