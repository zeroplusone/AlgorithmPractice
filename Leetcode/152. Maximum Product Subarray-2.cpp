class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0) {
            return 0;
        }
        int maxv=nums[0], newmax;
        int minv=nums[0], newmin;
        int ans=nums[0];
        for(int i=1;i<nums.size();++i) {
            newmax=maxv*nums[i];
            newmin=minv*nums[i];
            minv=min(nums[i], min(newmax, newmin));
            maxv=max(nums[i], max(newmax, newmin));
            ans=max(ans, maxv);
        }
        return ans;
    }
};
