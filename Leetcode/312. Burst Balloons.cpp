class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        return solve(nums, 1, nums.size()-2, dp);
    }
    
    int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if(r<l) {
            return 0;
        }
        
        if(dp[l][r]!=0) {
            return dp[l][r];
        } 

        int ret=0;
        for(int i=l;i<=r;++i) {
            int burst=nums[l-1]*nums[i]*nums[r+1];
            ret=max(ret, solve(nums, l, i-1, dp)+solve(nums, i+1, r, dp)+burst);
        }
        
        dp[l][r]=ret;
        return ret;
        
    }
};
