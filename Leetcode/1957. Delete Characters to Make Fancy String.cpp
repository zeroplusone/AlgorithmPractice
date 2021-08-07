class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        string ans=""; 
        
        ans+=s[0];
        for(int i=1;i<s.length();++i) {
            cnt=s[i]==s[i-1]? cnt+1:1;

            if(cnt<3) {
                ans+=s[i];
            }
        }
        return ans;

    }
};
