class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero, one;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto str: strs) {
            zero=0;
            one=0;
            for(auto c: str) {
                if(c=='1') one++;
                else if(c=='0') zero++;
            }
            
            for(int i=m;i>=zero;--i) {
                for(int j=n;j>=one;--j) {
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
                }
            }
        }
        
        return dp[m][n];
    }
};
