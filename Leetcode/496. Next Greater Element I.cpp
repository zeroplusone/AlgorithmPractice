class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        for(int i=0;i<nums1.size();++i) {
            bool found=false;
            for(int j=0;j<nums2.size();++j) {
                if(found && nums2[j]>nums1[i]) {
                    ans[i]=nums2[j];
                    break;
                }
                if(nums2[j]==nums1[i]) {
                    found=true;
                } 
                
            }
        }
        return ans;
    }
};
