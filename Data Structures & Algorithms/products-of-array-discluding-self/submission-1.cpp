class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t n{nums.size()};
        vector<int> output(n, 1);

        // Calculating prefix (except nums[i])
        int prefix{1};
        for (size_t i{0}; i < n - 1; ++i) {
            prefix *= nums[i];
            output[i + 1] = prefix;
        }

        // Calculating postfix (except nums[i])
        int postfix{1};
        for (int i{static_cast<int>(n - 1)}; i > 0; --i) {
            postfix *= nums[i];
            output[i - 1] *= postfix;
        }

        return output;
    }
};
