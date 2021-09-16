class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) {
            return true;
        } else if(x<0 || x%10==0) {
            return false;
        } 
        int revert=0;
        while(x>revert) {
            revert=revert*10+x%10;
            x/=10;
        }
        
        return revert==x || revert/10==x;
        
    }
};
