class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n, -1);
        for(int i=0;i<n;++i) {
            int x=findp(i, p);
            int y=findp(nums[i], p);

            p[y]=x;
        }
        int ans=0;
        unordered_map<int, int> cnt;
        for(int i=0;i<n;++i) {
            int now=findp(i, p);
            cnt[now]++;
            ans=max(ans, cnt[now]);
        }
        return ans;
    }
    
    int findp(int now, vector<int>& p) {
        if(p[now]==-1 || p[now]==now) {
            return now;
        } else {
            p[now]=findp(p[now], p);
            return p[now];
        }
    }
};
