class Solution {
public:
    int kInversePairs(int n, int k) {
        if(k==0) {
            return 1;
        }
        vector<vector<long long int>> dp(2, vector<long long int>(k+1, 0));
        int mod=1e9+7;

        dp[0][0]=1;
        int len=1;
        for(int i=2;i<=n;++i) {
            long long int sum=0;
            len=i-1+len; 
            for(int j=0;j<=min(k, len/2);++j) {
                sum=(sum+dp[0][j])%mod;
                sum=(sum-(j>=i?dp[0][j-i]:0)+mod)%mod;
                dp[1][j]=sum;
                if(len-j-1<=k) {
                    dp[1][len-j-1]=sum;
                }
            }
            dp[0]=dp[1];
        }
        return dp[0][k]%mod;
    }
    
};
