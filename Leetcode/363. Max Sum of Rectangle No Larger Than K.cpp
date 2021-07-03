class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int ans=-1e9;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+matrix[i][j];
            }
        }
        
        for(int l=1;l<=n;++l) {
            for(int r=l;r<=n;++r) {
                set<int> accSet;
                accSet.insert(0);
                for(int i=1;i<=m;++i) {
                    int sum=dp[i][r]-dp[i][l-1];
                    auto it=accSet.lower_bound(sum-k);
                    if(it!=accSet.end()) {
                        ans=max(ans, sum-*it);
                    }
                    accSet.insert(sum);
                }
            }
        }
        
        
        return ans;
    }
};
