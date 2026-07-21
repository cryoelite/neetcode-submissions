class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto l{nums.begin()};
        auto r{nums.begin() + 1};
        while (r < nums.end()) {
            //cout << "Checking l: " << *l << " r: " << *r << '\n';
            if (l != r && *l == *r && distance(l, r) <= k) {
                return true;
            }

            if (distance(l, r + 1) > k) {
                ++l;
            } else {
                ++r;
            }
        }

        return false;
    }
};