class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> cnt;
        for(int i=0;i<time.size();++i) {
            cnt[time[i]%60]++;
        }
        
        int ans=0;
        for(auto c: cnt) {
            int target=(60-c.first)%60;
            if(c.first==target) {
                ans+=c.second*(c.second-1)/2;
            } else if(cnt.count(target)!=0) {
                ans+=c.second*cnt[target];
                cnt[c.first]=0;
                cnt[target]=0;
            }
        }
        return ans;
    }
};
