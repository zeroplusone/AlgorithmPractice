class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> cnt(10, 0);
        unordered_set<int> s;
        for(int i=1, j=0;i<10;++i) {
            cnt[i]=cnt[i-1];
            if(j<digits.size() && i==stoi(digits[j])) {
                cnt[i]+=1;
                s.insert(i);
                j++;
            }
            
        }
        
        string nstr=to_string(n);
        int len=nstr.length();
        vector<int> dp(len+1, 0);
        dp[len]=1;
        int ans=0;
        for(int i=len-1;i>=0;--i) {
            int now=nstr[i]-'0';
            dp[i]+=(cnt[now]-(s.count(now)!=0?1:0))*pow(digits.size(), len-1-i);
            if(s.count(now)!=0) {
                dp[i]+=dp[i+1];
            }
        }
        
        for(int i=1;i<len;++i) {
            dp[0]+=pow(digits.size(), i);
        }
        
        return dp[0];
    }
};
