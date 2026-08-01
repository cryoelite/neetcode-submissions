#include <stack>
#include <numeric>
class Solution {
    stack<int> s{};

   public:
    int evalRPN(vector<string>& tokens) {
        for (const string& token : tokens) {
            if (token == "+") {
                int res{s.top()};
                s.pop();
                res += s.top();
                s.pop();
                s.push(res);
            } else if (token == "-") {
                int res{s.top()};
                s.pop();
                res = s.top() - res;
                s.pop();
                s.push(res);
            } else if (token == "*") {
                int res{s.top()};
                s.pop();
                res *= s.top();
                s.pop();
                s.push(res);
            } else if (token == "/") {
                int res{s.top()};
                s.pop();
                res = s.top() /
                      res;  // From C++11, integer division automatically truncates towards 0.
                s.pop();
                s.push(res);
            } else {  // token is an integer, as given by the problem constraints
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
