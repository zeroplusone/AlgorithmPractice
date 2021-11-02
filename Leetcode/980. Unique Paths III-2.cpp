class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int x, y;
        int zero=0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1) {
                    x=i;
                    y=j;
                } else if(grid[i][j]==0) {
                    zero++;
                }
            }
        }
        DFS(x, y, grid, ans, zero+1);
        return ans;
    }
    vector<vector<int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};

    void DFS(int x, int y, vector<vector<int>>& grid, int& ans, int cnt) {
        if(cnt<0) {
            return;
        }
        if(grid[x][y]==2) {
            if(cnt==0) {
                ans++;    
            }
            return;
        }

        for(int i=0;i<4;++i) {
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            
            if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size()) {
                if(grid[newx][newy]==0) {
                    grid[newx][newy]=1;
                    DFS(newx, newy, grid, ans, cnt-1);
                    grid[newx][newy]=0;    
                } else if(grid[newx][newy]==2) {
                    DFS(newx, newy, grid, ans, cnt-1);
                }
            }
        }
        
        
    }
};
