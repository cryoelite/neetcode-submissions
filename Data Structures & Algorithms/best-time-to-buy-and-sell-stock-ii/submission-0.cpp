class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP{0};
        int totalP{0};
        auto l{prices.begin()};
        auto r{prices.begin()+1};

        while(r<prices.end()){
            if(*l<*r && *r>*(r-1)){
                int profit{*r-*l};
                totalP+=max(profit,maxP) - maxP;
                maxP= max(profit, maxP);
                
            } else if (*r<*(r-1)){
                l=r;
                 //cleared previous shares and now ready to track again
                maxP=0;
            } else {
                l=r;
            }
            ++r;
        }
        return totalP;
    }
};