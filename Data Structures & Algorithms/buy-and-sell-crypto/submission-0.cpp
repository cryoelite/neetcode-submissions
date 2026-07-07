class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //the logic is simple
        //Using 2 pointers l and r, we put l at the smallest value
        //and r ahead of it.
        //If l<r, that means there is profit and we calculate it and track our max profit, update it if we find a greater one
        //if r>l, it means we have a new smallest value and we can bring l to it
        //In between where l is and where r are, we process all pairs
        //after we find r>l, we can bring l to it without worrying if there
        //could be a greater profit possible, because if it is, see the graph in the video
        //the l and next r pair will capture it, if not, then we already have a maxP
        //So we don't need to worry about the previous pairs.
        int maxP{0};
        auto l{prices.begin()};
        auto r{prices.begin()+1};
        while(r<prices.end()) {
            if(*l<*r) { //meaning there's profit
                //we calculate it and then process it, which is
                //that we store it if it's the largest profit ever or skip it since we already have a larger one
                //but in either case, we are done with this level of profit after this processing
                int profit{*r-*l};
                maxP= max(maxP, profit);
            } else {
                //in this case, l>=r, meaning r is potentially smaller, we shift
                //l to r, because 1. we have already calculated all profits between l and r with the smallest l
                //and the largest r in this range, and we can just go and check later ones
                //and we don't need l to be at its previous value any more because if the profit
                //ahead is larger, we get it, if not, we have already processed all the smaller profits
                l=r;
            }
            ++r; //shift r ahead to process the next pair
        }

        return maxP;
    }
};
