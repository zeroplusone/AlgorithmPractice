class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 1e5;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==target) {
                ans=min(ans, abs(start-i));
            }
        }
        return ans;
    }
};
