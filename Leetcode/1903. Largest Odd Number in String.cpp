class Solution {
public:
    string largestOddNumber(string num) {
        int odd_index=-1;
        for(int i=num.length()-1;i>=0;--i) {
            if((num[i]-'0')%2==1) {
                odd_index=i;
                break;
            }
        }
        if(odd_index==-1) {
            return "";
        } else {
            return num.substr(0, odd_index+1);    
        }
    }
};
