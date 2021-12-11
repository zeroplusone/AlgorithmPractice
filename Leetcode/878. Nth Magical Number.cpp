class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long int l=min(a, b);
        long long int r=l*n;
        
        int gcd=findGcd(a, b);
        int lcm=a*b/gcd;
        
        long long int mod=1e9+7;

        while(l<r) {
            long long int mid=(l+r)>>1;
            if(canbe(mid, a, b, lcm, n)) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return r%mod;
    }
    
    bool canbe(long long int m, int& a, int& b, int& lcm, int& n) {
        long long int cnt=m/a+m/b-m/lcm;
        return cnt>=n;
    }
    
    int findGcd(int a, int b) {
        if(b>a) {
            swap(a, b);
        }

        while(b>0) {
            int tmp=a;
            a=b;
            b=tmp%b;
        }
        return a;
    }
};
