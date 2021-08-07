class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> suffix(n+1, 0);
        suffix[n]=0;
        for(int i=n-1;i>=0;--i) {
            suffix[i]=suffix[i+1]+nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(k+1, 1e9));
        return solve(0, k, nums, dp, suffix);
    }
    
    int solve(int st, int k, vector<int>& nums, vector<vector<int>>& dp, vector<int>& suffix) {
        if(st==nums.size()) {
            return 0;
        } else if(k==0) {
            return (nums.size()-st)*(*max_element(nums.begin()+st, nums.end()))-suffix[st];
        } else if(dp[st][k]!=1e9) {
            return dp[st][k];
        }
        
        int maxv=0;
        int ans=1e9;
        int wasted=0;
        for(int i=st;i<nums.size();++i) {
            maxv=max(maxv, nums[i]);
            wasted=(i-st+1)*maxv-(suffix[st]-suffix[i+1]);
            ans=min(ans, wasted+solve(i+1, k-1, nums, dp, suffix));
        }
        
        dp[st][k]=ans;
        return ans;
        
    }
};
