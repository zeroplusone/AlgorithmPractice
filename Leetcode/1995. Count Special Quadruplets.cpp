class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        for(int d=nums.size()-1;d>=3;--d) {
            for(int a=0;a<d-2;++a) {
                for(int b=a+1;b<d-1;++b) {
                    for(int c=b+1;c<d;++c) {
                        if(nums[d]==nums[a]+nums[b]+nums[c]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
