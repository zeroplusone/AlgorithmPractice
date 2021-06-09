class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second<p2.second;    
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int sum=0;
        dp[0]=nums[0];
        for(int i=1;i<1+k && i<nums.size();++i) {
            dp[i]+=nums[0]+nums[i]+sum;
            sum+=nums[i]>0?nums[i]:0;
            pq.push(make_pair(i, dp[i]));
        }
        for(int i=1+k;i<nums.size();++i) {
            while(pq.top().first<i-k) {
                pq.pop();
            }
            dp[i]+=pq.top().second+nums[i];
            pq.push(make_pair(i, dp[i]));
        }
        return dp[nums.size()-1];
    }
};
