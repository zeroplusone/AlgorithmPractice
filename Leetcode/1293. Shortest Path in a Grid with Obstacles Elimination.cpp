class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>> que;
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> cnts(m, vector<int>(n, 1e9));
        que.push(vector<int>{0, 0, 0});
        grid[0][0]=-1e9;
        int step=0;
        

        while(!que.empty()) {
            int sz=que.size();
            for(int j=0;j<sz;++j) {
                int x=que.front()[0];
                int y=que.front()[1];
                int cnt=que.front()[2];
                que.pop();
                if(x==m-1 && y==n-1) {
                    return step;
                }

                for(int i=0;i<4;++i) {
                    int newx=x+dir[i][0];
                    int newy=y+dir[i][1];

                    if(newx>=0 && newx<m && newy>=0 && newy<n) {
                        if(grid[newx][newy]==0 && cnt<cnts[newx][newy]) {
                            cnts[newx][newy]=cnt;
                            que.push(vector<int>{newx, newy, cnt});
                        } else if(grid[newx][newy]==1 && cnt<k && cnt<cnts[newx][newy]) {
                            cnts[newx][newy]=-cnt-1;
                            que.push(vector<int>{newx, newy, cnt+1});
                        }
                    }
                }
            }
            step++;
            
        }
        return -1;
    }
};
