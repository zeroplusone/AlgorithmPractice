class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        if(m>n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int medium=(m+n+1)>>1;
        int l=0, r=m;
        int mid, mid2;
        while(l<=r) {
            mid=l+(r-l)/2;
            mid2=medium-mid;
            
            int aleft=mid==0?-1e9:nums1[mid-1];
            int aright=mid==m?1e9:nums1[mid];
            int bleft=mid2==0?-1e9:nums2[mid2-1];
            int bright=mid2==n?1e9:nums2[mid2];
            cout<<mid<<" "<<mid2<<endl;
            if(aright<bleft) {
                l=mid+1;
            } else if(aleft>bright) {
                r=mid-1;
            } else {
                int maxleft=max(aleft, bleft);
                int minright=min(aright, bright);
                if((m+n)%2==0) {
                    double sum=maxleft+minright;
                    return sum/2.0;
                } else {
                    return maxleft;
                }
            }
        }
        return -1;
    }
};
