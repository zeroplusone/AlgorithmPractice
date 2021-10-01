class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(2, vector<int>(text1.length()+1, 0));
        
        for(int i=0;i<text2.length();++i) {
            for(int j=0;j<text1.length();++j) {
                if(text1[j]==text2[i]) {
                    dp[1][j+1]=dp[0][j]+1;
                } else {
                    dp[1][j+1]=max(dp[1][j], dp[0][j+1]);
                }
            }
            dp[0]=dp[1];
        }
        return dp[1][text1.length()];
    }
};
