class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    
        int mod=1;
        for(int i=1;i<nums.size();++i) {
            if(nums[i]<nums[i-1]) {
                if(mod==0) {
                    return false;
                }else if(i==1 || nums[i-2]<=nums[i]) {
                    nums[i-1]=nums[i];
                } else if(nums[i-2]>nums[i-1]) {
                    return false;
                } else {
                    nums[i]=nums[i-1];
                }
                mod--;
            }
        }
        return true;   
        
    }
};
