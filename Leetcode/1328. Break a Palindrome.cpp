class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1) {
            return "";
        }
        
        for(int i=0;i<palindrome.length()/2;++i) {
            if(palindrome[i]!='a') {
                palindrome[i]='a';
                return palindrome;
            }
        }
        
        for(int i=palindrome.length()-1;i>=palindrome.length()/2;--i) {
            if(palindrome[i]!='z') {
                palindrome[i]++;
                return palindrome;
            }
        }
        
        return "";
    }
};
