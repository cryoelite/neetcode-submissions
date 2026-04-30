#include<iterator>
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res{};
        res.reserve(nums.size()*2);
        copy(nums.begin(),nums.end(), std::back_inserter(res));
        copy(nums.begin(),nums.end(), std::back_inserter(res));

        return res;
    }
};