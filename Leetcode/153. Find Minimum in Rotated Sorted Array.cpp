class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            if(l==r) {
                return nums[l];
            } else if(r==l+1) {
                return min(nums[l], nums[r]);
            }

            int mid=l+(r-l)/2;
            if(mid==0 || nums[mid-1]>nums[mid]) {
                return nums[mid];
            } else if(nums[l]>nums[mid] && nums[r]>nums[mid]) {
                r=mid-1;
            } else if(nums[l]<nums[mid] && nums[r]<nums[mid]) {
                l=mid;
            } else if(nums[l]<nums[mid] && nums[r]>nums[mid]) {
                r=mid;
            } 
        }
        return nums[r];
    }
};
