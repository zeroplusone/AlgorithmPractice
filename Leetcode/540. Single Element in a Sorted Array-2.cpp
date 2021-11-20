class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();

        int l=0, r=n-1;
        
        while(l<r) {
            int mid=(l+r)>>1;
            if(mid%2==1) {
                mid--;
            }
            if(nums[mid]==nums[mid+1]) {
                l=mid+2;
            } else {
                r=mid;
            }
        }
        return nums[r];
    }

};
