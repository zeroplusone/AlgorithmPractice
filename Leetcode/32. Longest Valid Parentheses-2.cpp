class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int ans=0;
        sta.push(-1);
        for(int i=0;i<s.length();++i) {
            if(s[i]=='(') {
                sta.push(i);
            } else {
                sta.pop();
                if(!sta.empty()) {
                    ans = max(ans, i-sta.top());
                } else {
                    sta.push(i);
                }
            }
        }
        
        return ans;
    }
};
