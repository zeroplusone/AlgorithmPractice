class Solution {
public:

    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int, int> p;

        for(int i=0;i<n;++i) {
            for(int j=2;j<=sqrt(nums[i]);++j) {
                if(nums[i]%j==0) {
                    uni(nums[i], j, p);
                    uni(nums[i], nums[i]/j, p);
                }
            }
        }
        
        unordered_map<int, int> cnt;
        int ans=1;
        for(int i=0;i<n;++i) {
            int pp=findp(nums[i], p);
            cnt[pp]++;
            ans=max(ans, cnt[pp]);
        }
        return ans;
    }
    
    void uni(int x, int y, unordered_map<int, int>& p) {
        int xp=findp(x, p);
        int yp=findp(y, p);
        p[yp]=xp;
    }
    
    int findp(int now, unordered_map<int, int>& p) {
        if(p[now]==0 || p[now]==now) {
            return now;
        } else {
            return p[now]=findp(p[now], p);
        }
    }
};
