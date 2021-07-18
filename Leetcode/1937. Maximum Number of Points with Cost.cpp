class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<long long> dp(n,0);
        long long last=0;

        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                dp[j]+=points[i][j];
            }
            last=0;
            for(int j=0;j<n;++j) {
                if(dp[j]>=last) {
                    last=dp[j]-1;
                } else {
                    dp[j]=last;
                    last--;
                }
            }
            last=0;
            for(int j=n-1;j>=0;--j) {
                if(dp[j]>=last) {
                    last=dp[j]-1;
                } else {
                    dp[j]=last;
                    last--;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;++i) {
            if(dp[i]>ans) {
                ans=dp[i];
            }
        }
        return ans;
    }
};
