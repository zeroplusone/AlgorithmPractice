class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]>=0) {
                int cnt=0;
                int j=i, tmp;
                while(nums[j]>=0) {
                    tmp=j;
                    j=nums[j];
                    nums[tmp]=-1;
                    cnt++;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
    
    
};
