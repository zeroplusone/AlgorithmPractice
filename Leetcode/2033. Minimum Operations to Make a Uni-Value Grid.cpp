class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr(m*n);
        int mod=grid[0][0]%x;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]%x!=mod) {
                    return -1;
                } else {
                    arr[i*n+j]=grid[i][j];
                }
            }
        }
        sort(arr.begin(), arr.end());
        
        int ans=0;
        int base=arr[arr.size()/2];
        for(int i=0;i<arr.size();++i) {
            ans+=abs(arr[i]-base)/x;
        }
        return ans;
    }
};
