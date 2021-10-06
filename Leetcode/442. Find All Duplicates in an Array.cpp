class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;
        for(int i=0;i<nums.size();++i) {
            int n=abs(nums[i])-1;
            nums[n]=(-1)*(abs(nums[n]));
        }
        
        for(int i=0;i<nums.size();++i) {
            if(nums[i]>0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }

};
