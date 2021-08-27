class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        
        map<string, int> m;
        int n=strs.size();
        vector<string> keys;
        for(int i=0;i<n;++i) {
            if(m[strs[i]]==0) {
                keys.push_back(strs[i]);
            }
            m[strs[i]]++;
        }
        sort(keys.begin(), keys.end(), [](string a, string b) { return a.length()>b.length();});
        for(int i=0;i<keys.size();++i) {
            if(m[keys[i]]==1) {
                return keys[i].length();
            } else {
                for(int j=i+1;j<keys.size();++j) {
                    if(keys[j].length()!=keys[i].length()) {
                        vector<vector<int>> dp(2, vector<int>(keys[i].length()+1, 0));
                        for(int k=0;k<keys[j].length();++k) {
                            for(int l=0;l<keys[i].length();++l) {
                                if(keys[i][l]==keys[j][k]) {
                                    dp[1][l+1]=dp[0][l]+1;
                                } else {
                                    dp[1][l+1]=max(dp[0][l+1], dp[1][l]);
                                }
                            }
                            dp[0]=dp[1];
                        }
                        if(dp[1][keys[i].length()]==keys[j].length()) {
                            m[keys[j]]++;
                        }
                    }
                }
                
            }
        }
        return -1;
    }
};
