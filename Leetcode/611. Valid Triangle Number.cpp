class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int start=0;
        while(nums[start]==0) {
            start++;
        }
        int ans=0;
        for(int i=start+1;i<n;++i) {
            for(int j=start;j<i;++j) {
                int bound=lower_bound(nums.begin()+i, nums.end(), nums[i]+nums[j])-nums.begin();
                ans+=bound-i-1;
            }
        }
        return ans;
    }
};
