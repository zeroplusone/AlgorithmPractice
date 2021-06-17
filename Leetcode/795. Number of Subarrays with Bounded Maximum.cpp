class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0;

        int start=-1, latestStart=-1, lastend=-1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]<left) {
                ans+=start==-1?0:latestStart-lastend;
            } else if(nums[i]<=right) {
                start=start==-1?i:start;
                latestStart=i;
                ans+=i-lastend;
            } else {
                start=-1;
                latestStart=-1;
                lastend=i;
            }
        }

        return ans;
    }
};
