class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') {
            return 0;
        } else if(s.length()==1) {
            return 1;
        }
        int dp0=1, dp1=1, now;
        for(int i=1;i<s.length();++i) {
            now=(s[i]=='0'?0:dp1)+((s[i-1]!='0'&&stoi(s.substr(i-1, 2))<=26)?dp0:0);
            dp0=dp1;
            dp1=now;
        }
        return now;
    }

};
