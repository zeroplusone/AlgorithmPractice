class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();++i) {
            sum+=stones[i];
        }
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
        return solve(0, stones.size()-1, sum, stones, dp);
    }
    
    int solve(int st, int en, int sum, vector<int>& stones, vector<vector<int>>& dp) {
        if(dp[st][en]!=0){
            return dp[st][en];
        } else if(st==en) {
            return 0;
        }  else {
            dp[st][en]=max(sum-stones[st]-solve(st+1, en, sum-stones[st], stones, dp), sum-stones[en]-solve(st, en-1, sum-stones[en], stones, dp));
            return dp[st][en];
        }
    }
};
