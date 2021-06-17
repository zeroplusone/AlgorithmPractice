class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0;
        int start=-1, end=-1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]>right) {
                start=i;
            } 
            if(nums[i]>=left) {
                end=i;
            } 
            ans+=end-start;
        }

        return ans;
    }
};
