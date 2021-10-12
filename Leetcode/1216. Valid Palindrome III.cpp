class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(2, vector<int>(s.length()+1, 0));
        for(int i=s.length()-1;i>=0;--i) {
            for(int j=0;j<s.length();++j) {
                if(s[i]==s[j]) {
                    dp[1][j+1]=dp[0][j]+1;
                } else {
                    dp[1][j+1]=max(dp[0][j+1], dp[1][j]);
                }
            }
            dp[0]=dp[1];
        }   
        return dp[1][s.length()]+k>=s.length();
    }
};
