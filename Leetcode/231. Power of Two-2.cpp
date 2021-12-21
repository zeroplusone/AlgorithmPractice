class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) {
            return false;
        }
        double l2=log2(n);
        return l2-(int)l2==0;
    }
};
