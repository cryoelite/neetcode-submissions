class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea{0};
        vector<pair<int, int>> s{};  // first is index, second is height
        const int n = heights.size();
        s.reserve(n);

        for (int i{0}; i < n; ++i) {
            if (s.empty() || heights[i] >= s.back().second) {
                maxArea = max(maxArea, heights[i]);
                s.push_back({i, heights[i]});
            } else {  // heights[i] is smaller than s.back()
                // calculating the area
                int pop_index{0};
                while (!s.empty() && heights[i] < s.back().second) {
                    int area{(i - s.back().first) * s.back().second};
                    pop_index = s.back().first;
                    s.pop_back();

                    maxArea = max(maxArea, area);
                }  // this computes an increasing height's area that
                // stopped increasing
                s.push_back({pop_index, heights[i]});
            }
        }

        while (!s.empty()) {
            int area{(n - s.back().first) * s.back().second};
            s.pop_back();
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
