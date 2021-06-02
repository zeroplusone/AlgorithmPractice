class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) {
            return false;
        }
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
    
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if(i<s1.length() && j<s2.length() && dp[i][j]!=-1) {
            return dp[i][j]==1;
        }
        if(k==s3.length()) {
            if(i==s1.length() && j==s2.length()) {
                return true;    
            } else {
                return false;
            }
        }
        bool ret=false;
        if(i<s1.length() && s1[i]==s3[k]) {
            ret|=solve(i+1, j, k+1, s1, s2, s3, dp);
        } 
        if(j<s2.length() && s2[j]==s3[k]) {
            ret|=solve(i, j+1, k+1, s1, s2, s3, dp);
        }
        dp[i][j]=ret?1:0;
        return ret;
    }
};
