class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i) {
            sum+=nums[i];
        }
        if(sum%2==1) {
            return false;
        }
        sum/=2;
        vector<bool> dp(sum+1, false);
        sort(nums.begin(), nums.end());
        dp[0]=true;
        for(int i=0;i<nums.size();++i) {
            for(int j=sum;j>=nums[i];--j) {
                dp[j]=dp[j] || dp[j-nums[i]];   
            }
        }
        return dp[sum];
    }

};
