class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans=nums[0];
        m[nums[0]]=0;
        int last=-1;
        for(int i=1;i<nums.size();++i) {
            if(m.count(nums[i])) {
                last=max(last, m[nums[i]]);
            } 
            m[nums[i]]=i;
            nums[i]+=nums[i-1];
            ans=max(ans, last==-1?nums[i]:nums[i]-nums[last]);
        }
        return ans;
    }
};
