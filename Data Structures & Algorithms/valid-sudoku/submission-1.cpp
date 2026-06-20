#include <array>
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr int N{9};
        // 1-indexed to make algorithm more convenient to understand
        array<array<bool, N + 1>, N + 1> squares{};
        array<array<bool, N + 1>, N + 1> rows{};
        array<array<bool, N + 1>, N + 1> cols{};

        for (size_t i{0}; i < N; ++i) {
            for (size_t j{0}; j < N; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                bool& r{rows[i+1][board[i][j] - '0']};
                bool& c{cols[j+1][board[i][j] - '0']};
                bool& s{squares[(i/3)*3 + (j/3)][board[i][j] - '0']};
                
                if(s || r || c) { //Value is already present at the given indices
                    return false;
                } else { //meaning all 3 of them are false (unintialized)
                    s=true;
                    r=true;
                    c=true;
                }
            }
        }
        return true;
    }
};
