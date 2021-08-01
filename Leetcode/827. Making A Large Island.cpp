class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> v(n, vector<bool>(n, false));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        vector<vector<int>> dir=vector<vector<int>>{{0,1},{1,0},{0,-1},{-1,0}};
        int x, y, nx, ny;
        int maxv=0;

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1 && !v[i][j]) {
                    // BFS
                    int land=0;
                    vector<pair<int, int>> edge;
                    queue<pair<int, int>> que;
                    que.push(make_pair(i, j));
                    v[i][j]=true;
                    while(!que.empty()) {
                        land++;
                        x=que.front().first;
                        y=que.front().second;
                        que.pop();
                        for(int k=0;k<4;++k) {
                            nx=x+dir[k][0];
                            ny=y+dir[k][1];
                            if(nx>=0 && nx<n && ny>=0 && ny<n && !v[nx][ny]) {
                                v[nx][ny]=true;
                                if(grid[nx][ny]==0) {
                                    edge.push_back(make_pair(nx, ny));
                                } else {
                                    que.push(make_pair(nx, ny));
                                }
                            }
                        }
                    }
                    maxv=max(maxv, land);
                    for(auto e:edge) {
                        ans[e.first][e.second]+=land;
                        v[e.first][e.second]=false;
                    }
                    
                }
            }
        }
        
        
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                maxv=max(maxv, ans[i][j]+1);
            }
        }
        return maxv;
    }
};
