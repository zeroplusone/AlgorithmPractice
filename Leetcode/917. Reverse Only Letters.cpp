class Solution {
public:
    string reverseOnlyLetters(string s) {
        int pre=0, en=s.length()-1;
        while(pre<en) {
            while(pre<s.length() && !((s[pre]>='a' && s[pre]<='z') || (s[pre]>='A' && s[pre]<='Z'))) {
                pre++;
            }
            
            while(en>=0 && !((s[en]>='a' && s[en]<='z') || (s[en]>='A' && s[en]<='Z'))) {
                en--;
            }
            
            if(pre<en) {
                char tmp=s[pre];
                s[pre]=s[en];
                s[en]=tmp;
                pre++;
                en--;
            }
        }
        return s;
    }
};
