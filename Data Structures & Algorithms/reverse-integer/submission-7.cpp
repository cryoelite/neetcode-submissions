#include <limits>
#include <iomanip>
class Solution {
   public:
    int reverse(int x) {
        constexpr int INTMAX{numeric_limits<int>::max() / 10};
        constexpr int INTMIN{numeric_limits<int>::min() / 10};  // explained later

        // Check if x+y <= z, then you can rephrase it as, z-y>=x means it is fine, but if z-y< x
        // that means there is not enough space for x in x+y to fit z
        // Similarly, if we want to check if x*y <=z then, we can do z/y and if that number is >=x
        // then sure there is space for x to be multiplied by y and fit inside z, otherwise not.
        // Such as if x is 20, z is 50 and y is 2, then we get 25 from z/y which means x*y which is
        // 20*2 will fit as x is smaller than z/y

        int res{0};
        while (x != 0) {
            int digit{x % 10};

            x /= 10;
            // if ((INTMAX / 10 < res) || (INTMIN / 10 > res)) { //We would be checking if res*10 >
            // INTMAX which means we can check if INTMAX/10 < res for the same effect, and hence we
            // have already done INTMAX/10 to avoid redoing it for every loop. Same for INTMIN
            if (INTMAX < res || INTMIN > res) {
                return 0;  // This number will exceed INTMAX (or INTMIN)
            }
            res *= 10;
            res += digit;
        }

        return res;
    }
};
