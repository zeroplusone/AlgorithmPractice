class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int l=1, r=1e6;
        long long int mid;
        while(l<r) {
            mid = (l+r)>>1;
            // calculate 第一象限 f(i)=12*i^2
            // sum(i) = 12*i^2+12*(i+1)^2+...+12*n^2;
            // sum of n^2 = n*(n+1)*(2*n+1)/6
            // 12 * n*(n+1)*(2*n+1)/6 = n*(n+1)*(2*n+1)*2
            long long int apples = (mid)*(mid+1)*(2*mid+1)*2;
            if(apples>=neededApples) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        
        // len = i*2正負*4邊
        return r*8;
    }
};
