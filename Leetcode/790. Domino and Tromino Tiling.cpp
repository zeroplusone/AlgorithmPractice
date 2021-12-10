class Solution {
public:
    int numTilings(int n) {
        long long int mod=1e9+7;
        vector<long long int> dp(4, 0);
        if(n==1) {
            return 1;
        } else if(n==2) {
            return 2;
        } else if(n==3) {
            return 5;
        }
        dp[0]=1;
        dp[1]=2;
        dp[2]=5;
        for(int i=4;i<=n;++i) {
            dp[3]=(2*dp[2]+dp[0])%mod;
            dp[0]=dp[1];
            dp[1]=dp[2];
            dp[2]=dp[3];
            
        }
        return dp[3];      
    }
};
