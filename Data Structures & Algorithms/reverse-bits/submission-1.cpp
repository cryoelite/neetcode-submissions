class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{0};
        size_t s{(sizeof(n)*8)-1};
        for(uint32_t i{0}; i<=s; ++i) {
            uint32_t b{(n>>(s-i)) & 1};
            res |= (b<<i);
        }
        return res;
    }
};
