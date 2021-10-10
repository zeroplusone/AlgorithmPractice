class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s;
        unordered_set<int> ans;
        for(int i=0;i<nums1.size();++i) {
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();++i) {
            if(s.count(nums2[i])!=0) {
                ans.insert(nums2[i]);
            }
        }
        
        for(int i=0;i<nums2.size();++i) {
            s.insert(nums2[i]);
        }
        
        for(int i=0;i<nums3.size();++i) {
            if(s.count(nums3[i])!=0) {
                ans.insert(nums3[i]);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
