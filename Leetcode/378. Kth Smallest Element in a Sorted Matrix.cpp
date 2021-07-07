class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0], r=matrix[n-1][n-1];

        int mid;
        while(l<r) {
            mid=(l+r)>>1;
            int cnt=0;
            for(int i=0;i<n;++i) {
                cnt+=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            
            if(cnt>=k) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return r;
    }
};
