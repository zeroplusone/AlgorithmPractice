class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        int medium=(m+n+1)>>1;
        if(m==0) {
            return n%2==0?(nums2[n/2]+nums2[n/2-1])/2.0:nums2[n/2];
        } else if(n==0) {
            return m%2==0?(nums1[m/2]+nums1[m/2-1])/2.0:nums1[m/2];
        }
        
        int l=max(medium-n, 0), r=min(m, medium);
        int mid, mid2;
        while(l<r) {
            mid=(l+r+1)>>1;
            mid2=medium-mid;
            if((mid==m && nums1[m-1]<=nums2[mid2-1<0?0:(mid2-1)]) || 
               (mid==0 && nums1[0]>=nums2[mid2-1]) ||  
               (mid2==0 && nums2[0]>=nums1[mid-1]) || 
               (mid2==n && nums1[mid]>=nums2[mid2-1])|| 
               (nums1[mid==m?(m-1):mid]>=nums2[mid2-1<0?0:(mid2-1)] && 
                nums1[mid-1<0?0:(mid-1)] <= nums2[mid2==n?(n-1):mid2])) {
                break;
            } else if(nums1[mid==m?(m-1):mid]<nums2[mid2==0?0:(mid2-1)]) {
                l=mid;
            } else if(nums1[mid==0?0:(mid-1)]>nums2[mid2==n?(n-1):mid2]) {
                r=mid-1;
            }
            mid=r;
            mid2=medium-mid;
        }
        if((m+n)%2==0) {
            int left=max(mid==0?-1e9:nums1[mid-1], mid2==0?-1e9:nums2[mid2-1]);
            int right=min(mid==m?1e9:nums1[mid], mid2==n?1e9:nums2[mid2]);
            return (left+right)/2.0;
        } else {
            return max(mid==0?-1e9:nums1[mid-1], mid2==0?-1e9:nums2[mid2-1]);
        }
    }
};
