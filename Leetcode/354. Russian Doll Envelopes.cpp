class Solution {
public:
    static bool comparator( const vector<int>& v1, const vector<int>& v2 ) {
    return v1[0]==v2[0]?v1[1] < v2[1] : v1[0] < v2[0];
}
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(), 1);
        sort(envelopes.begin(), envelopes.end(), comparator);

        for(int i=0;i<envelopes.size();++i) {
            for(int j=i+1;j<envelopes.size();++j) {
                if(envelopes[j][0]>envelopes[i][0] && envelopes[j][1]>envelopes[i][1]) {
                    dp[j] = max(dp[i]+1, dp[j]);
                }
            }
        }
        int ans = dp[0];
        for(int i=1;i<envelopes.size();++i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    
};
