#include<stack>
class MyQueue {
    stack<int> s1{};
    stack<int> s2{};

    ///Checks if s2 is empty, and if so, fills it from elements of s1,
    ///clearing s1.
    void check_and_fill_s2() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() = default;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        check_and_fill_s2();
        int top{s2.top()};
        s2.pop();
        return top;
    }

    int peek() {
        
        check_and_fill_s2();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};