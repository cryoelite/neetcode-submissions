class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        auto cur{nums.begin()};
        auto sim{nums.begin() + 1};  // similarityPointer
        int res{static_cast<int>(nums.size())};
        while (sim < nums.end()) {
            if (*sim != *cur) {
                *(cur + 1) = *sim;
                ++cur;
            } else {
                --res;
            }
            ++sim;
        }

        return res;
    }
};