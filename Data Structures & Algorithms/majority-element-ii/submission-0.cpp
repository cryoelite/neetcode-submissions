#include <unordered_map>
class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count{};
        vector<int> res{};
        res.reserve(2);

        for (int elem : nums) {
            ++count[elem];

            if (count.size() > 2) {
                for (auto it{count.begin()}; it!=count.end();) {
                    --it->second;
                    if(it->second == 0) {
                        it=count.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
    

        // 3 cases, there's 0 elements in count. 1 element or 2 elements.
        // In case there are 0 elements
        if (count.size() == 0) {
            return res;
        }

        // In case there are >0 elements
        for (auto& p : count) {
            p.second = 0;
        }

        for (int elem : nums) {
            auto it{count.find(elem)};
            if (it != count.end()) {
                ++it->second;
            }
        }

        for (auto& p : count) {
            if (p.second > static_cast<int>(floor(static_cast<double>(nums.size()) / 3))) {
                res.emplace_back(p.first);
            }
        }
        return res;
    }
};