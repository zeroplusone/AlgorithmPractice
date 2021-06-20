class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        
        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));
        dp[0][0]=grid[0][0];
        
        vector<vector<int>> dir={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!que.empty()) {
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            for(int i=0;i<4;++i) {
                int newx=x+dir[i][0];
                int newy=y+dir[i][1];
                if(newx>=0 && newx<n && newy>=0 && newy<n && max(dp[x][y], grid[newx][newy])<dp[newx][newy]) {
                    dp[newx][newy]=max(dp[x][y], grid[newx][newy]);
                    que.push(make_pair(newx, newy));
                }
            }
        }
        return dp[n-1][n-1];
        
    }
};
