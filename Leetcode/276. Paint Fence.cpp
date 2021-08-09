class Solution {
public:
    int numWays(int n, int k) {
        int f0=k;
        int f1=k*k;
        int f2;
        if(n==1) {
            return f0;
        } else if(n==2) {
            return f1;
        }

        for(int i=3;i<=n;++i) {
            f2=(k-1)*(f0+f1);
            f0=f1;
            f1=f2;
        }
        
        return f2;
    }
};
