class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=1e9;
        for(int i=0;i<=nums.size()-k;++i) {
            ans=min(nums[i+k-1]-nums[i], ans);
        }
        return ans;
    }
};
