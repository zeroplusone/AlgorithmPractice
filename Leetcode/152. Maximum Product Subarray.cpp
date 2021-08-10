class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1);
        pre[0]=1;
        int last=0;
        int ans=-1e9;
        for(int i=0;i<n;++i) {
            ans=max(ans, nums[i]);
            if(nums[i]==0) {
                pre[i+1]=1;
            } else {
                pre[i+1]=pre[i]*nums[i];    
            }
            
        }

        int neg=-1;
        int cnt=0;
        for(int i=0;i<n;++i) {
            if(nums[i]==0) {
                neg=-1;
                cnt=0;
            } else {
                cnt+=nums[i]>0?0:1; 
                if(cnt%2==1) {
                    ans=max(ans, pre[i+1]/pre[neg+1]);
                    neg=neg==-1?i:neg;
                } else {
                    ans=max(ans, pre[i+1]);
                }
            }
        }
        return ans;
    }
};
