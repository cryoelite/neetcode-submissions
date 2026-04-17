class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        size_t n{nums.size()};
        vector<int> res(n*2,0);
        copy(nums.begin(),nums.end(),res.begin());
        copy(nums.begin(),nums.end(),res.begin()+n);
        return res;
    }
};