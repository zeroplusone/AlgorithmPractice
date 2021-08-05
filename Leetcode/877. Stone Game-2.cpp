class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        // dp[i]: diff betwen start index i + len
        vector<int> dp(n);
        
        // len
        for(int i=0;i<n;++i) {
            // start index
            for(int j=0;j<n-i;++j) {
                dp[j]=i==0?piles[j]:max(piles[j]-dp[j+1], piles[j+i]-dp[j]);
            }
        }
        
        return dp[0];
        
    }
};
