class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator upper = upper_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), target);

        if(lower!=nums.end() && (*lower) == target) {
            int first = lower-nums.begin();
            int last = upper-nums.begin()-1;
            return vector<int>{first, last};
        }else {
            return vector<int>{-1, -1};
        }
    }
};
