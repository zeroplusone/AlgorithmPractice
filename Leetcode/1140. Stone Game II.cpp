class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffix(n);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;--i) {
            suffix[i]=suffix[i+1]+piles[i];
        }
        return DFS(0, 1, suffix, piles, dp);
    }
    
    int DFS(int now, int m, vector<int>& suffix, vector<int>& piles, vector<vector<int>>& dp) {
        if(now>=piles.size()) {
            return 0;    
        } if(m*2>=piles.size()) {
            return suffix[now];
        } else if(dp[now][m]!=-1) {
            return dp[now][m];
        }

        int ret=0;
        for(int i=1;i<=2*m && now+i-1<piles.size();++i) {
            ret=max(ret, suffix[now]-DFS(now+i, max(i,m), suffix, piles, dp));
        }
        
        dp[now][m]=ret;
        return ret;
    }
};
