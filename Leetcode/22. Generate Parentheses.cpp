class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string>> dp(n+1, unordered_set<string>(0));
        dp[0]=unordered_set<string>{""};
        dp[1]=unordered_set<string>{"()"};
        for(int i=2;i<=n;++i) {
            string init="";
            for(int j=0;j<i;++j) {
                init+="(";
            }
            for(int j=0;j<i;++j) {
                init+=")";
            }
            dp[i].insert(init);
            for(int j=1;j<i;++j) {
                for(auto k: dp[j]) {
                    for(auto l: dp[i-j]) {
                        dp[i].insert(k+l);    
                    }
                }   
            }
            for(auto j: dp[i-1]) {
                dp[i].insert("("+j+")");    
            }
        }

        vector<string> ans = vector<string>(dp[n].begin(), dp[n].end());
        return ans;
    }
};
