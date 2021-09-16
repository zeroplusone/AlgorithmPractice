class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> ans(m*n);
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x=0, y=0, d=0;
        for(int i=0;i<m*n;++i) {
            ans[i]=matrix[x][y];
            matrix[x][y]=101;
            int newx=x+dir[d][0];
            int newy=y+dir[d][1];
            if(newx>=0 && newx<m && newy>=0 && newy<n && matrix[newx][newy]!=101) {
                x=newx;
                y=newy;
            } else {
                d=(d+1)%4;
                x+=dir[d][0];
                y+=dir[d][1];
            }
        }
        return ans;
    }
};
