class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> minvec(n);
        vector<int> maxvec(n);
        
        int minv=nums[n-1];
        for(int i=n-1;i>=0;--i) {
            if(nums[i]<minv) {
                minv=nums[i];
            }
            minvec[i]=minv;
        }
        int maxv=nums[0];
        for(int i=0;i<n;++i) {
            if(nums[i]>maxv) {
                maxv=nums[i];
            }
            maxvec[i]=maxv;
        }
        
        for(int i=0;i<n-1;++i) {
            if(minvec[i+1]>=maxvec[i]) {
                return i+1;
            }
        }
        return n;
    }
};
