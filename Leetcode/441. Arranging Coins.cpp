class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0, now=1;
        long long int cnt=0;
        while(cnt+now<=n) {
            cnt+=now;
            ans++;
            now++;
        }
        return ans;
    }
};
