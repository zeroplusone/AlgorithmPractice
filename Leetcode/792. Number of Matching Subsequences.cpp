class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_set<char> schar;
        unordered_set<string> subsequence;
        for(int i=0;i<s.length();++i) {
            schar.insert(s[i]);
        }
        for(int i=0;i<words.size();++i) {
            if(subsequence.count(words[i])!=0) {
                ans++;
                continue;
            }
            int k=0, j=0;
            for(j=0;j<words[i].length();++j, ++k) {
                if(schar.count(words[i][j])==0) {
                    break;
                }
                while(k<s.length() && words[i][j]!=s[k]) {
                    k++;
                }
                if(k==s.length()) {
                    break;
                }
            }
            if(j==words[i].length()) {
                ans++;
                subsequence.insert(words[i]);
            }
        }
        return ans;
    }
};
