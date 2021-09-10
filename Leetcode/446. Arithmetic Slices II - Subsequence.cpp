class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long, int> > dp(n);
        
        int ans=0;
        for(int i=1;i<n;++i) {
            for(int j=0;j<i;++j) {
                long long diff=(long long)nums[i]-(long long)nums[j];
                
                int sum=0;
                if(dp[j].count(diff)!=0) {
                    sum=dp[j][diff];
                }
                ans+=sum;
                dp[i][diff]+=sum+1;
            }
        }
        return ans;
    }
};
