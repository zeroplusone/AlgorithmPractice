class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        for(int i=0;i<n;++i) {
            if(i<k) {
                ans[i]=i&1?n-(i>>1):(i>>1)+1;
            } else {
                ans[i]=k&1?((3-k)>>1)+i:n+(k>>1)-i;
            }
        }
        return ans;
    }
};
