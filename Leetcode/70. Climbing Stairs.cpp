class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp{1,2,3};
        if(n<=2) {
            return dp[n-1];
        }
        for(int i=3;i<=n;++i) {
            dp[2]=dp[1]+dp[0];
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return dp[2];
    }
};
