class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // One pass binary search
        size_t rows{matrix.size()};
        size_t cols{matrix[0].size()};

        long long n{static_cast<int>(rows * cols)};
        long long r{n-1};
        long long l{0};

        while (l <= r) {
            int m = (l + ((r - l) / 2));
            size_t row{static_cast<size_t>(m / cols)};
            size_t col{static_cast<size_t>(m % cols)};

            int val{matrix[row][col]};

            if (val > target) {
                r = m - 1;
            } else if (val < target) {
                l = m + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
