class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l{};
        int r{};
        int res{};
        for (int w : weights) {
            l = max(l, w);
            r += w;
        }
        res = r;
        while (l <= r) {
            int m = l + ((r - l) / 2);
            int capacity{0};
            int day{1};
            for (int w : weights) {
                if (capacity + w > m) {
                    capacity = w;
                    ++day;
                } else {
                    capacity += w;
                }
            }

            if (day > days) {
                l = m + 1;
            } else {
                res = m;
                r = m - 1;
            }
        }

        return res;
    }
};