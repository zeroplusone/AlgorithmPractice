class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        deque<int> dq;
        int sum=0;
        dp[0]=nums[0];
        dq.push_back(0);
        for(int i=1;i<nums.size();++i) {
            if(dq.front()==i-k-1) {
                dq.pop_front();
            }
            dp[i]=dp[dq.front()]+nums[i];
            while(!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[nums.size()-1];
    }
};
