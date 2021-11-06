class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int bitmask=0;
        for(int i=0;i<nums.size();++i) {
            bitmask^=nums[i];
        }
        
        long long int last=bitmask&(-bitmask);
        
        int x=0;
        for(int i=0;i<nums.size();++i) {
            if((last&nums[i])!=0) {
                x^=nums[i];
            }
        }
        
        int y=bitmask^x;
        
        return vector<int>{x, y};
    }
};
