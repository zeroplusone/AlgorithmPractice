class Solution {
public:
    int longestValidParentheses(string s) {
        map<int, bool> valid;
        stack<int> sta;
        
        for(int i=0;i<s.length();++i) {
            if(s[i]=='(') {
                sta.push(i);
                valid[i]=false;
            } else {
                if(!sta.empty()) {
                    valid[sta.top()]=true;
                    sta.pop();
                } else {
                    valid[i]=false;
                }
            }
        }
        int cal=0, ans=0;
        for(auto v: valid) {
            if(v.second) {
                cal++;
                ans = max(ans, cal);
            } else {
                cal=0;
            }
        }
        return ans*2;
    }
};
