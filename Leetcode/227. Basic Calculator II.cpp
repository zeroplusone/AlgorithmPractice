class Solution {
public:

    int calculate(string s) {
        stack<int> sta;
        char last='+';
        string num="";
        
        for(int i=0;i<s.length();++i) {
            if(s[i]==' ') {
                continue;
            } else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {
                cal(last, sta, num);
                last=s[i];
                num="";
            } else {
                num+=s[i];
            }
        } 
        cal(last, sta, num);
        
        int ans=0;
        while(!sta.empty()) {
            ans+=sta.top();
            sta.pop();
        }
        return ans;
    }
    
    void cal(char& last, stack<int>& sta, string& num) {
        if(last=='+') {
            sta.push(stoi(num));
        } else if(last=='-') {
            sta.push(stoi(num)*(-1));
        } else if(last=='*') {
            int top=sta.top();
            sta.pop();
            sta.push(top*stoi(num));
        } else if(last=='/') {
            int top=sta.top();
            sta.pop();
            sta.push(top/stoi(num));
        }
    }
};
