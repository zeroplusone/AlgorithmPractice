class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        
        queue<pair<int, int>> que;
        
        vector<vector<int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        int ans=0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(!v[i][j] && grid2[i][j]==1) {
                    bool subIsland=true;
                    que.push(make_pair(i, j));
                    v[i][j]=true;
                    while(!que.empty()) {
                        int x=que.front().first;
                        int y=que.front().second;
                        que.pop();
                        if(grid1[x][y]==0) {
                            subIsland=false;
                        }
                        for(int k=0;k<4;++k) {
                            int newx=x+dir[k][0];
                            int newy=y+dir[k][1];
                            if(newx>=0 && newx<m && newy>=0 && newy<n && grid2[newx][newy]==1 && !v[newx][newy]) {
                                v[newx][newy]=true;
                                que.push(make_pair(newx, newy));
                            }
                        }
                    }
                    if(subIsland) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
