class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;
        for(int i=0;i<s.length();++i) {
            if(!sta.empty()) {
                if(sta.top()==s[i]) {
                    sta.pop();
                    continue;
                }
            }
            sta.push(s[i]);
        }
        string ans="";
        while(!sta.empty()) {
            ans=sta.top()+ans;
            sta.pop();
        }
        return ans;
    }
};
