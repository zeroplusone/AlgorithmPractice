class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int diff=1e9;
        for(int i=0;i<n;++i) {
            int t=target-nums[i];
            int j=i+1, k=n-1;
            while(j<k) {
                int sum=nums[j]+nums[k];
                if(sum==t) {
                    return target;    
                } else if(sum<t) {
                    j++;
                } else if(sum>t) {
                    k--;
                }
                if(abs(sum-t)<abs(diff)) {
                    diff=sum-t;
                }
            }
        }
        return target+diff;
    }
};
