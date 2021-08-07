class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        vector<int> minCut(n+1, 0);
        for(int i=0;i<=n;++i) {
            minCut[i]=i-1;
        }
        
        for(int i=0;i<n;++i) {
            for(int j=0;j<=i;++j) {
                if (s[i]==s[j]&& ((i-j)<2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    minCut[i+1]=min(minCut[i+1], minCut[j]+1);
                }
            }
        }
        return minCut[n];
    }
};
