class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, 1);
        
        int mult=1;
        for(int i=1;i<n;++i) {
            mult*=nums[i-1];
            ans[i]=mult;
        }
        
        mult=1;
        for(int i=n-2;i>=0;--i) {
            mult*=nums[i+1];
            ans[i]=ans[i]*mult;
        }
        
        return ans;
    }
};
