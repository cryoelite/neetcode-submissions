class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //It sounds complicated but this version is easier than the previous
        //one. Because in this one, all we need to do is just calculate
        //every consecutive profit and that's it.
        //Alternatively, we could just do how we did the first one except
        //we can see that every time the r drops from its previous value, we can
        //clear the stock and start anew to track all profits that come after
        //We don't need to worry about finding a lower l because if we do we move l to it
        //and also if we find a r lower than its previous value.
        //But otherwise we just keep tracking the profit, and in this case the
        //difference between the max profit and the current profit so as to negate any extra profit
        //Check previous submission for that one.
        int totalP{0};

        for(size_t i{1}; i<prices.size(); ++i) {
            if(prices[i] > prices[i-1]) {
                totalP+=(prices[i]- prices[i-1]);
            }
        }
        return totalP;
    }
};