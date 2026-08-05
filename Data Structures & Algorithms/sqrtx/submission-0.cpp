class Solution {
public:
    // 3 approaches.
    // Brute force: We iterate from 0 (as our n is in the range 0 to n) to n
    // And for each element check if it*it <= n, if so we go terate ahead until it*it>n
    // Then we just take the last it value and that is our result (this is because either)
    // it*it == n or it*it <n, if it is <n and then becomes >n then it means that the root
    // has fractional value, but we have to discard it anyway and round down, so we can 
    // just take the last value that was <=n. TC appears to be O(n) but in actual we will
    // only loop till sqrt(n) so TC is O(sqrt(n)).

    // Second is binary search between the same range, 0 to n, and we apply the same logic
    // except we check m*m against n. The intuition is, that if there's a sequence of
    // increasing/decreasing numbers, binary search can be used in place of linear search
    // to cut the problem space in half at each turn, making the TC O(logn). logn is
    // slower than sqrt(n) in terms of growth.

    // Last is Newton's method. It says that if r^2=x, then we can find the root of the
    // equation f(r)=r^2-x. Newton's iteration formula gives us r_new= (r+x/r)/2. Starting
    // with r=x, we can repeatedly apply this formula to bring the value of r^2<=x, and
    // this is quick as well. TC is O(logn).

    int mySqrt(int x) {
        long long r{x}; //r*r can overflow if x is at the limit
        while(r*r > x) {
            r=(r+x/r)>>1;
        }
        return r;
    }
};