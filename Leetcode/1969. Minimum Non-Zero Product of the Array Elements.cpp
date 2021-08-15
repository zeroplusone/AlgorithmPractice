class Solution {
public:
    int minNonZeroProduct(int p) {
        if(p==1) {
            return 1;
        }

        long long int mod=1e9+7;
        long long int a=power(2, p, false)-1;
        long long int b=(a-1)%mod;
        long long int c=power(2, p-1, false)-1;

        long long int ans=a%mod*power(b, c, true)%mod;
        return ans;
    }
    
    long long int power(unsigned long long int base, unsigned long long int exp, bool needMod) {
        long long int mod=1e9+7;
        if(exp==0) {
            return 1;
        } else if(exp==1) {
            return base;
        }
        long long int half=power(base, exp/2, needMod);
        long long int ret=needMod?half*half%mod:half*half;    
        
        if(exp%2==1) {
            return needMod?ret*base%mod:ret*base;
        } else {
            return ret;
        }
    }
};
