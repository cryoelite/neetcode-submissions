class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        auto l{numbers.begin()};
        auto r{numbers.end() - 1};
        while (l <= r) {
            int sum{*l + *r};
            if (sum == target) {
                res[0] = distance(numbers.begin(), l)+1;
                res[1] = distance(numbers.begin(), r)+1;
                break;
            } else if (sum < target) {
                ++l;
            } else {  // sum is > target
                --r;
            }
        }

        return res;
    }
};
