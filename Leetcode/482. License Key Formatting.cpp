class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        int cnt=0;
        int st=0;
        while(st<s.length() && s[st]=='-') {
            st++;
        }
        for(int i=s.length()-1;i>=st;--i) {
            if(s[i]!='-') {
                cnt++;
                ans+=s[i]>='a'&&s[i]<='z'?'A'+(s[i]-'a'):s[i];
                if(cnt==k && i!=st) {
                    ans+='-';
                    cnt=0;
                } 
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
