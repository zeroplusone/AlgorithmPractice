class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minv=min(1, nums[0]);
        for(int i=1;i<nums.size();++i) {
            nums[i]=nums[i]+nums[i-1];
            minv=min(minv, nums[i]);
        }
        
        return minv<=0?-minv+1:minv;
    }
};
