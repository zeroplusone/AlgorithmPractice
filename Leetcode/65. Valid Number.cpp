class Solution {
public:
    bool isNumber(string s) {
        bool has_sign=false;
        bool has_dot=false;
        bool has_e=false;
        bool must_digit=true;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='+' || s[i]=='-') {
                if(has_sign) {
                    return false;
                } else {
                    has_sign=true;
                }
            } else if(s[i]=='.') {
                if(has_dot) {
                    return false;
                } else {
                    has_dot=true;
                    has_sign=true;
                }
            } else if(must_digit) {
                if(is_digit(s[i])) {
                    must_digit=false;
                    has_sign=true;
                } else {
                    return false;
                }
            } else if(s[i]=='e' || s[i]=='E') {
                if(has_e) {
                    return false;
                } else {
                    has_e=true;
                    has_sign=false;
                    has_dot=true;
                    must_digit=true;
                }
            } else if(is_digit(s[i])) {
                has_sign=true;
            } else {
                return false;
            }
        }
        return !must_digit;
    }
    
    bool is_digit(char c) {
        return '0'<=c && c<='9'; 
    }
};
