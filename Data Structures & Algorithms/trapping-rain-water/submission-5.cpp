class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int res{0};

        int l{0};
        int r = height.size() - 1;
        int lmax{height[l]};
        int rmax{height[r]};
        while (l <= r) {
            if (lmax <= rmax) {
                int water = lmax - height[l];
                if (water > 0) {
                    res += water;
                }
                lmax = max(lmax, height[l]);
                ++l;
            } else {
                int water = rmax - height[r];
                if (water > 0) {
                    res += water;
                }
                rmax = max(rmax, height[r]);
                --r;
            }
        }
        return res;
    }
};
