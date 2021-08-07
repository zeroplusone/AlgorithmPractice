class Solution {
public:
    string makeFancyString(string s) {
        char last=s[0];
        int cnt=1;
        int i=1;
        string ans="";
        ans+=last;
        while(i<s.length()) {
            if(s[i]==last) {
                cnt++;
            } else {
                cnt=1;
                last=s[i];
            }
            
            if(cnt<3) {
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};
