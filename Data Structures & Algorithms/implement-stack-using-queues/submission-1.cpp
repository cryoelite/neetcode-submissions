#include <queue>

class MyStack {
    queue<int> q;

   public:
    MyStack() { q = queue<int>(); }

    void push(int x) { q.push(x); }

    int pop() {
        for (size_t i{0}; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        int res{q.front()};
        q.pop();
        return res;
    }

    int top() {
        for (size_t i{0}; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        int res{q.front()};
        q.pop();
        q.push(res);
        return res;
    }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */