class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n;

        while(l<r) {
            int mid=(l+r)>>1;
            if(canbe(mid, m, n)>=k) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return r;
    }
    
    int canbe(int& ans, int& m , int& n) {
        int cnt=0;
        for(int i=1;i<=m;++i) {
            cnt+=min(ans/i, n);
        }
        return cnt;
    }
};
