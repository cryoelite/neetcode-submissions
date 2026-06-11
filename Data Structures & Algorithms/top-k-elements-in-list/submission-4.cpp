class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count{};
        vector<vector<int>> bucket(nums.size(), vector<int>());
        vector<int> res{};
        res.reserve(k);
        for (int c : nums) {
            ++count[c];
        }  
        
        for (auto& elem : count) {
            bucket[elem.second-1].push_back(elem.first);
        }
        
        for (int i{static_cast<int>(bucket.size()) - 1}; i >= 0; --i) {
            for (int elem : bucket[i]) {
                if (k > 0) {
                    res.push_back(elem);
                    --k;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
