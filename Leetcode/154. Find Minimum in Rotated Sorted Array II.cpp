class Solution {
public:
    int findMin(vector<int>& nums) {
        return solve(0, nums.size()-1, nums);
    }
    
    int solve(int l, int r, vector<int>& nums) {
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
            } else if(nums[l]==nums[mid] && nums[r]>nums[mid]) {
                return nums[l];
            } else if(nums[l]==nums[mid] && nums[r]<nums[mid]) {
                l=mid+1;
            } else if(nums[l]>nums[mid] && nums[r]==nums[mid]) {
                l++;
                r=mid;
            } else if(nums[l]<nums[mid] && nums[r]==nums[mid]) {
                return nums[l];
            } else {
                vector<int> left(nums.begin(), nums.begin()+mid);
                vector<int> right(nums.begin()+mid, nums.end());
                int li=solve(l, mid-1, nums);
                int ri=solve(mid, r, nums);
                if(li!=nums[mid]) {
                    return li;
                } else if(ri!=nums[mid]) {
                    return ri;
                } else {
                    return nums[mid];
                }
            }
        }
        return nums[r];
    }
};
