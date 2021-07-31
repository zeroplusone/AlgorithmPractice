class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) {
            return 0;
        }
        
        
        int ans=0;
        int sum=0;
        int last=height[0];
        for(int i=1;i<n;++i) {
            if(height[i]>=last) {
                ans+=sum;
                sum=0;
                last=height[i];
            } else {
                sum+=last-height[i];
            }
        }
        last=height[n-1];
        sum=0;
        for(int i=n-2;i>=0;--i) {
            if(height[i]>last) {
                ans+=sum;
                sum=0;
                last=height[i];
            } else {
                sum+=last-height[i];
            }
        }
        return ans;
    }
};
