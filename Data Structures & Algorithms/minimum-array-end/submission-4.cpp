class Solution {
   public:
    long long minEnd(int n, int x) {
        if (n == 1) {
            return x;
        }
        // We can skip creating the array and all that, because the logic can be built for skipping
        // it

        // Say n is 5 and x is 3, we get in the array 000011, 111, 1011, 1111, 10011, which is just
        // counting binary up after the common bits, which have to be common to give x after ANDing
        // all values in the range. If we look at the final value in the list, we can see that it is
        // basically, (n-1)(x) written in binary
        long long res{0LL};
        // we need n-1, because the first value in arr is x
        // we have binary value of n-1
        // now we just need to take y bits of x, from the right, which are 0, and impose binary
        // value of n-1 onto them. The y bits is retrieved from what power of 2 is n-1 is closest to
        // (ceiling), like 5 is closest to 2^3 as we need 3 bits to represent 5.
        long long last_elem{n - 1};
        long long bits{static_cast<long long>(
            floor(log2(last_elem)) +
            1)};  // here we add floor and add 1 because say n-1=4, we need 3 bits for it, not 2.

        res |= x;  // initialized res
        
        for(long long i{0},j{0}; i<bits && j<sizeof(res)*8; ++j) {
            long long rbit{(last_elem>>i)&1LL};
            long long current_bit{(res>>j)&1LL};
            if(!current_bit) {
                res|=(rbit<<j);
                ++i;
            }
        }

        return res;
    }
};