class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long long int> dp(stations.size()+1, 0);
        dp[0]=startFuel;
        for(int i=0;i<stations.size();++i) {
            for(int j=i+1;j>=1;--j) {
                if(dp[j-1]>=stations[i][0]) {
                    dp[j]=max(dp[j], dp[j-1]+stations[i][1]);
                }
            }
        }
        
        for(int i=0;i<dp.size();++i) {
            cout<<dp[i]<<endl;
            if(dp[i]>=target) {
                return i;
            }
        }
        return -1;
    }
};
