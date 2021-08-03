// iteration solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(1, vector<int>(0));
        int lastSize=0;
        for(int i=0;i<n;++i) {
            int st=0;
            if(i>=1 && nums[i]==nums[i-1]) {
                st=lastSize;
            }
            lastSize=ans.size();
            for(int j=st;j<lastSize;++j) {
                vector<int> copy=ans[j];
                copy.push_back(nums[i]);
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
