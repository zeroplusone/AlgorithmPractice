class Solution {
public:
    bool splitString(string s) {
        return solve(s, -1);
    }
    
    bool solve(string s, long long int last) {
        unsigned long long int start=0;
        for(int i=0;i<s.length();++i) {
            start=10*start+(s[i]-'0');
            if(last==-1) {
                if(i!=s.length()-1 && solve(s.substr(i+1, s.length()-i-1), start)) {
                    return true;
                }
            } else {
                if(start==last-1) {
                    if(i==s.length()-1 || solve(s.substr(i+1, s.length()-i-1), start)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
