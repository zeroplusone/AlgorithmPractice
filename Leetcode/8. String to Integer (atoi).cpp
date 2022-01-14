class Solution {
public:
    int myAtoi(string s) {
        // space 0, + 1, - 2, d 3
        int state=0;
        int sign=0;
        long long int digit=0;
        bool finish=false;
        bool hasd=false;
        for(int i=0;i<s.length()&&!finish;++i) {
            if(digit>INT_MAX || digit<INT_MIN) {
                break;
            }
            switch(state) {
                case 0:
                    if(s[i]==' ') {
                        continue;
                    } else if(s[i]=='+') {
                        state=1;
                        sign=1;
                    } else if(s[i]=='-') {
                        state=2;
                        sign=-1;
                    } else if(s[i]-'0'>=0 && s[i]-'0'<=9) {
                        state=3;
                        digit=digit*10+(int)(s[i]-'0');
                        hasd=true;
                    } else {
                        finish=true;
                    }
                    break;
                case 1:
                case 2:
                    if(s[i]-'0'>=0 && s[i]-'0'<=9) {
                        state=3;
                        digit=digit*10+(int)(s[i]-'0');
                        hasd=true;
                    } else {
                        digit=0;
                        finish=true;
                    }
                    break;
                case 3:
                    if(s[i]-'0'>=0 && s[i]-'0'<=9) {
                        state=3;
                        digit=digit*10+(int)(s[i]-'0');
                        hasd=true;
                    } else {
                        if(hasd) {
                            finish=true;
                        } 
                    }
                    break;
            }
        }
        digit=hasd?digit:0;
        digit=sign>=0?digit:-digit;
        if(digit>INT_MAX) {
            digit=INT_MAX;
        } else if(digit<INT_MIN) {
            digit=INT_MIN;
        }
        return digit;
    }
};
