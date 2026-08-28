#include <algorithm>
#include <ranges>
struct Fleet {
    int pos;
    int speed;
    Fleet(int pos, int speed) : pos(pos), speed(speed) {}
    Fleet() = delete;
};
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Fleet> fleets{};
        vector<double> res{};  // time, stack
        int fleet_count{0};
        const int n = position.size();
        fleets.reserve(n);

        for (int i{0}; i < n; ++i) {
            fleets.push_back(Fleet(position[i], speed[i]));
        }
        sort(fleets.begin(), fleets.end(),
             [](const Fleet& a, const Fleet& b) { return a.pos > b.pos; });
        // sorted in descending order, or rather monotonically non-increasing order

        for (const auto& elem : fleets) {
            double time = static_cast<double>((target - elem.pos)) / (elem.speed);
            if (!res.empty() && res.back() >= time) {
                // Nothing to do
            } else {
                res.push_back(time);
                ++fleet_count;
            }
        }

        return fleet_count;
    }
};
