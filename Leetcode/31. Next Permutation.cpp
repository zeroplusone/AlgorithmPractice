class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-2;i>=0;--i) {
            if(nums[i]<nums[i+1]) {
                int j=i+1;
                while(j<nums.size() && nums[i]<nums[j]) {
                    j++;
                }
                swap(i, j-1, nums);
                int rst=i+1;
                int ren=nums.size()-1;
                while(rst<ren) {
                    swap(rst, ren, nums);
                    rst++; ren--;
                }
                break;
            }
        }
        if(i==-1) {
            sort(nums.begin(), nums.end());
        }
    }
    
    void swap(int i, int j, vector<int>& nums) {
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
};
