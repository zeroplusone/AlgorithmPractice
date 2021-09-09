class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        vector<vector<int>> grid(n, vector<int>(n , n));
        for(int i=0;i<mines.size();++i) {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        
        for(int i=0;i<n;++i) {
            int u=1, d=1, l=1, r=1;
            for(int j=0;j<n;++j) {
                grid[j][i]=grid[j][i]!=0?min(grid[j][i], u):grid[j][i];
                u=grid[j][i]!=0?u+1:1;
                
                grid[i][j]=grid[i][j]!=0?min(grid[i][j], l):grid[i][j];
                l=grid[i][j]!=0?l+1:1;
                
                grid[n-j-1][i]=grid[n-j-1][i]!=0?min(grid[n-j-1][i], d):grid[n-j-1][i];
                d=grid[n-j-1][i]!=0?d+1:1;
                
                grid[i][n-j-1]=grid[i][n-j-1]!=0?min(grid[i][n-j-1], r):grid[i][n-j-1];
                r=grid[i][n-j-1]!=0?r+1:1;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                ans=max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};
