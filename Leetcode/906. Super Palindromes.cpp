class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long int l = stoll(left);
        long long int r = stoll(right);
        string sqrtl = to_string((int)sqrt(l));
        string sqrtr = to_string((int)sqrt(r));
        int ans=0;
        for(int i=sqrtl.length();i<=sqrtr.length();++i) {
            if(i==1) {
                if(l<=1 && r>=1) ans++;
                if(l<=4 && r>=4) ans++;
                if(l<=9 && r>=9) ans++;
            } else {
                count("", i, l, r, ans);    
            }
        }
        return ans;
    }
    
    void count(string now, int len, long long int& l, long long int& r, int& ans) {
        if(now.length()==len) {
            long long int square = stoll(now)*stoll(now);
            if(square>=l && square<=r && isPalindromes(to_string(square))) {
                ans++;
            }
            return;
        }
        
        if(now.length()==0 && len%2==1) {
            count("0", len, l, r, ans);
            count("1", len, l, r, ans);
            count("2", len, l, r, ans);
        } else {
            if(len-now.length()!=2) {
                count("0"+now+"0", len, l, r, ans);
            }
            count("1"+now+"1", len, l, r, ans);
            count("2"+now+"2", len, l, r, ans);
        }
    }
    
    bool isPalindromes(string str) {
        for(int i=0;i<str.length()/2;++i) {
            if(str[i]!=str[str.length()-i-1]) {
                return false;
            }
        }
        return true;
    }
};
