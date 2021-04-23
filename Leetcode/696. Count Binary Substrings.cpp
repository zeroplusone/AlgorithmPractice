class Solution {
public:
    int countBinarySubstrings(string s) {
        int last=0, now=1;
        char c=s[0];
        int ans=0;
        for(int i=1;i<s.length();++i) {
            if(s[i]==c) {
                now++;
            } else {
                ans+=min(last, now);
                last=now;
                now=1;
                c=s[i];
            }
        }
        ans+=min(last, now);
        return ans;
    }
};
