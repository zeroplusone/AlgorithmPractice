//back tracking solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current(0);
        sort(nums.begin(), nums.end());
        backtracking(0, current, nums, ans);
        return ans;
    }
    
    void backtracking(int now, vector<int>& current, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(current);
        
        for(int i=now;i<nums.size();++i) {
            if(i>=1 && i!=now && nums[i]==nums[i-1]) {
                continue;
            }
            
            current.push_back(nums[i]);
            backtracking(i+1, current, nums, ans);
            current.pop_back();
        }
    }
};
