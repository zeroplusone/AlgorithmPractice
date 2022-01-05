class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n-i;++j) {
                if(i==0) {
                    dp[j][j+i]=true;
                } else if(i==1) {
                    dp[j][j+i]=s[j]==s[j+i];
                } else {
                    dp[j][j+i]=s[j]==s[j+i]&&dp[j+1][j+i-1];
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> sub;
        solve(0, s, ans, dp, sub);
        return ans;
    }
    
    void solve(int now, string& s, vector<vector<string>>& ans, vector<vector<bool>>& dp, vector<string>& sub) {
        if(now>=s.length()) {
            ans.push_back(sub);
            return;
        }
        for(int i=now;i<s.length();++i) {
            if(dp[now][i]) {
                sub.push_back(s.substr(now, i-now+1));
                solve(i+1, s, ans, dp, sub);
                sub.pop_back();
            }
        }
    }
};
