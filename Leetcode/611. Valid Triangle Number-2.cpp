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
        for(int i=start;i<n;++i) {
            for(int j=i+1, k=i+2;j<n-1;++j) {
                while(k<n && nums[i]+nums[j]>nums[k]) {
                    k++;
                }
                ans+=k-j-1;
            }
        }
        return ans;
    }
};
