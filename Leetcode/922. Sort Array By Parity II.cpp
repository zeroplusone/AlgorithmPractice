class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0, j=1;
        while(i<nums.size() && j<nums.size()) {
            while(i<nums.size() && nums[i]%2==0) {
                i+=2;
            }
            
            while(j<nums.size() && nums[j]%2==1) {
                j+=2;
            }
            
            if(i<nums.size() && j<nums.size()) {
                int tmp=nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;    
            }
            
        }
        return nums;
    }
};
