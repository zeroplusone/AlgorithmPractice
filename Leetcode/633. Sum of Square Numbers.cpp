class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int l=0, r=sqrt(c);
        while(l<=r) {
            long long int val=l*l+r*r;
            if(val==c) {
                return true;
            } else if(val<c) {
                l++;
            } else {
                r--;
            }
        }
        
        return false;
    }
};
