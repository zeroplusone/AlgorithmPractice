class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        vector<int> ans(2, 0);
        int diff;
        for(int i=0;i<nums.size();++i) {
            diff=target-nums[i];
            if(m.count(diff)!=0) {
                ans[0]=i;
                ans[1]=m[diff];
                break;
            } else {
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};
