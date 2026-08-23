class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int res{0};
        int l{0};
        int r{static_cast<int>(people.size()) - 1};
        while (l <= r) {
            int& pl{people[l]};
            int& pr{people[r]};
            if (pl + pr <= limit) {
                ++l;
            }
            ++res;
            --r;
        }
        return res;
    }
};