class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<vector<int>> dp(n+1, vector<int>(0));   
        dp[1]=vector<int>{1};
        return solve(n, dp);
    }
    
    vector<int> solve(int n, vector<vector<int>>& dp) {
        if(dp[n].size()!=0) {
            return dp[n];
        }

        vector<int> right=solve(n/2, dp);
        vector<int> left=n%2==1?solve(n/2+1, dp):right;
        
        vector<int> ans(n);
        for(int i=0;i<left.size();++i) {
            ans[i]=left[i]*2-1;
        }
        
        for(int i=0;i<right.size();++i) {
            ans[left.size()+i]=right[i]*2;
        }
        dp[n]=ans;
        return dp[n];
    }
};
