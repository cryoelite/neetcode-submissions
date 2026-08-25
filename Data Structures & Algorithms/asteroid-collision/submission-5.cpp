class Solution {
   public:
    Solution() = default;
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s{};
        for (int elem : asteroids) {
            if (elem >= 0) {
                s.push_back(elem);
            } else {
                while (!s.empty() && s.back()>=0 && abs(elem) > s.back()) {
                    s.pop_back();
                }
                if (s.empty() || s.back()<0) {
                    s.push_back(elem);
                } else if (abs(elem) == s.back()) {
                    s.pop_back();
                }
            }
        }

        return s;
    }
};