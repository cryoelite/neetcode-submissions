class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res{};
        int r{0};
        int l{1};
        for (int p : piles) {
            r = max(r, p);
        }
        res = r;
        while (l <= r) {
            int k = l + ((r - l) / 2);
            long time{0};
            for (int p : piles) {
                time += ceil(static_cast<double>(p) / k);
            }
            if (time > h) {
                l=k+1;
            } else { //we also have a possible solution
                res=k;
                r=k-1;
            }
        }

        return res;
    }
};
