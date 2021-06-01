class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        
        int cnt=0;
        queue<pair<int, int>> que;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1) {
                    cnt=0;
                    que.push(make_pair(i, j));
                    grid[i][j]=0;
                    while(!que.empty()) {
                        cnt++;
                        int x = que.front().first;
                        int y = que.front().second;
                        que.pop();
                        for(int k=0;k<4;++k) {
                            int newx = x + dir[k][0];
                            int newy = y + dir[k][1];
                            if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1) {
                                que.push(make_pair(newx, newy));
                                grid[newx][newy]=0;
                            }
                        }
                    }
                    ans=max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
