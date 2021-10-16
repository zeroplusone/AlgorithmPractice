class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost1=1e9;
        int profit1=0;
        int cost2=1e9;
        int profit2=0;
        
        for(int i=0;i<prices.size();++i) {
            cost1=min(cost1, prices[i]);
            profit1=max(profit1, prices[i]-cost1);
            cost2=min(cost2, prices[i]-profit1);
            profit2=max(profit2, prices[i]-cost2);
        }
        
        return profit2;
    }
};
