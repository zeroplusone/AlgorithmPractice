class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for(int i=0;i<n/2;++i) {
            ans[i*2]=i+1;
            ans[i*2+1]=(-1)*(i+1);
        }
        return ans;
    }
};
