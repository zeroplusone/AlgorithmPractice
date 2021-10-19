class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> p;
        stack<int> sta;
        
        for(int i=0;i<nums2.size();++i) {
            while(!sta.empty() && sta.top()<nums2[i]) {
                p[sta.top()]=nums2[i];
                sta.pop();
            }
            sta.push(nums2[i]);
        }
        while(!sta.empty()) {
            p[sta.top()]=-1;
            sta.pop();
        }
        
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();++i) {
            ans[i]=p[nums1[i]];
        }
        return ans;
    }
};
