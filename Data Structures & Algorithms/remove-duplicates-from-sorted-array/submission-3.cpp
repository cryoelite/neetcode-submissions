class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        auto cur{nums.begin()};
        auto sim{nums.begin() + 1};  // similarityPointer
        int res{1};
        while (sim < nums.end()) {
            if (*sim != *cur) {
                *(cur + 1) = *sim;
                ++cur;
                ++res;
            } 
            ++sim;
        }

        return res;
    }
};