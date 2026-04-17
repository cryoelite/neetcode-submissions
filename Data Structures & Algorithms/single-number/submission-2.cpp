class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int dup{0};
        for(int elem: nums) {
            dup^=elem;
        }
        return dup;
    }
};
