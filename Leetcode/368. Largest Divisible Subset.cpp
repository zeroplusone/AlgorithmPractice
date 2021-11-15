class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int maxlen=1;
        int maxindex=0;
        // len, parent
        vector<pair<int, int>> dp(n, make_pair(1, -1));
        for(int i=1;i<n;++i) {
            for(int j=0;j<i;++j) {
                if(nums[i]%nums[j]==0 && dp[j].first+1>dp[i].first) {
                    dp[i]=make_pair(dp[j].first+1, j);
                    if(dp[i].first>maxlen) {
                        maxlen=dp[i].first;
                        maxindex=i;
                    }
                }
            }
        }
        
        vector<int> ans(maxlen);
        for(int i=maxlen-1;i>=0;--i) {
            ans[i]=nums[maxindex];
            maxindex=dp[maxindex].second;
        }
        return ans;
    }
};
