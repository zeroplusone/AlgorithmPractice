class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n=s.length();

        int cnt=0;
        for(int i=0;i<n;++i) {
            if(s[i]-'0'==0) {
                ++cnt;
            }
        }
        
        if(cnt==0 || cnt==n) {
            return 0;
        }
        
        int ans=cnt;
        for(int i=0;i<n;++i) {
            if(s[i]-'0'==0) {
                --cnt;
            } else {
                ++cnt;
            }
            if(cnt<ans) {
                ans=cnt;
            }
        }
        return ans;
    }
};
