class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int miss=1, ans=0;
        for(int i=0;miss<=n;) {
            if(i<nums.size() && nums[i]<=miss) {
                miss+=nums[i];
                i++;
            } else {
                miss+=miss;
                ans++;
            }
        }
        return ans;
    }
};
