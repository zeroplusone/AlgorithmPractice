class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> dp(1024, -1);
        return backtracking(0, 0, workers, bikes, dp);
    }
    
    int backtracking(int now, int mask, vector<vector<int>>& workers, vector<vector<int>>& bikes, vector<int>& dp) {

        if(now==workers.size()) {
            return 0;
        }
        
        if(dp[mask]!=-1) {
            return dp[mask];
        }
        
        int ans=1e9;
        for(int i=0;i<bikes.size();++i) {
            int one=1<<i;
            int visited=one&mask;
            if(visited==0) {
                ans=min(ans, abs(workers[now][0]-bikes[i][0])+abs(workers[now][1]-bikes[i][1])+backtracking(now+1, mask|one, workers, bikes, dp));
            }
        }
        dp[mask]=ans;
        return ans;
    }
};
