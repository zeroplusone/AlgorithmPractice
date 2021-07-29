class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int inf=1e9;
        vector<vector<int>> ans(m, vector<int>(n, inf));
        
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(mat[i][j]==0) {
                    ans[i][j]=0;
                }
            }
        }
        // from left top to right down
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(mat[i][j]!=0) {
                    if(i!=0) {
                        ans[i][j]=min(ans[i][j], ans[i-1][j]+1);    
                    }
                    if(j!=0) {
                        ans[i][j]=min(ans[i][j], ans[i][j-1]+1);  
                    }
                }
            }
            
        }
        
        // from right down to left top
        for(int i=m-1;i>=0;--i) {
            for(int j=n-1;j>=0;--j) {
                if(mat[i][j]!=0) {
                    if(i!=m-1) {
                        ans[i][j]=min(ans[i][j], ans[i+1][j]+1);    
                    }
                    if(j!=n-1) {
                        ans[i][j]=min(ans[i][j], ans[i][j+1]+1);  
                    }
                }
            }
        }
        
        return ans;
    }
};
