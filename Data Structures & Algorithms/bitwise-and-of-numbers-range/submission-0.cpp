class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int res{0};
        size_t n{(sizeof(left) * 8) - 1};

        for (int i{static_cast<int>(n)}; i >= 0; --i) {
            int bit_l{(left >> i) & 1};
            int bit_r{(right >> i) & 1};
            cout << "i: " << i << " l: " << bit_l << " r: " << bit_r << " res: " << res <<'\n';
            if (bit_l != bit_r) {
                break;
            }
            res |= ((bit_l & bit_r) << i);
        }
        return res;
    }
};