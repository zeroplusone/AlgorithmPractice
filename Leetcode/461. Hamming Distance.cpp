class Solution {
public:
    int hammingDistance(int x, int y) {
        int xornum=x^y;
        int ans=0;
        while(xornum!=0) {
            ans+=xornum&1;
            xornum=xornum>>1;
        }
        return ans;
    }
};
