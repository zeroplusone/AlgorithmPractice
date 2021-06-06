class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;

        for(int i=0;i<nums.size();++i) {
            num_set.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();++i) {
            if(!num_set.count(nums[i])) {
                continue;
            }
            int cnt=1;
            int now=nums[i];
            while(num_set.count(now-1)) {
                cnt++;
                num_set.erase(now-1);
                now-=1;
            }
            now=nums[i];
            while(num_set.count(now+1)) {
                cnt++;
                num_set.erase(now+1);
                now+=1;
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};
