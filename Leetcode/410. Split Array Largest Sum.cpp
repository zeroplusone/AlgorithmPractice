class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int> prefix(n, 0);
        vector<vector<int>> dp(2, vector<int>(n, 1e9+1000));
        
        prefix[0]=nums[0];
        for(int i=1;i<n;++i) {
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        dp[0]=prefix;

        for(int i=1;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(j==0) {
                    dp[1][j]=dp[0][j];
                } else {
                    for(int k=0;k<j;++k) {
                        dp[1][j]=min(dp[1][j], max(dp[0][k], prefix[j]-prefix[k]));
                    }
                }
            }
            dp[0]=dp[1];
        }
        
        return dp[0][n-1];
    }
};
