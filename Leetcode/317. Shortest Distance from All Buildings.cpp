class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> sum=grid;
        vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1) {
                    vector<vector<bool>> v(m, vector<bool>(n, false));
                    v[i][j]=true;
                    queue<pair<int, int>> que;
                    v[i][j]=true;
                    que.push(make_pair(i, j));
                    int cnt=1;
                    while(!que.empty()) {
                        int sz=que.size();
                        for(int k=0;k<sz;++k) {
                            int x=que.front().first;
                            int y=que.front().second;    
                            // cout<<x<<" "<<y<<endl;
                            que.pop();
                            for(int l=0;l<4;++l) {
                                int newx=x+dir[l][0];
                                int newy=y+dir[l][1];
                                if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==0 && !v[newx][newy]) {
                                    v[newx][newy]=true;
                                    que.push(make_pair(newx, newy));
                                    sum[newx][newy]+=cnt;
                                }
                            }
                        }
                        cnt++;
                    }
                    for(int ii=0;ii<m;++ii) {
                        for(int jj=0;jj<n;++jj) {
                            if(grid[ii][jj]==0 && !v[ii][jj]) {
                                grid[ii][jj]=-1;
                            }
                        }
                    }
                }
            }
        }
        
        int ans=1e9;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                // cout<<sum[i][j]<<" ";
                if(grid[i][j]==0) {
                    ans=min(ans, sum[i][j]);
                }
            }
            // cout<<endl;
        }
        return ans==1e9?-1:ans;
    }
};
