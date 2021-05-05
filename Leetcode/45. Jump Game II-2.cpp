class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int now_ind=0, now_val=0;
        for(int i=0;i<nums.size()-1;++i) {
            now_val=max(now_val, i+nums[i]);
            
            if(i==now_ind) {
                ans++;
                now_ind=now_val;
            }
        }
        return ans;
    }
};
