class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> costs(n, vector<string>(n, ""));
        for(int i=0;i<n;++i) {
            for(int j=i;j<n;++j) {
                if(i==j) {
                    costs[i][j]=words[i];
                } else {
                    costs[i][j]=cost(words[i], words[j]);
                    costs[j][i]=cost(words[j], words[i]);
                }
            }
        }
        
        vector<vector<string>> dp(pow(2,n), vector<string>(n, string(300, 'a')));
        string ans=string(300, 'a');
        int all = (1<<n)-1;
        for(int i=0;i<n;++i) {
            string sourcei=solve(all, i, dp, costs);
            if(sourcei.length()<ans.length()) {
                ans=sourcei;
            }
        }

        return ans;
    }
    
    string solve(int bitmask, int j, vector<vector<string>>& dp, vector<vector<string>>& costs) {
        if(dp[bitmask][j].length()!=300) {
            return dp[bitmask][j];
        } else if(bitmask==(1<<j)) {
            return dp[bitmask][j]=costs[j][j];
        } else {
            for(int i=0;i<costs.size();++i) {
                if(i==j) {
                    continue;
                } else if(bitmask&(1<<i)) {
                    string ret=solve(bitmask&~(1<<j), i, dp, costs)+costs[i][j];
                    if(ret.length()<dp[bitmask][j].length()) {
                        dp[bitmask][j]=ret;
                    }
                }
            }
        }

        return dp[bitmask][j];
    }
    
    string cost(string pre, string post) {
        int prelen = pre.length();
        int postlen = post.length();
        string presub=pre, postsub=post;

        for(int same = prelen>=postlen?postlen-1:prelen-1; same>0;--same) {
            presub = pre.substr(prelen-same,same);
            postsub = post.substr(0, same);
            if(presub==postsub) {
                return post.substr(same, post.length()-same);
            }
        }
        return post;
    }
};
