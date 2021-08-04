class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length(), j=t.length(), space=0;
        while(true) {
            space=0;
            while(i>=0) {
                if(s[i]=='#') {
                    space++;
                } else if(space>0) {
                    space--;
                } else {
                    break;
                }
                i--;
            }
            space=0;
            while(j>=0) {
                if(t[j]=='#') {
                    space++;
                } else if(space>0) {
                    space--;
                } else {
                    break;
                }
                j--;
            }
            
            if(i>=0 && j>=0 && s[i]==t[j]) {
                i--;    j--;
            } else {
                break;
            }

        }

        return i==-1 && j==-1;
        
    }
};
