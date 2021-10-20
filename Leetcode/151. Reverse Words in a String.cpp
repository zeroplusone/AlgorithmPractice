class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int index=0;
        int st=0, en=n-1;
        while(st<n && s[st]==' ') {
            st++;
        }
        
        while(en>=0 && s[en]==' ') {
            en--;
        }
        for(int i=st;i<=en;index++) {
            s[index]=s[i];
            if(s[i]!=' ') {
                i++;
            } else {
                while(i<n&&s[i]==' ') {
                    i++;
                }
            }
        }
        s.resize(index);
        
        reverse(s.begin(), s.end());
        st=0, en=0;
        while(st<index) {
            while(en<index && s[en]!=' ') {
                en++;
            }
            reverse(s.begin()+st, s.begin()+en);
            en++;
            st=en;
        }
        return s;
    }
};
