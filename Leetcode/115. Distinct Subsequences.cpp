class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length()<t.length()) {
            return 0;
        }

        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(0, 0, s, t, dp);
    }
    
    int solve(int si, int ti, string& s, string& t, vector<vector<int>>& dp) {
        if(si>=s.length() || ti>=t.length() || s.length() - si < t.length() - ti) {
            return 0;
        } else if(dp[si][ti]!=-1) {
            return dp[si][ti];
        }
        int ret=0;
        for(int i=si;i<s.length();++i) {
            if(s[i]==t[ti]) {
                if(ti==t.length()-1) {
                    ret+=1;
                } else {
                    ret+=solve(i+1, ti+1, s, t, dp);
                }        
            }
        }
        dp[si][ti]=ret;
        return ret;
    }
};
