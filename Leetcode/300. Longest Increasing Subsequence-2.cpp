class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int ans=1;
        for(int i=1;i<nums.size();++i) {
            int index=lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if(index==dp.size()) {
                dp.push_back(nums[i]);
            } else {
                dp[index]=nums[i];
            } 
        }
        return dp.size();
    }
};
