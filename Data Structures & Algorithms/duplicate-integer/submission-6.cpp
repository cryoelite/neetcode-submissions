class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> temp{};
        
        for(int elem: nums) {
            if(temp.contains(elem)){
                return true;
            } else {
                temp.insert(elem);
            }
        }

        return false;
    }
};