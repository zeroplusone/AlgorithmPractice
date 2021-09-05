class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        long long int mod=1e9+7;
        
        int n=nextVisit.size();
        vector<int> dp(n, 0);
        dp[0]=0;
        for(int i=1;i<n;++i) {
            long long int base=2;
            dp[i]=(base+2*dp[i-1]-dp[nextVisit[i-1]]+mod)%mod;
        }
        
        return dp[n-1];
    }
};
