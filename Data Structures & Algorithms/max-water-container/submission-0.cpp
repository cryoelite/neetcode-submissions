class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l{0};
        int r{static_cast<int>(heights.size())-1};
        int res{0};
        while (l < r) {
            int& lh{heights[l]};
            int& rh{heights[r]};
            int area{(r - l) * (min(lh, rh))};
            res=max(res,area);
            if(lh < rh) {
                ++l;
            } else if (rh < lh) {
                --r;
            } else {
                ++l;
            }
        }
        return res;
    }
};
