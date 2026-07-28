#include <stack>
class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> s{};
        int res{0};
        for (const string& op : operations) {
            // We parse the string to int at the very end (to avoid error handling with stoi
            // function) We can perform the rest of the operations before that in the if/else
            // branches, because the question's constraints guarantee that there will be elements in
            // the record before any operation is requested. If this guarantee was not there, we
            // would have to change the logic a bit.
            if (op == "+") {
                int top{s.top()};
                s.pop();  // Have to remove the top element to access the one before
                int sum{top + s.top()};
                s.push(top);
                s.push(sum);
                res += sum;
            } else if (op == "C") {
                res -= s.top();
                s.pop();
            } else if (op == "D") {
                res += (s.top() * 2);
                s.push(s.top() * 2);
            } else {
                // String is an int as that's the only input left
                int iop{stoi(op)};
                s.push(iop);

                res += iop;
            }
        }

        while(!s.empty()) {
            cout<<s.top()<<'\n';
            s.pop();
        }
        return res;
    }
};