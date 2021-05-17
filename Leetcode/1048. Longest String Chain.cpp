class Solution {
public:
    static bool comparator(string& a, string& b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        vector<int> dp(words.size(), 1);
        int ans=1;
        for(int i=1;i<words.size();++i) {
            for(int j=i-1;j>=0;--j) {
                if(words[i].length()==words[j].length()) {
                    continue;
                } else if(words[i].length()==words[j].length()+1) {
                    int diff=0;
                    for(int k=0,l=0;k<words[i].length();) {
                        if(l==words[j].length()) {
                            diff++;
                            k++;
                        } else if(words[i][k]==words[j][l]) {
                            k++;
                            l++;
                        } else {
                            diff++;
                            k++;
                        }
                    }
                    if(diff==1) {
                        dp[i]=max(dp[i], dp[j]+1);
                        ans=max(ans, dp[i]);
                    }
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
