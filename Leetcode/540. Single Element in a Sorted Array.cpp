class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1) {
            return nums[0];
        }

        int l=0, r=n-1;
        
        while(l<r) {
            int mid=(l+r)>>1;
            bool found=(mid==0&&nums[mid]!=nums[mid+1]) || (mid==n-1&&nums[n-2]!=nums[n-1]) || (nums[mid-1]!=nums[mid]&&nums[mid]!=nums[mid+1]);
            if(found) {
                r=mid;
                break;
            } else if(mid!=0&&mid!=n-1&& ((mid%2==0&&nums[mid-1]==nums[mid]) || (mid%2==1&&nums[mid]==nums[mid+1]))){
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return nums[r];
    }

};
