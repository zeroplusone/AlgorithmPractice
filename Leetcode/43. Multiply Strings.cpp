class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") {
            return "0";
        }
        int n1=num1.length(), n2=num2.length();
        vector<int> digit(n1+n2, 0);
        for(int i=0;i<n1;++i) {
            for(int j=0;j<n2;++j) {
                digit[i+j]+=(num1[n1-1-i]-'0')*(num2[n2-1-j]-'0');
            }
        }
        
        for(int i=0;i<digit.size();++i) {
            int tmp=digit[i];
            int index=1;
            while(tmp/10!=0) {
                tmp/=10;
                digit[i+index]+=tmp%10;
                index++;
            }
            digit[i]=digit[i]%10;
        }
        int i=n1+n2-1;
        while(digit[i]==0) {
            i--;
        }
        string ans="";
        for(;i>=0;--i) {
            ans+=(char)(digit[i]+'0');
        }
        return ans;
    }
};
