class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        } else if(x==0) {
            return true;
        }
        vector<int> digit;
        int n=0;
        while(x!=0) {
            digit.push_back(x%10);
            n++;
            x/=10;
        }

        for(int i=0;i<n/2;++i) {
            if(digit[i]!=digit[n-1-i]) {
                return false;
            }
        }
        return true;
        
    }
};
