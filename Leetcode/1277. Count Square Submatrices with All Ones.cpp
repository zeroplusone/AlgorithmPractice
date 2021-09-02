class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size(), n=matrix[0].size();
        for(int len=0;len<min(m, n);++len) {
            int tmp=ans;
            for(int i=m-1;i>=len;--i) {
                for(int j=n-1;j>=len;--j) {
                    if(len==0) {
                        ans+=matrix[i][j]==1?1:0;
                    } else {
                        if(matrix[i][j]==1 && matrix[i-1][j]==1 && matrix[i][j-1]==1 && matrix[i-1][j-1]==1) {
                            ans++;
                        } else {
                            matrix[i][j]=0;
                        }
                    }
                }
            }
            if(ans-tmp==0) {
                break;
            }
        }
        return ans;
    }
};
