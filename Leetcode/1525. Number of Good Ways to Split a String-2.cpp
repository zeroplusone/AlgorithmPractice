class Solution {
public:
    int numSplits(string s) {
        vector<int> pre(26, 0);
        vector<int> post(26, 0);
        int ans=0;
        for(int i=0;i<s.length();++i) {
            post[s[i]-'a']++;
        }
        
        for(int i=0;i<s.length();++i) {
            pre[s[i]-'a']++;
            post[s[i]-'a']--;
            int preCnt=0, postCnt=0;
            for(int j=0;j<26;++j) {
                preCnt+=pre[j]!=0?1:0;
                postCnt+=post[j]!=0?1:0;
            }
            if(preCnt==postCnt) {
                ans++;
            }
        }
        return ans;
    }
};
