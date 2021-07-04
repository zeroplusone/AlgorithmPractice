class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int>> dp(2, vector<long long int>(5, 1));
        long long int mod=1e9+7;
        // a=0, e=1, i=2, o=3, u=4
        for(int i=2;i<=n;++i) {
            dp[1][0]=(dp[0][1]+dp[0][2]+dp[0][4])%mod;
            dp[1][1]=(dp[0][0]+dp[0][2])%mod;
            dp[1][2]=(dp[0][1]+dp[0][3])%mod;
            dp[1][3]=dp[0][2];
            dp[1][4]=(dp[0][2]+dp[0][3])%mod;
            dp[0]=dp[1];
        }
            
        long long int ans=0;
        for(int i=0;i<dp[1].size();++i) {
            ans=(ans+dp[1][i])%mod;
        }
        return ans;
    }
};
