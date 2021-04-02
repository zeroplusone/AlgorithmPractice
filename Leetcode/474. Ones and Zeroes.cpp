class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> cnts(strs.size());
        
        for(int i=0;i<strs.size();++i) {
            int one=0, zero=0;
            for(auto c: strs[i]) {
                if(c=='1') one++;
                else if(c=='0') zero++;
            }
            cnts[i]=make_pair(zero, one);
        }

        vector<vector<Data>> dp(m+1, vector<Data>(n+1));
        for(auto cnt: cnts) {
            for(int i=m;i>=cnt.first;--i) {
                for(int j=n;j>=cnt.second;--j) {
                    if(dp[i-cnt.first][j-cnt.second].ans+1>dp[i][j].ans) {
                        Data data;
                        data.zero=dp[i-cnt.first][j-cnt.second].zero+cnt.first;
                        data.one=dp[i-cnt.first][j-cnt.second].one+cnt.second;
                        data.ans=dp[i-cnt.first][j-cnt.second].ans+1;
                        dp[i][j]=data;
                    }
                }
            }
        }
        
        return dp[m][n].ans;
    }
    
    struct Data{
        int zero;
        int one;
        int ans;
        Data(): zero(0), one(0), ans(0) {};
    };
};
