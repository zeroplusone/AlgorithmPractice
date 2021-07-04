class Solution {
public:
    int countGoodNumbers(long long n) {
        long long int mod=1e9+7;
        long long int five=power(5, (n-1)/2)%mod;
        long long int four=power(4, n/2)%mod;
        long long int ans=(five*four)%mod;
        ans=(ans*5)%mod;
        return ans;
    }
    
    long long int power(int base, long long int index) {
        if(index==0) {
            return 1;
        } else if(index==1) {
            return base;
        } else {
            long long int mod=1e9+7;
            long long int mid=power(base, index/2)%mod;
            if(index%2==0) {
                return (mid*mid)%mod;
            } else {
                return ((mid*mid)%mod*base)%mod;
            }
        }
    }
};
