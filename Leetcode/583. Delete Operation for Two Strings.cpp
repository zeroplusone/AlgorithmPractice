class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(2, vector<int>(word2.length()+1, 0));
        
        for(char w1:word1) {
            for(int i=0;i<word2.length();++i) {
                if(w1==word2[i]) {
                    dp[1][i+1]=dp[0][i]+1;
                } else {
                    dp[1][i+1]=max(dp[1][i], dp[0][i+1]);
                }
            }
            dp[0]=dp[1];
        }
        return word1.length()+word2.length()-2*dp[1][word2.length()];
    }
};
