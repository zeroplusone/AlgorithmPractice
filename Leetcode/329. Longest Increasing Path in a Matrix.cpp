class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(int &i, int &j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if(-1 != dp[i][j]) {
            return dp[i][j];
        }
    
        int ret=1;
        for(int k=0;k<dir.size();++k) {
            int x=i+dir[k][0], y=j+dir[k][1];
            if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                ret=max(ret, dfs(x, y, dp, matrix)+1);
            }
        }
        return dp[i][j]=ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int ans=1;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                ans=max(ans, dfs(i, j, dp, matrix));  
            }
        }
        
        return ans;
    }

};
