class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string>> dp(n+1, unordered_set<string>(0));
        dp[0]=unordered_set<string>{""};
        dp[1]=unordered_set<string>{"()"};
        for(int i=2;i<=n;++i) {
            for(int j=0;j<i;++j) {
                for(auto left: dp[j]) {
                    for(auto right: dp[i-j-1]) {
                        dp[i].insert("("+left+")"+right);  
                    }
                }   
            }
        }

        return vector<string>(dp[n].begin(), dp[n].end());
    }
};
