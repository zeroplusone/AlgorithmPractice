class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        if(n<=3) {
            return 0;
        }
        int st=0, en=n-4;
        int ans=2*1e9+1;
        for(int i=0;i<4;++i) {
            ans=min(ans, nums[en]-nums[st]);
            st++;
            en++;
        }
        return ans;
    }
};
