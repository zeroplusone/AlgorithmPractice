class Solution {
public:
    bool isThree(int n) {
        if(n==1) {
            return false;
        }
        int base=sqrt(n);
        if(base*base!=n) {
            return false;
        }
        if(base==2) {
            return true;
        } 
        
        for(int j=2;j<=sqrt(base);++j) {
            if(base%j==0) {
                return false;
            }
        }
        
        return true;
     }
};
