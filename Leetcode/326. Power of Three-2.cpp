class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) {
            return false;
        }
        
        double x = log10(n)/log10(3);
        int x_int = (int) x;
        return x-x_int==0;
    }
};
