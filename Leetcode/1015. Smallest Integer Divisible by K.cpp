class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int one=0;
        for(int i=1;i<=k;++i) {
            one=(one*10+1)%k;
            if(one==0) {
                return i;
            }
        }
        return -1;
    }
};
