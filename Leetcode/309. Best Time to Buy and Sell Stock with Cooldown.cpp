class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<=1) {
            return 0;
        }

        vector<int> dp(n+1, 0);
    
        dp[1]=max(dp[1], prices[1]-prices[0]);
        for(int i=2;i<n;++i) {
            dp[i]=dp[i-1];
            for(int j=0;j<i;++j) {
                int last=j>=2?dp[j-2]:0;
                dp[i]=max(dp[i], last+prices[i]-prices[j]);
            }
        }
        
        return dp[n-1];
    }
};
