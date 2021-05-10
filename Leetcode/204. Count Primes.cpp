class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> is_prime(n+1, true);
        is_prime[0]=false;
        is_prime[1]=false;
        for(int i=2;i<=sqrt(n);++i) {
            for(int j=i*i;j<=n;j+=i) {
                is_prime[j]=false;    
            }
        }
        for(int i=0;i<n;++i) {
            if(is_prime[i]) {
                ans++;
            }
        }
        return ans;
    }
};
