class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.length();++i) {
            if(s[i]==')') {
                if(sta.size()==0 || sta.top()!='(') {
                    return false;
                } else {
                    sta.pop();
                }
            } else if(s[i]==']') {
                if(sta.size()==0 || sta.top()!='[') {
                    return false;
                } else {
                    sta.pop();
                }
            } else if(s[i]=='}') {
                if(sta.size()==0 || sta.top()!='{') {
                    return false;
                } else {
                    sta.pop();
                }
            } else {
                sta.push(s[i]);
            }
        }
        return sta.size()==0;
    }
};
