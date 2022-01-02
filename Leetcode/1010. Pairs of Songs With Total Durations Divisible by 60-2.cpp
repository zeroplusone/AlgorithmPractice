class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60, 0);
        int ans=0;
        for(int i=0;i<time.size();++i) {
            time[i]=time[i]%60;
            ans+=cnt[(60-time[i])%60];
            cnt[time[i]]++;
        }
        return ans;
    }
};
