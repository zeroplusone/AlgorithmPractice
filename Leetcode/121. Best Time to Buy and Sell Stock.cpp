class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();++i) {
            if(prices[i]-buy>ans) {
                ans=prices[i]-buy;    
            }
            if(prices[i]<buy) {
                buy=prices[i];
            }
        }
        return ans;
    }
};
