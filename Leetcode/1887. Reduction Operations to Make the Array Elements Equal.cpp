class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> cnt;
        for(int i=0;i<nums.size();++i) {
            cnt[nums[i]]++;
        }
        int ans=0;
        int i=0;
        for(auto c:cnt) {
            ans+=i*c.second;
            i++;
        }
        return ans;
    }
};
