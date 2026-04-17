class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c{0};
        for(size_t i{0}; i<(sizeof(n)*8);++i) {
            if(n&(1<<i)) {
                ++c;
            }
        }
        return c;
    }
};
