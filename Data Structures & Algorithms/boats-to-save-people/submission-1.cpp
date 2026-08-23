class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); //We can use counting sort here as 
        //which will reduce the TC to O(n) instead of O(nlogn) but increase the
        //SC to O(m) where m is the maximum element in people
        //The intuition is, that counting sort can be used because the value m
        //is limited and small.

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