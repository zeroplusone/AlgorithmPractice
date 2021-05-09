class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0, j=0; i<nums1.size() && j<nums2.size();) {
            if(nums1[i]>nums2[j]) {
                if(i==j) {
                    j++;
                }
                i++;
            } else {
                ans=max(ans, j-i);
                j++;
            }
        }
        return ans;
    }
};
