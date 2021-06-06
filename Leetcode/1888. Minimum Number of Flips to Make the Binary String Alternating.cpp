class Solution {
public:
    int minFlips(string s) {
        int cnt10=0, cnt01=0;
        int n=s.length();
        for(int i=0;i<n;++i) {
            if(i%2==0) {
                cnt01+=s[i]=='0'?1:0;
                cnt10+=s[i]=='1'?1:0;
            } else {
                cnt01+=s[i]=='1'?1:0;
                cnt10+=s[i]=='0'?1:0;
            }
        }
        int ans=min(cnt01, cnt10);
        if(n%2==0) {
            return ans;
        } else {
            for(int i=0;i<n;++i) {
                if(i%2==0) {
                    if(s[i]=='0') {
                        cnt01--;
                        cnt10++;
                    } else {
                        cnt01++;
                        cnt10--;
                    }
                } else {
                    if(s[i]=='1') {
                        cnt01--;
                        cnt10++;
                    } else {
                        cnt01++;
                        cnt10--;
                    }
                }
                ans=min(ans, min(cnt01, cnt10));
            }
            return ans;
        }
        
        
    }
};
