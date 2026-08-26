#include <stack>
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s{};  // value,index
        int l{0};
        while (l < temperatures.size()) {
            int t{temperatures[l]};
            if (!s.empty() && s.top().first >= t) {
                s.push({t, l});
            } else {
                while(!s.empty() && s.top().first < t) {
                    int days{l-s.top().second};
                    res[s.top().second]=days;
                    s.pop();
                }
                if(s.empty() || s.top().first >=t){
                    s.push({t,l});
                }
            }
            ++l;
        }
        return res;
    }
};
