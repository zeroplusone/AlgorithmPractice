class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> dp(2, vector<int>(nums2.size(), 0));
        int ans=0;
        for(int i=0;i<nums1.size();++i) {
            for(int j=0;j<nums2.size();++j) {
                if(nums1[i]==nums2[j]) {
                    dp[1][j]=j==0?1:dp[0][j-1]+1;
                    ans=max(dp[1][j], ans);
                } else {
                    dp[1][j]=0;
                }
            }
            dp[0]=dp[1];
        }
        return ans;
    }
};
