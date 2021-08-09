class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        string ans="";
        while(i>=0 || j>=0 || carry>0) {
            int digit=0;
            if(i>=0) {
                digit+=num1[i]-'0';
            }
            
            if(j>=0) {
                digit+=num2[j]-'0';
            }
            
            digit+=carry;
            ans.insert(0, to_string(digit%10));
            carry=digit/10;
            i--;
            j--;
        }
        return ans;
    }
};
