class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;
        int sum=0;
        while(i>=0 || j>=0) {
            sum=carry;
            if(i>=0) {
                sum+=a[i]-'0';
                i--;
            }
            
            if(j>=0) {
                sum+=b[j]-'0';
                j--;
            }
            
            ans+='0'+sum%2;
            carry=sum/2;
        }
        if(carry!=0) {
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
