class NumMatrix {
    vector<vector<int>> prefix;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        const size_t rows{matrix.size()};
        const size_t cols{matrix[0].size()};
        prefix = vector<vector<int>>(
            rows + 1,
            vector<int>(cols +
                        1));  //+1 to have an offset row and column which eases calculations later
        for (size_t i{1}; i <= rows; ++i) {
            for (size_t j{1}; j <= cols; ++j) {
                prefix[i][j] +=
                    prefix[i - 1][j] + prefix[i][j - 1] +
                    matrix[i - 1][j - 1];  // encoded prefix sum into the current position

                prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        for (auto& i : prefix) {
            for (int j : i) {
                cout << j << ' ';
            }
            cout << '\n';
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1+=1;
        col1+=1;
        row2+=1;
        col2+=1;
        int sum{prefix[row2][col2]};  // Has the sum of the box from (0,0) to (row2,col2)
        // Now to subtract the overarching regions
        sum -= prefix[row1 - 1][col2];
        sum -= prefix[row2][col1 - 1];
        sum += prefix[row1 - 1][col1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */