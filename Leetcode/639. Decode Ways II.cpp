class Solution {
public:
    int numDecodings(string s) {
        
        if(s.length()==1) {
            if(s[0]=='*') {
                return 9;
            } else if(s[0]=='0') {
                return 0;
            } else {
                return 1;    
            }
        }

        vector<long long int> dp(3);
        long long int M = 1e9+7;
        dp[0]=1;
        if(s[0]=='*') {
            dp[1]=9;
        } else if(s[0]=='0') {
            dp[1]=0;
        } else {
            dp[1]=1;    
        }
        
        int last=s[0]=='*'?10:s[0]-'0';
        for(int i=1;i<s.length();++i) {
            int now=s[i]=='*'?10:s[i]-'0';
            if(now==10) {
                if(last==10) {
                    dp[2]=(9*dp[1]+15*dp[0])%M;
                } else if (last==1) {
                    dp[2]=(9*dp[1]+9*dp[0])%M;
                } else if (last==2) {
                    dp[2]=(9*dp[1]+6*dp[0])%M;
                } else {
                    dp[2]=(9*dp[1])%M;
                }
            } else if (now==0){
                if(last==10) {
                    dp[2] = (2*dp[0]) % M;
                } else if(last==1 || last==2) {
                    dp[2]=dp[0];
                } else {
                    return 0;
                }
            } else {
                if(last==10) {
                    dp[2] = (dp[1]+(now<=6?2:1)*dp[0]) % M;
                } else if (last==0) {
                    dp[2]=dp[1];
                } else {
                    if(last*10+now<=26) {
                        dp[2]=dp[1]+dp[0];
                    } else {
                        dp[2]=dp[1];
                    }
                }
            }

            dp[0]=dp[1];
            dp[1]=dp[2];
            last=now;
        }

        return dp[1];    
    }
};
