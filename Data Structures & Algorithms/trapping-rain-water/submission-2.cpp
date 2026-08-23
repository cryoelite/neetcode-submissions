class Solution {
   public:
    int trap(vector<int>& height) {
        // We need the biggest element from the right, it will divide
        // our rainwater collection into 2 parts, start to mid, and
        // then the end to mid.
        // Because up till mid, every l will be <=mid and it can be proven going
        // to mid from start will cover all pits to the left of this tower.
        // Then going from end to mid will cover all pits to the right of this tower.
        // As we will check increasingly bigger pits.
        int l{0};
        int r{static_cast<int>(height.size()) - 1};
        int mid{0};

        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > height[mid]) mid = i;
        }
        l = 0;
        r = 0;
        int temp{0};
        int res{0};
        while (r <= mid) {
            int hl = height[l];
            int hr = height[r];
            if (hr < hl) {
                temp += (hl - hr);
            } else {
                res += temp;
                temp = 0;
                l = r;
            }
            ++r;
        }
        // Now the right side
        l = height.size() - 1;
        r = height.size() - 1;
        temp = 0;
        while (l >= mid) {
            int hl = height[l];
            int hr = height[r];
            if (hl < hr) {
                temp += (hr - hl);
            } else {
                res += temp;
                temp = 0;
                r = l;
            }
            --l;
        }
        return res;
    }
};
