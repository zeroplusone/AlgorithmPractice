class Solution {
public:
    int fib(int n) {
        int last=0, now=1, tmp;
        if(n==0) {
            return last;
        } else if(n==1) {
            return now;
        } else {
            for(int i=2;i<=n;++i) {
                tmp=now;
                now=last+now;
                last=tmp;
            }
            return now;
        }
    }
};
