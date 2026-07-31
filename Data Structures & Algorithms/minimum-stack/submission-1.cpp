/* #include <stack>
class MinStack {
    stack<int> s;
    stack<int> min_s;

   public:
    MinStack() {
        s = stack<int>();
        min_s = stack<int>();
    }

    void push(int val) {
        s.push(val);
        if (min_s.empty()) {
            min_s.push(val);
        } else {
            min_s.push(min(val, min_s.top()));
        }
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return min_s.top(); }
};
 */

#include <stack>
class MinStack {
    stack<pair<int, int>> s{};

public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            s.push({val, min(val, s.top().second)});
        }
    }

    void pop() { s.pop(); }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }
};