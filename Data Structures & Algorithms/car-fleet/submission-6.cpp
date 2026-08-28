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
        vector<double> fleet_times{};  // time, stack
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
            if (!fleet_times.empty() && fleet_times.back() >= time) {
                // Nothing to do. Because say a new car is processed
                // It either joins an existing fleet, and hence total fleets
                // remain the same. Or it creates its own fleet
                // and hence it is added to the stack and increases
                // the fleet count.
            } else {
                fleet_times.push_back(time);
            }
        }

        return fleet_times.size();
    }
};
