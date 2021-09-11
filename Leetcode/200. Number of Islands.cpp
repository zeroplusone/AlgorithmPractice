class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]=='1') {
                    queue<pair<int, int>> que;
                    que.push(make_pair(i, j));
                    grid[i][j]='2';
                    while(!que.empty()) {
                        int x=que.front().first;
                        int y=que.front().second;
                        que.pop();
                        for(int k=0;k<4;++k) {
                            int newx=x+dir[k][0];
                            int newy=y+dir[k][1];
                            if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]=='1') {
                                grid[newx][newy]='2';
                                que.push(make_pair(newx, newy));
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
