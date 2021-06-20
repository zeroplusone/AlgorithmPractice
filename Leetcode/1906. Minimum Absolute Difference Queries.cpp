class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        // dp[i][j]=the # of j before index i
        vector<vector<int>> dp(nums.size()+1, vector<int>(101, 0));
        
        for(int i=1;i<=nums.size();++i) {
            for(int j=1;j<=100;++j) {
                dp[i][j]=dp[i-1][j]+(nums[i-1]==j?1:0);
            }
        }

        for(int i=0;i<queries.size();++i) {
            int l=queries[i][0];
            int r=queries[i][1]+1;

            int prev=-1, minDiff=1e9;
            for(int j=1;j<=100;++j) {
                if(dp[r][j]-dp[l][j]>0) {
                    if(prev==-1) {
                        prev=j;
                    } else {
                        minDiff=min(minDiff, j-prev);
                        prev=j;
                    }
                }
            }
            ans[i]=minDiff==1e9?-1:minDiff;
        }
        return ans;
        
    }

};
