class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0]=0;
        dp[1][0]=nums[0];
        for(int i=1;i<n;++i) {
            dp[0][i]=max(dp[0][i-1], dp[1][i-1]);
            dp[1][i]=dp[0][i-1]+nums[i];
        }
        return max(dp[0][n-1], dp[1][n-1]);
    }
};
