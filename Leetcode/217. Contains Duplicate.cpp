class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();++i) {
            if(s.count(nums[i])!=0) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
