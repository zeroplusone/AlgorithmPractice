class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int cnt=0;
        stack<char> sta;
        for(int i=0;i<n;++i) {
            if(s[i]=='[') {
                sta.push('[');
            } else if(sta.empty()) {
                cnt++;
            } else {
                sta.pop();
            }
        }
        return (cnt+1)/2;
    }
};
