class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int move=0;
        int mid=nums.size()/2;
        for(int i=0;i<nums.size();++i) {
            move+=abs(nums[i]-nums[mid]);
        }
        return move;
    }
};
