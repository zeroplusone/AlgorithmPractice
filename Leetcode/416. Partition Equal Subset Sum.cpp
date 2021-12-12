class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0;
        for(int i=0;i<nums.size();++i) {
            sum+=nums[i];
        }
        if(sum%2==1) {
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
        sum/=2;
        return backtracking(0, 0, sum, nums, dp);
    }
    
    int backtracking(int now, int sum, int& target, vector<int>& nums, vector<vector<int>>& dp) {
        if(now<nums.size()) {
            if(dp[now][sum]!=-1) {
                return dp[now][sum];
            } else if(sum==target) {
                dp[now][sum]=1;
            } else if(sum>target) {
                dp[now][sum]=0;
            } else {
                dp[now][sum]=backtracking(now+1, sum+nums[now], target, nums, dp)||backtracking(now+1, sum, target, nums, dp);
            }
        } else {
            return 0;
        }
        return dp[now][sum];
    }
};
