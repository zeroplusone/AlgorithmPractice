class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(31, 0);
        f[0]=1;
        f[1]=2;
        for(int i=2;i<31;++i) {
            f[i]=f[i-1]+f[i-2];
        }

        int ans=0;
        int pre=0;
        for(int i=30;i>=0;--i) {
            int mask=1<<i;
            if((n&mask)==0) {
                pre=0;
            } else {
                ans+=f[i];
                if(pre==1) {
                    ans-=1;
                    break;
                }
                pre=1;
            }
        }
        return ans+1;
    }
};
