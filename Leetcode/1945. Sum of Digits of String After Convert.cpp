class Solution {
public:
    int getLucky(string s, int k) {
        string num="";
        for(int i=0;i<s.length();++i) {
            num+=to_string(s[i]-'a'+1);
        }

        int ans;
        for(int i=0;i<k;++i) {
            ans=0;
            for(int j=0;j<num.length();++j) {
                ans+=(num[j]-'0');
            }
            num=to_string(ans);
        }
        return ans;
    }
};
