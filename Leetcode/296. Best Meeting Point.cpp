class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x, y;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int num=x.size();
        int midx=num%2==0?(x[num/2]+x[num/2-1])/2:x[num/2];
        int midy=num%2==0?(y[num/2]+y[num/2-1])/2:y[num/2];
        
        int ans=0;
        for(int i=0;i<num;++i) {
            ans+=abs(midx-x[i])+abs(midy-y[i]);
        }
        return ans;
            
    }
};
