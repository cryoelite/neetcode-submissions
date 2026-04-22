#include <limits>
#include <iomanip>
class Solution {
   public:
    int reverse(int x) {
        // constexpr int INTMAX{static_cast<unsigned int>(0 - 1) / 2}; //clever, works too, but non
        // standard
        constexpr int INTMAX{numeric_limits<int>::max()};
        constexpr int INTMIN{numeric_limits<int>::min()};
        const int LOG10INTMAX{static_cast<int>(pow(10, ceil(log10(INTMAX)) - 1))};
        const int LOG10INTMIN{-1 * static_cast<int>(pow(10, ceil(log10(INTMIN)) - 1))};

        // Checking if reverse of x exceeds the bounds
        // cout << fixed << "max: " << INTMAX
        //     << " Calc: " << static_cast<int>(pow(10, ceil(log10(INTMAX)) - 1)) << '\n';
        // Check if x+y <= z, then you can rephrase it as, z-y>=x means it is fine, but if z-y< x
        // that means there is not enough space for x in x+y to fit z
        // Similarly, if we want to check if x*y <=z then, we can do z/y and if that number is >=x
        // then sure there is space for x to be multiplied by y and fit inside z, otherwise not.
        // Such as if x is 20, z is 50 and y is 2, then we get 25 from z/y which means x*y which is
        // 20*2 will fit as x is smaller than z/y

        int res{0};
        while (x != 0) {
            int digit{x % 10};
            cout << "digit: " << digit << " x: " << x << " res: " << res << '\n';
            x /= 10;
            if ((INTMAX / 10 < res) || (INTMIN / 10 > res)) {
                return 0;  // This number will exceed INTMAX (or INTMIN)
            }
            res *= 10;
            res += digit;
            cout << "new x: " << x << " new res: " << res << '\n';
        }
        

        return res;
    }
};
