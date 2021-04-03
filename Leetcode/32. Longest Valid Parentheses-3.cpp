class Solution {
public:
    int longestValidParentheses(string s) {
        int left, right;
        left=0;right=0;
        int ans=0;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='(') {
                left++;
            } else {
                right++;
            }
            
            if(left==right) {
                ans=max(ans, right*2);
            } else if(left<right) {
                left=0; right=0;
            }
        }
        
        left=0; right=0;
        for(int i=s.length()-1;i>=0;--i) {
            if(s[i]=='(') {
                left++;
            } else {
                right++;
            }
            
            if(left==right) {
                ans=max(ans, left*2);
            } else if(left>right) {
                left=0; right=0;
            }
        }
        return ans;
    }
};
