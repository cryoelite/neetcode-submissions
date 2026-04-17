class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t n{nums.size()};
        vector<int> res {vector<int>(n*2,0)};
        for(size_t i {0}; i<(n*2); ++i) {
            res[i]=nums[i%n];
        }
        return res;
    }
};