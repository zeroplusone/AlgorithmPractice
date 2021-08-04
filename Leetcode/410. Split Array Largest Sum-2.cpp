class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int l=0, r=0;
        for(int i=0;i<n;++i) {
            r+=nums[i];
            l=max(l, nums[i]);
        }
        
        int mid;
        while(l<r) {
            mid=(l+r)>>1;
            int cnt=0, sum=0;
            for(int i=0;i<n;++i) {
                if(sum+nums[i]>mid) {
                    cnt++;
                    sum=nums[i];
                } else {
                    sum+=nums[i];
                }
            }
            
            if(cnt<m) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return r;
    }
};
