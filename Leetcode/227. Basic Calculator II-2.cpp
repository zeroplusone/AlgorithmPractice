class Solution {
public:

    int calculate(string s) {
        int ans=0;
        char last='+';
        int num1=0, num2=0;
        string num="";
        
        for(int i=0;i<s.length();++i) {
            if(s[i]==' ') {
                continue;
            } else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {
                num2=stoi(num);
                cal(last, num1, num2, ans);
                last=s[i];
                num="";
            } else {
                num+=s[i];
            }
        } 
        num2=stoi(num);
        cal(last, num1, num2, ans);
        
        return ans;
    }
    
    void cal(char& last, int& num1, int& num2, int& ans) {
        if(last=='+') {
            ans+=num2;
            num1=num2;
        } else if(last=='-') {
            ans-=num2;
            num1=-num2;
        } else if(last=='*') {
            ans-=num1;
            ans+=num1*num2;
            num1=num1*num2;
        } else if(last=='/') {
            ans-=num1;
            ans+=num1/num2;
            num1=num1/num2;
        }
    }
};
