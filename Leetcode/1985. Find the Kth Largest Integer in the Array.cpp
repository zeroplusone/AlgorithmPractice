class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), [](string s1, string s2) {
            return s1.length()==s2.length()?s1>s2:s1.length()>s2.length();
        });
        return nums[k-1];
            
    }
};
