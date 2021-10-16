class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> left(n, 0), right(n, 0);
        
        int cal=0;
        int buy=prices[0];
        for(int i=1;i<n;++i) {
            cal=max(cal, prices[i]-buy);
            left[i]=cal;
            buy=min(buy, prices[i]);
        }
        
        cal=0;
        int sell=prices[n-1];
        for(int i=n-2;i>=0;--i) {
            cal=max(cal, sell-prices[i]);
            right[i]=cal;
            sell=max(sell, prices[i]);
        }
        
        
        
        int ans=max(left[n-1], right[0]);
        
        for(int i=0;i<n-1;++i) {
            ans=max(ans, left[i]+right[i+1]);
        }
        
        
        return ans;
    }
};
