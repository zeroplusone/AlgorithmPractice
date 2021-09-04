class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int l=0, r=m*n-1;
        while(l<r) {
            int mid=(l+r+1)/2;
            int x=mid/n, y=mid%n;
            if(matrix[x][y]==target) {
                return true;
            } else if(matrix[x][y]<target) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        
        return matrix[r/n][r%n]==target;
    }
};
