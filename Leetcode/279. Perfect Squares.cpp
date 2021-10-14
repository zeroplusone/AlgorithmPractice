class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[1]=1;
        for(int i=2;i<=n;++i) {
            int sq=sqrt(i);
            if(sq*sq==i) {
                dp[i]=1;
                continue;
            }
            for(int j=sq;j>=1;--j) {
                dp[i]=min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
