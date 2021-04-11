class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto num:nums) {
            if(num>0) {
                ans*=1;
            } else if(num < 0) {
                ans*=(-1);
            } else {
                ans=0;
            }
        }
        return ans;
    }
};
