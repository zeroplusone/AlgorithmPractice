class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        int n=nums.size();
        for(int i=0;i<n/2;++i) {
            ans[i*2]=nums[n-1-i];
            ans[i*2+1]=nums[i];
        }
        if(n%2==1) {
            ans[n-1]=nums[n/2];
        }
        return ans;
    }
};
