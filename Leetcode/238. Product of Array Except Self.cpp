class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1, 1);
        vector<int> sub(n+1, 1);
        
        for(int i=0;i<n;++i) {
            pre[i+1]=pre[i]*nums[i];
        }
        
        for(int i=n-1;i>=0;--i) {
            sub[i]=sub[i+1]*nums[i];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;++i) {
            ans[i]=pre[i]*sub[i+1];
        }
        
        return ans;
    }
};
