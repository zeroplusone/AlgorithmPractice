class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int end=nums[0];
        for(int i=1;i<n;++i) {
            if(i>end) {
                return false;
            }
            end=max(end, i+nums[i]);
        }
        
        return true;
    }
};
