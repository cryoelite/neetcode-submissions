class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        size_t n{nums.size()};
        set<int> t{};
        for(int elem:nums) {
            if(t.find(elem)==t.end()) {
                t.insert(elem);
            }
            else {
                return true;
            }
        }

        return false;
    }
};