class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int zero=0, second=nums.size()-1;
        for(int i=0;i<nums.size()&&i<=second;){
            if(nums[i]==0){
                swap(nums[i++], nums[zero++]);
            }else if(nums[i]==2){
                swap(nums[i], nums[second--]);
            }else if(nums[i]==1){
                ++i;
            }
                
        }
    }
};
