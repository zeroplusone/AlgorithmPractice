class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(c, vector<int>(c, 0)));
        for(int i=r-1;i>=0;--i) {
            for(int j=0;j<c;++j) {
                for(int k=0;k<c;++k) {
                    if(j==k) {
                        dp[1][j][k]=grid[i][j];
                    } else {
                        dp[1][j][k]=grid[i][j]+grid[i][k];    
                    }
                    
                    int ret=0;
                    if(i<r-1) {
                        for(int m=j-1;m<=j+1;++m) {
                            for(int n=k-1;n<=k+1;++n) {
                                if(m<0 || n<0 || m>=c || n>=c) {
                                    continue;
                                }
                                ret=max(ret, dp[0][m][n]);
                            }
                        }
                    }
                    dp[1][j][k]+=ret;
                }
            }
            dp[0]=dp[1];
        }
        return dp[1][0][c-1];
                                       
    }
};
