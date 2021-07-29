class Solution {
public:
    string decodeString(string s) {
        stack<string> sta;
        string digit="", repeat;
        string ans="";
        for(int i=0;i<s.length();++i) {
            if(isDigit(s[i])) {
                digit="";
                while(isDigit(s[i])) {
                    digit+=s[i];
                    i++;
                }
                sta.push(digit);
            } else if(s[i]==']') {
                repeat="";
                while(!isDigit(sta.top()[0])){
                    repeat=sta.top()+repeat;
                    sta.pop();
                }
                int k=stoi(sta.top());
                sta.pop();
                string ret="";
                while(k--) {
                    ret+=repeat;
                }
                if(sta.empty()) {
                    ans+=ret;
                } else {
                    sta.push(ret);
                }
            } else {
                if(sta.empty()) {
                    ans+=s[i];    
                } else {
                    sta.push(string(1, s[i]));
                }
            }
            
        }
        return ans;
    }
    
    bool isDigit(char c) {
        return c>='0' && c<='9';
    }
};
