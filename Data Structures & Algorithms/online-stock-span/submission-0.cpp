#include <stack>
struct Stock {
    int price;
    int span;
    Stock(int price, int span) : price(price), span(span) {}
    Stock() = delete;
};
class StockSpanner {
    stack<Stock> s{};

   public:
    StockSpanner() {}

    int next(int price) {
        int span{1};

        while (!s.empty() && s.top().price <= price) {
            span += s.top().span;
            s.pop();
        }

        s.push(Stock(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */